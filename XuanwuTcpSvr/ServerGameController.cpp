#include "ServerGameController.h"
#include "GameModel.h"


ServerGameController::ServerGameController(ModelObject* p_model)
	: ServerBaseController(p_model)
{
	_state_value = idle;

	const GameModel *p_game_model = static_cast<GameModel*>(p_model);
	_up_serverboardcontroller = std::move(std::unique_ptr<ServerBoardController>{ new ServerBoardController(const_cast<Board*>(p_game_model->GetBoard())) });

	const std::map<std::string, std::unique_ptr<Player>> * p_map_players = p_game_model->GetPlayers();
	for (auto itr = p_map_players->cbegin(); itr != p_map_players->cend(); itr++)
	{
		_map_serverplayercontroller[itr->first] = std::move(std::unique_ptr<ServerPlayerController>{new ServerPlayerController(const_cast<Player*>(itr->second.get()))});
	}
}


ServerGameController::~ServerGameController()
{
}

void ServerGameController::HandleGameRequest(GamePlayRequest & gpr)

{
	bool ignore_castle_build_request = true;
	switch (_state_value)
	{
	case ServerGameController::idle:
	{
		switch (gpr.GetActionType())
		{
		case GameObjectAction_Restart:
		{
			GameModel *p_game_model = static_cast<GameModel*>(_p_model);
			auto key = gpr.GetKeyValue("client_name");
			p_game_model->AddPlayer(key.c_str());
			_map_serverplayercontroller[key] =
				std::move(std::unique_ptr<ServerPlayerController>{new ServerPlayerController(const_cast<Player*>(p_game_model->GetPlayer(key.c_str())))});
			break;
			//TODO: check if room is full
		}
		default:
		{
			break;
		}
		}
		break;
	}
	case ServerGameController::build_castle:
	{
		
		switch (gpr.GetActionType())
		{
		case GameObjectAction_BuildCastle:
		{
			
			auto key = gpr.GetKeyValue("client_name");
			GameModel *p_game_model = static_cast<GameModel*>(_p_model);
			const Map* p_map_model = p_game_model->GetBoard()->GetMap();
			if (p_map_model->GetTotalPlayerCastleNumber(key.c_str()) < 1)
			{
				ignore_castle_build_request = false;
			}

			break;
			//TODO: check if room is full
		}
		default:
		{
			break;
		}
		}
		break;
	}
	default:
		break;
	}

	if (ignore_castle_build_request == false) {
		_up_serverboardcontroller->HandleGameRequest(gpr);
	}
	

	for (auto itr = _map_serverplayercontroller.begin(); itr != _map_serverplayercontroller.end(); itr++)
	{
		itr->second->HandleGameRequest(gpr);
	}

	_change_state();
}

const ServerBoardController * ServerGameController::GetServerBoardController() const
{
	return _up_serverboardcontroller.get();
}

void ServerGameController::_change_state()
{
	GameModel*p_game_model = static_cast<GameModel*>(_p_model);
	switch (_state_value)
	{
	case idle:
	{
		
		if ((p_game_model)->GetPlayerNumber() == 2){ //change the 2 to a 4 later
			_state_value = build_castle;
		}
		//check the conditions to determine if change to next state and to what state.
		break;
	}
	case build_castle:
	{
		bool players_done = true;
		for (auto itr = p_game_model->GetPlayers()->cbegin(); itr != p_game_model->GetPlayers()->cend(); itr++) 
		{
			if (p_game_model->GetBoard()->GetMap()->GetTotalPlayerCastleNumber((itr)->first.c_str()) < 1) {
				players_done = false;
				break;
			}
		}
		if (players_done == true) {
			_state_value = playing;
		}
	}
	default:
	{
		//TODO:log errors
		break;
	}
	}
}

