#pragma once
#include "BaseView.h"
# include "CellView.h"
#include "MineView.h"
#include <vector>
class MapView :
	public BaseView
{
public:
	MapView(int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~MapView();
	void Draw(const GameEngine *p_game_engine) override;

	void Invalidate(const ModelObject *p_game_model) override;

private:
	std::vector<CellView> _vector_cell;
	std::vector<MineView> _vector_mine;
	friend class MapController;
};

