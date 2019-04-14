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
	void Draw(const GameModel &gamemodel);
private:
	std::vector<CellView> _vector_cell;
	std::vector<MineView> _vector_mine;
};

