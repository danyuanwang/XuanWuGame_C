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

void Cell::TakeRequest(GamePlayRequest & request)
{
}

ptree & Cell::GetPropertyTree(ptree & propert_tree)
{
	PROPERTY_TREE_PUT(propert_tree, _row_index);
	PROPERTY_TREE_PUT(propert_tree, _col_index);
	PROPERTY_TREE_PUT(propert_tree, _elevation);
	PROPERTY_TREE_PUT(propert_tree, _type);
	return propert_tree;
}
