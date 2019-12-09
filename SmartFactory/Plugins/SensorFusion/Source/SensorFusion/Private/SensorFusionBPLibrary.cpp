// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SensorFusionBPLibrary.h"
#include "SensorFusionEngine.h"

SensorFusionEngine g_sensorFusion;


USensorFusionBPLibrary::USensorFusionBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

//Connect
bool USensorFusionBPLibrary::Connect()
{
	UE_LOG(LogTemp, Warning, TEXT("++++++ USensorFusionBPLibrary::Connect()"));

	g_sensorFusion.Connect();

	return true;
}

void USensorFusionBPLibrary::Disconnect()
{
	UE_LOG(LogTemp, Warning, TEXT("++++++ USensorFusionBPLibrary::Disconnect()"));

	g_sensorFusion.Disconnect();

	return;
}

bool USensorFusionBPLibrary::IsConnected()
{
	return g_sensorFusion.IsConnected();
}

void USensorFusionBPLibrary::SetRootSensorTransform(UPARAM(ref) FTransform& rootTransform)
{
	g_sensorFusion.SetRootSensorTransform(rootTransform);

	return;
}

FTransform USensorFusionBPLibrary::GetRootSensorTransform(bool bRawData)
{
	FTransform tf;

	g_sensorFusion.GetRootSensorTransform(tf, bRawData);

	return tf;
}

FQuat USensorFusionBPLibrary::GetRootSensorRotation(bool bRawData)
{
	FTransform tf;

	g_sensorFusion.GetRootSensorTransform(tf, bRawData);
	FQuat quatRot = tf.GetRotation();

#if 1 // for Debug
	char buffer[1024];
	sprintf(buffer, "index[Root] quatRot[%.2f, %.2f, %.2f, %.2f]\0",
		quatRot.X, quatRot.Y, quatRot.Z, quatRot.W);
	int len = strlen(buffer);
	wchar_t* t = new wchar_t[len + 1];
	mbstowcs(t, buffer, len);
	t[len] = 0x00;
	UE_LOG(LogSensorFusion, Warning, TEXT("Quat Rotation : %s"), t);
	delete t;
#endif

	return quatRot;
}


FTransform USensorFusionBPLibrary::GetSensorTransform(int idxSensor, bool bRawData)
{
	FTransform tf;

	g_sensorFusion.GetSensorTransform(idxSensor, tf, bRawData);

	return tf;
}

FQuat USensorFusionBPLibrary::GetSensorRotation(int idxSensor, bool bRawData)
{
	FTransform tf;

	g_sensorFusion.GetSensorTransform(idxSensor, tf, bRawData);
	FQuat quatRot = tf.GetRotation();

#if 1 // for Debug
	char buffer[1024];
	sprintf(buffer, "index[%d] quatRot[%.2f, %.2f, %.2f, %.2f]\0",
		idxSensor, quatRot.X, quatRot.Y, quatRot.Z, quatRot.W);
	int len = strlen(buffer);
	wchar_t* t = new wchar_t[len + 1];
	mbstowcs(t, buffer, len);
	t[len] = 0x00;
	UE_LOG(LogSensorFusion, Warning, TEXT("Quat Rotation : %s"), t);
	delete t;
#endif

	return quatRot;
}


bool USensorFusionBPLibrary::BindRotation()
{
	return g_sensorFusion.BindRotation();
}

bool USensorFusionBPLibrary::IsRotationBinded()
{
	return g_sensorFusion.IsRotationBinded();
}

void USensorFusionBPLibrary::PrintLog()
{
	UE_LOG(LogSensorFusion, Warning, TEXT("이 플러그인은, 한국산업기술대 게임공학과 이택희 교수님 연구팀에서 제작하였습니다."));
}

FVector USensorFusionBPLibrary::GetSensorAccelerometer(int idxSensor)
{
	FVector vec;

	g_sensorFusion.GetSensorAccelerometer(idxSensor, vec);

	return vec;
}

FVector USensorFusionBPLibrary::GetSensorGyroscope(int idxSensor)
{
	FVector vec;

	g_sensorFusion.GetSensorGyroscope(idxSensor, vec);

	return vec;
}

FVector USensorFusionBPLibrary::GetRootSensorAccelerometer()
{
	FVector vec;

	g_sensorFusion.GetRootSensorAccelerometer(vec);

	return vec;
}

FVector USensorFusionBPLibrary::GetRootSensorGyroscope()
{
	FVector vec;

	g_sensorFusion.GetRootSensorGyroscope(vec);

	return vec;
}