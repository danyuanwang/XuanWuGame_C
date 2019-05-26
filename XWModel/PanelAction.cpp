#include "PanelAction.h"



PanelAction::PanelAction()
{
}


PanelAction::~PanelAction()
{
}

ptree & PanelAction::GetPropertyTree()
{
	_property_tree.clear();

	//PROPERTY_TREE_PUT(_property_tree, _row_index);
	//PROPERTY_TREE_PUT(_property_tree, _col_index);
	//PROPERTY_TREE_PUT(_property_tree, _cell_type);
	//PROPERTY_TREE_PUT(_property_tree, _value_fore_sale);
	//PROPERTY_TREE_PUT(_property_tree, _type);

	return _property_tree;
}

void PanelAction::UpdateByPropertyTree(const ptree & propert_tree)
{
	_property_tree = propert_tree;

	//PTREE_GET(_row_index);
	//PTREE_GET(_col_index);
	//PTREE_GET(_elevation);
	//PTREE_GET(_value_fore_sale);
	//PTREE_GET_T(_cell_type, CellType);
	//PTREE_GET_T(_type, MineType);
}
