#pragma once
#include <Vector>
#include <memory>
#include "ModelObject.h"
#include "GameModelCallback.h"
#include "GamePlayRequest.h"
#include "GameModel.h"
#include "Board.h"
#include "ConnectionMgr.h"

class GameModel:public ModelObject, public NetMsgCallback
{
private:
	void _notifyUpdate();

	Board _gameBoard;

	ConnectionMgr* _p_connectionMgr;

public:
	GameModel();
	~GameModel();

	const char* GetClassName() const  { return "GameModel"; }
	void TakeRequest(GamePlayRequest& request);
	void GetPropertyTree(ptree& propert_tree) const;

	void BindConnection(ConnectionMgr* _p_onnectionMgr/*using ordinary pointer means no ownership*/);

	int OnReceivedMsgCallback(std::unique_ptr<NetPackMsg>  up_message) ;
	int OnReceivedMsgCallback(NetPackMsg*  up_message /*ordinary pointer means no ownership transfer*/);
	int OnSentMsgCallback(boost::system::error_code ec, std::size_t);


};

