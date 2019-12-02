// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomNetworkProcesser.h"
#include "CustomNetworkManagerActor.h"

// Sets default values
ACustomNetworkProcesser::ACustomNetworkProcesser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isOnTick = true;
}

// Called when the game starts or when spawned
void ACustomNetworkProcesser::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACustomNetworkProcesser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!isOnTick) { return; }

	_PacketType retPacket;

	while (7)
	{
		if (!jobQueue.try_pop(retPacket)) { return; }

		if (retPacket == FACTORY_PACKET_TYPE::GetOnOffState)
		{
			DoFactoryOnOff(customNetworkManagerActorInst->factoryOnOffFlag);
		}
		else if (retPacket == FACTORY_PACKET_TYPE::GetOrder)
		{
			DoFactoryOrder(customNetworkManagerActorInst->customClientInfo);
		}
		else if (retPacket == FACTORY_PACKET_TYPE::GetCameraIndex)
		{
			DoFactoryChangeCameraIndex(customNetworkManagerActorInst->cameraIndex);
		}
		//else if (retPacket == FACTORY_PACKET_TYPE::CameraData)
		//{
		//
		//}
	}

	// Need Camera Data Copy!
	// customNetworkManagerActorInst->cameraData;

	customNetworkManagerActorInst->AddFactoryCameraData();
}

/////////////////////////////////////////////////////
void ACustomNetworkProcesser::SetCustomNetworkManagerActorInst(ACustomNetworkManagerActor* pCustomNetworkManagerActorInst)
{
	customNetworkManagerActorInst = pCustomNetworkManagerActorInst;
	isOnTick = true;
}

//void ACustomNetworkProcesser::DoFactoryOnOff(_Flag factoryOnOffFlag)
//{
//
//}
//
//void ACustomNetworkProcesser::DoFactoryOrder(ClientOrder clientOrder)
//{
//
//}
//
//void ACustomNetworkProcesser::DoFactoryChangeCameraIndex(_Index cameraIndex)
//{
//
//}
