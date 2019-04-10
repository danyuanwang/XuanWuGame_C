#pragma once
#include"ModelObject.h"
#include<memory>
#include "Cell.h"
#include "mine.h"

class Map :public ModelObject
{
private:
	std::vector<std::unique_ptr<Cell>> _list_cell;
	std::vector< std::unique_ptr<Mine>> _list_mine;
	int _num_of_row;
	int _num_of_col;

	int _num_of_stone_mine;
	int _num_of_iron_mine;
	int _num_of_diamond_mine;

	void _init_map();

	int _rand_in_range(int userBeg, int userEnd) { return std::rand() % ((userEnd - userBeg) + 1) + userBeg; }
public:
	Map();
	~Map();
	const char* GetNameForPTree() const { return "Map"; }

	ptree &  GetPropertyTree(ptree& propert_tree)  ;
	void OnIterateCallback(std::string key, std::string value, int level);
	void UpdateByPropertyTree(ptree& propert_tree);

};

