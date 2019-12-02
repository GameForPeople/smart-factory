// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomClientInfo.generated.h"

UCLASS()
class SMARTFACTORY_API ACustomClientInfo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomClientInfo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 carType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 colorType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 tireType;
};
