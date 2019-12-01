// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomNetworkManagerActor.h"

// Sets default values
ACustomNetworkManagerActor::ACustomNetworkManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ACustomNetworkManagerActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACustomNetworkManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/////////////////////////////My Function

namespace NETWORK_UTIL
{
	int recvn(SOCKET socket, char* buf, int len, int flags)
	{
		int received;
		char* ptr = buf;

		int left = len;

		while (left > 0)
		{
			received = recv(socket, ptr, left, flags);

			if (received == SOCKET_ERROR) 
			{
				return SOCKET_ERROR;
			}
			else if (received == 0) { return -2; }

			left -= received;
			ptr += received;
		}

		return (len - left);
	}
}

void ACustomNetworkManagerActor::StartNetwork(bool isUsePublicIP)
{
#pragma region [ WSA ]
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) { UE_LOG(LogTemp, Fatal, TEXT("WSA Init Error")); }
#pragma endregion

#pragma region [ socket() ]
	socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, NULL);
	if (socket == INVALID_SOCKET) { UE_LOG(LogTemp, Fatal, TEXT("Create Socket Fail")); }
#pragma endregion

#pragma region [ connect() ]
	static SOCKADDR_IN serverAddr;
	ZeroMemory(&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;

	if (isUsePublicIP) { serverAddr.sin_addr.s_addr = inet_addr(PUBLIC_SERVER_IP.c_str()); }
	else { serverAddr.sin_addr.s_addr = inet_addr(LOCAL_HOST_IP.c_str()); }
	
	serverAddr.sin_port = htons(SERVER_LISTEN_PORT);
	int retVal = connect(socket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
	if (retVal == SOCKET_ERROR) { UE_LOG(LogTemp, Fatal, TEXT("Connect Fail")); }
#pragma endregion

	{
		std::lock_guard<std::mutex> localLock(networkLock);
		Auth auth;
		auth.clientType = CLIENT_TYPE::Factory;
		auth.commonPassword = COMMON_PASSWORD;
		send(socket, (char*)&auth, sizeof(auth), 0);
	}
	networkThread = std::thread([&] { this->NetworkFunction(); });
}

void ACustomNetworkManagerActor::NetworkFunction()
{
	_PacketType popedType;

	while (7)
	{
		if (!packetQueue.try_pop(popedType))
		{
			std::this_thread::yield();
			continue;
		}

		// Send Packet Type
		send(socket, (char*)&popedType, sizeof(popedType), 0);

		if (popedType == FACTORY_PACKET_TYPE::GetOnOffState)
		{
			OnOffFactory onoffFactory;
			if(NETWORK_UTIL::recvn(socket, (char*)&onoffFactory, sizeof(onoffFactory), 0) < 0)
			{
				UE_LOG(LogTemp, Fatal, TEXT("RECV ERROR"));
			}

			if (factoryOnOffFlag != onoffFactory.flag)
			{
				factoryOnOffFlag = onoffFactory.flag;
				DoFactoryOnOff(factoryOnOffFlag);
			}
		}
		else if (popedType == FACTORY_PACKET_TYPE::GetOrder)
		{
			OrderInfo orderInfo;
			if (NETWORK_UTIL::recvn(socket, (char*)&orderInfo, sizeof(orderInfo), 0) < 0)
			{
				UE_LOG(LogTemp, Fatal, TEXT("RECV ERROR"));
			}

			if (orderInfo.flag == 0) { continue; }

			DoFactoryOrder(orderInfo.clientOrder);
		}
		else if (popedType == FACTORY_PACKET_TYPE::GetCameraIndex)
		{
			ChangeCamera changeCamera;
			if (NETWORK_UTIL::recvn(socket, (char*)&changeCamera, sizeof(changeCamera), 0) < 0)
			{
				UE_LOG(LogTemp, Fatal, TEXT("RECV ERROR"));
			}

			if (cameraIndex != changeCamera.cameraIndex)
			{
				cameraIndex = changeCamera.cameraIndex;
				DoFactoryOnOff(cameraIndex);
			}
		}
		else if (popedType == FACTORY_PACKET_TYPE::CameraData)
		{
			// Send Packet Type
			send(socket, (char*)&cameraData, sizeof(cameraData), 0);
		}
	}
}

void ACustomNetworkManagerActor::DoFactoryOnOff(_Flag factoryOnOffFlag)
{

}

void ACustomNetworkManagerActor::DoFactoryOrder(ClientOrder clientOrder)
{

}

void ACustomNetworkManagerActor::DoFactoryChangeCameraIndex(_Index clientOrder)
{

}

void ACustomNetworkManagerActor::AddFactoryOnOff()
{
	packetQueue.push(FACTORY_PACKET_TYPE::GetOnOffState);
}

void ACustomNetworkManagerActor::AddFactoryOrder()
{
	packetQueue.push(FACTORY_PACKET_TYPE::GetOrder);
}

void ACustomNetworkManagerActor::AddFactoryCameraIndex()
{
	packetQueue.push(FACTORY_PACKET_TYPE::GetCameraIndex);
}

void ACustomNetworkManagerActor::AddFactoryCameraData()
{
	packetQueue.push(FACTORY_PACKET_TYPE::CameraData);
}