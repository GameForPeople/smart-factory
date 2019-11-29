#include "stdafx.h"
#include "Server.h"

int main()
{
	std::unique_ptr<Server> server = std::make_unique<Server>();
	server->Run();

	std::system("PAUSE");
}