#pragma once
#include "BaseView.h"
class PanelScaleView :
	public BaseView
{
private:
	XW_RGB_Color _background_color;
	std::string _title;
	std::string _description;
	int _title_x;
	int _title_y;
	int _title_width;
	int _title_height;
	int _description_x;
	int _description_y;
	int _description_width;
	int _description_height;
public:
	PanelScaleView(int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~PanelScaleView();

	void Draw(const GameEngine *p_game_engine) override;

	void Invalidate(const ModelObject *p_gamemodel) override;
};

