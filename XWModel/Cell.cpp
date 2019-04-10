#include "Cell.h"

Cell::Cell(const ptree& property_tree)
{
	UpdateByPropertyTree(property_tree);
}

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

ptree & Cell::GetPropertyTree()
{
	_property_tree.clear();

	PROPERTY_TREE_PUT(_property_tree, _row_index);
	PROPERTY_TREE_PUT(_property_tree, _col_index);
	PROPERTY_TREE_PUT(_property_tree, _elevation);
	PROPERTY_TREE_PUT(_property_tree, _type);
	return _property_tree;
}

void Cell::OnIterateCallback(std::string key, std::string value, int level)
{
	throw std::logic_error("not implemented");
}

void Cell::UpdateByPropertyTree(const ptree& propert_tree)
{
	_property_tree = propert_tree;

	PTREE_GET(_row_index);
	PTREE_GET(_col_index);
	PTREE_GET(_elevation);
	PTREE_GET_T(_type, CellType);
}
