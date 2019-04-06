#include "ConnectionMgr.h"
#if _DEBUG
#include <iostream>
#endif



ConnectionMgr::ConnectionMgr() 
{
}


ConnectionMgr::~ConnectionMgr()
{
}

void ConnectionMgr::AddSession(tcp::socket socket)
{
	auto up_session = std::unique_ptr<ConnectionSession>(
		new ConnectionSession(std::move(socket), this)
		);
	up_session.get()->Start();
	_list_session.push_back(std::move(up_session));

}

void ConnectionMgr::StopAll()
{
	while (_list_session.size() > 0)
	{
		_list_session.front().get()->Stop();
		_list_session.pop_front();
	}
}

int ConnectionMgr::OnReceivedMsgCallback(std::unique_ptr<NetPackMsg> up_message)
{
#if _DEBUG
	std::cout << __FUNCTION__ << " : " << std::endl;
	std::cout << std::string{ (const char*)up_message->Body() } << std::endl;
#endif

	for (auto p = _list_message_handler.cbegin(); p != _list_message_handler.cend(); ++p)
	{
		(*p)->OnReceivedMsgCallback(up_message.get()/*using ordinary pointer not to transfer ownership*/);
	}


	return 0;
}

int ConnectionMgr::OnReceivedMsgCallback(NetPackMsg * up_message)
{
	throw E_NOTIMPL;
}

int ConnectionMgr::OnSentMsgCallback(boost::system::error_code ec, std::size_t size)
{
	for (auto p = _list_message_handler.cbegin(); p != _list_message_handler.cend(); ++p)
	{
		(*p)->OnSentMsgCallback(ec, size);
	}
	return 0;
}

void ConnectionMgr::SendMsg(NetPackMsg * p_message)
{
#if _DEBUG
	std::cout << __FUNCTION__ << " : " << std::endl;
	std::cout << std::string{ (const char*)p_message->Body() } << std::endl;
#endif

	for (auto p = _list_session.cbegin(); p != _list_session.cend(); ++p)
	{
		p->get()->Deliver(p_message);
	}

}


void ConnectionMgr::AddMsgListener(NetMsgCallback * callback)
{
	_list_message_handler.push_back(callback);
}
