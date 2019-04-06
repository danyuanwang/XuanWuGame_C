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

	void TakeRequest(GamePlayRequest& request);
	ptree&  GetPropertyTree(ptree& propert_tree);
	const char* GetNameForPTree() const { return "Board"; }

private:
	std::unique_ptr<Map> _up_map;

};

