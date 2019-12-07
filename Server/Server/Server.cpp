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
		std::cout << "사용하실 IP를 입력해주세요. \n"
			<< " 0. Local host 127.0.0.1 \n"
			<< " 1. Public AWS EC2 IP \n";

		std::cout << "--> ";
		std::cin >> ServerIpType;

		if (ServerIpType > 1) 
		{ 
			ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "비 정상적인 입력값 입니다. \n");
		}
	}

	for (int i = 0; i < 90000; ++i)
	{
		savedCameraData.colorArr[i * 3] = (char)0;
		savedCameraData.colorArr[i * 3 + 1] = (char)255;
		savedCameraData.colorArr[i * 3 + 2] = (char)0;
	}

	Init();
}

Server::~Server()
{
	// if (managerFlag) { closesocket(managerSocket); managerNetworkThread.join(); }
	// if (factoryFlag) { closesocket(factorySocket); factoryNetworkThread.join(); }
}

void Server::Init()
{
#pragma region [ WSAStartup() ]
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) { ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "WSA 에러 \n"); }
#pragma endregion

#pragma region [ Socket() ]
	if (listenSocket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, NULL)
		; listenSocket == INVALID_SOCKET)
	{
		ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "Listen Socket 생성 에러 : " + WSAGetLastError());
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
		ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "바인드 에러 \n");
	}
#pragma endregion
}

void Server::Run()
{
#pragma region [ Listen() ]
	if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "리슨 에러 \n");
	}
#pragma endregion

	system("CLS");

	std::printf("\n■■■■■■■■■■■■■■■\n");
	std::printf("■ Smart Factory Server  \n");
	std::printf("■                   6조 \n");
	std::printf("■\n");

	if(ServerIpType) { std::cout << "■ IP : " << PUBLIC_SERVER_IP << "\n"; }
	else { std::cout << "■ IP : " << LOCAL_HOST_IP << "\n"; }

	std::printf("■ Listen Port : %d", (int)SERVER_LISTEN_PORT);
	std::printf("\n■■■■■■■■■■■■■■■\n");
	
	SOCKET clientSocket;
	SOCKADDR_IN clientAddr;
	int addrLen = sizeof(clientAddr);

	while (7)
	{
		if (clientSocket = accept(listenSocket, (SOCKADDR*)& clientAddr, &addrLen)
			; clientSocket == INVALID_SOCKET) 
		{
			ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "소켓 생성 실패?");
		}

		std::cout
			<< "[ 새로운 클라이언트 접속 IP : "
			<< inet_ntoa(clientAddr.sin_addr)
			<< "  PORT : "
			<< ntohs(clientAddr.sin_port)
			<< "  ] \n";

		Auth auth;
		NETWORK_UTIL::recvn(clientSocket, (char*)&auth, sizeof(auth), 0);

		if (auth.commonPassword != DEFINE::COMMON_PASSWORD)
		{
			closesocket(clientSocket);
			continue;
		}

		if (auth.clientType == CLIENT_TYPE::Client)
		{
			ClientOrder clientOrder;
			NETWORK_UTIL::recvn(clientSocket, (char*)&clientOrder, sizeof(clientOrder), 0);

			std::wprintf(L"[Client] 오더를 받았습니다. 차종 %d, 차색 %d, 타이어 %d"
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
				std::cout << "[Manager] 매니저 연결 성공\n";
				managerSocket = clientSocket;

				if (managerNetworkThread.joinable()) { managerNetworkThread.join(); }
				managerNetworkThread = std::thread([&]{ this->ManagerNetwork(); });
				//managerNetworkThread.detach();
			}
			else { closesocket(clientSocket); }
		}
		else if (auth.clientType == CLIENT_TYPE::Factory)
		{
			if (bool tempValue = false
				; factoryFlag.compare_exchange_strong(tempValue, true, memory_order::memory_order_seq_cst))
			{
				std::cout << "[Factory] 팩토리 연결 성공\n";
				factorySocket = clientSocket;
				
				if (factoryNetworkThread.joinable()) { factoryNetworkThread.join(); }
				factoryNetworkThread = std::thread([&] { this->FactoryNetwork(); });
				//factoryNetworkThread.detach();
			}
			else { closesocket(clientSocket); }
		}
		else
		{
			ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, "[ERROR] 확인되지 않은 클라이언트 타입이 접속하였습니다.");
		}
	}
}

void Server::ManagerNetwork()
{
	_PacketType typeBuffer{};
	while (7)
	{
		if (auto retValue = NETWORK_UTIL::recvn(managerSocket, (char*)&typeBuffer, sizeof(_PacketType), 0)
			; retValue < 0)
		{
			// -2 Client End , -1 Socket Error
			closesocket(managerSocket);
			managerFlag = false;
			std::cout << "[Manager] 매니저 연결 종료\n";
			return;
		}

		if (typeBuffer == MANAGER_PACKET_TYPE::OnOffFactory)
		{
			std::cout << "[Manager] onOffFactory! \n";

			OnOffFactory onOffFactory;
			NETWORK_UTIL::recvn(managerSocket, (char*)& onOffFactory, sizeof(onOffFactory), 0);

			factoryOnOffFlag = onOffFactory.flag;
		}
		else if (typeBuffer == MANAGER_PACKET_TYPE::ChangeCamera)
		{
			std::cout << "[Manager] ChangeCamera! \n";

			ChangeCamera changeCamera;
			NETWORK_UTIL::recvn(managerSocket, (char*)& changeCamera, sizeof(changeCamera), 0);

			savedCameraIndex = changeCamera.cameraIndex;
		}
		else if (typeBuffer == MANAGER_PACKET_TYPE::NeedCameraData)
		{
			//	std::cout << "[Manager] NeedCameraData! \n";

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
		if (auto retValue = NETWORK_UTIL::recvn(factorySocket, (char*)&typeBuffer, sizeof(_PacketType), 0)
			; retValue < 0)
		{
			// -2 Client End , -1 Socket Error
			closesocket(factorySocket);
			factoryFlag = false;
			std::cout << "[Factory] 팩토리 연결 종료\n";
			return;
		}

		if (typeBuffer == FACTORY_PACKET_TYPE::GetOnOffState)
		{
			std::cout << "[Factory] GetOnOffState! \n";

			OnOffFactory onoffFactory;
			onoffFactory.flag = factoryOnOffFlag;

			send(factorySocket, (char*)&onoffFactory, sizeof(onoffFactory), 0);
		}
		else if (typeBuffer == FACTORY_PACKET_TYPE::GetOrder)
		{
			std::cout << "[Factory] GetOrder! \n";


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
			std::cout << "[Factory] GetCameraIndex! \n";

			ChangeCamera changeCamera;
			changeCamera.cameraIndex = savedCameraIndex;

			send(factorySocket, (char*)& changeCamera, sizeof(changeCamera), 0);
		}
		else if (typeBuffer == FACTORY_PACKET_TYPE::CameraData)
		{
			std::cout << "[Factory] CameraData! \n";

			NETWORK_UTIL::recvn(factorySocket, (char*)& recvedCameraData, sizeof(recvedCameraData), 0);
			{
				std::unique_lock<mutex> localLock(cameraDataLock);
				savedCameraData = recvedCameraData;
			}
		}
	}
}
