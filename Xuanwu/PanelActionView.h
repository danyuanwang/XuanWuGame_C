#pragma once
#include "BaseView.h"
class PanelActionView :
	public BaseView
{
public:
	PanelActionView(int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~PanelActionView();

	void Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine) override;

};

