#pragma once
#include "BaseView.h"
class CellView :
	public BaseView
{
public:
	CellView();
	virtual ~CellView();
	void Draw(const GameModel &gamemodel);
};

