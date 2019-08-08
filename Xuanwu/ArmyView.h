#pragma once
#include "BaseView.h"
#include "Army.h"
class ArmyView :
	public BaseView
{
public:
	ArmyView(int index, int x, int y, int container_x, int container_y, int width, int height, int margin_x, int margin_y);
	virtual ~ArmyView();
	void Draw(const GameEngine* p_game_engine) override;
	void Invalidate(const ModelObject *p_game_model) override;
	int GetIndex();
	virtual int ConvertColToX(int col) override;
	virtual int ConvertRowToY(int row) override;

private:
	int _index;
};

