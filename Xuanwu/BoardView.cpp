#include "BoardView.h"
#include "Settings.h"


BoardView::BoardView(int x, int y, int container_x, int container_y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, container_x, container_y, width, height, margin_x, margin_y),
	_map_view(x + (margin_x + GameSettings::PanelWidth), y + (margin_y), x, y, GameSettings::MapWidth, GameSettings::MapHeight, 0, 0),
	_panel_view(x + (margin_x), y + margin_y, x, y, GameSettings::PanelWidth, GameSettings::PanelHeight, GameSettings::PanelMarginX, GameSettings::PanelMarginY)
{
}


BoardView::~BoardView()
{
}

void BoardView::Draw(const GameEngine *p_game_engine)
{
	_map_view.Draw( p_game_engine);
	_panel_view.Draw( p_game_engine);
}

const MapView * BoardView::GetMapView() const
{
	return &_map_view;
}

const PanelView * BoardView::GetPanelView() const
{
	return &_panel_view;
}

void BoardView::Invalidate(const ModelObject * p_game_model)
{
	const Board* p_board = static_cast<const Board*>(p_game_model);

	_map_view.Invalidate(p_board->GetMap());
	_panel_view.Invalidate(p_board->GetPanel());

	BaseView::Invalidate(p_game_model);
}
