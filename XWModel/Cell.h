#pragma once
#include"ModelObject.h"
enum CellType 
{
	CellType_Basic,
	CellType_Ice,
	CellType_Mountain,
	CellType_Forest,
	CellType_River,
	CellType_Water,
	CellType_Grass,

	CellType_Total,
};


class Cell :public ModelObject
{
private:
	const int _elevation_of_cell_type[CellType_Total] = {1, 1, 2, 1, 0, 1, 0};
	int _row_index;
	int _col_index;
	int _elevation;
	CellType _type;
	std::string _str_name_id;

public:
	Cell(
		int _row_index, 
		int _col_index,
		CellType _type
	);
	~Cell();
	const char* GetNameForPTree() const { return  _str_name_id.c_str();}

	ptree & GetPropertyTree(ptree& propert_tree);
	void OnIterateCallback(std::string key, std::string value, int level);
	void UpdateByPropertyTree(ptree& propert_tree);

	CellType GetCellType() { return _type;  };
	int GetRowIndex() { return _row_index; };
	int GetColIndex() { return _col_index; };
};

