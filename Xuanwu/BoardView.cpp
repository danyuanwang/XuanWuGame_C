#include "BoardView.h"



BoardView::BoardView()
{
}


BoardView::~BoardView()
{
}

void BoardView::Draw(const GameModel &gamemodel)
{
	_map_view.Draw(gamemodel);
	_panel_view.Draw(gamemodel);
}
