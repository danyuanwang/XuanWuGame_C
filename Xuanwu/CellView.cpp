#include "CellView.h"
#include "Settings.h"
#include "Logger.h"

std::map<std::string, XW_Color_Value> CellView::_s_map_colors;


CellView::CellView(int index, CellType cell_type, int x, int y, int container_x, int container_y, int width, int height, int margin_x, int margin_y)
	:BaseView(x, y, container_x, container_y, width, height, margin_x, margin_y),
	_index(index),
	_cell_type(cell_type)
{
}


CellView::~CellView()
{
}

void CellView::Invalidate(const ModelObject * p_game_model)
{
	const Cell* p_cell = static_cast<const Cell*>(p_game_model);
	_cell_type = p_cell->GetCellType();
	_player_identity = p_cell->GetPlayerIdentity();
	if (_player_identity.empty() != true) {
		AddColor(_player_identity);
	}
}

bool CellView::intercepts(int mouse_x, int mouse_y) const
{
	bool result = ((mouse_x >= _x) && (mouse_x <= (_x + _width)) && (mouse_y >= _y) && (mouse_y <= (_y + _height)));
	LOGDEBUG("class:%s, mouse_x:%d, mouse_y:%d, _x:%d, _y:%d, _width:%d, _height:%d, _margin_x:%d, _margin_y:%d, result:%d",
		typeid(*this).name(), mouse_x, mouse_y, _x, _y, _width, _height, _margin_x, _margin_y, result);

	return result;

}

void CellView::AddColor(std::string player_identity)
{
	if (_s_map_colors.find(player_identity) == _s_map_colors.end()) 
	{
		int number_of_colors = sizeof(GameSettings::PlayerColorMap) / sizeof(GameSettings::PlayerColorMap[0]);
		int random_index = _s_map_colors.size() % number_of_colors;
		_s_map_colors[player_identity] = GameSettings::PlayerColorMap[random_index].GetColorValue();
	}
}

void CellView::Draw(const GameEngine *p_game_engine)
{
	p_game_engine->DrawRect(_x, _y, _width, _height, GameSettings::CellColorMap[_cell_type]);
	if (_player_identity.empty() != true) {
		p_game_engine->DrawRect(_x, _y, _width, _height, _s_map_colors[_player_identity], 0x7F);

	}
}

int CellView::GetIndex() const
{
	return _index;
}
