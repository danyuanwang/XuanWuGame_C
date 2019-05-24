#include "GameView.h"
#include"ErrorHandling.h"
#include"BoardView.h"
#include "GameEngine.h"
#include "Settings.h"
GameView::GameView(int x, int y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, width, height, margin_x, margin_y), 
	_board_view(0, 0, GameSettings::WidthOfWindowX, GameSettings::HeightWindowY, GameSettings::MarginOfBoardX, GameSettings::MarginOfBoardY)
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