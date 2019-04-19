#include "BoardView.h"



BoardView::BoardView()
{
}


BoardView::~BoardView()
{
}

void BoardView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{
	_map_view.Draw(static_cast<const Board*>(p_gamemodel)->GetMap(), p_game_engine);
//	_panel_view.Draw(gamemodel);
}
