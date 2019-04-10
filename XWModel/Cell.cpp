#include "Cell.h"

Cell::Cell(
	int row_index,
	int col_index,
	CellType type
) : 
	_row_index(row_index),
	_col_index(col_index),
	_type(type),
	_elevation(_elevation_of_cell_type[(int)type])
{
	_str_name_id.append("Cell");

}



Cell::~Cell()
{
}

ptree & Cell::GetPropertyTree(ptree & property_tree)
{
	_property_tree.clear();

	PROPERTY_TREE_PUT(_property_tree, _row_index);
	PROPERTY_TREE_PUT(_property_tree, _col_index);
	PROPERTY_TREE_PUT(_property_tree, _elevation);
	PROPERTY_TREE_PUT(_property_tree, _type);

	property_tree.push_back(ptree::value_type(
		GetNameForPTree(),
		_property_tree)
	);
	return property_tree;
}

void Cell::OnIterateCallback(std::string key, std::string value, int level)
{
	throw std::logic_error("not implemented");
}

void Cell::UpdateByPropertyTree(ptree& propert_tree)
{
	throw std::logic_error("not implemented");
}
