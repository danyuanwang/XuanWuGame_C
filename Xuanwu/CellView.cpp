#include "CellView.h"
#include "Settings.h"


CellView::CellView(int index, int x, int y, int width, int height, int margin_x, int margin_y)
	:BaseView(x, y, width, height, margin_x, margin_y), _index(index)
{
}


CellView::~CellView()
{
}

void CellView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{
	

	const Cell* p_cell = static_cast<const Cell*>(p_gamemodel);
	CellType cell_type = p_cell->GetCellType();
	p_game_engine->DrawRect(_x, _y, _width, _height, GameSettings::CellColorMap[cell_type]);

	

}

int CellView::GetIndex() const
{
	return _index;
}
