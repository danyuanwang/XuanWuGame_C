#include "ConnectionSession.h"


ConnectionSession::ConnectionSession(tcp::socket socket)
{
	_up_net_msg_handler = 
		std::unique_ptr<NetPackMsgHandler>( 
			NetPackMsgHandler::CreateNetPackMsgHandler(std::move(socket))
			);
}


ConnectionSession::~ConnectionSession()
{

}

void ConnectionSession::Start()
{
	_up_net_msg_handler->ReadAsync(_on_read_msg);
}

void ConnectionSession::Stop()
{
	_up_net_msg_handler->CloseSocket();
}

void ConnectionSession::Deliver(std::unique_ptr<NetPackMsg>  up_message)
{
	bool write_in_progress = !_msg_write_queue.empty();
	_msg_write_queue.push_back(std::move(up_message));

	if (!write_in_progress)
	{
		_do_write();
	}
}

int ConnectionSession::_on_read_msg(std::unique_ptr<NetPackMsg>  up_message)
{
	return 0;
}

int ConnectionSession::_on_write_msg(boost::system::error_code ec, std::size_t)
{
	return 0;
}

void  ConnectionSession::_do_write()
{
	std::unique_ptr<NetPackMsg>  up_message = std::move(_msg_write_queue.front());
	_msg_write_queue.pop_front();

	_up_net_msg_handler->WriteAsync(std::move(up_message), _on_write_msg);
}
