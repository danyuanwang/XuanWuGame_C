#pragma once
#include "BaseView.h"
# include "CellView.h"
#include "MineView.h"
#include <vector>
class MapView :
	public BaseView
{
public:
	MapView();
	virtual ~MapView();
	void Draw(const ModelObject *p_game_model, const GameEngine *p_game_engine);
private:
	std::vector<CellView> _vector_cell;
	std::vector<MineView> _vector_mine;
};

