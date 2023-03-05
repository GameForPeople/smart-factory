// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SensorFusion/Public/SensorFusionBPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSensorFusionBPLibrary() {}
// Cross Module References
	SENSORFUSION_API UClass* Z_Construct_UClass_USensorFusionBPLibrary_NoRegister();
	SENSORFUSION_API UClass* Z_Construct_UClass_USensorFusionBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_SensorFusion();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_Connect();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_Disconnect();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_PrintLog();
	SENSORFUSION_API UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform();
// End Cross Module References
	void USensorFusionBPLibrary::StaticRegisterNativesUSensorFusionBPLibrary()
	{
		UClass* Class = USensorFusionBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BindRotation", &USensorFusionBPLibrary::execBindRotation },
			{ "Connect", &USensorFusionBPLibrary::execConnect },
			{ "Disconnect", &USensorFusionBPLibrary::execDisconnect },
			{ "GetRootSensorAccelerometer", &USensorFusionBPLibrary::execGetRootSensorAccelerometer },
			{ "GetRootSensorGyroscope", &USensorFusionBPLibrary::execGetRootSensorGyroscope },
			{ "GetRootSensorRotation", &USensorFusionBPLibrary::execGetRootSensorRotation },
			{ "GetRootSensorTransform", &USensorFusionBPLibrary::execGetRootSensorTransform },
			{ "GetSensorAccelerometer", &USensorFusionBPLibrary::execGetSensorAccelerometer },
			{ "GetSensorGyroscope", &USensorFusionBPLibrary::execGetSensorGyroscope },
			{ "GetSensorRotation", &USensorFusionBPLibrary::execGetSensorRotation },
			{ "GetSensorTransform", &USensorFusionBPLibrary::execGetSensorTransform },
			{ "IsConnected", &USensorFusionBPLibrary::execIsConnected },
			{ "IsRotationBinded", &USensorFusionBPLibrary::execIsRotationBinded },
			{ "PrintLog", &USensorFusionBPLibrary::execPrintLog },
			{ "SetRootSensorTransform", &USensorFusionBPLibrary::execSetRootSensorTransform },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics
	{
		struct SensorFusionBPLibrary_eventBindRotation_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SensorFusionBPLibrary_eventBindRotation_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SensorFusionBPLibrary_eventBindRotation_Parms), &Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "Comment", "/**\n\x09* RootSensor?? ???\xcf\xbf? Rotation?? Bind?\xd5\xb4\xcf\xb4?.\n\x09*/" },
		{ "DisplayName", "BindRotation" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "RootSensor?? ???\xcf\xbf? Rotation?? Bind?\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "BindRotation", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventBindRotation_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics
	{
		struct SensorFusionBPLibrary_eventConnect_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SensorFusionBPLibrary_eventConnect_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SensorFusionBPLibrary_eventConnect_Parms), &Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "Comment", "/**\n\x09* ???????? ?????? ?\xc3\xb5??\xd5\xb4\xcf\xb4?.\n\x09*/" },
		{ "DisplayName", "ConnectToSensor" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "???????? ?????? ?\xc3\xb5??\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "Connect", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventConnect_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_Connect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_Connect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_Disconnect_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_Disconnect_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "Comment", "/**\n\x09* ???????? ?????? ?????\xcf\xb4?.\n\x09*/" },
		{ "DisplayName", "DisconnectFromSensor" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "???????? ?????? ?????\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_Disconnect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "Disconnect", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_Disconnect_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_Disconnect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_Disconnect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_Disconnect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer_Statics
	{
		struct SensorFusionBPLibrary_eventGetRootSensorAccelerometer_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetRootSensorAccelerometer_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "DisplayName", "GetRootSensorAccelerometer" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "GetRootSensorAccelerometer", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventGetRootSensorAccelerometer_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope_Statics
	{
		struct SensorFusionBPLibrary_eventGetRootSensorGyroscope_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetRootSensorGyroscope_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "DisplayName", "GetRootSensorGyroscope" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "GetRootSensorGyroscope", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventGetRootSensorGyroscope_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics
	{
		struct SensorFusionBPLibrary_eventGetRootSensorRotation_Parms
		{
			bool bRawData;
			FQuat ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static void NewProp_bRawData_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRawData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetRootSensorRotation_Parms, ReturnValue), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::NewProp_bRawData_SetBit(void* Obj)
	{
		((SensorFusionBPLibrary_eventGetRootSensorRotation_Parms*)Obj)->bRawData = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::NewProp_bRawData = { "bRawData", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SensorFusionBPLibrary_eventGetRootSensorRotation_Parms), &Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::NewProp_bRawData_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::NewProp_bRawData,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "Comment", "/**\n\x09* RootSensor?? Rotation???? \xc8\xae???\xd5\xb4\xcf\xb4?.\n\x09*/" },
		{ "CPP_Default_bRawData", "false" },
		{ "DisplayName", "GetRootSensorRotation" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "RootSensor?? Rotation???? \xc8\xae???\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "GetRootSensorRotation", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventGetRootSensorRotation_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics
	{
		struct SensorFusionBPLibrary_eventGetRootSensorTransform_Parms
		{
			bool bRawData;
			FTransform ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static void NewProp_bRawData_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRawData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetRootSensorTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::NewProp_bRawData_SetBit(void* Obj)
	{
		((SensorFusionBPLibrary_eventGetRootSensorTransform_Parms*)Obj)->bRawData = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::NewProp_bRawData = { "bRawData", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SensorFusionBPLibrary_eventGetRootSensorTransform_Parms), &Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::NewProp_bRawData_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::NewProp_bRawData,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "Comment", "/**\n\x09* RootSensor?? Transform???? \xc8\xae???\xd5\xb4\xcf\xb4?.\n\x09*/" },
		{ "CPP_Default_bRawData", "false" },
		{ "DisplayName", "GetRootSensorTransform" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "RootSensor?? Transform???? \xc8\xae???\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "GetRootSensorTransform", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventGetRootSensorTransform_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics
	{
		struct SensorFusionBPLibrary_eventGetSensorAccelerometer_Parms
		{
			int32 idxSensor;
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_idxSensor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetSensorAccelerometer_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::NewProp_idxSensor = { "idxSensor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetSensorAccelerometer_Parms, idxSensor), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::NewProp_idxSensor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "DisplayName", "GetSensorAccelerometer" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "GetSensorAccelerometer", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventGetSensorAccelerometer_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics
	{
		struct SensorFusionBPLibrary_eventGetSensorGyroscope_Parms
		{
			int32 idxSensor;
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_idxSensor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetSensorGyroscope_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::NewProp_idxSensor = { "idxSensor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetSensorGyroscope_Parms, idxSensor), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::NewProp_idxSensor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "DisplayName", "GetSensorGyroscope" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "GetSensorGyroscope", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventGetSensorGyroscope_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics
	{
		struct SensorFusionBPLibrary_eventGetSensorRotation_Parms
		{
			int32 idxSensor;
			bool bRawData;
			FQuat ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static void NewProp_bRawData_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRawData;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_idxSensor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetSensorRotation_Parms, ReturnValue), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::NewProp_bRawData_SetBit(void* Obj)
	{
		((SensorFusionBPLibrary_eventGetSensorRotation_Parms*)Obj)->bRawData = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::NewProp_bRawData = { "bRawData", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SensorFusionBPLibrary_eventGetSensorRotation_Parms), &Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::NewProp_bRawData_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::NewProp_idxSensor = { "idxSensor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetSensorRotation_Parms, idxSensor), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::NewProp_bRawData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::NewProp_idxSensor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "Comment", "/**\n\x09* ?\xd6\xbe??? ?\xce\xb5????? ?\xd8\xb4??\xcf\xb4? ?????? Rotation??(???\xcd\xb4\xcf\xbe?)?? \xc8\xae???\xd5\xb4\xcf\xb4?.\n\x09*/" },
		{ "CPP_Default_bRawData", "false" },
		{ "DisplayName", "GetSensorRotation" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "?\xd6\xbe??? ?\xce\xb5????? ?\xd8\xb4??\xcf\xb4? ?????? Rotation??(???\xcd\xb4\xcf\xbe?)?? \xc8\xae???\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "GetSensorRotation", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventGetSensorRotation_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics
	{
		struct SensorFusionBPLibrary_eventGetSensorTransform_Parms
		{
			int32 idxSensor;
			bool bRawData;
			FTransform ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static void NewProp_bRawData_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRawData;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_idxSensor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetSensorTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::NewProp_bRawData_SetBit(void* Obj)
	{
		((SensorFusionBPLibrary_eventGetSensorTransform_Parms*)Obj)->bRawData = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::NewProp_bRawData = { "bRawData", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SensorFusionBPLibrary_eventGetSensorTransform_Parms), &Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::NewProp_bRawData_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::NewProp_idxSensor = { "idxSensor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventGetSensorTransform_Parms, idxSensor), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::NewProp_bRawData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::NewProp_idxSensor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "Comment", "/**\n\x09* ?\xd6\xbe??? ?\xce\xb5????? ?\xd8\xb4??\xcf\xb4? ?????? Transform???? \xc8\xae???\xd5\xb4\xcf\xb4?.\n\x09*/" },
		{ "CPP_Default_bRawData", "false" },
		{ "DisplayName", "GetSensorTransform" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "?\xd6\xbe??? ?\xce\xb5????? ?\xd8\xb4??\xcf\xb4? ?????? Transform???? \xc8\xae???\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "GetSensorTransform", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventGetSensorTransform_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics
	{
		struct SensorFusionBPLibrary_eventIsConnected_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SensorFusionBPLibrary_eventIsConnected_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SensorFusionBPLibrary_eventIsConnected_Parms), &Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "Comment", "/**\n\x09* ???????? ???\xe1\xbf\xa9?\xce\xb8? \xc8\xae???\xd5\xb4\xcf\xb4?.\n\x09*/" },
		{ "DisplayName", "IsSensorConnected" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "???????? ???\xe1\xbf\xa9?\xce\xb8? \xc8\xae???\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "IsConnected", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventIsConnected_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics
	{
		struct SensorFusionBPLibrary_eventIsRotationBinded_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SensorFusionBPLibrary_eventIsRotationBinded_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SensorFusionBPLibrary_eventIsRotationBinded_Parms), &Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "Comment", "/**\n\x09* RootSensor?? Rotation?? Bind ???\xce\xb8? \xc8\xae???\xd5\xb4\xcf\xb4?.\n\x09*/" },
		{ "DisplayName", "IsRotationBinded" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "RootSensor?? Rotation?? Bind ???\xce\xb8? \xc8\xae???\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "IsRotationBinded", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventIsRotationBinded_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_PrintLog_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_PrintLog_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "Comment", "/**\n\x09* Log?? ?????\xd5\xb4\xcf\xb4?.\n\x09*/" },
		{ "DisplayName", "PrintLog" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "Log?? ?????\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_PrintLog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "PrintLog", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_PrintLog_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_PrintLog_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_PrintLog()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_PrintLog_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform_Statics
	{
		struct SensorFusionBPLibrary_eventSetRootSensorTransform_Parms
		{
			FTransform rootTransform;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_rootTransform;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform_Statics::NewProp_rootTransform = { "rootTransform", nullptr, (EPropertyFlags)0x0010000008000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SensorFusionBPLibrary_eventSetRootSensorTransform_Parms, rootTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform_Statics::NewProp_rootTransform,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform_Statics::Function_MetaDataParams[] = {
		{ "Category", "SensorFusion" },
		{ "Comment", "/**\n\x09* RootSensor?? Transform???? ?????\xd5\xb4\xcf\xb4?.\n\x09*/" },
		{ "DisplayName", "SetRootSensorTransform" },
		{ "Keywords", "" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "RootSensor?? Transform???? ?????\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USensorFusionBPLibrary, nullptr, "SetRootSensorTransform", nullptr, nullptr, sizeof(SensorFusionBPLibrary_eventSetRootSensorTransform_Parms), Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USensorFusionBPLibrary_NoRegister()
	{
		return USensorFusionBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_USensorFusionBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USensorFusionBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_SensorFusion,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USensorFusionBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_BindRotation, "BindRotation" }, // 3881524119
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_Connect, "Connect" }, // 1177264974
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_Disconnect, "Disconnect" }, // 4213299977
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorAccelerometer, "GetRootSensorAccelerometer" }, // 162850840
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorGyroscope, "GetRootSensorGyroscope" }, // 2683414062
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorRotation, "GetRootSensorRotation" }, // 980092347
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_GetRootSensorTransform, "GetRootSensorTransform" }, // 2697522633
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorAccelerometer, "GetSensorAccelerometer" }, // 4126108598
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorGyroscope, "GetSensorGyroscope" }, // 2387053998
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorRotation, "GetSensorRotation" }, // 3585605979
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_GetSensorTransform, "GetSensorTransform" }, // 3204088491
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_IsConnected, "IsConnected" }, // 3987790644
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_IsRotationBinded, "IsRotationBinded" }, // 2501294541
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_PrintLog, "PrintLog" }, // 4205467876
		{ &Z_Construct_UFunction_USensorFusionBPLibrary_SetRootSensorTransform, "SetRootSensorTransform" }, // 3932146111
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USensorFusionBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/* \n*\x09""Function library class.\n*\x09""Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*\x09When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*\x09""BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*\x09""BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*\x09""DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*\x09\x09\x09\x09Its lets you name the node using characters not allowed in C++ function names.\n*\x09""CompactNodeTitle - the word(s) that appear on the node.\n*\x09Keywords -\x09the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. \n*\x09\x09\x09\x09Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*\x09""Category -\x09the category your node will be under in the Blueprint drop-down menu.\n*\n*\x09""For more info on custom blueprint nodes visit documentation:\n*\x09https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation\n*/" },
		{ "IncludePath", "SensorFusionBPLibrary.h" },
		{ "ModuleRelativePath", "Public/SensorFusionBPLibrary.h" },
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USensorFusionBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USensorFusionBPLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USensorFusionBPLibrary_Statics::ClassParams = {
		&USensorFusionBPLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USensorFusionBPLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_USensorFusionBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USensorFusionBPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USensorFusionBPLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USensorFusionBPLibrary, 4030724156);
	template<> SENSORFUSION_API UClass* StaticClass<USensorFusionBPLibrary>()
	{
		return USensorFusionBPLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USensorFusionBPLibrary(Z_Construct_UClass_USensorFusionBPLibrary, &USensorFusionBPLibrary::StaticClass, TEXT("/Script/SensorFusion"), TEXT("USensorFusionBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USensorFusionBPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
