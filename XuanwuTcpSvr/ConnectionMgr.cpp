#include "ConnectionMgr.h"



ConnectionMgr::ConnectionMgr():_quit_thread(false)
{
	std::thread t { _consume_net_msg, this };

	_net_msg_consumer_thread = std::move(t);

}


ConnectionMgr::~ConnectionMgr()
{
}

void ConnectionMgr::AddSession(tcp::socket socket)
{
	auto up_session = std::unique_ptr<ConnectionSession>(new ConnectionSession(std::move(socket), this));
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

	std::lock_guard<std::mutex> lck(_queue_mutex);
	_quit_thread = true;
	_queue_cond.notify_one();
	_net_msg_consumer_thread.join();

}

int ConnectionMgr::OnReceivedMsgCallback(std::unique_ptr<NetPackMsg> up_message)
{
	std::lock_guard<std::mutex> lck(_queue_mutex);
	_queue_net_msg.push(std::move(up_message));
	_queue_cond.notify_one();

	return 0;
}

int ConnectionMgr::OnSentMsgCallback(boost::system::error_code ec, std::size_t)
{
	return 0;
}

void ConnectionMgr::_consume_net_msg(ConnectionMgr* p_connnectMgr)
{
	while (!p_connnectMgr->_quit_thread)
	{
		std::unique_lock<std::mutex> lck(p_connnectMgr->_queue_mutex);
		p_connnectMgr->_queue_cond.wait(lck);
		if (!p_connnectMgr->_quit_thread)
		{
			while (!p_connnectMgr->_queue_net_msg.empty())
			{
				auto msg = std::move(p_connnectMgr->_queue_net_msg.front());
				p_connnectMgr->_queue_net_msg.pop();

				//handle msg
				p_connnectMgr->_notify_client();
			}
		}
	}

}

void ConnectionMgr::_notify_client()
{

	for (auto p = _list_session.cbegin();p!=_list_session.cend();++p)
	{
		//p->get()->Deliver();
	}
}