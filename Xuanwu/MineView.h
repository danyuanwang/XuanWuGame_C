#pragma once
#include "BaseView.h"
#include "Mine.h"
class MineView :
	public BaseView
{
public:
	MineView(int index);
	virtual ~MineView();
	void Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine);
private:
	int _index;
};

