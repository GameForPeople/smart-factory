// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sensor.h"
#include "SensorData.h"
#include <string>
#include <vector>
#include <map>

// SensorFusion General Log
DECLARE_LOG_CATEGORY_EXTERN(LogSensorFusion, Log, All);

/**
 * @class SensorFusionEngine
 *
 */
class SENSORFUSION_API SensorFusionEngine
{
public:
	SensorFusionEngine();
	~SensorFusionEngine();

	bool Connect();
	void Disconnect();
	bool IsConnected();
	void SetRootSensorTransform(FTransform &rootTransform);
	bool GetRootSensorTransform(FTransform &targetTransform, bool bRawData=false);
	bool GetSensorTransform(int sensorIdx, FTransform& targetTransform, bool bRawData=false);
	bool BindRotation();
	bool IsRotationBinded();

	bool GetRootSensorAccelerometer(FVector & targetVector);
	bool GetRootSensorGyroscope(FVector & targetVector);

	bool GetSensorAccelerometer(int sensorIdx, FVector& targetVector);
	bool GetSensorGyroscope(int sensorIdx, FVector& targetVector);

	static DWORD ReadThread(LPVOID lpParameter);
private:
	bool LoadSettings();
	int ReadData();
	void CloseConnection();
//	void Update();
	bool SensorData2FTransform(SensorData *pData, FTransform& targetTransform, bool bRoot=false, bool bRawData=false);
	bool SensorData2AccelerometerVector(SensorData *pData, FVector& targetVector, bool bRoot = false);
	bool SensorData2GyroscopeVector(SensorData *pData, FVector& targetVector, bool bRoot = false);


	std::string TCHAR2String(const TCHAR *src);
	HANDLE m_hThread;

	int	m_sensorCnt;
	FString m_comPort;
	SensorData m_rootData;
	vector<SensorData *> m_sensorData;
#ifdef SENSOR_FILE
	int m_sleepTime;
#endif
public:
	Sensor m_serialPort;//
};
