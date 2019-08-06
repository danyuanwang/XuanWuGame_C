#pragma once
#include "BaseView.h"
# include "CellView.h"
#include "MineView.h"
#include "ShopView.h"
#include "CastleView.h"
#include "ArmyView.h"
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
	std::vector<std::unique_ptr<CellView>> _vector_cell;
	std::vector<std::unique_ptr<MineView>> _vector_mine;
	std::unique_ptr<ShopView> _up_shop;
	std::vector<std::unique_ptr<CastleView>> _vector_castle;
	std::vector<std::unique_ptr<ArmyView>> _vector_army;
	friend class MapController;
};

