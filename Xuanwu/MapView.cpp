#include "MapView.h"
#include "Map.h"
#include "Settings.h"


MapView::MapView(int x, int y, int container_x, int container_y, int width, int height, int margin_x, int margin_y)
	: BaseView(x, y, container_x, container_y, width, height, margin_x, margin_y)
{
}


MapView::~MapView()
{
}

void MapView::Invalidate(const ModelObject * p_gamemodel)
{

	const Map* p_map = static_cast<const Map*>(p_gamemodel);

	int num_of_cell = p_map->GetTotalCellNumber();
	for (int i = 0; i < num_of_cell; i++) {
		const Cell* p_cell = p_map->GetCell(i);

		if (_vector_cell.size() <= i) 
		{//if the cell is added newly
			int cell_index_col = p_cell->GetColIndex();
			int cell_index_row = p_cell->GetRowIndex();
			int cell_x = ((cell_index_col * (GameSettings::CellMarginX*2 + GameSettings::CellWidth))+ GameSettings::CellMarginX) + _x;
			int cell_y = ((cell_index_row * (GameSettings::CellMarginY*2 + GameSettings::CellHeight)) + GameSettings::CellMarginY) + _y;
			std::unique_ptr<CellView> up_cellView{
				new CellView(
					i,
					p_cell->GetCellType(),
					cell_x, cell_y, _x, _y,
					GameSettings::CellWidth,
					GameSettings::CellHeight,
					GameSettings::CellMarginX,
					GameSettings::CellMarginY) };
			_vector_cell.push_back(std::move(up_cellView));
		}
		else
		{
			_vector_cell[i]->Invalidate(p_cell);
		}
	}

	for (int i = 0; i < p_map->GetTotalMineNumber(); i++) {
		const Mine* p_mine = p_map->GetMine(i);
		if (_vector_mine.size() <= i)
		{//if the cell is added newly
			int mine_index_col = p_mine->GetColIndex();
			int mine_index_row = p_mine->GetRowIndex();
			int mine_x = ((mine_index_col * (GameSettings::CellMarginX*2 + GameSettings::CellWidth)) + GameSettings::MineMarginX) + _x;
			int mine_y = ((mine_index_row * (GameSettings::CellMarginY*2 + GameSettings::CellHeight)) + GameSettings::MineMarginY) + _y;
			std::unique_ptr<MineView> up_mineView{ 
				new MineView(
					i, 
					p_mine->GetMineType(), 
					mine_x, 
					mine_y, 
					 _x, _y,
					GameSettings::MineWidth, 
					GameSettings::MineHeight, 
					GameSettings::MineMarginX, 
					GameSettings::MineMarginY) 
			};
			_vector_mine.push_back(std::move(up_mineView));
		}
		else
		{
			_vector_mine[i]->Invalidate(p_mine);
		}
	}

	const Shop* p_shop = p_map->GetShop();
	if (p_shop != nullptr) 
	{
		if (_up_shop.get() == nullptr)
		{
			int shop_index_col = p_shop->GetColIndex();
			int shop_index_row = p_shop->GetRowIndex();
			int shop_x = ((shop_index_col * (GameSettings::CellMarginX * 2 + GameSettings::CellWidth)) + GameSettings::MineMarginX) + _x;
			int shop_y = ((shop_index_row * (GameSettings::CellMarginY * 2 + GameSettings::CellHeight)) + GameSettings::MineMarginY) + _y;
			_up_shop = std::move(
				std::unique_ptr<ShopView>{
				new ShopView(
					shop_x,
					shop_y,
					_x, _y,
					GameSettings::MineWidth,
					GameSettings::MineHeight,
					GameSettings::MineMarginX,
					GameSettings::MineMarginY
				)
			});
		}
		else
		{
			_up_shop->Invalidate(p_shop);
		}
	}

	int num_of_castle = p_map->GetTotalCastleNumber();
	for (int i = 0; i < num_of_castle; i++) {
		const Castle* p_castle = p_map->GetCastle(i);

		if (_vector_castle.size() <= i)
		{//if the cell is added newly
			int castle_index_col = p_castle->GetColIndex();
			int castle_index_row = p_castle->GetRowIndex();
			int cell_x = ((castle_index_col * (GameSettings::CellMarginX * 2 + GameSettings::CellWidth)) + GameSettings::MineMarginX) + _x;
			int cell_y = ((castle_index_row * (GameSettings::CellMarginY * 2 + GameSettings::CellHeight)) + GameSettings::MineMarginY) + _y;
			std::unique_ptr<CastleView> up_castleView{
				new CastleView(
					i,
					cell_x,
					cell_y,
					 _x, _y,
					GameSettings::MineWidth,
					GameSettings::MineHeight,
					GameSettings::MineMarginX,
					GameSettings::MineMarginY)
			};
			_vector_castle.push_back(std::move(up_castleView));
		}
		else
		{
			_vector_castle[i]->Invalidate(p_castle);
		}
	}

	int num_of_army = p_map->GetTotalArmyNumber();
	for (int i = 0; i < num_of_army; i++) {
		const Army* p_army = p_map->GetArmy(i);

		if (_vector_army.size() <= i)
		{//if the cell is added newly
			int army_index_col = p_army->GetColIndex();
			int army_index_row = p_army->GetRowIndex();
			int cell_x = ((army_index_col * (GameSettings::CellMarginX * 2 + GameSettings::CellWidth)) + GameSettings::MineMarginX) + _x;
			int cell_y = ((army_index_row * (GameSettings::CellMarginY * 2 + GameSettings::CellHeight)) + GameSettings::MineMarginY) + _y;
			std::unique_ptr<ArmyView> up_armyView{
				new ArmyView(
					i,
					cell_x,
					cell_y,
					_x,
					_y,
					GameSettings::MineWidth,
					GameSettings::MineHeight,
					GameSettings::MineMarginX,
					GameSettings::MineMarginY)
			};
			_vector_army.push_back(std::move(up_armyView));
		}
		else
		{
			_vector_army[i]->Invalidate(p_army);
		}
	}
	BaseView::Invalidate(p_gamemodel);
}

void MapView::Draw(const GameEngine *p_game_engine)
{
	for (auto itr = _vector_cell.begin(); itr < _vector_cell.end(); itr++)
	{
		(*itr)->Draw(p_game_engine);
	}

	for (auto itr = _vector_mine.begin(); itr < _vector_mine.end(); itr++)
	{
		(*itr)->Draw(p_game_engine);
	}

	_up_shop->Draw(p_game_engine);

	for (auto itr = _vector_castle.begin(); itr < _vector_castle.end(); itr++)
	{
		(*itr)->Draw(p_game_engine);
	}
	for (auto itr = _vector_army.begin(); itr < _vector_army.end(); itr++) 
	{
		(*itr)->Draw(p_game_engine);
	}
}
