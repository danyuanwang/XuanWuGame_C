#include "Mine.h"


Mine::Mine(
	int row_index,
	int col_index,
	CellType cell_type,
	MineType mine_type
):
	_row_index(row_index),
	_col_index(col_index),
	_cell_type(cell_type),
	_type(mine_type),
	_value_fore_sale(_value_of_mine_type[(int)cell_type])

{
	_str_name_id.append("Mine");
}


Mine::~Mine()
{
}


ptree & Mine::GetPropertyTree(ptree & property_tree)
{
	_property_tree.clear();

	PROPERTY_TREE_PUT(_property_tree, _row_index);
	PROPERTY_TREE_PUT(_property_tree, _col_index);
	PROPERTY_TREE_PUT(_property_tree, _cell_type);
	PROPERTY_TREE_PUT(_property_tree, _value_fore_sale);
	PROPERTY_TREE_PUT(_property_tree, _type);

	property_tree.push_back(ptree::value_type(
		GetNameForPTree(),
		_property_tree)
	);

	return property_tree;
}


void Mine::OnIterateCallback(std::string key, std::string value, int level)
{
	throw std::logic_error("not implemented");
}

void Mine::UpdateByPropertyTree(ptree& propert_tree)
{
	throw std::logic_error("not implemented");
}
