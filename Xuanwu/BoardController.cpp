#include "BoardController.h"



BoardView * BoardController::GetBoardView() const
{
	return static_cast<BoardView*>(_p_view);
}

Board * BoardController::GetBoardModel() const
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
