// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomClientInfo.h"

// Sets default values
ACustomClientInfo::ACustomClientInfo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACustomClientInfo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomClientInfo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

