#pragma once
#include "BaseView.h"
class PanelScaleView :
	public BaseView
{
private:
	XW_RGB_Color _background_color;

public:
	PanelScaleView(int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~PanelScaleView();

	void Draw(const GameEngine *p_game_engine) override;

	void Invalidate(const ModelObject *p_gamemodel) override;
};

