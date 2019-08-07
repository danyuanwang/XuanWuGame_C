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
	int GetEndColIndex() const;

	int GetEndrowIndex() const;
	void SetEndIndex(int end_row, int end_col);
	const char* GetPlayerIdentity();

	void UpdateData();

private: 
	int _row_index;
	int _end_row_index = -1;
	int _col_index;
	int _end_col_index = -1;

	std::string _player_identity;

};

