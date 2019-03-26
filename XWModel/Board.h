#pragma once
#include "GamePlayRequest.h"
#include "Map.h"
#include <memory>
#include"ModelObject.h"

class Board :public ModelObject
{
public:
	Board();
	~Board();

	void TakeRequest(GamePlayRequest& request);
	void GetPropertyTree(ptree& propert_tree) const;

private:
	std::unique_ptr<Map> _map;

	void _restartGame();
	void _endGame();

};

