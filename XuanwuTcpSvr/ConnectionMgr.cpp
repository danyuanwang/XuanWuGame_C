#include "ConnectionMgr.h"



ConnectionMgr::ConnectionMgr()
{
}


ConnectionMgr::~ConnectionMgr()
{
}

void ConnectionMgr::AddSession(tcp::socket socket)
{
	auto up_session = std::unique_ptr<ConnectionSession>(new ConnectionSession(std::move(socket)));
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
