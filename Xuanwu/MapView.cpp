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

void MapView::Invalidate(const ModelObject * p_gamemodel)
{

	_vector_cell.clear();
	_vector_mine.clear();

	const Map* p_map = static_cast<const Map*>(p_gamemodel);

	for (int i = 0; i < p_map->GetTotalCellNumber(); i++) {
		const Cell* p_cell = p_map->GetCell(i);
		int cell_index_col = p_cell->GetColIndex();
		int cell_index_row = p_cell->GetRowIndex();
		int cell_x = ((cell_index_col * (GameSettings::CellMarginX + GameSettings::CellWidth))) + _x;
		int cell_y = ((cell_index_row * (GameSettings::CellMarginY + GameSettings::CellHeight))) + _y;
		CellView cellView(i, p_cell->GetCellType(), cell_x, cell_y, GameSettings::CellWidth, GameSettings::CellHeight, GameSettings::CellMarginX, GameSettings::CellMarginY);
		_vector_cell.push_back(cellView);
	}

	for (int i = 0; i < p_map->GetTotalMineNumber(); i++) {
		const Mine* p_mine = p_map->GetMine(i);
		int mine_index_col = p_mine->GetColIndex();
		int mine_index_row = p_mine->GetRowIndex();
		int mine_x = ((mine_index_col * (GameSettings::CellMarginX + GameSettings::CellWidth)) + GameSettings::MineMarginX) + _x;
		int mine_y = ((mine_index_row * (GameSettings::CellMarginY + GameSettings::CellHeight)) + GameSettings::MineMarginY) + _y;
		MineView mineView(i, p_mine->GetMineType(), mine_x, mine_y, GameSettings::Minewidth, GameSettings::MineHeight, GameSettings::MineMarginX, GameSettings::MineMarginY);
		_vector_mine.push_back(mineView);
	}
	const Shop* p_shop = p_map->GetShop();
	int shop_index_col = p_shop->get_col_index();
	int shop_index_row = p_shop->get_row_index();
	int shop_x = ((shop_index_col * (GameSettings::CellMarginX + GameSettings::CellWidth)) + GameSettings::MineMarginX) + _x;
	int shop_y = ((shop_index_row * (GameSettings::CellMarginY + GameSettings::CellHeight)) + GameSettings::MineMarginY) + _y;
	_up_shop = std::move(
		std::unique_ptr<ShopView>{
		new ShopView(
			shop_x,
			shop_y,
			GameSettings::Minewidth,
			GameSettings::MineHeight,
			GameSettings::MineMarginX,
			GameSettings::MineMarginY
		)
	});
	BaseView::Invalidate(p_gamemodel);

}

void MapView::Draw(const GameEngine *p_game_engine)
{
	for (auto itr = _vector_cell.begin(); itr < _vector_cell.end(); itr++)
	{
		itr->Draw(p_game_engine);
	}

	for (auto itr = _vector_mine.begin(); itr < _vector_mine.end(); itr++)
	{
		itr->Draw(p_game_engine);
	}
	_up_shop->Draw(p_game_engine);

}
