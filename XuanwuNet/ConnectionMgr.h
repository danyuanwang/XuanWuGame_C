#pragma once
#include"NetMsgCallback.h"
#include "MsgPump.h"
#include "ConnectionSession.h"
#include <list>
#include <memory>
#include <queue>
#include <thread>

class ConnectionMgr :public NetMsgCallback
{
public:
	ConnectionMgr();
	virtual ~ConnectionMgr();

	void AddSession(tcp::socket socket);
	void AddSession(udp::socket socket) { throw E_NOTIMPL; }

	void AddMsgListener(NetMsgCallback* callback);

	void StopAll();

	void SendMsg(NetPackMsg*  p_message /*ordinary pointer means no ownership transfer*/);

	int OnReceivedMsgCallback(std::unique_ptr<NetPackMsg>  up_message);
	int OnReceivedMsgCallback(NetPackMsg*  up_message /*ordinary pointer means no ownership transfer*/);
	int OnSentMsgCallback(boost::system::error_code ec, std::size_t);


private:
	std::list<std::unique_ptr<ConnectionSession>> _list_session;
	std::list<NetMsgCallback* > _list_message_handler;

};

