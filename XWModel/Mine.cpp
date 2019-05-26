#include "Mine.h"

Mine::Mine(const ptree& property_tree)
{
	UpdateByPropertyTree(property_tree);
}

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


ptree & Mine::GetPropertyTree()
{
	_property_tree.clear();

	PROPERTY_TREE_PUT(_property_tree, _row_index);
	PROPERTY_TREE_PUT(_property_tree, _col_index);
	PROPERTY_TREE_PUT(_property_tree, _cell_type);
	PROPERTY_TREE_PUT(_property_tree, _value_fore_sale);
	PROPERTY_TREE_PUT(_property_tree, _type);

	return _property_tree;
}

void Mine::UpdateByPropertyTree(const ptree& propert_tree)
{
	_property_tree = propert_tree;

	PTREE_GET(_row_index);
	PTREE_GET(_col_index);
	PTREE_GET(_elevation);
	PTREE_GET(_value_fore_sale);
	PTREE_GET_T(_cell_type, CellType);
	PTREE_GET_T(_type, MineType);
}

MineType Mine::GetMineType() const
{
	return _type;
}

int Mine::GetRowIndex() const
{
	return _row_index;
}

int Mine::GetColIndex() const
{
	return _col_index;
}
