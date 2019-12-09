// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SensorFusion/Public/SensorFusionSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSensorFusionSettings() {}
// Cross Module References
	SENSORFUSION_API UScriptStruct* Z_Construct_UScriptStruct_FSensorData();
	UPackage* Z_Construct_UPackage__Script_SensorFusion();
	SENSORFUSION_API UClass* Z_Construct_UClass_USensorFusionSettings_NoRegister();
	SENSORFUSION_API UClass* Z_Construct_UClass_USensorFusionSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
class UScriptStruct* FSensorData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SENSORFUSION_API uint32 Get_Z_Construct_UScriptStruct_FSensorData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSensorData, Z_Construct_UPackage__Script_SensorFusion(), TEXT("SensorData"), sizeof(FSensorData), Get_Z_Construct_UScriptStruct_FSensorData_Hash());
	}
	return Singleton;
}
template<> SENSORFUSION_API UScriptStruct* StaticStruct<FSensorData>()
{
	return FSensorData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSensorData(FSensorData::StaticStruct, TEXT("/Script/SensorFusion"), TEXT("SensorData"), false, nullptr, nullptr);
static struct FScriptStruct_SensorFusion_StaticRegisterNativesFSensorData
{
	FScriptStruct_SensorFusion_StaticRegisterNativesFSensorData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("SensorData")),new UScriptStruct::TCppStructOps<FSensorData>);
	}
} ScriptStruct_SensorFusion_StaticRegisterNativesFSensorData;
	struct Z_Construct_UScriptStruct_FSensorData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParentSensorIdx_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ParentSensorIdx;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SensorID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SensorID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSensorData_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "ModuleRelativePath", "Public/SensorFusionSettings.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSensorData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSensorData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSensorData_Statics::NewProp_ParentSensorIdx_MetaData[] = {
		{ "Category", "Custom" },
		{ "ModuleRelativePath", "Public/SensorFusionSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSensorData_Statics::NewProp_ParentSensorIdx = { "ParentSensorIdx", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSensorData, ParentSensorIdx), METADATA_PARAMS(Z_Construct_UScriptStruct_FSensorData_Statics::NewProp_ParentSensorIdx_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FSensorData_Statics::NewProp_ParentSensorIdx_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSensorData_Statics::NewProp_SensorID_MetaData[] = {
		{ "Category", "Custom" },
		{ "ModuleRelativePath", "Public/SensorFusionSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSensorData_Statics::NewProp_SensorID = { "SensorID", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSensorData, SensorID), METADATA_PARAMS(Z_Construct_UScriptStruct_FSensorData_Statics::NewProp_SensorID_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FSensorData_Statics::NewProp_SensorID_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSensorData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSensorData_Statics::NewProp_ParentSensorIdx,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSensorData_Statics::NewProp_SensorID,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSensorData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SensorFusion,
		nullptr,
		&NewStructOps,
		"SensorData",
		sizeof(FSensorData),
		alignof(FSensorData),
		Z_Construct_UScriptStruct_FSensorData_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FSensorData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSensorData_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FSensorData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSensorData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSensorData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SensorFusion();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SensorData"), sizeof(FSensorData), Get_Z_Construct_UScriptStruct_FSensorData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSensorData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSensorData_Hash() { return 501439253U; }
	void USensorFusionSettings::StaticRegisterNativesUSensorFusionSettings()
	{
	}
	UClass* Z_Construct_UClass_USensorFusionSettings_NoRegister()
	{
		return USensorFusionSettings::StaticClass();
	}
	struct Z_Construct_UClass_USensorFusionSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SleepTimeForFile_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_SleepTimeForFile;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sensors_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Sensors;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Sensors_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReferenceSensorID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReferenceSensorID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ComPort_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ComPort;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USensorFusionSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SensorFusion,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USensorFusionSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SensorFusionSettings.h" },
		{ "ModuleRelativePath", "Public/SensorFusionSettings.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_SleepTimeForFile_MetaData[] = {
		{ "Category", "Custom" },
		{ "ModuleRelativePath", "Public/SensorFusionSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_SleepTimeForFile = { "SleepTimeForFile", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USensorFusionSettings, SleepTimeForFile), METADATA_PARAMS(Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_SleepTimeForFile_MetaData, ARRAY_COUNT(Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_SleepTimeForFile_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_Sensors_MetaData[] = {
		{ "Category", "Custom" },
		{ "ModuleRelativePath", "Public/SensorFusionSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_Sensors = { "Sensors", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USensorFusionSettings, Sensors), METADATA_PARAMS(Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_Sensors_MetaData, ARRAY_COUNT(Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_Sensors_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_Sensors_Inner = { "Sensors", nullptr, (EPropertyFlags)0x0000000000004000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSensorData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_ReferenceSensorID_MetaData[] = {
		{ "Category", "Custom" },
		{ "ModuleRelativePath", "Public/SensorFusionSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_ReferenceSensorID = { "ReferenceSensorID", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USensorFusionSettings, ReferenceSensorID), METADATA_PARAMS(Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_ReferenceSensorID_MetaData, ARRAY_COUNT(Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_ReferenceSensorID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_ComPort_MetaData[] = {
		{ "Category", "Custom" },
		{ "ModuleRelativePath", "Public/SensorFusionSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_ComPort = { "ComPort", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USensorFusionSettings, ComPort), METADATA_PARAMS(Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_ComPort_MetaData, ARRAY_COUNT(Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_ComPort_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USensorFusionSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_SleepTimeForFile,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_Sensors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_Sensors_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_ReferenceSensorID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USensorFusionSettings_Statics::NewProp_ComPort,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USensorFusionSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USensorFusionSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USensorFusionSettings_Statics::ClassParams = {
		&USensorFusionSettings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USensorFusionSettings_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_USensorFusionSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_USensorFusionSettings_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_USensorFusionSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USensorFusionSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USensorFusionSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USensorFusionSettings, 3144329985);
	template<> SENSORFUSION_API UClass* StaticClass<USensorFusionSettings>()
	{
		return USensorFusionSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USensorFusionSettings(Z_Construct_UClass_USensorFusionSettings, &USensorFusionSettings::StaticClass, TEXT("/Script/SensorFusion"), TEXT("USensorFusionSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USensorFusionSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
