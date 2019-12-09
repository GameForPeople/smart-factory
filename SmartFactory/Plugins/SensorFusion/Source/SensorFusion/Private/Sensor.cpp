// Fill out your copyright notice in the Description page of Project Settings.

#include "Sensor.h"

#include <Windows.h>

#ifdef SENSOR_FILE
#include "Paths.h"
#endif


Sensor::Sensor()
{
	m_hComm = INVALID_HANDLE_VALUE;
	m_bPortReady = false;

#ifdef SENSOR_FILE
	m_bSensorFile = false;
	m_sleepMSec = 10;
#endif
}

Sensor::~Sensor()
{
	ClosePort();
}

void Sensor::ClosePort() {
	if( m_hComm != INVALID_HANDLE_VALUE )
		CloseHandle(m_hComm);
	m_hComm = INVALID_HANDLE_VALUE;
	m_bPortReady = false;

	return;
}

bool Sensor::IsPortOpened() {
	if (m_hComm != INVALID_HANDLE_VALUE && m_bPortReady)
		return true;

	ClosePort();
	return false;
}

bool Sensor::ReadByteStr(string& buffer) {
	string rx;
	char c = 0;
	DWORD dwBytesTransferred = 0;

#ifdef SENSOR_FILE
	if (m_bSensorFile) {
		Sleep(m_sleepMSec);
	}
#endif

	while (true) {
		if (ReadFile(m_hComm, &c, 1, &dwBytesTransferred, 0)) {
			if (dwBytesTransferred == 1) {
				if (c == '\n') {
					buffer.push_back(c);
					return true;
				}
				else {
					buffer.push_back(c);
				}
			}
			else {
#ifdef SENSOR_FILE
				if (m_bSensorFile)
					return false;
				else
					return true;
#else
				return true;
#endif
			}
		}
		else {
			return false;
		}
	}

	return false;
}

// Sensor 클래스 내부에 있는 parsedata에 데이터를 파싱해서
// 넣어준다.
void Sensor::Parsing(string& buffer) {
	// 파싱포인트
	string delimiter = ",";
	int parse_count = 0;

	size_t pos = 0;
	string token;

	if (buffer.empty())
		return;

	while ((pos = buffer.find(delimiter)) != string::npos) {
		token = buffer.substr(0, pos);
		if (parse_count == 0)
			parsedata.str_id = token;
		else if (parse_count == 1)
			parsedata.euler_x = (float)atof(token.c_str());
		else if (parse_count == 2)
			parsedata.euler_y = (float)atof(token.c_str());
		else if (parse_count == 3)
			parsedata.euler_z = (float)atof(token.c_str());
		else if (parse_count == 4)
			parsedata.gyro_x = (float)atof(token.c_str());
		else if (parse_count == 5)
			parsedata.gyro_y = (float)atof(token.c_str());
		else if (parse_count == 6)
			parsedata.gyro_z = (float)atof(token.c_str());
		else if (parse_count == 7)
			parsedata.acc_x = (float)atof(token.c_str());
		else if (parse_count == 8)
			parsedata.acc_y = (float)atof(token.c_str());
		else if (parse_count == 9) {
			parsedata.acc_z = (float)atof(token.c_str());
			parse_count = -1;
		}
		parse_count++;
		buffer.erase(0, pos + delimiter.length());
	}

	parsedata.battery = atoi(buffer.c_str());
}

bool Sensor::WriteByte(BYTE bybyte) {
	m_iBytesWritten = 0;
	if (WriteFile(m_hComm, &bybyte, 1, &m_iBytesWritten, NULL) == 0)
		return false;
	else
		return true;
}

