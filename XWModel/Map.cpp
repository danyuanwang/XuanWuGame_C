#include "Map.h"
#define MAP_NUM_OF_COL 20
#define MAP_NUM_OF_ROW 16

static const CellType mapdata[MAP_NUM_OF_ROW][MAP_NUM_OF_COL] = {
		{CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Ice},
		{CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Mountain, CellType_Mountain, CellType_Forest, CellType_Forest, CellType_Forest, CellType_River, CellType_Forest, CellType_Forest, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Ice, CellType_Water, CellType_Ice},
		{CellType_Water, CellType_Water, CellType_Mountain, CellType_Ice, CellType_Water, CellType_Water, CellType_Grass, CellType_Mountain, CellType_Forest, CellType_Forest, CellType_River, CellType_River, CellType_Forest, CellType_Forest, CellType_Water, CellType_Water, CellType_Water, CellType_Ice, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Mountain, CellType_Water, CellType_Water, CellType_Water, CellType_Grass, CellType_Mountain, CellType_Forest, CellType_Forest, CellType_Forest, CellType_River, CellType_River, CellType_Forest, CellType_Ice, CellType_Water, CellType_Ice, CellType_Ice, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Mountain, CellType_Water, CellType_Water, CellType_Water, CellType_Grass, CellType_Mountain, CellType_Forest, CellType_Forest, CellType_Forest, CellType_River, CellType_River, CellType_Ice, CellType_Ice, CellType_Ice, CellType_Ice, CellType_Ice, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Ice, CellType_Mountain, CellType_Ice, CellType_Mountain, CellType_Mountain, CellType_Forest, CellType_Forest, CellType_Forest, CellType_Forest, CellType_Forest, CellType_River, CellType_Ice, CellType_Ice, CellType_Ice, CellType_Ice, CellType_Ice, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Water, CellType_Ice, CellType_Ice, CellType_Mountain, CellType_Mountain, CellType_Forest, CellType_Forest, CellType_Forest, CellType_Grass, CellType_Forest, CellType_River, CellType_River, CellType_Ice, CellType_Ice, CellType_Ice, CellType_Ice, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Water, CellType_Grass, CellType_Mountain, CellType_Mountain, CellType_Forest, CellType_Forest, CellType_Forest, CellType_Forest, CellType_Grass, CellType_Grass, CellType_Grass, CellType_River, CellType_Grass, CellType_Ice, CellType_Ice, CellType_Ice, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Water, CellType_Ice, CellType_Ice, CellType_Grass, CellType_Grass, CellType_Grass, CellType_Grass, CellType_Grass, CellType_Grass, CellType_Grass, CellType_River, CellType_River, CellType_River, CellType_River, CellType_Water, CellType_Water, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Water, CellType_Ice, CellType_Mountain, CellType_Mountain, CellType_Grass, CellType_Grass, CellType_Grass, CellType_Grass, CellType_Grass, CellType_River, CellType_River, CellType_Grass, CellType_Grass, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Ice, CellType_Mountain, CellType_Mountain, CellType_Grass, CellType_Grass, CellType_Grass, CellType_River, CellType_River, CellType_Grass, CellType_Grass, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Mountain, CellType_Ice, CellType_Mountain, CellType_Grass, CellType_Grass, CellType_Grass, CellType_River, CellType_Grass, CellType_Mountain, CellType_Mountain, CellType_Water, CellType_Water, CellType_Ice, CellType_Water, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Mountain, CellType_Mountain, CellType_Mountain, CellType_Grass, CellType_Grass, CellType_River, CellType_Mountain, CellType_Mountain, CellType_Water, CellType_Water, CellType_Water, CellType_Ice, CellType_Ice, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Mountain, CellType_Mountain, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water},
		{CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water, CellType_Water}

};

void Map::_generate_mines(std::vector<int> &cell_list, int number_of_mines, MineType minetype)
{
	while (number_of_mines > 0)
	{

		int index_selected_cell = _rand_in_range(0, (int)cell_list.size() - 1);
		int cell_index = cell_list[index_selected_cell];
		int row_index = (cell_index / _num_of_col);
		int col_index = cell_index % _num_of_col;
		MineType mine_type = minetype;
		number_of_mines--;
		auto up_mine = std::unique_ptr<Mine>(
			new Mine(row_index, col_index, _list_cell[cell_index]->GetCellType(), mine_type)
			);

		_list_mine.push_back(std::move(up_mine));

		cell_list.erase(cell_list.cbegin() + index_selected_cell);
	}
}

