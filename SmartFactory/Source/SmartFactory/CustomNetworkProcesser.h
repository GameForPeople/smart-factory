// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// c++ Header
#include <thread>
#include <string>
#include <mutex>

// ppl
#include <concurrent_queue.h>

#include "CustomClientInfo.h"
#include "../../Protocol.hh"

#include "Engine/Texture.h"
#include "Engine/Texture2D.h"
#include "Engine/Texture2DDynamic.h"
#include "Engine/TextureRenderTarget2D.h"

#include "Components/SceneCaptureComponent2D.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomNetworkProcesser.generated.h"

class ACustomNetworkManagerActor;

UCLASS()
class SMARTFACTORY_API ACustomNetworkProcesser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomNetworkProcesser();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

////////////////////////////////////////////////////////////////////Custom
public:

	UPROPERTY(EditAnywhere)
	ACustomNetworkManagerActor* customNetworkManagerActorInst;
	
	UPROPERTY(EditAnywhere)
	UTextureRenderTarget2D* textureRenderTarget;
	
	UPROPERTY(EditAnywhere)
	UTexture2D* texture2DInst;

	//UPROPERTY(EditAnywhere)
	//USceneCaptureComponent2D* sceneCaptureComponent2DInst;

	UFUNCTION(BlueprintCallable, Category = "FACTORY_NETWORK")
	void SetCustomNetworkManagerActorInst( ACustomNetworkManagerActor* pCustomNetworkManager);
	
	bool isOnTick;

	//Message Function
	UFUNCTION(BlueprintImplementableEvent, Category = "FACTORY_NETWORK")
	void DoFactoryOnOff(uint8 factoryOnOffFlag);
	//void DoFactoryOnOff(_Flag factoryOnOffFlag);

	UFUNCTION(BlueprintImplementableEvent, Category = "FACTORY_NETWORK")
	void DoFactoryOrder(ACustomClientInfo* clientOrder);
	//void DoFactoryOrder(ClientOrder clientOrder);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "FACTORY_NETWORK")
	void DoFactoryChangeCameraIndex(int32 clientOrder);
	//void DoFactoryChangeCameraIndex(_Index clientOrder);

	void CopyData();

	UFUNCTION(BlueprintCallable, Category = "FACTORY_NETWORK")
	void SetPixel(int32 index, uint8 pixelValue);

	UFUNCTION(BlueprintCallable, Category = "FACTORY_NETWORK")
	void CustomTick();

	concurrency::concurrent_queue<_PacketType> jobQueue;

	UFUNCTION(BlueprintCallable, Category = "FACTORY_NETWORK")
	UTextureRenderTarget2D* GetTextureRenderTarget2D();
private:
};
