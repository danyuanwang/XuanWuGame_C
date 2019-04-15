#include "BoardView.h"



BoardView::BoardView()
{
}


BoardView::~BoardView()
{
}

void BoardView::Draw(const ModelObject *p_gamemodel)
{
	_map_view.Draw(static_cast<const Board*>(p_gamemodel)->GetMap());
//	_panel_view.Draw(gamemodel);
}
