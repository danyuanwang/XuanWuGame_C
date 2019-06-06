#include "ShopView.h"



ShopView::ShopView(int x , int y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, width, height, margin_x, margin_y)
{
}


ShopView::~ShopView()
{
}

void ShopView::Draw(const GameEngine * p_game_engine)
{
	p_game_engine->RenderPic(_x, _y, _width, _height, "market.PNG");
}

void ShopView::Invalidate(const ModelObject * p_game_model)
{
	
}
