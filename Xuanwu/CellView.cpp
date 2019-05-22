#include "CellView.h"
#include "Settings.h"


CellView::CellView(int index) :
	_index(index)
{
}


CellView::~CellView()
{
}

void CellView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{
	

	const Cell* p_cell = static_cast<const Cell*>(p_gamemodel);
	CellType cell_type = p_cell->GetCellType();
	int  cell_index_col = p_cell->GetColIndex();
	int cell_index_row = p_cell->GetRowIndex();
	int cell_x = cell_index_col * (GameSettings::CellMarginX + GameSettings::CellWidth) + (GameSettings::MarginOfBoardX + GameSettings::PanelWidth);
	int cell_y = cell_index_row * (GameSettings::CellMarginY + GameSettings::CellHeight) + GameSettings::MarginOfBoardY;
	p_game_engine->DrawRect(cell_x, cell_y, GameSettings::CellWidth, GameSettings::CellHeight, GameSettings::CellColorMap[cell_type]);

	

}
