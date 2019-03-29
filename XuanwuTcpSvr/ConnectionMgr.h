#pragma once
#include"NetMsgCallback.h"
#include "ConnectionSession.h"
#include <list>
#include <memory>
#include <queue>
#include <thread>

#include "..\XWModel\GameModel.h"

class ConnectionMgr:public NetMsgCallback
{
public:
	ConnectionMgr();
	virtual ~ConnectionMgr();

	void AddSession(tcp::socket socket);
	void AddSession(udp::socket socket) { throw E_NOTIMPL; }

	void StopAll();

	int OnReceivedMsgCallback(std::unique_ptr<NetPackMsg>  up_message);
	int OnSentMsgCallback(boost::system::error_code ec, std::size_t);


private:
	std::list<std::unique_ptr<ConnectionSession>> _list_session;
	std::queue<std::unique_ptr<NetPackMsg>> _queue_net_msg;

	std::mutex _queue_mutex;
	std::condition_variable _queue_cond;
	std::thread _net_msg_consumer_thread;
	bool _quit_thread;

	static void _consume_net_msg(ConnectionMgr* connnectMgr);

	DataModel _dataModel;

	void _notify_client();
};

