#pragma once

namespace USING
{
	using _Flag = char; // bool;
	using _Index = int;
	using _PacketType = char;

	using _ClientType = char;
	using _Password = int;
	using _Name = wchar_t[10];

	using _CarType = char;
	using _ColorType = char;
	using _TireType = char;

	using _Address = wchar_t[50];
	using _Number = int;
	using _Price = int;

	//using _Color = char[3];
	using _CameraDataType = char[3 * 300 * 300];

}using namespace USING;

namespace DEFINE
{
	static constexpr _Password COMMON_PASSWORD = 19942019;
}

namespace CLIENT_TYPE
{
	// 0 일반 클라이언트, 1 매니저, 2 언리얼
	enum : _ClientType
	{
		  Client = 0
		, Manager = 1
		, Factory = 2
	};
}

namespace MANAGER_PACKET_TYPE
{
	enum : char
	{
		  OnOffFactory = 0
		, ChangeCamera = 1
		, NeedCameraData = 2
	};
}

namespace FACTORY_PACKET_TYPE
{
	// 0 일반 클라이언트, 1 매니저, 2 언리얼
	enum : char
	{
		GetOnOffState = 0
		, GetOrder = 1
		, GetCameraIndex = 2
		, CameraData = 3
	};
}

#pragma pack(push, 1)
struct Auth
{
	_ClientType clientType;	
	_Password commonPassword; // 공통으로 19942019
	_Name name; // 클라 사용 안함
	_Password privatePassword; // 클라 사용 안함
};

// client - server
struct ClientOrder
{
	// car setting
	_CarType carType;
	_ColorType colorType;
	_TireType tireType;
	
	//others
	// _Name name;
	// _Address addr;
	// _Number number;
	// _Price price;
};

struct AnswerToClient
{
	_Flag flag; // 0 fail, 1 succ
};

// Other - server
struct OrderInfo
{
	_Flag flag; // 0 주문 없음, 1 주문 있음
	ClientOrder clientOrder;
};

struct OnOffFactory
{
	_Flag flag; // 0 fail, 1 succ
};

struct ChangeCamera
{
	_Index cameraIndex;
};

struct CameraData
{
	_CameraDataType colorArr;
};

#pragma pack(pop)