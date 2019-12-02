#include "stdafx.h"

namespace LOG_UTIL
{
	SourceLocation::SourceLocation(const char* fileName, int fileLine, const char* functionName)
		: fileName(fileName), fileLine(fileLine), functionName(functionName)
	{
	}

	string SourceLocation::operator()() const
	{
		return
			'['
			+ std::string(fileName)
			+ ':'
			+ std::to_string(fileLine)
			+ "] "
			+ std::string(functionName);
	}
}

namespace ERROR_UTIL
{
	_NORETURN void Error(const LOG_UTIL::SourceLocation& sourceLocation, const string& printLog)
	{
		std::cout << "ERROR -> "<< sourceLocation() << ", " << printLog << "\n";

		while (7)
		{
			// Infinite loop
		}
	};
}

namespace NETWORK_UTIL
{
	int recvn(SOCKET socket, char* buf, int len, int flags)
	{
		int received;
		char* ptr = buf;

		int left = len;

		while (left > 0) 
		{
			if (received = recv(socket, ptr, left, flags)
				; received == SOCKET_ERROR) { return SOCKET_ERROR; }
			else if (received == 0) { return -2; }

			left -= received;
			ptr += received;
		}

		return (len - left);
	}
}

namespace UNICODE_UTIL
{
	void SetLocaleToKorean()
	{
		_wsetlocale(LC_ALL, L"Korean");

		auto oldLocale = std::wcout.imbue(std::locale("korean"));
	}

	_NODISCARD std::string WStringToString(const std::wstring& InWString)
	{
		const int sizeBuffer = WideCharToMultiByte(CP_ACP, 0, &InWString[0], -1, NULL, 0, NULL, NULL);

		std::string retString(sizeBuffer, 0);

		WideCharToMultiByte(CP_ACP, 0, &InWString[0], -1, &retString[0], sizeBuffer, NULL, NULL);

		// FixError ==
		retString.pop_back(); //(retString.end(), retString.end());
		//retString.insert(retString.end(), '\0');

		return retString;
	}

	_NODISCARD std::wstring StringToWString(const std::string& InString)
	{
		const int sizeBuffer = MultiByteToWideChar(CP_ACP, 0, &InString[0], -1, NULL, 0);

		std::wstring retString(sizeBuffer, 0);

		MultiByteToWideChar(CP_ACP, 0, &InString[0], -1, &retString[0], sizeBuffer);

		return retString;
	}
}