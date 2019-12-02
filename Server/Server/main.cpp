#include "stdafx.h"
#include "Server.h"

int main()
{
	UNICODE_UTIL::SetLocaleToKorean();
	std::unique_ptr<Server> server = std::make_unique<Server>();
	server->Run();

	std::system("PAUSE");
}