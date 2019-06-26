#include "ServerGameStateIdle.h"
#include"GameModel.h"

ServerGameStateIdle::ServerGameStateIdle()
{
}


ServerGameStateIdle::~ServerGameStateIdle()
{
}

void ServerGameStateIdle::HandleGameRequest(ServerBaseController * p_controller, GamePlayRequest & gpr)
{
	ServerGameController* p_game_controller = static_cast<ServerGameController*>(p_controller);
	switch (gpr.GetActionType())
	{
	case GameObjectAction_Restart:
	{
		GameModel *p_game_model = static_cast<GameModel*>(p_game_controller->_p_model);
		auto key = gpr.GetKeyValue("client_name").c_str();
		p_game_model->AddPlayer(key);
		p_game_controller->_map_serverplayercontroller[key] =
			std::move(std::unique_ptr<ServerPlayerController>{new ServerPlayerController(const_cast<Player*>(p_game_model->GetPlayer(key)))});
		break;
		//TODO: check if room is full
	}
	default:
	{
		break;
	}
	}

	ServerGameState::HandleGameRequest(p_controller, gpr);

}

