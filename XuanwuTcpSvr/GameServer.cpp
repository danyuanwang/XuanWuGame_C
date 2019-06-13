#include "GameServer.h"

GameServer::GameServer()
{
	up_game_model = std::unique_ptr<GameModel>{ new GameModel() };
}


GameServer::~GameServer()
{
}

void GameServer::BindConnection(ConnectionMgr * p_onnectionMgr)
{
	_p_connectionMgr = p_onnectionMgr;
}

int GameServer::OnReceivedMsgCallback(std::unique_ptr<NetPackMsg> up_message)
{
	return OnReceivedMsgCallback(up_message.get());
}

int GameServer::OnReceivedMsgCallback(NetPackMsg * p_message)
{
	GamePlayRequest gpr = GamePlayRequest{ p_message->GetContent() };
	_processRequest(gpr);

	return 0;
}

int GameServer::OnSentMsgCallback(boost::system::error_code ec, std::size_t)
{
	return 0;
}

void GameServer::_notifyUpdate()
{
	GamePlayRequest gr;
	gr.SetScenario(GameScenario_DataModel);
	gr.SetFromObject(GameObject_GameBoard);
	gr.SetToObject(GameObject_GameModel);
	gr.SetActionType(GameObjectAction_UpdateView);

	gr.AddChild(up_game_model->GetNameForPTree(), up_game_model->GetPropertyTree());

	NetPackMsg netMsg;
	if (netMsg.SetConent(gr.ToJson().c_str()) > 0)
	{
		_p_connectionMgr->SendMsg(&netMsg);
	}
}

void GameServer::_processRequest(GamePlayRequest& gpr)
{

	switch (gpr.GetActionType())
	{
		case  GameObjectAction_BuildCastle:
		{
			int col = gpr.GetKeyValue<int>("col_index");
			int row = gpr.GetKeyValue<int>("row_index");
			break;
		}
	default:
	break;
	}

	_notifyUpdate();
}