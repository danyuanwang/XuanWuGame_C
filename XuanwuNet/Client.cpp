#include "Client.h"

Client::~Client()
{
	_p_connectionMgr = nullptr;
}

Client::Client(
	const std::string& address, 
	const std::string& port, 
	ConnectionMgr* p_connection_manager):
	_socket_tmp_holder(_io_context)
{
	tcp::resolver resolver(_io_context);
	auto endpoints = resolver.resolve(address, port);
	_do_connect(endpoints);

	_p_connectionMgr = p_connection_manager;
}

void Client::Run()
{
	// The io_context::run() call will block until all asynchronous operations
	// have finished. While the server is running, there is always at least one
	// asynchronous operation outstanding: the asynchronous read call waiting
	// for new incoming message.	

	_io_context.run();

	_io_context.stop();
}

void Client::Start()
{
	std::thread td{ _s_run_service, this }; 
	_thread_service = std::move(td);
}

void Client::Stop()
{
	_p_connectionMgr->StopAll();

	if (_thread_service.joinable())
	{
		_thread_service.join();
	}
}
void Client::_s_run_service(Client * p_client)
{
	p_client->Run();
}

void Client::_do_connect(const tcp::resolver::results_type& endpoints)
{
	boost::asio::async_connect(_socket_tmp_holder, endpoints,
		[this](boost::system::error_code ec, tcp::endpoint ep)
	{
		if (!ec)
		{
			_p_connectionMgr->AddSession(std::move(_socket_tmp_holder));
		}
	});
}


