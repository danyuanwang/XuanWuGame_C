// XuanwuTcpSvr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Server.h"
#include <string>
#include <iostream>
void PTIterateCallback(std::string key, std::string value, int level)
{
	if (key.empty())
	{
		std::cout << "node value:" << value << ", level:" << level << std::endl;
	}
	else
	{
		std::cout << "key:" << key << ", value:" << value << ", level:" << level << std::endl;
	}
}

int main()
{
	std::string ips("0.0.0.0");
	std::string port("2014");

	server s(ips, port);
	s.run();

}
