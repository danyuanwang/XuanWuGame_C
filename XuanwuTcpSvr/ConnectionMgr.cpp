#include "ConnectionMgr.h"



ConnectionMgr::ConnectionMgr():_signal_quit_thread(false)
{
	_up_gameModel = std::unique_ptr<GameModel>{ new GameModel };

	std::thread t { _s_process_net_msg, this };

	_thread_net_msg_consumer = std::move(t);

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
	_signal_quit_thread = true;
	_queue_cond.notify_one();
	_thread_net_msg_consumer.join();

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

int ConnectionMgr::OnGameModelObserverCallback()
{
	GamePlayRequest gr{ GameScenario_DataModel , GameOjbect_GameBoard , GameOjbect_GameView , GameOjbectAction_UpdateView };

	ptree property_tree;
	_up_gameModel->GetPropertyTree(property_tree);
	gr.Attach(_up_gameModel->GetClassName(), property_tree);

	NetPackMsg netMsg{ gr.ToJson().c_str() };
	for (auto p = _list_session.cbegin(); p != _list_session.cend(); ++p)
	{
		p->get()->Deliver(&netMsg);
	}

	return 0;
}

void ConnectionMgr::_s_process_net_msg(ConnectionMgr* p_connnectMgr)
{
	p_connnectMgr->_process_net_msg();
}

void ConnectionMgr::_process_net_msg()
{
	while (!_signal_quit_thread)
	{
		std::unique_lock<std::mutex> lck(_queue_mutex);
		_queue_cond.wait(lck);
		if (!_signal_quit_thread)
		{
			while (!_queue_net_msg.empty())
			{
				auto msg = std::move(_queue_net_msg.front());
				_queue_net_msg.pop();

				GamePlayRequest gr {(char*)msg->Data() };
				_up_gameModel->TakeRequest(gr);

			}
		}
	}

}
