#pragma once
#include <memory>
#include <mutex>
#include <string>
#include "ConnectionMgr.h"

class GameConnection : public ConnectionMgr
{
private:
	static std::unique_ptr<GameConnection> _ps_connection;
	static std::mutex _singleton_mutex;

	std::unique_ptr<NetMsgPump> up_msp;

public:
	GameConnection();
	virtual ~GameConnection();
	bool PollMsg(std::unique_ptr<NetPackMsg> & up_msg);
	void SendContent(const char* content);

	static GameConnection* GetSingleton();
};

