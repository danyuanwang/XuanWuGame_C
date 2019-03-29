// XuanwuTcpSvr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Server.h"
#include <string>
#include <iostream>
int main()
{
	//std::string ips("0.0.0.0");
	//std::string port("2014");

	//server s(ips, port);
	//s.run();

	GamePlayRequest request{ GameScenario_Map , GameOjbect_Player ,GameOjbect_Army ,GameOjbectAction_Move};
	std::cout << request.ToJson();
}
