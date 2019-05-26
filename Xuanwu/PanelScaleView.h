#pragma once
#include "BaseView.h"
class PanelScaleView :
	public BaseView
{
public:
	PanelScaleView(int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~PanelScaleView();

	void Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine) override;
};

