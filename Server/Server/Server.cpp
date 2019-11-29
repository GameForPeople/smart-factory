#include "stdafx.h"
#include "Server.h"

Server::Server()
	: ServerIpType()
	, listenSocket()
	, managerNetworkThread()
	, managerFlag(false)
	, managerSocket()
	, factoryNetworkThread()
	, factoryFlag(false)
	, factorySocket()
	, clientOrderQueue()
	, factoryOnOffFlag(false)
	, cameraDataLock()
	, savedCameraData()
	, recvedCameraData()
	, sendedCameraData()
	, savedCameraIndex(0)
{
	{
		std::cout << "����Ͻ� IP�� �Է����ּ���. \n"
			<< " 0. Local host 127.0.0.1 \n"
			<< " 1. Public AWS EC2 IP \n";

		std::cout << "--> ";
		std::cin >> ServerIpType;

		if (ServerIpType > 1) 
		{ 
			ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "�� �������� �Է°� �Դϴ�. \n");
		}
	}

	Init();
}

Server::~Server()
{
	if (managerFlag) { closesocket(managerSocket); managerNetworkThread.join(); }
	if (factoryFlag) { closesocket(factorySocket); factoryNetworkThread.join(); }
}

void Server::Init()
{
#pragma region [ WSAStartup() ]
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) { ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "WSA ���� \n"); }
#pragma endregion

#pragma region [ Socket() ]
	if (listenSocket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, NULL)
		; listenSocket == INVALID_SOCKET)
	{
		ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "Listen Socket ���� ���� : " + WSAGetLastError());
	}
#pragma endregion

#pragma region [ Bind() ]
	SOCKADDR_IN serverAddr;
	ZeroMemory(&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(SERVER_LISTEN_PORT);

	if (::bind(listenSocket, (SOCKADDR*)& serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "���ε� ���� \n");
	}
#pragma endregion
}

void Server::Run()
{
#pragma region [ Listen() ]
	if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "���� ���� \n");
	}
#pragma endregion

	system("CLS");

	std::printf("\n����������������\n");
	std::printf("�� Smart Factory Server  \n");
	std::printf("��                   6�� \n");
	std::printf("��\n");

	if(ServerIpType) { std::cout << "�� IP : " << PUBLIC_SERVER_IP << "\n"; }
	else { std::cout << "�� IP : " << LOCAL_HOST_IP << "\n"; }

	std::printf("�� Listen Port : %d", (int)SERVER_LISTEN_PORT);
	std::printf("\n����������������\n");
	
	SOCKET clientSocket;
	SOCKADDR_IN clientAddr;
	int addrLen = sizeof(clientAddr);

	while (7)
	{
		if (clientSocket = accept(listenSocket, (SOCKADDR*)& clientAddr, &addrLen)
			; clientSocket == INVALID_SOCKET) 
		{
			ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "���� ���� ����?");
		}

		std::cout
			<< "[ ���ο� Ŭ���̾�Ʈ ���� IP : "
			<< inet_ntoa(clientAddr.sin_addr)
			<< "  PORT : "
			<< ntohs(clientAddr.sin_port)
			<< "  ] \n";

		Auth auth;
		recv(clientSocket, (char*)&auth, sizeof(auth), 0);

		if (auth.commonPassword != DEFINE::COMMON_PASSWORD)
		{
			closesocket(clientSocket);
			continue;
		}

		if (auth.clientType == CLIENT_TYPE::Client)
		{
			ClientOrder clientOrder;
			recv(clientSocket, (char*)&clientOrder, sizeof(clientOrder), 0);

			std::wprintf(L"[Client] ������ �޾ҽ��ϴ�. ���� %d, ���� %d, Ÿ�̾� %d"
				, (int)(clientOrder.carType)
				, (int)(clientOrder.colorType)
				, (int)(clientOrder.tireType)
			);

			clientOrderQueue.push(clientOrder);
			closesocket(clientSocket);
		}
		else if (auth.clientType == CLIENT_TYPE::Manager)
		{
			if (bool tempValue = false
			; managerFlag.compare_exchange_strong(tempValue, true, memory_order::memory_order_seq_cst))
			{
				std::cout << "[Manager] �Ŵ��� ���� ����\n";
				managerSocket = clientSocket;
				managerNetworkThread = std::thread([&]{ this->ManagerNetwork(); });
			}
			else { closesocket(clientSocket); }
		}
		else if (auth.clientType == CLIENT_TYPE::Factory)
		{
			if (bool tempValue = false
				; factoryFlag.compare_exchange_strong(tempValue, true, memory_order::memory_order_seq_cst))
			{
				std::cout << "[Factory] ���丮 ���� ����\n";
				factorySocket = clientSocket;
				factoryNetworkThread = std::thread([&] { this->FactoryNetwork(); });
			}
			else { closesocket(clientSocket); }
		}
		else
		{
			ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "[ERROR] Ȯ�ε��� ���� Ŭ���̾�Ʈ Ÿ���� �����Ͽ����ϴ�.");
		}
	}
}

