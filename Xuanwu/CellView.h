#pragma once
#include "BaseView.h"
class CellView :
	public BaseView
{
private:
	int _index;
public:
	CellView(int index);
	virtual ~CellView();
	void Draw(const GameModel &gamemodel);
};

