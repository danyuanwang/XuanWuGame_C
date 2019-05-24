#include "PanelView.h"
#include "Settings.h"



PanelView::PanelView(int x, int y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, width, height, margin_x, margin_y)
{
}


PanelView::~PanelView()
{
}

void PanelView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{
	p_game_engine->DrawRect(_x, _y, _width, _height, GameSettings::PanelColor);

}
