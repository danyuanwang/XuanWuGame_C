#include "Castle.h"



Castle::Castle(const ptree & propert_tree)
{
	UpdateByPropertyTree(propert_tree);
}

Castle::Castle(int row_index, int col_index, const char* player_identity)
{
	_row_index = row_index;
	_col_index = col_index;
	_player_identity = player_identity;
}


Castle::~Castle()
{
}

ptree & Castle::GetPropertyTree()
{
	_property_tree.clear();
	PROPERTY_TREE_PUT(_property_tree, _row_index);
	PROPERTY_TREE_PUT(_property_tree, _col_index);
	PROPERTY_TREE_PUT_STRING(_property_tree, _player_identity);
	return _property_tree;
}

void Castle::UpdateByPropertyTree(const ptree & propert_tree)
{
	_property_tree = propert_tree;

	PTREE_GET(_row_index);
	PTREE_GET(_col_index);
	PROPERTY_TREE_GET_STRING(_property_tree, _player_identity);
}

int Castle::GetRowIndex() const
{
	return _row_index;
}

int Castle::GetColIndex() const
{
	return _col_index;
}

const char* Castle::GetPlayerIdentity()
{
	return _player_identity.c_str();
}
