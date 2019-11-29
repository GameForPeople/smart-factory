#pragma once

#include "Protocol.hh"

class Server
{
	_INLINE static constexpr unsigned short SERVER_LISTEN_PORT = 9000;
	_INLINE static const string PUBLIC_SERVER_IP = "13.125.73.63";
	_INLINE static const string LOCAL_HOST_IP = "127.0.0.1";

public:
	void Run();
	void ManagerNetwork();
	void FactoryNetwork();

private:
	void Init();

public:
	Server();
	~Server();

private:
	int ServerIpType;
	SOCKET listenSocket;

	std::thread managerNetworkThread;
	std::atomic<bool> managerFlag;
	SOCKET managerSocket;

	std::thread factoryNetworkThread;
	std::atomic<bool> factoryFlag;
	SOCKET factorySocket;

private:
	concurrency::concurrent_queue<ClientOrder> clientOrderQueue;
	std::atomic<bool> factoryOnOffFlag;

	std::mutex cameraDataLock;
	CameraData savedCameraData;
	CameraData recvedCameraData;
	CameraData sendedCameraData;
	
	std::atomic<int> savedCameraIndex;
};