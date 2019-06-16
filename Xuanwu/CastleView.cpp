#include "CastleView.h"



CastleView::CastleView(int index, int x, int y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, width, height, margin_x, margin_y)
{
	_index = index;
}


CastleView::~CastleView()
{
}

void CastleView::Draw(const GameEngine * p_game_engine)
{
	p_game_engine->RenderPic(_x, _y, _width, _height, "castle.PNG");
}

void CastleView::Invalidate(const ModelObject * p_game_model)
{
}

int CastleView::GetIndex()
{
	return _index;
}
