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
			else if (received == 0) { break; }

			left -= received;
			ptr += received;
		}

		return (len - left);
	}
}