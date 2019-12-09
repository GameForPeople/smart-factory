// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
//#include "SensorFusionEngine.h"
#include "SensorFusionBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class USensorFusionBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/**
	* 센서와의 연결을 시도합니다.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ConnectToSensor", Keywords = ""), Category = "SensorFusion")
		static bool Connect();

	/**
	* 센서와의 연결을 끊습니다.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "DisconnectFromSensor", Keywords = ""), Category = "SensorFusion")
		static void Disconnect(); 

	/**
	* 센서와의 연결여부를 확인합니다.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsSensorConnected", Keywords = ""), Category = "SensorFusion")
		static bool IsConnected();

	/**
	* RootSensor의 Transform값을 설정합니다.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetRootSensorTransform", Keywords = ""), Category = "SensorFusion")
		static void SetRootSensorTransform(UPARAM(ref) FTransform& rootTransform);

	/**
	* RootSensor의 Transform값을 확인합니다.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetRootSensorTransform", Keywords = ""), Category = "SensorFusion")
		static FTransform GetRootSensorTransform(bool bRawData=false);

	/**
	* RootSensor의 Rotation값을 확인합니다.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetRootSensorRotation", Keywords = ""), Category = "SensorFusion")
		static FQuat GetRootSensorRotation(bool bRawData = false);

	/**
	* 주어진 인덱스에 해당하는 센서의 Transform값을 확인합니다.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetSensorTransform", Keywords = ""), Category = "SensorFusion")
		static FTransform GetSensorTransform(int idxSensor, bool bRawData=false);

	/**
	* 주어진 인덱스에 해당하는 센서의 Rotation값(쿼터니언)을 확인합니다.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetSensorRotation", Keywords = ""), Category = "SensorFusion")
		static FQuat GetSensorRotation(int idxSensor, bool bRawData = false);

	/**
	* RootSensor에 대하여 Rotation을 Bind합니다.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "BindRotation", Keywords = ""), Category = "SensorFusion")
		static bool BindRotation();

	/**
	* RootSensor의 Rotation의 Bind 여부를 확인합니다.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsRotationBinded", Keywords = ""), Category = "SensorFusion")
		static bool IsRotationBinded();

	/**
	* Log를 출력합니다.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PrintLog", Keywords = ""), Category = "SensorFusion")
		static void PrintLog();


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetSensorAccelerometer", Keywords = ""), Category = "SensorFusion")
		static FVector GetSensorAccelerometer(int idxSensor);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetSensorGyroscope", Keywords = ""), Category = "SensorFusion")
		static FVector GetSensorGyroscope(int idxSensor);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetRootSensorAccelerometer", Keywords = ""), Category = "SensorFusion")
		static FVector GetRootSensorAccelerometer();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetRootSensorGyroscope", Keywords = ""), Category = "SensorFusion")
		static FVector GetRootSensorGyroscope();
};
