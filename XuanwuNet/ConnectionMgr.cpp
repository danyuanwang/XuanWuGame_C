#include "ConnectionMgr.h"
#if _DEBUG
#include <iostream>
#endif



ConnectionMgr::ConnectionMgr() :
	_sent_message_counter(0),
	_received_message_counter(0)
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
	return OnReceivedMsgCallback(up_message.get()/*using ordinary pointer not to transfer ownership*/);
}

int ConnectionMgr::OnReceivedMsgCallback(NetPackMsg * p_message)
{
	for (auto p = _list_message_handler.cbegin(); p != _list_message_handler.cend(); ++p)
	{
		(*p)->OnReceivedMsgCallback(p_message);
	}

	_received_message_counter++;

	//#if _DEBUG
	//	std::cout << __FUNCTION__ << " : " << _received_message_counter << " : " << std::endl;
	//	std::cout << std::string{ (const char*)up_message->Body() } << std::endl;
	//#endif

	return 0;

}

int ConnectionMgr::OnSentMsgCallback(boost::system::error_code ec, std::size_t size)
{
	_sent_message_counter++;

	for (auto p = _list_message_handler.cbegin(); p != _list_message_handler.cend(); ++p)
	{
		(*p)->OnSentMsgCallback(ec, size);
	}
	return 0;
}

void ConnectionMgr::SendMsg(NetPackMsg * p_message)
{
	for (auto p = _list_session.cbegin(); p != _list_session.cend(); ++p)
	{
		p->get()->Deliver(p_message);
	}

#if _DEBUG
	std::cout << __FUNCTION__ << " : " << _sent_message_counter << " : " << std::endl;
	std::cout << std::string{ (const char*)p_message->Body() } << std::endl;
#endif

}


void ConnectionMgr::AddMsgListener(NetMsgCallback * callback)
{
	_list_message_handler.push_back(callback);
}
