#pragma once
#include"ModelObject.h"
#include<memory>
#include "Cell.h"

class Map :public ModelObject
{
private:
	std::unique_ptr<Cell> _cellList;

public:
	Map();
	~Map();
	const char* GetClassName() const { return "Map"; }

	void TakeRequest(GamePlayRequest & request) ;
	void GetPropertyTree(ptree& propert_tree) const ;

};

