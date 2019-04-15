#pragma once
#include "BaseView.h"
#include "Cell.h"
class CellView :
	public BaseView
{
private:
	int _index;
public:
	CellView(int index);
	virtual ~CellView();
	void Draw(const ModelObject *p_gamemodel);
};

