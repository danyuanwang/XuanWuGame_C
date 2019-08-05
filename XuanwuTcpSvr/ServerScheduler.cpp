#include "ServerScheduler.h"
#include "GamePlayRequest.h"


ServerScheduler::ServerScheduler(NetMsgPump *p_msg_pump)
{
	_signal_quit_thread = true;
	_p_msg_pump = p_msg_pump;
}


ServerScheduler::~ServerScheduler()
{
	Stop();
	_p_msg_pump = nullptr;
}

void ServerScheduler::Start()
{
	if (_signal_quit_thread == true)
	{
		_signal_quit_thread = false;
		std::thread t{ _s_process_scheduler, this };
		_thread_scheduler = std::move(t);
	}
}

void ServerScheduler::Stop()
{
	if (_signal_quit_thread == false)
	{
		_signal_quit_thread = true;
		_thread_scheduler.join();
	}
}

void ServerScheduler::_s_process_scheduler(ServerScheduler * p_scheduler)
{
	p_scheduler->_process_scheduler();
}

void ServerScheduler::_process_scheduler()
{
	using namespace std::chrono_literals;
	while (_signal_quit_thread ==false)
	{
		std::this_thread::sleep_for(1s);
		if (_p_msg_pump != nullptr)
		{
			GamePlayRequest gr;
			gr.SetScenario(GameScenario_DataModel);
			gr.SetFromObject(GameObject_GameBoard);
			gr.SetToObject(GameObject_GameModel);
			gr.SetActionType(GameObjectAction_UpdateDataModel);

			std::unique_ptr<NetPackMsg> up_message{new NetPackMsg};
			up_message->SetConent(gr.ToJson().c_str());
			_p_msg_pump->Enqueue(std::move(up_message));
		}
	}
}
