#include "MsgPump.h"

NetMsgPump::NetMsgPump() :
	_signal_quit_thread(true)
{
}


NetMsgPump::~NetMsgPump()
{
}

void NetMsgPump::Enqueue(std::unique_ptr<NetPackMsg> up_message)
{
	std::lock_guard<std::mutex> lck(_queue_mutex);
	_queue_net_msg.push(std::move(up_message));
	if (!_signal_quit_thread)
	{
		_queue_cond.notify_one();
	}
}

std::unique_ptr<NetPackMsg> NetMsgPump::Dequeue()
{
	std::lock_guard<std::mutex> lck(_queue_mutex);

	auto msg = std::move(_queue_net_msg.front());
	_queue_net_msg.pop();

	return std::move(msg);
}

bool NetMsgPump::Empty()
{
	std::lock_guard<std::mutex> lck(_queue_mutex);
	return _queue_net_msg.empty();
}

bool NetMsgPump::Poll(std::unique_ptr<NetPackMsg>& up_msg)
{
	bool result = false;
	std::lock_guard<std::mutex> lck(_queue_mutex);
	if (!_queue_net_msg.empty())
	{
		auto msg = std::move(_queue_net_msg.front());
		_queue_net_msg.pop();
		up_msg = std::move(msg);
		result = true;
	}
	return result;
}
void NetMsgPump::Close()
{
	std::lock_guard<std::mutex> lck(_queue_mutex);
	_signal_quit_thread = true;
	_queue_cond.notify_one();
	_thread_net_msg_consumer.join();
}

void NetMsgPump::_s_process_net_msg(NetMsgPump* p_msg_pump)
{
	p_msg_pump->_process_net_msg();
}

void NetMsgPump::_process_net_msg()
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

				for (auto p = _list_message_handler.cbegin(); p != _list_message_handler.cend(); ++p)
				{
					(*p)->OnReceivedMsgCallback(msg.get()/*using ordinary pointer not to transfer ownership*/);
				}

			}
		}
	}

}

void NetMsgPump::AddMsgListener(NetMsgCallback * callback)
{
	_list_message_handler.push_back(callback);

	if (_signal_quit_thread)
	{
		_signal_quit_thread = false;
		std::thread t{ _s_process_net_msg, this };
		_thread_net_msg_consumer = std::move(t);
	}

}

int NetMsgPump::OnReceivedMsgCallback(std::unique_ptr<NetPackMsg> up_message)
{
	Enqueue(std::move(up_message));

	return 0;
}

int NetMsgPump::OnReceivedMsgCallback(NetPackMsg * p_message)
{
	/*make a copy of the message*/
	auto up_msg = std::unique_ptr<NetPackMsg>(
		new NetPackMsg{ *p_message }
	);

	return OnReceivedMsgCallback(std::move(up_msg));
}

int NetMsgPump::OnSentMsgCallback(boost::system::error_code ec, std::size_t size)
{
	return 0;
}
