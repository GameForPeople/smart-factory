// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomNetworkProcesser.h"
#include "CustomNetworkManagerActor.h"


// Sets default values
ACustomNetworkProcesser::ACustomNetworkProcesser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isOnTick = false;

	//texture2DInst = CreateDefaultSubobject<UTexture2D>(TEXT("TEXTURE2D"));
	//texture2DInst = UTexture2D::CreateTransient(300, 300);
	
	textureRenderTarget = CreateDefaultSubobject<UTextureRenderTarget2D>(TEXT("TEXTURE2D")); // UTextureRenderTarget2D::CreateResource();
	textureRenderTarget->ResizeTarget(300, 300);
	texture2DInst = textureRenderTarget->ConstructTexture2D(texture2DInst, "TEX_2D", EObjectFlags::RF_Public);

	//sceneCaptureComponent2DInst = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture2d_custom"));
	//sceneCaptureComponent2DInst->TextureTarget = textureRenderTarget;

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
}

/////////////////////////////////////////////////////
void ACustomNetworkProcesser::CustomTick()
{
	if (!isOnTick) { return; }

	_PacketType retPacket;

	while (7)
	{
		if (!jobQueue.try_pop(retPacket)) { break; }

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

void ACustomNetworkProcesser::SetCustomNetworkManagerActorInst(ACustomNetworkManagerActor* pCustomNetworkManagerActorInst)
{
	customNetworkManagerActorInst = pCustomNetworkManagerActorInst;
	isOnTick = true;
}

void ACustomNetworkProcesser::CopyData()
{
	TextureCompressionSettings OldCompressionSettings = texture2DInst->CompressionSettings;
	TextureMipGenSettings OldMipGenSettings = texture2DInst->MipGenSettings;
	bool OldSRGB = texture2DInst->SRGB;

	texture2DInst->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
	texture2DInst->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	texture2DInst->SRGB = false;
	texture2DInst->UpdateUnrealResource();

	const FColor* FormatedImageData = static_cast<const FColor*>(texture2DInst->PlatformData->Mips[0].BulkData.LockReadOnly());

	for (int32 X = 0; X < /*texture2DInst->GetSizeX()*/ 64; X++)
	{
		for (int32 Y = 0; Y < /*texture2DInst->GetSizeY()*/ 64; Y++)
		{
			int tempIndex = Y * /*texture2DInst->GetSizeX()*/ 64 + X;
			customNetworkManagerActorInst->cameraData[tempIndex] = FormatedImageData[tempIndex].R;

			++tempIndex;

			customNetworkManagerActorInst->cameraData[tempIndex] = FormatedImageData[tempIndex].G;
			
			++tempIndex;

			customNetworkManagerActorInst->cameraData[tempIndex] = FormatedImageData[tempIndex].B;
		}
	}

	texture2DInst->PlatformData->Mips[0].BulkData.Unlock();

	texture2DInst->CompressionSettings = OldCompressionSettings;
	texture2DInst->MipGenSettings = OldMipGenSettings;
	texture2DInst->SRGB = OldSRGB;
	texture2DInst->UpdateUnrealResource();
}

void ACustomNetworkProcesser::SetPixel(int32 index, uint8 pixelValue)
{
	UE_LOG(LogTemp, Log, TEXT("%d %d"), index, pixelValue);
	customNetworkManagerActorInst->cameraData[index] = pixelValue;
}

UTextureRenderTarget2D* ACustomNetworkProcesser::GetTextureRenderTarget2D()
{
	return textureRenderTarget;
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
