#pragma once
#include <memory>
#include <deque>
#include "NetPackMsgHandler.h"
#include "NetMsgCallback.h"

class ConnectionSession:
	public NetMsgCallback, 
	public std::enable_shared_from_this<ConnectionSession>
{
private:
	std::unique_ptr<NetPackMsgHandler> _up_net_msg_handler;
	std::deque<std::unique_ptr<NetPackMsg>> _msg_write_queue;
	std::deque<std::unique_ptr<NetPackMsg>> _msg_wait_for_sent_queue;
	std::mutex _queue_mutex;

	NetMsgCallback* _p_net_msg_callback; //using odinary pointer means no ownership.

	void _do_write();

public:
	ConnectionSession(tcp::socket socket, NetMsgCallback* p_net_msg_callback);
	ConnectionSession(udp::socket socket, NetMsgCallback* p_net_msg_callback);

	~ConnectionSession();
	void Start();
	void Stop();
	void Deliver(const NetPackMsg*  p_message/*using ordinary pointer means we don't own it*/);

	int OnReceivedMsgCallback(std::unique_ptr<NetPackMsg>  up_message);
	int OnReceivedMsgCallback(NetPackMsg*  p_message /*ordinary pointer means no ownership transfer*/);
	int OnSentMsgCallback(boost::system::error_code ec, std::size_t);

};

