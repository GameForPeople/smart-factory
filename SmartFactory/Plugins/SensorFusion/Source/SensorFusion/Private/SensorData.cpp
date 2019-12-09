// Fill out your copyright notice in the Description page of ProjectSen Settings.

#include "SensorData.h"
#include "Sensor.h"

SensorData::SensorData()
{
	m_bConnected = false;
	m_bBinded = false;
}

SensorData::SensorData(string sensorId)
{
	sensor_id = sensorId;

	SensorData();
}

SensorData::~SensorData()
{
}

void SensorData::SetSensorValue(ParseNode &parsedata)
{
	// sensor_id = parsedata.str_id;
	euler_x = parsedata.euler_x;
	euler_y = parsedata.euler_y;
	euler_z = parsedata.euler_z;
	gyro_x = parsedata.gyro_x;
	gyro_y = parsedata.gyro_y;
	gyro_z = parsedata.gyro_z;
	acc_x = parsedata.acc_x;
	acc_y = parsedata.acc_y;
	acc_z = parsedata.acc_z;
	battery = parsedata.battery;

	m_bConnected = true;
}

#if 0
void SensorData::Update(const glm::vec3 &i_v3ParentRotaion)
{
	// Set Parent Rotaion vec3
	m_v3ParentRotationEuler = i_v3ParentRotaion;

	// Set my rotation(Original) vec3
	m_v3MyRotationEuler.x = euler_x;
	m_v3MyRotationEuler.y = euler_y;
	m_v3MyRotationEuler.z = euler_z;

	// Set my rotation (between parent) vec3
	m_v3MyRotationDiffParent = m_v3ParentRotationEuler - m_v3MyRotationEuler;
}

glm::vec3 SensorData::GetDiffAngle() 
{
	return m_v3MyRotationDiffParent;
}
#endif

glm::vec3 SensorData::GetMyOriginalRotaion()
{
	m_v3MyRotationEuler.x = euler_x;
	m_v3MyRotationEuler.y = euler_y;
	m_v3MyRotationEuler.z = euler_z;

	return m_v3MyRotationEuler;
}


bool SensorData::SetBindingAngle()
{
	if (!m_bConnected)
		return false;

	// 현 위치를 0으로 맞춰주기위함.
	m_v3BindAngle.x = -euler_x;
	m_v3BindAngle.y = -euler_y;
	m_v3BindAngle.z = -euler_z;

	m_bBinded = true;

	return m_bBinded;
}


glm::vec3 SensorData::GetAngle() {
	glm::vec3 v3RetVal = glm::vec3{ 0.f };
	v3RetVal.x = euler_x + m_v3BindAngle.x;
	v3RetVal.y = euler_y + m_v3BindAngle.y;
	v3RetVal.z = euler_z + m_v3BindAngle.z;

	return v3RetVal;
}

glm::vec3 SensorData::GetAccelData()
{

	glm::vec3 AccelData;

	AccelData.x = acc_x;
	AccelData.y = acc_y;
	AccelData.z = acc_z;

	return AccelData;
}

glm::vec3 SensorData::GetGyroData()
{
	glm::vec3 GyroData;

	GyroData.x = gyro_x;
	GyroData.y = gyro_y;
	GyroData.z = gyro_z;

	return GyroData;
}