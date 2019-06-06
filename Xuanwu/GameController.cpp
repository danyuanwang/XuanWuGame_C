#include "GameController.h"
#include"GameView.h"


GameController::GameController(GameView* p_view, GameModel* p_model)
	:
	BaseController(p_view, p_model),
	_boardController(const_cast<BoardView*>(GetGameView()->GetBoardView()), const_cast<Board*>(GetGameModel()->GetBoard()))
{
	Invalidate();
}


GameController::~GameController()
{
}

const BoardController * GameController::GetBoardController() const
{
	return &_boardController;
}

bool GameController::HandleSdlEvent(SDL_Event & e)
{
	//pass down to board controller;
	return _boardController.HandleSdlEvent(e);
}

void GameController::Invalidate()
{
	BaseController::Invalidate();

	_boardController.Invalidate();
}

GameView * GameController::GetGameView() const
{
	return static_cast<GameView*>(_p_view);
}

GameModel * GameController::GetGameModel() const
{
	return static_cast<GameModel*>(_p_model);
}
