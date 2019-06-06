#pragma once
#include "ModelObject.h"
class Shop :
	public ModelObject
{
public:
	Shop(int row_index, int col_index);
	Shop(const ptree& property_tree);
	virtual ~Shop();
	const char* GetNameForPTree() const { return  "Shop"; }

	ptree & GetPropertyTree();
	void UpdateByPropertyTree(const ptree& propert_tree);
	int get_row_index() const;
	int get_col_index() const;
private:
	int _row_index;
	int _col_index;

};