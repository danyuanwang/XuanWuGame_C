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
	void GetPropertyTree(ptree& propert_tree) const;
	const char* GetClassName() const { return "Board"; }

private:
	const char* _game_title;
	const int _screen_width;
	const int _screen_height;
	const int _screen_margin_x;
	const int _screen_margin_y;

	DataModel _dataModel;
	std::unique_ptr<Map> _map;

	void _restartGame();
	void _endGame();

};

