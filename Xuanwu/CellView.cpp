#include "CellView.h"
#include "Settings.h"


CellView::CellView(int index, CellType cell_type, int x, int y, int width, int height, int margin_x, int margin_y)
	:BaseView(x, y, width, height, margin_x, margin_y),
	_index(index), 
	_cell_type(cell_type)
{
}


CellView::~CellView()
{
}

void CellView::Invalidate(const ModelObject * p_game_model)
{
	const Cell* p_cell = static_cast<const Cell*>(p_game_model);
	_cell_type = p_cell->GetCellType();

}

void CellView::Draw(const GameEngine *p_game_engine)
{
	p_game_engine->DrawRect(_x, _y, _width, _height, GameSettings::CellColorMap[_cell_type]);
}

int CellView::GetIndex() const
{
	return _index;
}
