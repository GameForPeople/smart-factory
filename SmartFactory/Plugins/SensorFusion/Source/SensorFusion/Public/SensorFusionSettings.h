// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SensorFusionSettings.generated.h"

/**
 * 
 */
USTRUCT()
struct SENSORFUSION_API FSensorData {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, config, Category = Custom)
		FString SensorID;
	UPROPERTY(EditAnywhere, config, Category = Custom)
		int32 ParentSensorIdx;

	FSensorData() { ParentSensorIdx = -1; }
};

UCLASS(config=Game, defaultconfig)
class SENSORFUSION_API USensorFusionSettings : public UObject
{
	GENERATED_BODY()
	
public:

	USensorFusionSettings(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(EditAnywhere, config, Category = Custom)
		FString ComPort;
	UPROPERTY(EditAnywhere, config, Category = Custom)
		FString ReferenceSensorID;
#if 0
	UPROPERTY(EditAnywhere, config, Category = Custom)
		int SensorCount;
	UPROPERTY(EditAnywhere, config, Category = Custom)
		TArray<FString> SensorIDList;
#endif

	UPROPERTY(EditAnywhere, config, Category = Custom)
		TArray<struct FSensorData> Sensors;

	UPROPERTY(EditAnywhere, config, Category = Custom)
		int SleepTimeForFile;
};
