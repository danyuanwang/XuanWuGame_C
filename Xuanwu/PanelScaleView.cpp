#include "PanelScaleView.h"
#include "PanelScale.h"
#include "Settings.h"

PanelScaleView::PanelScaleView(int x, int y, int width, int height, int margin_x, int margin_y):
	BaseView(x, y, width, height, margin_x, margin_y),
	_background_color(0)
{
}


PanelScaleView::~PanelScaleView()
{
}

void PanelScaleView::Invalidate(const ModelObject * p_gamemodel)
{
	BaseView::Invalidate(p_gamemodel);
	const PanelScale* p_scale = static_cast<const PanelScale*>(p_gamemodel);
	_background_color = GameSettings::CellColorMap[p_scale->GetCellType()];

}

void PanelScaleView::Draw(const GameEngine * p_game_engine)
{
	p_game_engine->DrawRect(_x, _y, _width, _height, _background_color);
	p_game_engine->RenderText("hello world",XW_RGB_Color(XW_Color_Value::RED));
}
