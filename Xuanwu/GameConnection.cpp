#include "GameConnection.h"

std::unique_ptr<GameConnection> GameConnection::_ps_connection{ nullptr };
std::mutex GameConnection::_singleton_mutex;

GameConnection::GameConnection() :
	up_msp(new NetMsgPump())
{
	AddMsgListener(up_msp.get());

}


GameConnection::~GameConnection()
{
}

void GameConnection::SendContent(const char * content)
{
	auto up_netMsg = std::unique_ptr<NetPackMsg>(
		new NetPackMsg
		);
	up_netMsg->SetConent(content);

	SendMsg(up_netMsg.get());
}

bool GameConnection::PollMsg(std::unique_ptr<NetPackMsg> & up_msg)
{
	return up_msp->Poll(up_msg);
}

GameConnection * GameConnection::GetSingleton()
{
	if (_ps_connection.get() == nullptr)
	{
		std::unique_lock<std::mutex> lck(_singleton_mutex);
		if (_ps_connection.get() == nullptr)
		{
			_ps_connection = std::move(std::unique_ptr<GameConnection>{ new GameConnection() });
		}
	}
	return _ps_connection.get();
}
