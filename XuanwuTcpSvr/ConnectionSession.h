#pragma once
#include <memory>
#include <deque>
#include "NetPackMsgHandler.h"


class ConnectionSession:
	public std::enable_shared_from_this<ConnectionSession>
{
private:
	std::unique_ptr<NetPackMsgHandler> _up_net_msg_handler;
	std::deque<std::unique_ptr<NetPackMsg>> _msg_write_queue;

	static int _on_read_msg(std::unique_ptr<NetPackMsg>  up_message);
	static int  _on_write_msg(boost::system::error_code ec, std::size_t);

	void _do_write();
public:
	ConnectionSession(tcp::socket socket);
	ConnectionSession(udp::socket socket);

	~ConnectionSession();
	void Start();
	void Stop();
	void Deliver(std::unique_ptr<NetPackMsg>  up_message);
};

