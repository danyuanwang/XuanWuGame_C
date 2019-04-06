#include "Cell.h"
static unsigned int s_id_counter = 0;

Cell::Cell(
	int row_index,
	int col_index,
	CellType type
) : 
	_row_index(row_index),
	_col_index(col_index),
	_type(type),
	_elevation(_elevation_of_cell_type[(int)type]),
	_id(s_id_counter++)
{
	_s_name_id.append("Cell");
	_s_name_id.append(std::to_string(_id));
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
