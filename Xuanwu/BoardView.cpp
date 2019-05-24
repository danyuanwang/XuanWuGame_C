#include "BoardView.h"
#include "Settings.h"


BoardView::BoardView(int x, int y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, width, height, margin_x, margin_y),
	_map_view(x + (margin_x + GameSettings::PanelWidth) ,y + (margin_y), GameSettings::MapWidth, GameSettings::MapHeight, 0, 0),
	_panel_view(x + (margin_x), y + margin_y, GameSettings::PanelWidth, GameSettings::PanelHeight, 0, 0)
{
}


BoardView::~BoardView()
{
}

void BoardView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{
	_map_view.Draw(static_cast<const Board*>(p_gamemodel)->GetMap(), p_game_engine);
	_panel_view.Draw(p_gamemodel, p_game_engine);
}
