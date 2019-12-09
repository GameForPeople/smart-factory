// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
struct FQuat;
struct FTransform;
#ifdef SENSORFUSION_SensorFusionBPLibrary_generated_h
#error "SensorFusionBPLibrary.generated.h already included, missing '#pragma once' in SensorFusionBPLibrary.h"
#endif
#define SENSORFUSION_SensorFusionBPLibrary_generated_h

#define SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetRootSensorGyroscope) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=USensorFusionBPLibrary::GetRootSensorGyroscope(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRootSensorAccelerometer) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=USensorFusionBPLibrary::GetRootSensorAccelerometer(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSensorGyroscope) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_idxSensor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=USensorFusionBPLibrary::GetSensorGyroscope(Z_Param_idxSensor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSensorAccelerometer) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_idxSensor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=USensorFusionBPLibrary::GetSensorAccelerometer(Z_Param_idxSensor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPrintLog) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USensorFusionBPLibrary::PrintLog(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsRotationBinded) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USensorFusionBPLibrary::IsRotationBinded(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBindRotation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USensorFusionBPLibrary::BindRotation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSensorRotation) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_idxSensor); \
		P_GET_UBOOL(Z_Param_bRawData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FQuat*)Z_Param__Result=USensorFusionBPLibrary::GetSensorRotation(Z_Param_idxSensor,Z_Param_bRawData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSensorTransform) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_idxSensor); \
		P_GET_UBOOL(Z_Param_bRawData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FTransform*)Z_Param__Result=USensorFusionBPLibrary::GetSensorTransform(Z_Param_idxSensor,Z_Param_bRawData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRootSensorRotation) \
	{ \
		P_GET_UBOOL(Z_Param_bRawData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FQuat*)Z_Param__Result=USensorFusionBPLibrary::GetRootSensorRotation(Z_Param_bRawData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRootSensorTransform) \
	{ \
		P_GET_UBOOL(Z_Param_bRawData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FTransform*)Z_Param__Result=USensorFusionBPLibrary::GetRootSensorTransform(Z_Param_bRawData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRootSensorTransform) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_rootTransform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USensorFusionBPLibrary::SetRootSensorTransform(Z_Param_Out_rootTransform); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsConnected) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USensorFusionBPLibrary::IsConnected(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisconnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USensorFusionBPLibrary::Disconnect(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USensorFusionBPLibrary::Connect(); \
		P_NATIVE_END; \
	}


#define SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetRootSensorGyroscope) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=USensorFusionBPLibrary::GetRootSensorGyroscope(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRootSensorAccelerometer) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=USensorFusionBPLibrary::GetRootSensorAccelerometer(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSensorGyroscope) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_idxSensor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=USensorFusionBPLibrary::GetSensorGyroscope(Z_Param_idxSensor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSensorAccelerometer) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_idxSensor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=USensorFusionBPLibrary::GetSensorAccelerometer(Z_Param_idxSensor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPrintLog) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USensorFusionBPLibrary::PrintLog(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsRotationBinded) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USensorFusionBPLibrary::IsRotationBinded(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBindRotation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USensorFusionBPLibrary::BindRotation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSensorRotation) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_idxSensor); \
		P_GET_UBOOL(Z_Param_bRawData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FQuat*)Z_Param__Result=USensorFusionBPLibrary::GetSensorRotation(Z_Param_idxSensor,Z_Param_bRawData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSensorTransform) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_idxSensor); \
		P_GET_UBOOL(Z_Param_bRawData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FTransform*)Z_Param__Result=USensorFusionBPLibrary::GetSensorTransform(Z_Param_idxSensor,Z_Param_bRawData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRootSensorRotation) \
	{ \
		P_GET_UBOOL(Z_Param_bRawData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FQuat*)Z_Param__Result=USensorFusionBPLibrary::GetRootSensorRotation(Z_Param_bRawData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRootSensorTransform) \
	{ \
		P_GET_UBOOL(Z_Param_bRawData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FTransform*)Z_Param__Result=USensorFusionBPLibrary::GetRootSensorTransform(Z_Param_bRawData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRootSensorTransform) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_rootTransform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USensorFusionBPLibrary::SetRootSensorTransform(Z_Param_Out_rootTransform); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsConnected) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USensorFusionBPLibrary::IsConnected(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisconnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USensorFusionBPLibrary::Disconnect(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USensorFusionBPLibrary::Connect(); \
		P_NATIVE_END; \
	}


#define SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSensorFusionBPLibrary(); \
	friend struct Z_Construct_UClass_USensorFusionBPLibrary_Statics; \
public: \
	DECLARE_CLASS(USensorFusionBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SensorFusion"), NO_API) \
	DECLARE_SERIALIZER(USensorFusionBPLibrary)


#define SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_INCLASS \
private: \
	static void StaticRegisterNativesUSensorFusionBPLibrary(); \
	friend struct Z_Construct_UClass_USensorFusionBPLibrary_Statics; \
public: \
	DECLARE_CLASS(USensorFusionBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SensorFusion"), NO_API) \
	DECLARE_SERIALIZER(USensorFusionBPLibrary)


#define SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USensorFusionBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USensorFusionBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USensorFusionBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USensorFusionBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USensorFusionBPLibrary(USensorFusionBPLibrary&&); \
	NO_API USensorFusionBPLibrary(const USensorFusionBPLibrary&); \
public:


#define SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USensorFusionBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USensorFusionBPLibrary(USensorFusionBPLibrary&&); \
	NO_API USensorFusionBPLibrary(const USensorFusionBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USensorFusionBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USensorFusionBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USensorFusionBPLibrary)


#define SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_PRIVATE_PROPERTY_OFFSET
#define SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_26_PROLOG
#define SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_PRIVATE_PROPERTY_OFFSET \
	SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_RPC_WRAPPERS \
	SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_INCLASS \
	SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_PRIVATE_PROPERTY_OFFSET \
	SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_INCLASS_NO_PURE_DECLS \
	SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h_29_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SensorFusionBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SENSORFUSION_API UClass* StaticClass<class USensorFusionBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SmartFactory_Plugins_SensorFusion_Source_SensorFusion_Public_SensorFusionBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
