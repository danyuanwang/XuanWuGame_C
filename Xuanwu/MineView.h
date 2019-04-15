#pragma once
#include "BaseView.h"
#include "Mine.h"
class MineView :
	public BaseView
{
public:
	MineView(int index);
	virtual ~MineView();
	void Draw(const ModelObject *p_gamemodel);
private:
	int _index;
};

