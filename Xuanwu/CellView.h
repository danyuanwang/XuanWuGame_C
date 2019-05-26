#pragma once
#include "BaseView.h"
#include "Cell.h"
class CellView :
	public BaseView
{
private:
	int _index;
	CellType _cell_type;
public:
	CellView(int index, CellType cell_type, int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~CellView();
	void Draw(const GameEngine *p_game_engine) override;
	void Invalidate(const ModelObject *p_game_model) override;

	int GetIndex() const;
};

