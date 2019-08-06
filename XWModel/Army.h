#pragma once
#include "ModelObject.h"
class Army :
	public ModelObject
{
public:
	Army(const ptree& property_tree);
	Army(int row_index, int col_index, const char* player_identity);
	virtual ~Army();

	ptree&  GetPropertyTree();
	const char* GetNameForPTree() const override { return "Army"; }
	void UpdateByPropertyTree(const ptree& propert_tree) override;
	int GetRowIndex() const;
	int GetColIndex() const;
	const char* GetPlayerIdentity();
private:
	int _row_index;
	int _col_index;
	std::string _player_identity;
};

