#pragma once
#include "BaseView.h"
class MineView :
	public BaseView
{
public:
	MineView(int index);
	virtual ~MineView();
	void Draw(const GameModel &gamemodel);
private:
	int _index;
};

