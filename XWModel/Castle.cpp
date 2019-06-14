#include "Castle.h"



Castle::Castle(int row_index, int col_index)
{
	_row_index = row_index;
	_col_index = col_index;
}


Castle::~Castle()
{
}

ptree & Castle::GetPropertyTree()
{
	_property_tree.clear();
	PROPERTY_TREE_PUT(_property_tree, _row_index);
	PROPERTY_TREE_PUT(_property_tree, _col_index);
	return _property_tree;
}

void Castle::UpdateByPropertyTree(const ptree & propert_tree)
{
	_property_tree = propert_tree;

	PTREE_GET(_row_index);
	PTREE_GET(_col_index);
}

int Castle::GetRowIndex()
{
	return _row_index;
}

int Castle::GetColIndex()
{
	return _col_index;
}
