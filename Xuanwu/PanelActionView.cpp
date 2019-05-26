#include "PanelActionView.h"



PanelActionView::PanelActionView(int x, int y, int width, int height, int margin_x, int margin_y) :
	BaseView(x, y, width, height, margin_x, margin_y)
{
}


PanelActionView::~PanelActionView()
{
}

void PanelActionView::Invalidate(const ModelObject * p_gamemodel)
{
	BaseView::Invalidate(p_gamemodel);
}

void PanelActionView::Draw(const GameEngine * p_game_engine)
{

}
