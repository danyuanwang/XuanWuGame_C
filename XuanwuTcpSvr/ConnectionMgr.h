#pragma once
#include "ConnectionSession.h"
#include <list>
#include <memory>
#include "..\XWModel\GameModel.h"

class ConnectionMgr
{
public:
	ConnectionMgr();
	virtual ~ConnectionMgr();

	void AddSession(tcp::socket socket);
	void AddSession(udp::socket socket) { throw E_NOTIMPL; }

	void StopAll();

private:
	std::list<std::unique_ptr<ConnectionSession>> _list_session;
};

