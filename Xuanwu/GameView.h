#pragma once
#include "GamePlayRequest.h"
#include "ConnectionMgr.h"
#include "GameEngine.h"
#include "BoardView.h"
class GameView: public BaseView
{

public:
	GameView(int x, int y, int width, int height, int margin_x, int margin_y);
	~GameView();
	void Draw(const GameEngine *p_game_engine) override;

	const BoardView* GetBoardView() const;

	void Invalidate(const ModelObject *p_gamemodel) override;

private:
	BoardView _board_view;
};

