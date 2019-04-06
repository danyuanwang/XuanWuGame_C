#pragma once
#include"ModelObject.h"
#include<memory>
#include "Cell.h"
#include "mine.h"

class Map :public ModelObject
{
private:
	std::vector<std::unique_ptr<Cell>> _list_cell;
//	std::vector< std::unique_ptr<Mine>> _list_mine;
	int _num_of_row;
	int _num_of_col;

	void _init_map();
public:
	Map();
	~Map();
	const char* GetNameForPTree() const { return "Map"; }

	void TakeRequest(GamePlayRequest & request) ;
	ptree &  GetPropertyTree(ptree& propert_tree)  ;

};

