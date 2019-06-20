#include "Player.h"



Player::Player(const char*player_identity)
{
	_player_identity = player_identity;
}

Player::Player(const ptree & property_tree)
{
	UpdateByPropertyTree(property_tree);
}


Player::~Player()
{
}

ptree & Player::GetPropertyTree()
{
	_property_tree.clear();
	PROPERTY_TREE_PUT_STRING(_property_tree, _player_identity);

	return _property_tree;

}

void Player::UpdateByPropertyTree(const ptree & propert_tree)
{
	_property_tree = propert_tree;

	PROPERTY_TREE_GET_STRING(_property_tree, _player_identity);
}

