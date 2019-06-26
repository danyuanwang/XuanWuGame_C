#include "ServerGameController.h"
#include "GameModel.h"
#include"ServerGameStateIdle.h"


ServerGameController::ServerGameController(ModelObject* p_model)
	: ServerBaseController(p_model)
{
	_state_value = idle;

	_state_machine[idle] = std::move(std::unique_ptr<ServerGameState>{new ServerGameStateIdle});

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

	_state_machine[_state_value]->HandleGameRequest(this, gpr);

	_up_serverboardcontroller->HandleGameRequest(gpr);

	for (auto itr = _map_serverplayercontroller.begin(); itr != _map_serverplayercontroller.end(); itr++)
	{
		itr->second->HandleGameRequest(gpr);
	}
}

const ServerBoardController * ServerGameController::GetServerBoardController() const
{
	return _up_serverboardcontroller.get();
}

void ServerGameController::_change_state()
{
	switch (_state_value)
	{
		case idle:
		{
			//check the conditions to determine if change to next state and to what state.
			break;
		}
		default:
		{
			//TODO:log errors
			break;
		}
	}
}

