#include "GameClient.h"
#include "GamePlayRequest.h"


GameClient::GameClient(GameEngine* pge, ConnectionMgr* pcmr) :
	mp_game_engine(pge), mp_connection_mgr(pcmr)
{
	up_gameModel = std::unique_ptr<GameModel>{ new GameModel() };
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

	/*<< END for test purpose*/


	switch (e.type)
	{
	case SDL_KEYDOWN:
	{ //Select surfaces based on key press 
		switch (e.key.keysym.sym)
		{
			case SDLK_UP:
			{
				mp_connection_mgr->SendMsg(up_netMsg.get());
				break;
			}
			case SDLK_DOWN:
			{
				mp_connection_mgr->SendMsg(up_netMsg.get());
				break;
			}
			case SDLK_LEFT:
			{
				mp_connection_mgr->SendMsg(up_netMsg.get());
				break;
			}
			case SDLK_RIGHT:
			{
				mp_connection_mgr->SendMsg(up_netMsg.get());
				break;
			}
			default:
			{
				break;
			}
		}
	}
	default:
	{
		break;
	}
	}
}

void GameClient::ProcessGameRequest(GamePlayRequest & gpr)
{
	switch (gpr.GetToType())
	{
		case GameOjbect_GameModel:
		{
			//up_gameModel->UpdateByJson();
			break;
		}
		default:
		{
			break;
		}
	}
}
