#include "Army.h"
#include "DataModel.h"


Army::Army(const ptree& property_tree)
{
	UpdateByPropertyTree(property_tree);
}


Army::Army(int row_index, int col_index, const char* player_identity)
{
	_row_index = row_index;
	_col_index = col_index;
	_player_identity = player_identity;
}

Army::~Army()
{
}



ptree & Army::GetPropertyTree()
{
	_property_tree.clear();
	PROPERTY_TREE_PUT(_property_tree, _row_index);
	PROPERTY_TREE_PUT(_property_tree, _col_index);
	PROPERTY_TREE_PUT(_property_tree, _end_row_index);
	PROPERTY_TREE_PUT(_property_tree, _end_col_index);
	PROPERTY_TREE_PUT_STRING(_property_tree, _player_identity);
	return _property_tree;
}

void Army::UpdateByPropertyTree(const ptree& propert_tree)
{
	_property_tree = propert_tree;
	PTREE_GET(_row_index);
	PTREE_GET(_col_index);
	PTREE_GET(_end_row_index);
	PTREE_GET(_end_col_index);
	PROPERTY_TREE_GET_STRING(_property_tree, _player_identity);
}

int Army::GetRowIndex() const
{
	return _row_index;
}

int Army::GetColIndex() const
{
	return _col_index;
}

int Army::GetEndColIndex() const
{
	return _end_col_index;
}

int Army::GetEndrowIndex() const
{
	return _end_row_index;
}

void Army::SetEndIndex(int end_row, int end_col)
{
	_end_col_index = end_col;
	_end_row_index = end_row;
}

const char* Army::GetPlayerIdentity()
{ 
	return _player_identity.c_str();
}

void Army::UpdateData()
{
	if (_end_col_index >= 0 && _end_row_index >= 0)
	{
		if (_end_col_index != _col_index || _end_row_index != _row_index) 
		{
			int slope = 0;
			int x1 = _col_index;
			int y1 = _row_index;
			int x2 = _end_col_index;
			int y2 = _end_row_index;
			if (x1 - x2 == 0) {
				if (_end_row_index > _row_index) {
					_row_index++;
				}
				else if (_end_row_index< _row_index) {
					_row_index--;
				}
				else {
					int slope = (y1 - y2) / (x1 - x2);
				}
			
			}
			
			int y_intercept = y1 - slope * x1;
			int result1 = slope * x1 + y_intercept;
			int result2 = slope * (x1 + 1) + y_intercept;
			int delta1 = (y1 + 1) - result1;
			int delta2 = (y1)-result2;
			if (x1 - x2 != 0) {
				if (abs(delta1) < abs(delta2))
				{
					if (_end_col_index > _col_index) {
						_col_index++;
					}
					else {
						_col_index--;
					}

				}
				else
				{
					if (_end_row_index > _row_index) {
						_row_index++;
					}
					else {
						_row_index--;
					}

				}
			}
		}
	}
}
