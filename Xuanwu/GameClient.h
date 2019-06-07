#pragma once
#include "GameEngine.h"
#include "ConnectionMgr.h"
#include "GameModel.h"
#include "GameView.h"
#include "GameController.h"

class GameClient
{
private:
	GameEngine* mp_game_engine = nullptr; // no ownership
	ConnectionMgr* mp_connection_mgr = nullptr;  // no ownership
	std::unique_ptr<GameModel> up_gameModel;
	std::unique_ptr<GameView> up_gameView;
	std::unique_ptr<GameController> up_gameController;

public:
	GameClient(GameEngine* pge, ConnectionMgr* pcmr);
	~GameClient();

	void CheckSdlEvent(SDL_Event &e);
	void ProcessGameRequest(GamePlayRequest& gpr);

	void Start();
};

