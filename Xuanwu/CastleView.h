#pragma once
#include "BaseView.h"
class CastleView :
	public BaseView
{
public:
	CastleView(int index, int x, int y, int container_x, int container_y, int width, int height, int margin_x, int margin_y);
	virtual ~CastleView();
	void Draw(const GameEngine* p_game_engine) override;
	void Invalidate(const ModelObject *p_game_model) override;
	int GetIndex();
private:
	int _index;
};
