// XuanwuTcpSvr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Server.h"
#include <string>
#include <iostream>
#include "GameModel.h"
int main()
{
	std::string ips("0.0.0.0");
	std::string port("2014");

	GameModel gm;
	ConnectionMgr cnMgr;
	gm.BindConnection(&cnMgr);
	server s(ips, port, &cnMgr);
	s.run();

}
