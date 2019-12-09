// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/euler_angles.hpp"

/**
 * 
 */
using namespace std;

struct ParseNode;

class SENSORFUSION_API SensorData
{
public:
	SensorData();
	SensorData(string sensorId);
	~SensorData();

	string sensor_id;
	//오일러
	float euler_x;
	float euler_y;
	float euler_z;
	// 자이로
	float gyro_x;
	float gyro_y;
	float gyro_z;
	// 가속도
	float acc_x;
	float acc_y;
	float acc_z;

	int battery;

private:
	glm::vec3 m_v3BindAngle{ 0.f };
	glm::vec3 m_v3Angle{ 0.f };

	glm::vec3 m_v3ParentRotationEuler{ 1.f };

	// 2018 8 2 Update
	glm::vec3 m_v3MyRotationEuler{ 0.f };
	glm::vec3 m_v3MyRotationDiffParent{ 0.f };

	bool m_bBinded;
	bool m_bConnected;
public:
	void SetSensorValue(ParseNode &parsedata);
	bool SetBindingAngle();

	glm::vec3 GetAngle();
	glm::vec3 GetAccelData();
	glm::vec3 GetGyroData();

	bool IsBinded() { return m_bBinded;  }

	// 2018. 8. 2 아래 세 함수만 사용
//	void Update(const glm::vec3 &i_v3ParentRotaion);
	// 자식센서에서 나온 값을 vec3화 해서 return 
	glm::vec3 GetMyOriginalRotaion();
	// 부모센서의 값을 뺀 vec3 return
//	glm::vec3 GetDiffAngle();
};