Map::Map()
{
	_num_of_row = MAP_NUM_OF_ROW;
	_num_of_col = MAP_NUM_OF_COL;

	_num_of_stone_mine = _rand_in_range(3, 6);
	_num_of_iron_mine = _rand_in_range(2, 4);
	_num_of_diamond_mine = _rand_in_range(1, 2);
	_num_of_big_log_mine = _rand_in_range(2, 4);
	_num_of_small_log_mine = _rand_in_range(4, 8);
	_num_of_big_hunt_mine = _rand_in_range(1, 4);
	_num_of_small_hunt_mine = _rand_in_range(3, 5);
	_num_of_gold_mine = _rand_in_range(1, 1);
}


Map::~Map()
{
}


ptree & Map::GetPropertyTree()
{
	_property_tree.clear();

	ptree pt_cells;
	for (auto iter = _list_cell.cbegin(); iter < _list_cell.cend(); iter++)
	{
		pt_cells.push_back(
			ptree::value_type(
			(*iter)->GetNameForPTree(),
				(*iter)->GetPropertyTree()
			)
		);
	}

	_property_tree.add_child(QUOTES(_list_cell), pt_cells);

	ptree pt_mines;
	for (auto iter = _list_mine.cbegin(); iter < _list_mine.cend(); iter++)
	{
		pt_mines.push_back(
			ptree::value_type(
			(*iter)->GetNameForPTree(),
				(*iter)->GetPropertyTree()
			)
		);
	}

	_property_tree.add_child(QUOTES(_list_mine), pt_mines);

	ptree pt_shop;
	pt_shop.push_back(
		ptree::value_type(
			_up_shop->GetNameForPTree(),
			_up_shop->GetPropertyTree()
		)
	);
	
	_property_tree.add_child(QUOTES(_up_shop), pt_shop);


	ptree pt_castle;
	for (auto iter = _list_castle.cbegin(); iter < _list_castle.cend(); iter++)
	{
		pt_castle.push_back(
			ptree::value_type(
			(*iter)->GetNameForPTree(),
				(*iter)->GetPropertyTree()
			)
		);
	}
	_property_tree.add_child(QUOTES(_list_castle), pt_castle);
	
	return _property_tree;
}

void Map::Reset()
{
	_init_map();
}
void Map::_init_map()
{

	int stone_to_generate = _num_of_stone_mine;
	int iron_to_generate = _num_of_iron_mine;
	int diamond_to_generate = _num_of_diamond_mine;

	std::vector<int> list_of_mountain_cell_no;
	std::vector<int> list_of_forest_cell_no;
	std::vector<int> list_of_grass_cell_no;
	std::vector<int> list_of_ice_cell_no;
	std::vector<int> list_of_center_cells_no;

	for (int r = 0; r < _num_of_row; r++)
	{
		for (int c = 0; c < _num_of_col; c++)
		{
			int cell_num = r * _num_of_col + c;
			std::unique_ptr<Cell> up_cell(new Cell(r, c, mapdata[r][c]));

			switch (up_cell->GetCellType())
			{
			case CellType_Mountain:
			{
				list_of_mountain_cell_no.push_back(cell_num);
				break;
			}
			case CellType_Forest:
			{
				list_of_forest_cell_no.push_back(cell_num);
				break;
			}
			case CellType_Grass:
			{
				list_of_grass_cell_no.push_back(cell_num);
				break;
			}
			case CellType_Ice:
			{
				list_of_ice_cell_no.push_back(cell_num);
				break;
			}
			default:
				break;
			}//switch

			if (r >= (_num_of_row / 2) - 1 && r <= (_num_of_row / 2) + 2)
			{
				if (c >= (_num_of_col / 2) - 1 && c <= (_num_of_col / 2) + 2)
					if (up_cell->GetCellType() != CellType_Water)
					{
						list_of_center_cells_no.push_back(cell_num);
					}
			}
			_list_cell.push_back(std::move(up_cell));
		}
	}
	_generate_mines(list_of_mountain_cell_no, _num_of_stone_mine, MineType_Stone);
	_generate_mines(list_of_mountain_cell_no, _num_of_iron_mine, MineType_Iron);
	_generate_mines(list_of_mountain_cell_no, _num_of_diamond_mine, MineType_Diamond);
	_generate_mines(list_of_forest_cell_no, _num_of_big_log_mine, MineType_Big_Log);
	_generate_mines(list_of_forest_cell_no, _num_of_small_log_mine, MineType_Small_Log);
	_generate_mines(list_of_grass_cell_no, _num_of_big_hunt_mine, MineType_Big_Hunt);
	_generate_mines(list_of_grass_cell_no, _num_of_small_log_mine, MineType_Small_Hunt);
	_generate_mines(list_of_ice_cell_no, _num_of_gold_mine, MineType_Gold);

	/*select random cell to put shop*/
	int index_selected_cell = _rand_in_range(0, (int)list_of_center_cells_no.size() - 1);
	int cell_index = list_of_center_cells_no[index_selected_cell];
	int row_index = (cell_index / _num_of_col);
	int col_index = cell_index % _num_of_col;
	_up_shop = std::move(std::unique_ptr<Shop>{ new Shop(row_index, col_index) });

}

