#pragma once
#include "GamePlayRequest.h"
#include "Map.h"
#include <memory>
#include"ModelObject.h"
#include "DataModel.h"

class Board :public ModelObject
{
public:
	Board();
	~Board();

	ptree&  GetPropertyTree();
	const char* GetNameForPTree() const { return "Board"; }
	void OnIterateCallback(std::string key, std::string value, int level);
	void UpdateByPropertyTree(const ptree& propert_tree);

private:
	std::unique_ptr<Map> _up_map;

};

