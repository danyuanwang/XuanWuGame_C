#pragma once
#include "GamePlayRequest.h"
#include "ConnectionMgr.h"
#include "GameEngine.h"
#include "BoardView.h"
class GameView: public BaseView
{

public:
	GameView();
	~GameView();
	void Draw(const GameModel &gamemodel);
private:
	BoardView _board_view;
};

