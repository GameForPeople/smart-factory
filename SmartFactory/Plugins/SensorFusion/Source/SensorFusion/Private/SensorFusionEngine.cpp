// Fill out your copyright notice in the Description page of Project Settings.

#include "SensorFusionEngine.h"
#include "Sensor.h"
#include "Paths.h"
#include "SensorFusionSettings.h"

//#include "Dependencies/glew.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/euler_angles.hpp"

// SensorFusion General Log
DEFINE_LOG_CATEGORY(LogSensorFusion);

SensorFusionEngine::SensorFusionEngine()
{
	m_hThread = INVALID_HANDLE_VALUE;
	m_sensorCnt = 0;
}

SensorFusionEngine::~SensorFusionEngine()
{
	Disconnect();
}

bool SensorFusionEngine::Connect()
{
	UE_LOG(LogSensorFusion, Display, TEXT("Connecting..."));

	// DefaultGame.ini 로 부터 설정 값을 읽어 온다.
	if (!LoadSettings()) {
		return false;
	}

	// 센서 수신기의 COM 포트를 연다.
	if (m_serialPort.OpenPort(*m_comPort)) {
		UE_LOG(LogSensorFusion, Display, TEXT("Port is opened. (%s)"), *m_comPort);

		m_serialPort.ConfigurePort(CBR_115200, 8, FALSE, NOPARITY, ONESTOPBIT);
		m_serialPort.SetCommunicationTimeouts(100, 100, 1000, 0, 0);
#ifdef SENSOR_FILE
		m_serialPort.SetSleepTime(m_sleepTime);
#endif
	}
	else {
		UE_LOG(LogSensorFusion, Error, TEXT("Failed to open port (%s)"), *m_comPort);
		return false;
	}

	// 센서 수신기로 부터 센서 값을 읽어오는 thread 를 생성한다.
	m_hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ReadThread, this, 0, NULL);

#ifdef SENSOR_FILE
	FString strPortFile("FILE");
	if ( !m_comPort.Compare(strPortFile)) {
		Sleep(100);
	}

#endif
	UE_LOG(LogSensorFusion, Display, TEXT("Connected"));

	return true;
}

bool SensorFusionEngine::LoadSettings()
{
	// 이미 Setting 값을 Load 함.
	if (m_sensorData.size() > 0)
		return true;

	USensorFusionSettings* Settings = GetMutableDefault<USensorFusionSettings>();

	if (!Settings)
		return false;

	UE_LOG(LogSensorFusion, Display, TEXT("COM Port (%s)"), *(Settings->ComPort));
	m_comPort = Settings->ComPort;

	UE_LOG(LogSensorFusion, Display, TEXT("Reference Sensor ID (%s)"), *(Settings->ReferenceSensorID));
	m_rootData.sensor_id = TCHAR2String(*(Settings->ReferenceSensorID));

#if 0
	UE_LOG(LogSensorFusion, Display, TEXT("SensorData Count (%d)"), Settings->SensorCount);
	m_sensorCnt = Settings->SensorCount;

	if (m_sensorCnt > Settings->SensorIDList.Num())
		m_sensorCnt = Settings->SensorIDList.Num();

	FString strSensorID;
	for (int i = 0; i < m_sensorCnt; i++)
	{
		strSensorID = Settings->SensorIDList[i];
		UE_LOG(LogSensorFusion, Display, TEXT("SensorData id (%s)"), *strSensorID);
		string filterId = TCHAR2String(*strSensorID);
		SensorData *pData = new SensorData(filderId);
		m_sensorData.push_back(pData);
	}
#else
	m_sensorCnt = Settings->Sensors.Num();
	FString strSensorID;
	for (int i = 0; i < m_sensorCnt; i++)
	{
		strSensorID = Settings->Sensors[i].SensorID;
		UE_LOG(LogSensorFusion, Display, TEXT("Sensor id (%s)"), *strSensorID);
		string filterId = TCHAR2String(*strSensorID);
		SensorData *pData = new SensorData(filterId);
		m_sensorData.push_back(pData);
	}
#endif

	
#ifdef SENSOR_FILE
	m_sleepTime = Settings->SleepTimeForFile;
	UE_LOG(LogSensorFusion, Display, TEXT("SleepTime (%d)msec"), m_sleepTime);
#endif

	return true;
}

void SensorFusionEngine::CloseConnection()
{
	UE_LOG(LogSensorFusion, Warning, TEXT("+++ CloseConnection"));

	if (m_hThread != INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_hThread);
		m_hThread = INVALID_HANDLE_VALUE;
	}

	m_serialPort.ClosePort();
}

