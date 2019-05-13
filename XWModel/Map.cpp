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

Map::Map()
{
	_num_of_row = MAP_NUM_OF_ROW;
	_num_of_col = MAP_NUM_OF_COL;

	_num_of_stone_mine = _rand_in_range(1, 5);
	_num_of_iron_mine = _rand_in_range(1, 3);
	_num_of_diamond_mine = _rand_in_range(1, 1);

	_init_map();
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

	return _property_tree;
}

void Map::_init_map()
{

int stone_to_generate = _num_of_stone_mine;
	int iron_to_generate = _num_of_iron_mine;
	int diamond_to_generate = _num_of_diamond_mine;

	std::vector<int> list_of_mountain_cell_no;

	for (int r = 0; r < _num_of_row; r++)
	{
		for (int c = 0; c < _num_of_col; c++)
		{
			auto up_cell = std::unique_ptr<Cell>(new Cell(r, c, mapdata[r][c]));
			switch (up_cell->GetCellType())
			{
			case CellType_Mountain:
			{
				list_of_mountain_cell_no.push_back(r*_num_of_col + c);
				break;
			}
			default:
				break;
			}

			_list_cell.push_back(std::move(up_cell));
		}
	}
	while (stone_to_generate > 0 || iron_to_generate > 0 || diamond_to_generate > 0)
	{
		int index_selected_cell = _rand_in_range(0, (int)list_of_mountain_cell_no.size() - 1);
		int cell_index = list_of_mountain_cell_no[index_selected_cell];
		int row_index = (cell_index / _num_of_col);
		int col_index = cell_index % _num_of_col;
		MineType mine_type = MineType_Stone;

		if (stone_to_generate > 0)
		{
			mine_type = MineType_Stone;
			stone_to_generate--;
		}
		else if (iron_to_generate > 0)
		{
			mine_type = MineType_Iron;
			iron_to_generate--;
		}
		else if (diamond_to_generate > 0)
		{
			mine_type = MineType_Diamond;
			diamond_to_generate--;
		}
		auto up_mine = std::unique_ptr<Mine>(
			new Mine(row_index, col_index, _list_cell[cell_index]->GetCellType(), mine_type)
			);

		_list_mine.push_back(std::move(up_mine));

		list_of_mountain_cell_no.erase(list_of_mountain_cell_no.cbegin() + index_selected_cell);
	}
}

void Map::OnIterateCallback(std::string key, std::string value, int level)
{
	throw std::logic_error("not implemented");
}

void Map::UpdateByPropertyTree(const ptree& propert_tree)
{
	_property_tree = propert_tree.get_child(GetNameForPTree());

	_list_cell.clear();
	ptree pt_cells = _property_tree.get_child(QUOTES(_list_cell));
	BOOST_FOREACH(ptree::value_type const&v, pt_cells)
	{
		const std::string & key = v.first; // key
		const boost::property_tree::ptree & subtree = v.second; // value (or a subnode)
		if (key == QUOTES(Cell))
		{
			_list_cell.push_back(std::move(std::unique_ptr<Cell>(new Cell(subtree))));
		}
	}

	_list_mine.clear();
	ptree pt_mines = _property_tree.get_child(QUOTES(_list_mine));
	BOOST_FOREACH(ptree::value_type const&v, pt_mines)
	{
		const std::string & key = v.first; // key
		const boost::property_tree::ptree & subtree = v.second; // value (or a subnode)
		if (key == QUOTES(Mine))
		{
			_list_mine.push_back(std::move(std::unique_ptr<Mine>(new Mine(subtree))));
		}
	}

}

const Cell* Map::GetCell (int index) const {
	return _list_cell[index].get();
}

const Mine* Map::GetMine(int index) const {
	return _list_mine[index].get();
}

int Map::GetTotalCellNumber() const
{
	return (int)_list_cell.size();
}

int Map::GetTotalMineNumber() const
{
	return (int)_list_mine.size();
}
