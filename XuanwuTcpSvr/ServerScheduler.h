#pragma once
#include <thread>
#include"MsgPump.h"

class ServerScheduler
{
public:
	ServerScheduler(NetMsgPump* p_msg_pump);
	virtual ~ServerScheduler();
	void Start();
	void Stop();
private:
	std::thread _thread_scheduler;
	bool _signal_quit_thread;
	NetMsgPump* _p_msg_pump;

	static void _s_process_scheduler(ServerScheduler *p_scheduler);
	void _process_scheduler();
};

