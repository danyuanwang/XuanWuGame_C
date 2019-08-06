#include "ArmyView.h"



ArmyView::ArmyView(int index, int x, int y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, width, height, margin_x, margin_y)
{
	_index = index;
}



ArmyView::~ArmyView()
{
}

void ArmyView::Draw(const GameEngine * p_game_engine)
{
	p_game_engine->RenderPic(_x, _y, _width, _height, "army.PNG");
}

void ArmyView::Invalidate(const ModelObject * p_game_model)
{
}

int ArmyView::GetIndex()
{
	return _index;
}
