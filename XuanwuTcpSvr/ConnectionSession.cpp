#include "ConnectionSession.h"


ConnectionSession::ConnectionSession(tcp::socket socket, NetMsgCallback* p_net_msg_callback):_p_net_msg_callback(p_net_msg_callback)
{
	_up_net_msg_handler = 
		std::unique_ptr<NetPackMsgHandler>( 
			NetPackMsgHandler::CreateNetPackMsgHandler(std::move(socket))
			);
	_up_net_msg_handler.get()->SetMsgCallback(p_net_msg_callback);
}


ConnectionSession::~ConnectionSession()
{

}

void ConnectionSession::Start()
{
	_up_net_msg_handler->ReadAsync();
}

void ConnectionSession::Stop()
{
	_up_net_msg_handler->CloseSocket();
}

void ConnectionSession::Deliver(const NetPackMsg*  p_message)
{
	bool write_in_progress = !_msg_write_queue.empty();
	auto p = std::unique_ptr<NetPackMsg>{ new NetPackMsg(*p_message) }; // make a copy
	_msg_write_queue.push_back(std::move(p));

	if (!write_in_progress)
	{
		_do_write();
	}
}

void  ConnectionSession::_do_write()
{
	std::unique_ptr<NetPackMsg>  up_message = std::move(_msg_write_queue.front());
	_msg_write_queue.pop_front();

	_up_net_msg_handler->WriteAsync(std::move(up_message));
}
