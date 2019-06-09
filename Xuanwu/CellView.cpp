#include "CellView.h"
#include "Settings.h"
#include "Logger.h"

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

bool CellView::intercepts(int mouse_x, int mouse_y) const
{
	bool result = ((mouse_x > _x) && (mouse_x < (_x + _width)) && (mouse_y > _y) && (mouse_y < (_y + _height)));

	LOGDEBUG("class:%s, mouse_x:%d, mouse_y:%d, _x:%d, _y:%d, _width:%d, _height:%d, _margin_x:%d, _margin_y:%d, result:%d",
		typeid(*this).name(), mouse_x, mouse_y, _x, _y, _width, _height, _margin_x, _margin_y, result);

	return result;
}

void CellView::Draw(const GameEngine *p_game_engine)
{
	p_game_engine->DrawRect(_x, _y, _width, _height, GameSettings::CellColorMap[_cell_type]);
}

int CellView::GetIndex() const
{
	return _index;
}
