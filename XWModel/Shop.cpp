#include "Shop.h"



Shop::Shop(int row_index, int col_index)
{
	_row_index = row_index;
	_col_index = col_index;
}

Shop::Shop(const ptree & property_tree)
{
	UpdateByPropertyTree(property_tree);
}


Shop::~Shop()
{
}

ptree & Shop::GetPropertyTree()
{
	_property_tree.clear();
	PROPERTY_TREE_PUT(_property_tree, _row_index);
	PROPERTY_TREE_PUT(_property_tree, _col_index);
	return _property_tree;
}

void Shop::UpdateByPropertyTree(const ptree & propert_tree)
{
	_property_tree = propert_tree;

	PTREE_GET(_row_index);
	PTREE_GET(_col_index);
}

int Shop::GetRowIndex()const
{
	return _row_index;
}

int Shop::GetColIndex() const
{
	return _col_index;
}