void Map::OnIterateCallback(std::string key, std::string value, int level)
{
	throw std::logic_error("not implemented");
}

void Map::UpdateByPropertyTree(const ptree & propert_tree)
{
	_property_tree = propert_tree.get_child(GetNameForPTree());

	ptree pt_cells = _property_tree.get_child(QUOTES(_list_cell));
	int index_cell = 0;
	BOOST_FOREACH(ptree::value_type const&v, pt_cells)
	{
		const std::string & key = v.first; // key
		const boost::property_tree::ptree & subtree = v.second; // value (or a subnode)
		if (key == QUOTES(Cell))
		{
			if (_list_cell.size() <= index_cell)
			{
				_list_cell.push_back(std::move(std::unique_ptr<Cell>(new Cell(subtree))));
			}
			else
			{
				_list_cell[index_cell]->UpdateByPropertyTree(subtree);
			}
		}
		index_cell++;
	}

	ptree pt_mines = _property_tree.get_child(QUOTES(_list_mine));
	int index_mine = 0;
	BOOST_FOREACH(ptree::value_type const&v, pt_mines)
	{
		const std::string & key = v.first; // key
		const boost::property_tree::ptree & subtree = v.second; // value (or a subnode)
		if (key == QUOTES(Mine))
		{
			if (_list_mine.size() <= index_mine)
			{
				_list_mine.push_back(std::move(std::unique_ptr<Mine>(new Mine(subtree))));
			}
			else
			{
				_list_mine[index_mine]->UpdateByPropertyTree(subtree);
			}
		}
		index_mine++;
	}


	ptree pt_shop = _property_tree.get_child(QUOTES(_up_shop));
	BOOST_FOREACH(ptree::value_type const&v, pt_shop)
	{
		const std::string & key = v.first; // key
		const boost::property_tree::ptree & subtree = v.second; // value (or a subnode)
		if (key == QUOTES(Shop))
		{
			if (_up_shop.get() == nullptr)
			{
				_up_shop = std::move(std::unique_ptr<Shop>(new Shop(subtree)));
			}
			else
			{
				_up_shop->UpdateByPropertyTree(subtree);
			}
		}
	}

	ptree pt_castle = _property_tree.get_child(QUOTES(_list_castle));
	int index_castle = 0;
	BOOST_FOREACH(ptree::value_type const&v, pt_castle)
	{
		const std::string & key = v.first; // key
		const boost::property_tree::ptree & subtree = v.second; // value (or a subnode)
		if (key == QUOTES(Castle))
		{
			if (_list_castle.size() <= index_castle)
			{
				_list_castle.push_back(std::move(std::unique_ptr<Castle>(new Castle(subtree))));
			}
			else
			{
				_list_castle[index_castle]->UpdateByPropertyTree(subtree);
			}
		}
		index_castle++;
	}


}

const Cell* Map::GetCell(int index) const {
	return _list_cell[index].get();
}

const Mine* Map::GetMine(int index) const {
	return _list_mine[index].get();
}

const Shop * Map::GetShop() const
{
	return _up_shop.get();
}

const Castle * Map::GetCastle(int index) const
{
	return _list_castle[index].get();
}

const Castle * Map::GetCastle(int row, int col) const
{
	Castle* p_castle = nullptr;
	for (auto itr = _list_castle.cbegin(); itr != _list_castle.cend(); itr++) {
		if ((*itr)->GetRowIndex() == row && (*itr)->GetColIndex() == col) 
		{
			p_castle =  (*itr).get();
			break;
		}
		
	}
	return p_castle;
	
}

int Map::GetTotalCellNumber() const
{
	return (int)_list_cell.size();
}

int Map::GetTotalMineNumber() const
{
	return (int)_list_mine.size();
}

int Map::GetTotalCastleNumber() const
{
	return (int)_list_castle.size();
}

int Map::GetNumberOfCol() const
{
	return _num_of_col;
}

int Map::GetNumberOfRow() const
{
	return _num_of_row;
}

void Map::AddCastle(int row, int col)
{
	
	bool found_overlap = false;
	for (auto itr = _list_castle.begin(); itr < _list_castle.end(); itr++) 
	{
		if ((*itr)->GetColIndex() == row && (*itr)->GetRowIndex() ==  col)
		{

			found_overlap = true;
			break;
		}
		
	}
	if (found_overlap == false)
	{
		std::unique_ptr<Castle> up_castle(
			new Castle(row, col)
		);
		_list_castle.push_back(std::move(up_castle));
	}
	
}
