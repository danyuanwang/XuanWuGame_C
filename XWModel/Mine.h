#pragma once
#include "ModelObject.h"
#include "Cell.h"

enum MineType 
{
	MineType_Stone,
	MineType_Iron,
	MineType_Diamond,

	MineType_Total
};

class Mine :public ModelObject
{
public:
	Mine(
		int _row_index,
		int _col_index,
		CellType cell_type,
		MineType mine_type
	);

	~Mine();

	const char* GetNameForPTree() const { return  _str_name_id.c_str(); }

	void TakeRequest(GamePlayRequest & request);
	ptree & GetPropertyTree(ptree& propert_tree);

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

