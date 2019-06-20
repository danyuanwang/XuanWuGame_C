#include "GameServer.h"

GameServer::GameServer()
{
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
	case  GameObjectAction_Restart:
	{
		if (up_game_model.get() == nullptr)
		{
			up_game_model = std::unique_ptr<GameModel>{ new GameModel() };
			Map* p_map = const_cast<Map*>(up_game_model->GetBoard()->GetMap());
			p_map->Reset();
		}

		up_game_model->AddPlayer(gpr.GetKeyValue("client_name").c_str());
		break;
	}
	case  GameObjectAction_BuildCastle:
	{
		int col = gpr.GetKeyValue<int>("col_index");
		int row = gpr.GetKeyValue<int>("row_index");

		Map* p_map = const_cast<Map*>(up_game_model->GetBoard()->GetMap());
		p_map->AddCastle(row, col);

		break;
	}
	default:
		break;
	}

	_notifyUpdate();
}