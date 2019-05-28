#pragma once
#include <vector>
#include <memory>
#include "ModelObject.h"
#include "GameModelCallback.h"
#include "GamePlayRequest.h"
#include "GameModel.h"
#include "Board.h"
#include "ConnectionMgr.h"
#include "Player.h"

class GameModel :
	public ModelObject
{
private:
	std::unique_ptr<Board> up_game_board;
	std::list<std::unique_ptr<Player>> _list_player; 


public:
	GameModel();
	~GameModel();

	const char* GetNameForPTree() const { return "GameModel"; }
	ptree& GetPropertyTree();
	void OnIterateCallback(std::string key, std::string value, int level);
	void UpdateByPropertyTree(const ptree& propert_tree);

	const Board* GetBoard() const ;
};

