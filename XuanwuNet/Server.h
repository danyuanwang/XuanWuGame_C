#pragma once
#include <boost/asio.hpp>
#include <string>
#include "ConnectionMgr.h"

class server
{
public:
	server(const server&) = delete;
	server& operator=(const server&) = delete;

	/// Construct the server to listen on the specified TCP address and port, and
	/// serve up files from the given directory.
	explicit server(const std::string& address, const std::string& port, ConnectionMgr* p_connection_manager);

	/// Run the server's io_context loop.
	void run();

private:
	/// Perform an asynchronous accept operation.
	void do_accept();

	/// Wait for a request to stop the server.
	void do_await_stop();

	/// The io_context used to perform asynchronous operations.
	boost::asio::io_context io_context_;

	/// The signal_set is used to register for process termination notifications.
	boost::asio::signal_set signals_;

	/// Acceptor used to listen for incoming connections.
	boost::asio::ip::tcp::acceptor acceptor_;

	/// The connection manager which owns all live connections.
	ConnectionMgr* _p_connection_manager; //Using ordinaory pointer means no ownership

};