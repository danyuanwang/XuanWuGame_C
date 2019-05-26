#include "BaseView.h"
BaseView::BaseView(int x, int y, int width, int height, int margin_x, int margin_y)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_margin_x = margin_x;
	_margin_y = margin_y;

	_high_lighted = false;
}


BaseView::~BaseView()
{
}

bool BaseView::intercepts(int mouse_x, int mouse_y) const
{
	return ((mouse_x > _x) && (mouse_x < (_x + _width)) && (mouse_y > _y) && (mouse_y < (_y + _height)));
}

void BaseView::HighLight(bool high_lighted)
{
	_high_lighted = high_lighted;
}

void BaseView::Invalidate(const ModelObject *p_gamemodel)
{

}
