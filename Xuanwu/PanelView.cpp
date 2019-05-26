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

void PanelView::Invalidate(const ModelObject * p_gamemodel)
{
	Panel* p_panel = const_cast<Panel*>(static_cast<const Panel*>(p_gamemodel));

	BaseView::Invalidate(p_gamemodel);
	_action_view.Invalidate(p_panel->GetAction());
	_scale_view.Invalidate(p_panel->GetScale());
}

void PanelView::Draw(const GameEngine *p_game_engine)
{
	p_game_engine->DrawRect(_x, _y, _width, _height, GameSettings::PanelColor);
	_action_view.Draw(p_game_engine);
	_scale_view.Draw(p_game_engine);
}

PanelActionView * PanelView::GetActionView() const
{
	return const_cast<PanelActionView *>(&_action_view);
}

PanelScaleView * PanelView::GetScaleView() const
{
	return const_cast<PanelScaleView *>(&_scale_view);
}
