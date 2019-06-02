#include "MineView.h"
#include "Settings.h"
#include <vector>



MineView::MineView(int index, MineType mine_type, int x, int y, int width, int height, int margin_x, int margin_y)
	:BaseView(x, y, width, height, margin_x, margin_y),
	_index(index),
	_mine_type(mine_type)
{
}


MineView::~MineView()
{
}

void MineView::Invalidate(const ModelObject * p_game_model)
{
	const Mine* p_mine = static_cast<const Mine*>(p_game_model);
	_mine_type = p_mine->GetMineType();
}


void MineView::Draw(const GameEngine *p_game_engine)
{
	p_game_engine->RenderPic(_x, _y, _width,_height, GetImagePath(_mine_type));
}

int MineView::GetIndex() const
{
	return _index;
}

const char * MineView::GetImagePath(MineType mine_type) const
{
	switch (mine_type)
	{
	case MineType_Stone:
		return "stone_mine.png";
		break;
	case MineType_Iron:
		return "iron_mine.png";
		break;
	case MineType_Diamond:
		return "diamond_mine.png";
		break;
	case MineType_Big_Log:
		return "big_log_mine.png";
		break;
	case MineType_Small_Log:
		return "small_log_mine.png";
		break;
	case MineType_Big_Hunt:
		return "big_hunting_mine.png";
		break;
	case MineType_Small_Hunt:
		return "small_hunting_mine.png";
		break;
	case MineType_Gold:
		return "gold_mine.png";
		break;
	default:
		return NULL;
	}
}
