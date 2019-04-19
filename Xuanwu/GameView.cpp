#include "GameView.h"
#include"ErrorHandling.h"
#include"BoardView.h"
#include "GameEngine.h"
GameView::GameView()
{

}


GameView::~GameView()
{
}


void GameView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{
//	CHECK_VALUE(m_pScreen != NULL, XW_ERROR_CODE::BD_SDL_SURFACE_NOT_INITED, "Please call 'Board::SetScreen' to set screen");
	_board_view.Draw(static_cast<const GameModel*>(p_gamemodel)->GetBoard(), p_game_engine);
}