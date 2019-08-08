#include "BaseView.h"
#include "Logger.h"
BaseView::BaseView(int x, int y, int container_x, int container_y, int width, int height, int margin_x, int margin_y)
{
	_x = x;
	_y = y;
	_container_x = container_x;
	_container_y = container_y;
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
	bool result = ((mouse_x >= _x - _margin_x) && (mouse_x <= (_x + _width) + _margin_x) && (mouse_y >= _y - _margin_y) && (mouse_y <= (_y + _height) + _margin_y));
	LOGDEBUG("class:%s, mouse_x:%d, mouse_y:%d, _x:%d, _y:%d, _width:%d, _height:%d, _margin_x:%d, _margin_y:%d, result:%d",
	typeid(*this).name(), mouse_x, mouse_y, _x, _y, _width, _height, _margin_x, _margin_y, result);

	return result;
}

void BaseView::HighLight(bool high_lighted)
{
	_high_lighted = high_lighted;
}

void BaseView::Invalidate(const ModelObject *p_gamemodel)
{

}

int BaseView::ConvertColToX(int col)
{
	return ((col * (_margin_x * 2 + _width)) + _margin_x) + _container_x;
}

int BaseView::ConvertRowToY(int row)
{
	return ((row * (_margin_y * 2 + _height)) + _margin_y) + _container_y;
}
