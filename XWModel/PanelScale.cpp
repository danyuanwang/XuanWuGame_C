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
		if (typeid(*p_model) == typeid(Shop))
		{
			const Shop* p_shop = static_cast<const Shop*>(p_model);
			_title = "Shop";//TODO: refine the value to _title and _information
			_information = "this is a shop";

		}
		else if (typeid(*p_model) == typeid(Mine))
		{
			const Mine* p_mine= static_cast<const Mine*>(p_model);
			_mine_type = p_mine->GetMineType();
			_title = "mine";//TODO: refine the value to _title and _information
			_information = "this is a mine";
		}
		else if (typeid(*p_model) == typeid(Cell))
		{
			const Cell* p_cell= static_cast<const Cell*>(p_model);
			_cell_type = p_cell->GetCellType();
			_title = "Cell";//TODO: refine the value to _title and _information
			_information = "this is a cell";
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

const char* PanelScale::GetTitle() const
{
	return _title.c_str();
}

const char* PanelScale::GetInformation() const
{
	return _information.c_str();
}