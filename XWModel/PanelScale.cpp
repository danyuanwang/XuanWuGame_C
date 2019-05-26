#include "PanelScale.h"
#include <typeinfo>


PanelScale::PanelScale() :
	_mine_type(MineType_Undefined),
	_cell_type(CellType_Undefined)
{
}


PanelScale::~PanelScale()
{
}

ptree & PanelScale::GetPropertyTree()
{
	_property_tree.clear();

	//PROPERTY_TREE_PUT(_property_tree, _row_index);
	//PROPERTY_TREE_PUT(_property_tree, _col_index);
	//PROPERTY_TREE_PUT(_property_tree, _cell_type);
	//PROPERTY_TREE_PUT(_property_tree, _value_fore_sale);
	//PROPERTY_TREE_PUT(_property_tree, _type);

	return _property_tree;
}

void PanelScale::UpdateByPropertyTree(const ptree & propert_tree)
{
	_property_tree = propert_tree;

	//PTREE_GET(_row_index);
	//PTREE_GET(_col_index);
	//PTREE_GET(_elevation);
	//PTREE_GET(_value_fore_sale);
	//PTREE_GET_T(_cell_type, CellType);
	//PTREE_GET_T(_type, MineType);
}

void PanelScale::TakeDataObject(const ModelObject * p_model)
{
	if (p_model)
	{
		if (typeid(*p_model) == typeid(Mine))
		{
			const Mine* p_mine= static_cast<const Mine*>(p_model);
			_mine_type = p_mine->GetMineType();
		}
		else if (typeid(*p_model) == typeid(Cell))
		{
			const Cell* p_cell= static_cast<const Cell*>(p_model);
			_cell_type = p_cell->GetCellType();
		}
	}
}

MineType PanelScale::GetMineType() const
{
	return _mine_type;
}

CellType PanelScale::GetCellType() const
{
	return _cell_type;
}
