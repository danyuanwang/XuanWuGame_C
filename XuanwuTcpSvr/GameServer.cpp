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
	gr.SetFromObject(GameOjbect_GameBoard);
	gr.SetToObject(GameOjbect_GameView);
	gr.SetActionType(GameOjbectAction_UpdateView);

	gr.AddChild(up_game_model->GetNameForPTree(), up_game_model->GetPropertyTree());

	NetPackMsg netMsg;
	if (netMsg.SetConent(gr.ToJson().c_str()) > 0)
	{
		_p_connectionMgr->SendMsg(&netMsg);
	}
}

void GameServer::_processRequest(GamePlayRequest& gpr)
{

	//switch (gpr.GetScenarioType())
	//{
	//default:
	//	break;
	//}

	/*for test purpse*/
	_notifyUpdate();
}