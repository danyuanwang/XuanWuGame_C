#include "GameClient.h"
#include "GamePlayRequest.h"


GameClient::GameClient(GameEngine* pge, ConnectionMgr* pcmr) :
	mp_game_engine(pge), mp_connection_mgr(pcmr)
{
	up_gameModel = std::unique_ptr<GameModel>{ new GameModel() };
	up_gameView = std::unique_ptr<GameView>{ new GameView() };
	up_gameController = std::unique_ptr<GameController>{ new GameController() };
}


GameClient::~GameClient()
{

}

void GameClient::CheckSdlEvent(SDL_Event & e)
{
	/*for test purpose START >>*/
	auto up_gpr = std::unique_ptr<GamePlayRequest>(
		new GamePlayRequest
		);

	up_gpr->SetScenario(GameScenario_GameBoard);
	up_gpr->SetFromObject(GameOjbect_GameView);
	up_gpr->SetToObject(GameOjbect_GameBoard);
	up_gpr->SetActionType(GameOjbectAction_Restart);

	auto up_netMsg = std::unique_ptr<NetPackMsg>(
		new NetPackMsg
		);
	up_netMsg->SetConent(up_gpr->ToJson().c_str());
	mp_connection_mgr->SendMsg(up_netMsg.get());

	/*<< END for test purpose*/

	up_gameController->CheckSdlEvent(e);

	up_gameView->Draw(up_gameModel.get());

}

void GameClient::ProcessGameRequest(GamePlayRequest & gpr)
{
	switch (gpr.GetToType())
	{
		case GameOjbect_GameView:
		{
			break;
		}
		case GameOjbect_GameBoard:
		case GameOjbect_GameModel:
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

	up_gameView->Draw(up_gameModel.get());
}
