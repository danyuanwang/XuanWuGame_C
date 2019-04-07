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

void Mine::TakeRequest(GamePlayRequest & request)
{
}

ptree & Mine::GetPropertyTree(ptree & propert_tree)
{
	PROPERTY_TREE_PUT(propert_tree, _row_index);
	PROPERTY_TREE_PUT(propert_tree, _col_index);
	PROPERTY_TREE_PUT(propert_tree, _cell_type);
	PROPERTY_TREE_PUT(propert_tree, _value_fore_sale);
	PROPERTY_TREE_PUT(propert_tree, _type);
	return propert_tree;
}
