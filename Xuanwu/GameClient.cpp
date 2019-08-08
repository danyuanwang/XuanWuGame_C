#include "GameClient.h"
#include "GamePlayRequest.h"
#include "GameConnection.h"
#include "RestartCommand.h"
GameClient::GameClient(GameEngine* pge) :
	mp_game_engine(pge)
{
	up_gameModel = std::move(std::unique_ptr<GameModel>{  new GameModel() });

	up_gameView = std::move(std::unique_ptr<GameView>{ new GameView(0, 0, 0, 0, 0, 0, 0, 0) });

	up_gameController = std::move(std::unique_ptr<GameController>{ new GameController(up_gameView.get(), up_gameModel.get()) });

}


GameClient::~GameClient()
{

}

void GameClient::CheckSdlEvent(SDL_Event & e)
{
	if (up_gameController->HandleSdlEvent(e))
	{
		up_gameController->Invalidate();
		up_gameView->Draw(mp_game_engine);
	}

}

void GameClient::ProcessGameRequest(GamePlayRequest & gpr)
{
	switch (gpr.GetToType())
	{
	case GameObject_GameView:
	{
		break;
	}
	case GameObject_GameBoard:
	case GameObject_GameModel:
	{
		ptree property_tree = gpr.GetChild(up_gameModel->GetNameForPTree());
		up_gameModel->UpdateByPropertyTree(property_tree);
		break;
	}
	default:
	{
		break;
	}
	}

	up_gameController->Invalidate();
	up_gameView->Draw(mp_game_engine);
}

void GameClient::Start()
{
	RestartCommand restart_command;
	restart_command.Execute();
}
