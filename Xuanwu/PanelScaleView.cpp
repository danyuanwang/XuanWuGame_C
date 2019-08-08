#include "PanelScaleView.h"
#include "PanelScale.h"
#include "Settings.h"

PanelScaleView::PanelScaleView(int x, int y, int container_x, int container_y, int width, int height, int margin_x, int margin_y) :
	BaseView(x, y, container_x, container_y, width, height, margin_x, margin_y),
	_background_color(0)
{
	_title_x = x + margin_x;
	_title_y = y + margin_y;
	_title_width = width - (margin_x*2);
	_title_height = (height - (margin_y*2)) / 3;
	_description_x = x + margin_x;
	_description_y = y + _title_height;
	_description_width = width - (margin_x * 2);
	_description_height = _title_height * 2;

};


PanelScaleView::~PanelScaleView()
{
}

void PanelScaleView::Invalidate(const ModelObject * p_gamemodel)
{
	BaseView::Invalidate(p_gamemodel);
	const PanelScale* p_scale = static_cast<const PanelScale*>(p_gamemodel);
	_background_color = GameSettings::CellColorMap[p_scale->GetCellType()];
	_title = p_scale->GetTitle(); 
	_description = p_scale->GetInformation();

}

void PanelScaleView::Draw(const GameEngine * p_game_engine)
{
	//p_game_engine->DrawRect(_x, _y, _width, _height, _background_color);
	p_game_engine->RenderText(_title.c_str() ,XW_RGB_Color(XW_Color_Value::BLACK), _title_x, _title_y, _title_width, _title_height);
	p_game_engine->RenderText(_description.c_str() ,XW_RGB_Color(XW_Color_Value::BLACK), _description_x, _description_y, _description_width, _description_height);
}
