#pragma once
#include <Vector>
#include <memory>
#include "ModelObject.h"
#include "GameModelCallback.h"
#include "GamePlayRequest.h"
#include "GameModel.h"
#include "Board.h"
#include "ConnectionMgr.h"
#include "Player.h"

class GameModel :
	public ModelObject, 
	public NetMsgCallback
{
private:
	void _notifyUpdate();

	std::unique_ptr<Board> up_game_board;

	ConnectionMgr* _p_connectionMgr;

	std::list<std::unique_ptr<Player>> _list_player; 


public:
	GameModel();
	~GameModel();

	const char* GetNameForPTree() const { return "GameModel"; }
	void TakeRequest(GamePlayRequest& request);
	ptree& GetPropertyTree(ptree& propert_tree);

	void BindConnection(ConnectionMgr* _p_onnectionMgr/*using ordinary pointer means no ownership*/);

	int OnReceivedMsgCallback(std::unique_ptr<NetPackMsg>  up_message);
	int OnReceivedMsgCallback(NetPackMsg*  up_message /*ordinary pointer means no ownership transfer*/);
	int OnSentMsgCallback(boost::system::error_code ec, std::size_t);


};

