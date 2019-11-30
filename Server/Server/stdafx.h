#pragma once

//-----
#define WONSY_PCH
//-----

// C++ Base
#include <iostream>
#include <chrono>
#include <string>

#include <cwchar>

#define NDEBUG
#include <cassert>

// C++11
#include <mutex>
#include <atomic>
#include <thread>

// C++ STL
#include <vector>

// PPL
#include <concurrent_queue.h>

// Windows
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "ws2_32")
#pragma comment(lib, "wininet.lib")

#include <winsock2.h>

// Attributes
#define	_NORETURN		[[noreturn]]
#define	_DEPRECATED		[[deprecated]]
#define	_MAYBE_UNUSED	[[maybe_unused]]
#define	_FALLTHROUGH	[[fallthrough]]
#define	_NODISCARD		[[nodiscard]]

#define	_INLINE			inline
#define	_DO_NOT_DELETE	/* not Owner pointer */	
#define	_NOT_NULLPTR

// Using Namespace
using namespace std;
using namespace std::chrono;
using namespace concurrency;

// others Macro


// Utils
namespace LOG_UTIL
{
#define __FUNCTION_NAME__ __FUNCTION__
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define SOURCE_LOCATION __FILENAME__, __LINE__, __FUNCTION_NAME__
	
	struct SourceLocation
	{
		const char* fileName;
		int fileLine;
		const char* functionName;

		SourceLocation(const char* fileName, int fileLine, const char* functionName);
		string operator()() const;
	};

#define MAKE_SOURCE_LOCATION LOG_UTIL::SourceLocation(SOURCE_LOCATION)
}

namespace ERROR_UTIL
{
	_NORETURN void Error(const LOG_UTIL::SourceLocation& sourceLocation, const string& printLog);
}

namespace NETWORK_UTIL
{
	int recvn(SOCKET socket, char* buf, int len, int flags);
}
