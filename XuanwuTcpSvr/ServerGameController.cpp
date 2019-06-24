#include "ServerGameController.h"
#include "GameModel.h"



ServerGameController::ServerGameController(ModelObject* p_model)
	: ServerBaseController(p_model)
{
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
	switch (gpr.GetActionType())
	{
		case GameObjectAction_Restart:
		{
			GameModel *p_game_model = static_cast<GameModel*>(_p_model);
			p_game_model->AddPlayer(gpr.GetKeyValue("client_name").c_str());
			break;
			//TODO: check if room is full
		}
	}

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

const std::map< std::string, std::unique_ptr<ServerPlayerController> >* ServerGameController::GetServerPlayerControllers() const
{
	return &_map_serverplayercontroller;
}