void SensorFusionEngine::Disconnect()
{
	UE_LOG(LogSensorFusion, Warning, TEXT("+++ Disconnected"));

	// Close thread and port
	CloseConnection();

	// Release sensor data
	for (int i = 0; i < m_sensorData.size(); i++)
	{
		SensorData *pData = m_sensorData.at(i);
		if (pData != NULL)
		{
			delete pData;
			pData = NULL;
		}
	}
	m_sensorData.clear();
	m_sensorCnt = 0;
}

bool SensorFusionEngine::IsConnected()
{
	return m_serialPort.IsPortOpened();
}

bool SensorFusionEngine::BindRotation()
{
	UE_LOG(LogSensorFusion, Warning, TEXT("BindRotation"));

	SensorData *pData = NULL;
	bool bRet = true;

	if (!IsConnected()) {
		UE_LOG(LogSensorFusion, Error, TEXT("Disconnected.."));
		return false;
	}

	if (!m_rootData.SetBindingAngle()) {
		UE_LOG(LogSensorFusion, Error, TEXT("Bind root sensor.."));
		bRet = false;
	}
#if 1 //for debug
	else
	{
		char buffer[1024];
		sprintf(buffer, "id[%s] euler[%.2f, %.2f, %.2f]\0",
			m_rootData.sensor_id.c_str(), m_rootData.euler_x, m_rootData.euler_y, m_rootData.euler_z);
		int len = strlen(buffer);
		wchar_t* t = new wchar_t[len + 1];
		mbstowcs(t, buffer, len);
		t[len] = 0x00;
		UE_LOG(LogSensorFusion, Warning, TEXT("binding rotation : %s"), t);
		delete t;
	}
#endif


	for (int i = 0; i < m_sensorData.size(); i++)
	{
		pData = m_sensorData.at(i);
		if (pData != NULL) {
			if (!pData->SetBindingAngle()) {
				UE_LOG(LogSensorFusion, Error, TEXT("Bind sensor(%s)"), ANSI_TO_TCHAR(pData->sensor_id.c_str()));
				bRet = false;
			}
#if 1 //for debug
			else
			{
				char buffer[1024];
				sprintf(buffer, "id[%s] euler[%.2f, %.2f, %.2f]\0",
					pData->sensor_id.c_str(), pData->euler_x, pData->euler_y, pData->euler_z);
				int len = strlen(buffer);
				wchar_t* t = new wchar_t[len + 1];
				mbstowcs(t, buffer, len);
				t[len] = 0x00;
				UE_LOG(LogSensorFusion, Warning, TEXT("binding rotation : %s"), t);
				delete t;
			}
#endif
		}
	}

	if (bRet) {
		UE_LOG(LogSensorFusion, Warning, TEXT("Success to bind sensor"));
	}

	return bRet;
}

bool SensorFusionEngine::IsRotationBinded()
{
	SensorData *pData = NULL;
	bool bRet = true;

	if (!IsConnected())
		return false;

	if (!m_rootData.IsBinded())
		bRet = false;

	for (int i = 0; i < m_sensorData.size(); i++)
	{
		pData = m_sensorData.at(i);
		if (pData != NULL) {
			if (!pData->IsBinded()) {
				bRet = false;
			}
		}
	}

	if (bRet) {
		UE_LOG(LogSensorFusion, Warning, TEXT("IsRotationBinded (true)"));
	}
	else {
		UE_LOG(LogSensorFusion, Error, TEXT("IsRotationBinded (false"));
	}

	return bRet;
}

DWORD SensorFusionEngine::ReadThread(LPVOID lpParameter)
{
	SensorFusionEngine *pClass = (SensorFusionEngine*)lpParameter;

	while (1) {
		if (!pClass->ReadData()) {
			break;
		}
	}

	return 0;
}

