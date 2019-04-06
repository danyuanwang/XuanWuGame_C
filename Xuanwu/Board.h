#pragma once
#include "GamePlayRequest.h"
#include "ConnectionMgr.h"
#include "GameEngine.h"

class Board
{
private:
	GameEngine* mp_game_engine = nullptr; // no ownership
	ConnectionMgr* mp_connection_mgr = nullptr;  // no ownership

public:
	Board(GameEngine* pge, ConnectionMgr* pcmr);
	~Board();
	void CheckSdlEvent(SDL_Event &e);
	void TakeRequest(GamePlayRequest &gpr);
	void Draw();
};

