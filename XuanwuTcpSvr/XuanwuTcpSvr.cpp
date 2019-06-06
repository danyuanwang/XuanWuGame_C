// XuanwuTcpSvr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Server.h"
#include <string>
#include "GameServer.h"
int main()
{
	std::string ips("0.0.0.0");
	std::string port("2014");

	auto up_gs = std::unique_ptr<GameServer>(new GameServer);
	auto up_msp = std::unique_ptr<NetMsgPump>(new NetMsgPump);
	auto up_cnmgr = std::unique_ptr<ConnectionMgr>(new  ConnectionMgr);

	up_cnmgr->AddMsgListener(up_msp.get());

	up_gs->BindConnection(up_cnmgr.get());

	up_msp->AddMsgListener(up_gs.get());

	server s(ips, port, up_cnmgr.get());
	s.run();

}
