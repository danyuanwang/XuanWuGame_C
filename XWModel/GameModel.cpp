#include "GameModel.h"
#include<iterator>


GameModel::GameModel()
{
	up_game_board =  std::move(std::unique_ptr<Board>{ new Board() } );
}


GameModel::~GameModel()
{

}

ptree& GameModel::GetPropertyTree()
{
	_property_tree.clear();

	ptree pt_board;
	{
		pt_board.push_back(
			ptree::value_type(
				up_game_board->GetNameForPTree(),
				up_game_board->GetPropertyTree()
			)
		);

		_property_tree.add_child(
			QUOTES(up_game_board),
			pt_board
		);
	}


	return _property_tree;
}

void GameModel::OnIterateCallback(std::string key, std::string value, int level)
{
	throw std::logic_error("not implemented");
}

void GameModel::UpdateByPropertyTree(const ptree& propert_tree)
{
	_property_tree = propert_tree;
	up_game_board->UpdateByPropertyTree(_property_tree.get_child(QUOTES(up_game_board)));
}

const Board* GameModel::GetBoard() const {
	return up_game_board.get();
}

