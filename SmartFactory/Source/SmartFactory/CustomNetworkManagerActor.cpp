// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomNetworkManagerActor.h"
#include <thread>

// Sets default values
ACustomNetworkManagerActor::ACustomNetworkManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

