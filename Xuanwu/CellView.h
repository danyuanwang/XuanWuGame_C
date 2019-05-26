#pragma once
#include "BaseView.h"
#include "Cell.h"
class CellView :
	public BaseView
{
private:
	int _index;
public:
	CellView(int index, int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~CellView();
	void Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine) override;

	int GetIndex() const;
};

