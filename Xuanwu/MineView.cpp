#include "MineView.h"
#include "Settings.h"
#include <vector>



MineView::MineView(int index, int x, int y, int width, int height, int margin_x, int margin_y)
	:BaseView(x, y, width, height, margin_x, margin_y), _index(index)
{
}


MineView::~MineView()
{
}


void MineView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{
	const Mine* p_mine = static_cast<const Mine*>(p_gamemodel);
	MineType mine_type = p_mine->GetMineType();
	
	p_game_engine->RenderPic(_x, _y, _width,_height, GetImagePath(mine_type));


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
	default:
		return NULL;
	}
}