int SensorFusionEngine::ReadData()
{
	bool bRoot = false;
	string string_buffer;
	string_buffer.clear();

	// 이 함수를 통해서 파라미터로 들어온 string_buffer에 저장합니다.
	if (!m_serialPort.ReadByteStr(string_buffer))
	{
		UE_LOG(LogSensorFusion, Error, TEXT("Fail to read data."));
		CloseConnection();
		return 0;
	}

	UE_LOG(LogSensorFusion, Display, TEXT("Read data: %s"), ANSI_TO_TCHAR(string_buffer.c_str()));

	// 파싱 함수를 통해 출력값을 파싱한다. 
	m_serialPort.Parsing(string_buffer);

	SensorData *pData = NULL;
	if (m_serialPort.parsedata.str_id == m_rootData.sensor_id)
	{
		pData = &m_rootData;
		bRoot = true;
	} else {
		for (int i = 0; i < m_sensorData.size(); i++)
		{
			pData = m_sensorData.at(i);
			if (m_serialPort.parsedata.str_id == pData->sensor_id)
			{
				break;
			}
			pData = NULL;
		}
	}

	if (pData != NULL)
	{
		pData->SetSensorValue(m_serialPort.parsedata);

#if 0  // BindRotation 적용 시 필요 없음.
		if (bRoot) {
			Update();
		}
		else {
			pData->Update(glm::vec3(m_rootData.euler_x, m_rootData.euler_y, m_rootData.euler_z));
		}
#endif
		return 1;
	}

	UE_LOG(LogSensorFusion, Error, TEXT("No matching sonsor id (%s)"), ANSI_TO_TCHAR(m_serialPort.parsedata.str_id.c_str()));

	return 1;
}

#if 0
void SensorFusionEngine::Update()
{
	int i = 0;
	SensorData *pData = NULL;

	m_rootData.Update(glm::vec3(0.f, 0.f, 0.f));
	for (i = 0; i < m_sensorData.size(); i++)
	{
		pData = m_sensorData.at(i);
		if (pData != NULL) {
			pData->Update(glm::vec3(m_rootData.euler_x, m_rootData.euler_y, m_rootData.euler_z));
		}
	}
}
#endif

void SensorFusionEngine::SetRootSensorTransform(FTransform &rootTransform)
{
	int i = 0;
	SensorData *pData = NULL;
	FVector loc = rootTransform.GetLocation();
	FQuat rot = rootTransform.GetRotation();
	FVector vecRot = rot.Euler();

	UE_LOG(LogSensorFusion, Warning, TEXT("SetRootTransform pos(%.2f, %.2f, %.2f) rot(%.2f, %.2f, %.2f)"),
		loc.X, loc.Y, loc.Z, vecRot.X, vecRot.Y, vecRot.Z);

	for (i = 0; i < m_sensorData.size(); i++)
	{
		pData = m_sensorData.at(i);
		if (pData != NULL) {
			//pData->SetBindPosition(glm::vec3(loc.X, loc.Y, loc.Z));
			//pData->SetBindAvgAngel(glm::vec3(vecRot.X, vecRot.Y, vecRot.Z));
		}
	}
}



bool SensorFusionEngine::GetRootSensorTransform(FTransform& targetTransform, bool bRawData)
{
	bool ret = false;

	if (!IsConnected())
	{
		UE_LOG(LogSensorFusion, Error, TEXT("Port(%s) is not opened."), *m_comPort);
		return false;
	}

	SensorData *pData = &m_rootData;

#if 1 //for debug
	{
		char buffer[1024];
		sprintf(buffer, "id[%s] euler[%.2f, %.2f, %.2f] gyro[%.2f, %.2f, %.2f] acc[%.2f, %.2f, %.2f] battery[%d]\0",
			pData->sensor_id.c_str(), pData->euler_x, pData->euler_y, pData->euler_z,
			pData->gyro_x, pData->gyro_y, pData->gyro_z,
			pData->acc_x, pData->acc_y, pData->acc_z, pData->battery);
		int len = strlen(buffer);
		wchar_t* t = new wchar_t[len + 1];
		mbstowcs(t, buffer, len);
		t[len] = 0x00;
		UE_LOG(LogSensorFusion, Warning, TEXT("+++ data : %s"), t);
		delete t;
	}
#endif

	ret = SensorData2FTransform(pData, targetTransform, true, bRawData);

	return ret;
}


bool SensorFusionEngine::GetSensorTransform(int sensorIdx, FTransform& targetTransform, bool bRawData)
{
	bool ret = false;

	// check the validation of input parameters
	if (sensorIdx < 0 || sensorIdx >= m_sensorData.size())
	{
		UE_LOG(LogSensorFusion, Warning, TEXT("Invalid sensor no (%d)"), sensorIdx);
		return false;
	}

	if (!IsConnected())
	{
		UE_LOG(LogSensorFusion, Error, TEXT("Port(%s) is not opened."), *m_comPort);
		return false;
	}

	SensorData *pData = m_sensorData.at(sensorIdx);
	if (pData == NULL)
	{
		return false;
	}

#if 0 //for debug
	{
		char buffer[1024];
		sprintf(buffer, "id[%s] euler[%.2f, %.2f, %.2f] gyro[%.2f, %.2f, %.2f] acc[%.2f, %.2f, %.2f] battery[%d]\0",
			pData->sensor_id.c_str(), pData->euler_x, pData->euler_y, pData->euler_z,
			pData->gyro_x, pData->gyro_y, pData->gyro_z,
			pData->acc_x, pData->acc_y, pData->acc_z, pData->battery);
		int len = strlen(buffer);
		wchar_t* t = new wchar_t[len + 1];
		mbstowcs(t, buffer, len);
		t[len] = 0x00;
		UE_LOG(LogSensorFusion, Display, TEXT("+++ data : %s"), t);
		delete t;
	}
#endif

	ret = SensorData2FTransform(pData, targetTransform, false, bRawData);

	return ret;
}