void Server::ManagerNetwork()
{
	_PacketType typeBuffer{};
	while (7)
	{
		recv(managerSocket, (char*)& typeBuffer, sizeof(_PacketType), 0);

		if (typeBuffer == MANAGER_PACKET_TYPE::OnOffFactory)
		{
			OnOffFactory onOffFactory;
			recv(managerSocket, (char*)& onOffFactory, sizeof(onOffFactory), 0);

			factoryOnOffFlag = onOffFactory.flag;
		}
		else if (typeBuffer == MANAGER_PACKET_TYPE::ChangeCamera)
		{
			ChangeCamera changeCamera;
			recv(managerSocket, (char*)& changeCamera, sizeof(changeCamera), 0);

			savedCameraIndex = changeCamera.cameraIndex;
		}
		else if (typeBuffer == MANAGER_PACKET_TYPE::NeedCameraData)
		{
			{
				std::unique_lock<mutex> localLock(cameraDataLock);
				sendedCameraData = savedCameraData;
			}

			send(managerSocket, (char*)& sendedCameraData, sizeof(sendedCameraData), 0);
		}
	}
}

void Server::FactoryNetwork()
{
	_PacketType typeBuffer{};
	while (7)
	{
		recv(factorySocket, (char*)& typeBuffer, sizeof(_PacketType), 0);

		if (typeBuffer == FACTORY_PACKET_TYPE::GetOnOffState)
		{
			OnOffFactory onoffFactory;
			onoffFactory.flag = factoryOnOffFlag;

			send(factorySocket, (char*)&onoffFactory, sizeof(onoffFactory), 0);
		}
		else if (typeBuffer == FACTORY_PACKET_TYPE::GetOrder)
		{
			OrderInfo orderInfo;
			ClientOrder clientOrder;
			if (clientOrderQueue.try_pop(clientOrder))
			{
				orderInfo.flag = true;
				orderInfo.clientOrder = clientOrder;
			}
			else
			{
				orderInfo.flag = false;
			}
			
			send(factorySocket, (char*)& orderInfo, sizeof(orderInfo), 0);
		}
		else if (typeBuffer == FACTORY_PACKET_TYPE::GetCameraIndex)
		{
			ChangeCamera changeCamera;
			changeCamera.cameraIndex = savedCameraIndex;

			send(factorySocket, (char*)& changeCamera, sizeof(changeCamera), 0);
		}
		else if (typeBuffer == FACTORY_PACKET_TYPE::CameraData)
		{
			recv(factorySocket, (char*)& recvedCameraData, sizeof(recvedCameraData), 0);
			{
				std::unique_lock<mutex> localLock(cameraDataLock);
				savedCameraData = recvedCameraData;
			}
		}
	}
}