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

	_init_map();
}


Map::~Map()
{
}

void Map::TakeRequest(GamePlayRequest & request)
{

}

ptree & Map::GetPropertyTree(ptree & propert_tree)
{
	std::vector<std::unique_ptr<Cell>> ::const_iterator iter;
	for (auto iter = _list_cell.cbegin();  iter < _list_cell.cend(); iter++)
	{
		ptree pt_element; 
		propert_tree.push_back(
			ptree::value_type(
			(*iter)->GetNameForPTree(), 
				(*iter)->GetPropertyTree(pt_element)
			)
		);
	}
	return propert_tree;
}

void Map::_init_map()
{
	for (int r = 0; r < MAP_NUM_OF_ROW; r++)
	{
		for (int c = 0; c < MAP_NUM_OF_COL; c++)
		{
			auto up_cell = std::unique_ptr<Cell>(new Cell(r, c, mapdata[r][c]));
			_list_cell.push_back(std::move(up_cell));
		}
	}
}