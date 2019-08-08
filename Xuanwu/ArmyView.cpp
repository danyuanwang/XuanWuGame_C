#include "ArmyView.h"
#include "Settings.h"



ArmyView::ArmyView(int index, int x, int y, int container_x, int container_y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, container_x,container_y, width, height, margin_x, margin_y)
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
	const Army* p_army = static_cast<const Army*>(p_game_model);
	_x = ConvertColToX(p_army->GetColIndex());
	_y = ConvertRowToY(p_army->GetRowIndex());
}

int ArmyView::GetIndex()
{
	return _index;
}

int ArmyView::ConvertColToX(int col)
{
	return ((col * (GameSettings::CellMarginX * 2 + GameSettings::CellWidth)) + GameSettings::MineMarginX) + _container_x;
}

int ArmyView::ConvertRowToY(int row)
{
	return ((row * (GameSettings::CellMarginY * 2 + GameSettings::CellHeight)) + GameSettings::MineMarginY) + _container_y;
}
