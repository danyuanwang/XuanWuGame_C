#pragma once
#include "BaseView.h"
#include "GameModel.h"
class PanelView :
	public BaseView
{
public:
	PanelView(int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~PanelView();
	void Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine);
};

