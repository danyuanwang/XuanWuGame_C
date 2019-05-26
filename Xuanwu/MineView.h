#pragma once
#include "BaseView.h"
#include "Mine.h"
class MineView :
	public BaseView
{
public:
	MineView(int index, int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~MineView();
	void Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine) override;

	int GetIndex() const;

private:
	int _index;
	const char* GetImagePath(MineType mine_type) const;
};

