// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// c++ Header
#include <thread>
#include <string>
#include <mutex>

// ppl
#include <concurrent_queue.h>

// Windows
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "ws2_32")
#pragma comment(lib, "wininet.lib")

#include <winsock2.h>

#include "CustomClientInfo.h"
#include "../../Protocol.hh"

// unreal!
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomNetworkManagerActor.generated.h"

namespace NETWORK_UTIL
{
	int recvn(SOCKET socket, char* buf, int len, int flags);
}

class ACustomNetworkProcesser;

UCLASS()
class SMARTFACTORY_API ACustomNetworkManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomNetworkManagerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

/////////////////////////////// My Function
private:
	const int COMMON_PASSWORD = 19942019;
	const unsigned short SERVER_LISTEN_PORT = 9000;
	const std::string PUBLIC_SERVER_IP = "13.125.73.63";
	const std::string LOCAL_HOST_IP = "127.0.0.1";

public:
	UFUNCTION(BlueprintCallable, Category = "FACTORY_NETWORK")
	void StartNetwork(bool isUsePublicIP);
	
	UFUNCTION(BlueprintCallable, Category = "FACTORY_NETWORK")
	void EndNetwork();

	void NetworkFunction();

	UPROPERTY(EditAnywhere)
	ACustomNetworkProcesser* customNetworkProcesserInst;

	UFUNCTION(BlueprintCallable, Category = "FACTORY_NETWORK")
	void SetCustomNetworkProcesserInst(ACustomNetworkProcesser* pCustomNetworkProcesserInst);
public:

	UFUNCTION(BlueprintCallable, Category = "FACTORY_NETWORK")
	void AddFactoryOnOff();

	UFUNCTION(BlueprintCallable, Category = "FACTORY_NETWORK")
	void AddFactoryOrder();

	UFUNCTION(BlueprintCallable, Category = "FACTORY_NETWORK")
	void AddFactoryCameraIndex();

	UFUNCTION(BlueprintCallable, Category = "FACTORY_NETWORK")
	void AddFactoryCameraData();

private:
	std::thread networkThread;
	SOCKET socket;
	std::mutex networkLock;

	concurrency::concurrent_queue<_PacketType> packetQueue;

public:
	_Flag factoryOnOffFlag;
	_Index cameraIndex;
	_CameraDataType cameraData;
	ACustomClientInfo* customClientInfo;

	std::atomic<bool> threadEnd;
};
