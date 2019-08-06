#pragma once
#include "BaseView.h"
class ArmyView :
	public BaseView
{
public:
	ArmyView(int index, int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~ArmyView();
	void Draw(const GameEngine* p_game_engine) override;
	void Invalidate(const ModelObject *p_game_model) override;
	int GetIndex();
private:
	int _index;
};

