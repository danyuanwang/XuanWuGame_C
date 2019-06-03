#pragma once
#include "ModelObject.h"
class Shop :
	public ModelObject
{
public:
	Shop(int row_index, int col_index);
	virtual ~Shop();
};

