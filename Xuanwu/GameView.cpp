#include "GameView.h"
#include"ErrorHandling.h"
#include"BoardView.h"
GameView::GameView()
{

}


GameView::~GameView()
{
}


void GameView::Draw(const ModelObject *p_gamemodel)
{
//	CHECK_VALUE(m_pScreen != NULL, XW_ERROR_CODE::BD_SDL_SURFACE_NOT_INITED, "Please call 'Board::SetScreen' to set screen");
	_board_view.Draw(static_cast<const GameModel*>(p_gamemodel)->GetBoard());
}