bool Sensor::OpenPort(LPCTSTR portname) {
	TCHAR portPath[MAX_PATH];
#ifdef SENSOR_FILE
	if (!_tcscmp(portname, _T("FILE")) ) {
		m_bSensorFile = true;

		FString BaseDir = FPaths::GamePluginsDir();
		FString LogPath = FPaths::Combine(*BaseDir, TEXT("SensorFusion"), TEXT("SensorLog.txt"));

		UE_LOG(LogTemp, Warning, TEXT("LogFile Path (%s)"), *LogPath);
		_tcscpy(portPath, *LogPath);
	}
	else {
		m_bSensorFile = false;
		wsprintf(portPath, L"//./%s", portname);
	}
#else
	wsprintf(portPath, L"//./%s", portname);
#endif

	m_hComm = CreateFile(portPath,
		GENERIC_READ | GENERIC_WRITE, // 읽어오기만 할 예정이므로
		0,
		0,
		OPEN_EXISTING,
		0,
		0);

	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		return false;
	}
	else
		return true;
}

bool Sensor::SetCommunicationTimeouts(DWORD ReadIntervalTimeout,
	DWORD ReadTotalTimeoutMultiplier, DWORD ReadTotalTimeoutConstant,
	DWORD WriteTotalTimeoutMultiplier, DWORD WriteTotalTimeoutConstant) {
#ifdef SENSOR_FILE
	if (m_bSensorFile) {
		m_bPortReady = true;
		return true;
	}
#endif

	if ((m_bPortReady = GetCommTimeouts(m_hComm, &m_CommTimeouts)) == 0)
		return false;

	m_CommTimeouts.ReadIntervalTimeout = ReadIntervalTimeout;
	m_CommTimeouts.ReadTotalTimeoutConstant = ReadTotalTimeoutConstant;
	m_CommTimeouts.ReadTotalTimeoutMultiplier = ReadTotalTimeoutMultiplier;
	m_CommTimeouts.WriteTotalTimeoutConstant = WriteTotalTimeoutConstant;
	m_CommTimeouts.WriteTotalTimeoutMultiplier = WriteTotalTimeoutMultiplier;

	m_bPortReady = SetCommTimeouts(m_hComm, &m_CommTimeouts);

	if (m_bPortReady == 0)
	{
		ClosePort();
		return false;
	}
	return true;
}

bool Sensor::ConfigurePort(DWORD BaudRate, BYTE ByteSize, DWORD fParity,
	BYTE  Parity, BYTE StopBits) {
#ifdef SENSOR_FILE
	if (m_bSensorFile) {
		m_bPortReady = true;
		return true;
	}
#endif

	if ((m_bPortReady = GetCommState(m_hComm, &m_dcb)) == 0)
	{
		ClosePort();
		return false;
	}

	m_dcb.BaudRate = BaudRate;
	m_dcb.ByteSize = ByteSize;
	m_dcb.Parity = Parity;
	m_dcb.StopBits = StopBits;
	m_dcb.fBinary = true;
	m_dcb.fDsrSensitivity = false;
	m_dcb.fParity = fParity;
	m_dcb.fOutX = false;
	m_dcb.fInX = false;
	m_dcb.fNull = false;
	m_dcb.fAbortOnError = true;
	m_dcb.fOutxCtsFlow = false;
	m_dcb.fOutxDsrFlow = false;
	m_dcb.fDtrControl = DTR_CONTROL_DISABLE;
	m_dcb.fDsrSensitivity = false;
	m_dcb.fRtsControl = RTS_CONTROL_DISABLE;
	m_dcb.fOutxCtsFlow = false;
	m_dcb.fOutxCtsFlow = false;

	m_bPortReady = SetCommState(m_hComm, &m_dcb);
	if (m_bPortReady == 0)
	{
		ClosePort();
		return false;
	}

	SetupComm(m_hComm, 4096, 4096);

	// 버퍼 초기화
	m_bPortReady = PurgeComm(m_hComm, PURGE_TXABORT | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_RXCLEAR);
	if (m_bPortReady == 0)
	{
		ClosePort();
		return false;
	}

	return true;
}
