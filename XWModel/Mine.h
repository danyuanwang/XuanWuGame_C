#pragma once
#include "ModelObject.h"
#include "Cell.h"

enum MineType
{
	MineType_Stone,
	MineType_Iron,
	MineType_Diamond,
	MineType_Big_Log,
	MineType_Small_Log,
	MineType_Big_Hunt,
	MineType_Small_Hunt,
	MineType_Gold,
	MineType_Undefined,
	MineType_Total
};

class Mine :public ModelObject
{
public:
	Mine(const ptree& property_tree);

	Mine(
		int _row_index,
		int _col_index,
		CellType cell_type,
		MineType mine_type
	);

	~Mine();

	const char* GetNameForPTree() const { return  _str_name_id.c_str(); }

	ptree & GetPropertyTree();
	void UpdateByPropertyTree(const ptree& propert_tree);
	MineType GetMineType() const;
	int GetRowIndex() const;
	int GetColIndex()const;


private:
	const int _value_of_mine_type[MineType_Total] = { 5, 15, 25 };

	static unsigned long s_id_counter;

	int _row_index;
	int _col_index;
	int _elevation;
	CellType _cell_type;
	MineType _type;
	int _value_fore_sale;
	

	std::string _str_name_id;

};

