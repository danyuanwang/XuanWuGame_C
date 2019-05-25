#include "BoardController.h"



BoardView * BoardController::GetBoardView()
{
	return static_cast<BoardView*>(_p_view);
}

Board * BoardController::GetBoardModel()
{
	return static_cast<Board*>(_p_model);
}

BoardController::BoardController(BoardView* p_view, Board* p_model) :
	BaseController(p_view, p_model)
{
}


BoardController::~BoardController()
{
}

bool BoardController::OnKeyUp(SDL_Event & e)
{
	return false;
}

bool BoardController::OnMouseMove(SDL_Event & e)
{
	return false;
}

bool BoardController::OnMouseButtonUp(SDL_Event & e)
{
	const BaseView* pview = GetBoardView()->GetMapView()->intercepts(e.button.x, e.button.y);

	return false;
}
