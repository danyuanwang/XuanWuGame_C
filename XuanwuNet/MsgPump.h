#pragma once
#include "NetStructure.h"
#include <queue>
#include "NetMsgCallback.h"

class NetMsgPump: public NetMsgCallback
{
public:
	NetMsgPump();
	virtual ~NetMsgPump();

	void Enqueue(std::unique_ptr<NetPackMsg>);
	std::unique_ptr<NetPackMsg> Dequeue();
	bool Empty();
	bool Poll(std::unique_ptr<NetPackMsg> & up_msg);

	void AddMsgListener(NetMsgCallback * callback);
	void Close();

	int OnReceivedMsgCallback(std::unique_ptr<NetPackMsg>  up_message);
	int OnReceivedMsgCallback(NetPackMsg*  up_message /*ordinary pointer means no ownership transfer*/);
	int OnSentMsgCallback(boost::system::error_code ec, std::size_t);

private:
	std::queue<std::unique_ptr<NetPackMsg>> _queue_net_msg;

	std::mutex _queue_mutex;
	std::condition_variable _queue_cond;
	std::thread _thread_net_msg_consumer;
	bool _signal_quit_thread;

	static void _s_process_net_msg(NetMsgPump* msp);
	void _process_net_msg();

	std::list<NetMsgCallback* > _list_message_handler;

};

 