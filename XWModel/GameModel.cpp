#include "GameModel.h"
#include<iterator>


GameModel::GameModel()
{
	up_game_board = std::move(std::unique_ptr<Board>{ new Board() });
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

	ptree pt_player;
	for (auto iter = _map_players.cbegin(); iter != _map_players.cend(); iter++)
	{
		pt_player.push_back(
			ptree::value_type(
			(*iter).first, //the key, the play identity
				(*iter).second->GetPropertyTree() //the value, the player object 
			)
		);
	}
	_property_tree.add_child(QUOTES(_map_players), pt_player);


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

	ptree pt_players = _property_tree.get_child(QUOTES(_map_players));
	BOOST_FOREACH(ptree::value_type const&v, pt_players)
	{
		const std::string & key = v.first; // key, the identify
		const boost::property_tree::ptree & subtree = v.second; // value (or a subnode)

		if (_map_players.find(key) == _map_players.end())
		{
			_map_players[key] = std::move(std::unique_ptr<Player>{ new Player(key.c_str()) });
		}
		else
		{
			_map_players[key]->UpdateByPropertyTree(subtree);
		}
	}
}

const Board* GameModel::GetBoard() const {
	return up_game_board.get();
}

void GameModel::AddPlayer(const char* identity)
{
	auto player_itr = _map_players.find(identity);
	if (player_itr == _map_players.end()) {
		_map_players[identity] = std::move(std::unique_ptr<Player>{ new Player(identity) });
	}
}

