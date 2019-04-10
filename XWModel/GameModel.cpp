#include "GameModel.h"
#include<iterator>


GameModel::GameModel()
{
	up_game_board = std::unique_ptr<Board>{ new Board() };
}


GameModel::~GameModel()
{

}

ptree& GameModel::GetPropertyTree(ptree & property_tree)
{
	_property_tree.clear();

	{
		ptree pt_element;
		_property_tree.add_child(
			QUOTES(up_game_board),
			up_game_board->GetPropertyTree(pt_element)
		);
	}

	property_tree.push_back(
		ptree::value_type(
			GetNameForPTree(),
			_property_tree
		)
	);

	return property_tree;
}

void GameModel::OnIterateCallback(std::string key, std::string value, int level)
{
	throw std::logic_error("not implemented");
}

void GameModel::UpdateByPropertyTree(ptree& propert_tree)
{
	throw std::logic_error("not implemented");
}
