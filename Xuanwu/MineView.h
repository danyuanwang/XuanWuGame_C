#pragma once
#include "BaseView.h"
class MineView :
	public BaseView
{
public:
	MineView();
	virtual ~MineView();
	void Draw(const GameModel &gamemodel);
};