bool SensorFusionEngine::SensorData2FTransform(SensorData *pData, FTransform& targetTransform, bool bRoot, bool bRawData)
{
	if (pData == NULL) 
		return false;

	glm::vec3 vecRot = { 0.f, 0.f, 0.f };
#if 0
	if (bRoot)
		vecRot = pData->GetMyOriginalRotaion();
	else
		vecRot = pData->GetDiffAngle();
#else  // BindRotation 적용
	if (bRawData)
		vecRot = pData->GetMyOriginalRotaion();
	else
		vecRot = pData->GetAngle();
#endif
	FRotator rot = FRotator(vecRot.y, vecRot.z, vecRot.x);
	FQuat quatRot(rot);
	targetTransform.SetRotation(quatRot);

#if 1 // for debug
	{
		FQuat rot = targetTransform.GetRotation();
		FVector tmpRot = rot.Euler();

		char buffer[1024];
		sprintf(buffer, "id[%s] eulerRot[%2.f, %.2f, %.2f]  quatRot[%.2f, %.2f, %.2f, %.2f]\0",
			pData->sensor_id.c_str(), tmpRot.X, tmpRot.Y, tmpRot.Z, rot.X, rot.Y, rot.Z, rot.W);
		int len = strlen(buffer);
		wchar_t* t = new wchar_t[len + 1];
		mbstowcs(t, buffer, len);
		t[len] = 0x00;
		UE_LOG(LogSensorFusion, Warning, TEXT("+++ rotation : %s"), t);
		delete t;

	}
#endif

	FVector scale;
	scale.X = 1.0f;
	scale.Y = 1.0f;
	scale.Z = 1.0f;
	targetTransform.SetScale3D(scale);

	return true;
}

std::string SensorFusionEngine::TCHAR2String(const TCHAR *src)
{
#ifdef _UNICODE
	int len = wcslen(src);
	char* _ch = new char[len * 2 + 1];
	wcstombs(_ch, (wchar_t*)src, 2 * len + 1);	
	std::string _str = _ch;
	delete _ch;

#else
	string _str = (char*)src;
#endif
	return _str;
}


bool SensorFusionEngine::GetRootSensorAccelerometer(FVector & targetVector)
{
	bool ret = false;

	if (!IsConnected())
	{
		UE_LOG(LogSensorFusion, Error, TEXT("Port(%s) is not opened."), *m_comPort);
		return false;
	}

	SensorData *pData = &m_rootData;
	if (pData == NULL)
	{
		return false;
	}

#if 1 //for debug
	{
		char buffer[1024];
		sprintf(buffer, "id[%s] euler[%.2f, %.2f, %.2f] gyro[%.2f, %.2f, %.2f] acc[%.2f, %.2f, %.2f] battery[%d]\0",
			pData->sensor_id.c_str(), pData->euler_x, pData->euler_y, pData->euler_z,
			pData->gyro_x, pData->gyro_y, pData->gyro_z,
			pData->acc_x, pData->acc_y, pData->acc_z, pData->battery);
		int len = strlen(buffer);
		wchar_t* t = new wchar_t[len + 1];
		mbstowcs(t, buffer, len);
		t[len] = 0x00;
		UE_LOG(LogSensorFusion, Warning, TEXT("+++ data : %s"), t);
		delete t;
	}
#endif

	ret = SensorData2AccelerometerVector(pData, targetVector, true);

	return ret;
}

