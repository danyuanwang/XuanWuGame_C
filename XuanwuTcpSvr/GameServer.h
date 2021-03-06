#pragma once
#include <NetMsgCallback.h>
#include "ConnectionMgr.h"
#include "GameModel.h"
#include "ServerGameController.h"

class GameServer :
	public NetMsgCallback
{
private:
	std::unique_ptr<GameModel> _up_game_model;
	std::unique_ptr<ServerGameController> _up_game_controller;
	ConnectionMgr* _p_connectionMgr;

	void _notifyUpdate();
	void _processRequest(GamePlayRequest& gr);

public:
	GameServer();
	virtual ~GameServer();
	void BindConnection(ConnectionMgr* _p_onnectionMgr/*using ordinary pointer means no ownership*/);

	int OnReceivedMsgCallback(std::unique_ptr<NetPackMsg>  up_message);
	int OnReceivedMsgCallback(NetPackMsg*  up_message /*ordinary pointer means no ownership transfer*/);
	int OnSentMsgCallback(boost::system::error_code ec, std::size_t);
};

