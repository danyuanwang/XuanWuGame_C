#include "MapView.h"
#include "Map.h"
#include "Settings.h"


MapView::MapView(int x, int y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, width, height, margin_x, margin_y)
{
}


MapView::~MapView()
{
}

void MapView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{

	_vector_cell.clear();
	_vector_mine.clear();

	const Map* p_map = static_cast<const Map*>(p_gamemodel);

	for (int i = 0; i < p_map->GetTotalCellNumber(); i++) {
		const Cell* p_cell = p_map->GetCell(i);
		int cell_index_col = p_cell->GetColIndex();
		int cell_index_row = p_cell->GetRowIndex();
		int cell_x = ((cell_index_col * (GameSettings::CellMarginX + GameSettings::CellWidth)))
			+ (_x);
		int cell_y = ((cell_index_row * (GameSettings::CellMarginY + GameSettings::CellHeight)))
			+ _y;
		CellView cellView(i, cell_x, cell_y, GameSettings::CellWidth, GameSettings::CellHeight, GameSettings::CellMarginX, GameSettings::CellMarginY);
		_vector_cell.push_back(cellView);
		cellView.Draw(p_map->GetCell(i), p_game_engine);
	}

	for (int i = 0; i < p_map->GetTotalMineNumber(); i++) {
		const Mine* p_mine = p_map->GetMine(i);
		int mine_index_col = p_mine->GetColIndex();
		int mine_index_row = p_mine->GetRowIndex();
		int mine_x = ((mine_index_col * (GameSettings::CellMarginX + GameSettings::CellWidth))+ GameSettings::MineMarginX )+ _x;
		int mine_y = ((mine_index_row * (GameSettings::CellMarginY + GameSettings::CellHeight)) + GameSettings::MineMarginY)+ _y;
		MineView mineView(i, mine_x, mine_y, GameSettings::Minewidth, GameSettings::MineHeight, GameSettings::MineMarginX, GameSettings::MineMarginY);
		_vector_mine.push_back(mineView);
		mineView.Draw(p_map->GetMine(i), p_game_engine);
	}

}
