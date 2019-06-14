#pragma once
#include "ModelObject.h"
class Castle :
	public ModelObject
{
public:
	Castle(int row_index, int col_index);
	virtual ~Castle();
	const char* GetNameForPTree() const { return  "Castle"; }

	ptree & GetPropertyTree();
	void UpdateByPropertyTree(const ptree& propert_tree);
	int GetRowIndex();
	int GetColIndex();
private:
	int _row_index;
	int _col_index;
};