bool SensorFusionEngine::GetRootSensorGyroscope(FVector & targetVector)
{
	bool ret = false;

	if (!IsConnected())
	{
		UE_LOG(LogSensorFusion, Error, TEXT("Port(%s) is not opened."), *m_comPort);
		return false;
	}

	SensorData *pData = &m_rootData;
	if (pData == NULL)
	{
		return false;
	}

#if 1 //for debug
	{
		char buffer[1024];
		sprintf(buffer, "id[%s] euler[%.2f, %.2f, %.2f] gyro[%.2f, %.2f, %.2f] acc[%.2f, %.2f, %.2f] battery[%d]\0",
			pData->sensor_id.c_str(), pData->euler_x, pData->euler_y, pData->euler_z,
			pData->gyro_x, pData->gyro_y, pData->gyro_z,
			pData->acc_x, pData->acc_y, pData->acc_z, pData->battery);
		int len = strlen(buffer);
		wchar_t* t = new wchar_t[len + 1];
		mbstowcs(t, buffer, len);
		t[len] = 0x00;
		UE_LOG(LogSensorFusion, Warning, TEXT("+++ data : %s"), t);
		delete t;
	}
#endif

	ret = SensorData2GyroscopeVector(pData, targetVector, true);

	return ret;
}


bool SensorFusionEngine::GetSensorAccelerometer(int sensorIdx, FVector & targetVector)
{
	bool ret = false;

	// check the validation of input parameters
	if (sensorIdx < 0 || sensorIdx >= m_sensorData.size())
	{
		UE_LOG(LogSensorFusion, Warning, TEXT("Invalid sensor no (%d)"), sensorIdx);
		return false;
	}

	if (!IsConnected())
	{
		UE_LOG(LogSensorFusion, Error, TEXT("Port(%s) is not opened."), *m_comPort);
		return false;
	}

	SensorData *pData = m_sensorData.at(sensorIdx);
	if (pData == NULL)
	{
		return false;
	}

#if 1 //for debug
	{
		char buffer[1024];
		sprintf(buffer, "id[%s] euler[%.2f, %.2f, %.2f] gyro[%.2f, %.2f, %.2f] acc[%.2f, %.2f, %.2f] battery[%d]\0",
			pData->sensor_id.c_str(), pData->euler_x, pData->euler_y, pData->euler_z,
			pData->gyro_x, pData->gyro_y, pData->gyro_z,
			pData->acc_x, pData->acc_y, pData->acc_z, pData->battery);
		int len = strlen(buffer);
		wchar_t* t = new wchar_t[len + 1];
		mbstowcs(t, buffer, len);
		t[len] = 0x00;
		UE_LOG(LogSensorFusion, Warning, TEXT("+++ data : %s"), t);
		delete t;
	}
#endif

	ret = SensorData2AccelerometerVector(pData, targetVector, true);

	return ret;
}

bool SensorFusionEngine::GetSensorGyroscope(int sensorIdx, FVector & targetVector)
{
	bool ret = false;

	// check the validation of input parameters
	if (sensorIdx < 0 || sensorIdx >= m_sensorData.size())
	{
		UE_LOG(LogSensorFusion, Warning, TEXT("Invalid sensor no (%d)"), sensorIdx);
		return false;
	}

	if (!IsConnected())
	{
		UE_LOG(LogSensorFusion, Error, TEXT("Port(%s) is not opened."), *m_comPort);
		return false;
	}

	SensorData *pData = m_sensorData.at(sensorIdx);
	if (pData == NULL)
	{
		return false;
	}

#if 1 //for debug
	{
		char buffer[1024];
		sprintf(buffer, "id[%s] euler[%.2f, %.2f, %.2f] gyro[%.2f, %.2f, %.2f] acc[%.2f, %.2f, %.2f] battery[%d]\0",
			pData->sensor_id.c_str(), pData->euler_x, pData->euler_y, pData->euler_z,
			pData->gyro_x, pData->gyro_y, pData->gyro_z,
			pData->acc_x, pData->acc_y, pData->acc_z, pData->battery);
		int len = strlen(buffer);
		wchar_t* t = new wchar_t[len + 1];
		mbstowcs(t, buffer, len);
		t[len] = 0x00;
		UE_LOG(LogSensorFusion, Warning, TEXT("+++ data : %s"), t);
		delete t;
	}
#endif

	ret = SensorData2GyroscopeVector(pData, targetVector, true);

	return ret;
}


bool SensorFusionEngine::SensorData2AccelerometerVector(SensorData * pData, FVector & targetVector, bool bRoot)
{
	if (pData == NULL)
		return false;

	glm::vec3 AccelData = pData->GetAccelData();

	targetVector.Set(AccelData.x, AccelData.y, AccelData.z);

#if 1 // for debug
	{

	}
#endif

	return true;
}

bool SensorFusionEngine::SensorData2GyroscopeVector(SensorData * pData, FVector & targetVector, bool bRoot)
{
	if (pData == NULL)
		return false;

	glm::vec3 GyroData = pData->GetGyroData();

	targetVector.Set(GyroData.x, GyroData.y, GyroData.z);

#if 1 // for debug
	{

	}
#endif

	return true;
}