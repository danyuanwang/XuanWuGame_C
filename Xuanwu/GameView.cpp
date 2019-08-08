#include "GameView.h"
#include"ErrorHandling.h"
#include"BoardView.h"
#include "GameEngine.h"
#include "Settings.h"
GameView::GameView(int x, int y, int container_x, int container_y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, container_x, container_y, width, height, margin_x, margin_y),
	_board_view(0, 0, x, y, GameSettings::WidthOfWindowX, GameSettings::HeightWindowY, GameSettings::MarginOfBoardX, GameSettings::MarginOfBoardY)
{

}


GameView::~GameView()
{
}


void GameView::Draw(const GameEngine *p_game_engine)
{
	//	CHECK_VALUE(m_pScreen != NULL, XW_ERROR_CODE::BD_SDL_SURFACE_NOT_INITED, "Please call 'Board::SetScreen' to set screen");
	_board_view.Draw(p_game_engine);
}

const BoardView * GameView::GetBoardView() const
{
	return &_board_view;
}

void GameView::Invalidate(const ModelObject *p_gamemodel)
{
	_board_view.Invalidate(static_cast<const GameModel*>(p_gamemodel)->GetBoard());

	BaseView::Invalidate(p_gamemodel);
}
