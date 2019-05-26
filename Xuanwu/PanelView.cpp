#include "PanelView.h"
#include "Settings.h"



PanelView::PanelView(int x, int y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, width, height, margin_x, margin_y),
	_action_view(x, y, width, height, margin_x, margin_y), //TODO:need to re-caculate
	_scale_view(x, y, width, height, margin_x, margin_y)  //TODO:need to re-caculate
{
}


PanelView::~PanelView()
{
}

void PanelView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{
	p_game_engine->DrawRect(_x, _y, _width, _height, GameSettings::PanelColor);
	//_action_view.Draw();
	//_scale_view.Draw();
}

PanelActionView * PanelView::GetActionView() const
{
	return const_cast<PanelActionView *>(&_action_view);
}

PanelScaleView * PanelView::GetScaleView() const
{
	return const_cast<PanelScaleView *>(&_scale_view);
}
