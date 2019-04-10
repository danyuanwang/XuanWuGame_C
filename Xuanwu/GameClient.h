#pragma once
#include "GameEngine.h"
#include "ConnectionMgr.h"
#include "GameModel.h"

class GameClient
{
private:
	GameEngine* mp_game_engine = nullptr; // no ownership
	ConnectionMgr* mp_connection_mgr = nullptr;  // no ownership
	std::unique_ptr<GameModel> up_gameModel;

public:
	GameClient(GameEngine* pge, ConnectionMgr* pcmr);
	~GameClient();

	void CheckSdlEvent(SDL_Event &e);
	void ProcessGameRequest(GamePlayRequest& gpr);
};

