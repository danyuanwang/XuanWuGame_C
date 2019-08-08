#pragma once
#include "BaseView.h"
#include "Mine.h"
class MineView :
	public BaseView
{
public:
	MineView(int index, MineType mine_type, int x, int y, int container_x, int container_y, int width, int height, int margin_x, int margin_y);
	virtual ~MineView();
	void Draw(const GameEngine *p_game_engine) override;
	void Invalidate(const ModelObject *p_game_model) override;

	int GetIndex() const;

private:
	int _index;
	MineType _mine_type;
	const char* GetImagePath(MineType mine_type) const;
};

