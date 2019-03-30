#pragma once
#include <boost/asio.hpp>
#include <string>
#include "ConnectionMgr.h"

class Client
{
public:
	Client(const Client&) = delete;
	Client& operator=(const Client&) = delete;

	Client(const std::string& address, const std::string& port, ConnectionMgr* p_connection_manager);

	~Client();

	void Run();
	void Start();
	void Stop();

private:
	boost::asio::io_context _io_context;

	/*
	just a temp holder for tcp socket when we do connection, 
	the ownership will be moved to connection manager. 
	don't ever really use it.
	*/
	tcp::socket _socket_tmp_holder; 
	ConnectionMgr* _p_connectionMgr;
	std::thread _thread_service;

	void _do_connect(const tcp::resolver::results_type& endpoints);
	static void _s_run_service(Client* p_client);
};

