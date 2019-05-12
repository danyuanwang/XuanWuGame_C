#include "MineView.h"
#include "Settings.h"
#include <vector>



MineView::MineView(int index):
	_index(index)
{
}


MineView::~MineView()
{
}


void MineView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{
	const Mine* p_mine = static_cast<const Mine*>(p_gamemodel);
	MineType mine_type = p_mine->GetMineType();
	int cell_index_col = p_mine->GetColIndex();
	int cell_index_row = p_mine->GetRowIndex();
	int cell_x = (cell_index_col * (GameSettings::CellMarginX + GameSettings::CellWidth)) + GameSettings::MineMarginX;
	int cell_y = (cell_index_row * (GameSettings::CellMarginY + GameSettings::CellHeight)) + GameSettings::MineMarginY;
	p_game_engine->RenderPic(cell_x, cell_y, GameSettings::Minewidth,GameSettings::MineHeight, GetImagePath(mine_type));


}

const char * MineView::GetImagePath(MineType mine_type) const
{
	switch (mine_type)
	{
	case MineType_Stone:
		return "C:\\Users\\Danyuan\\source\\repos\\XuanWuGame_C\\Xuanwu\\resource\\stone_mine.png";
		break;
	case MineType_Iron:
		return "C:\\Users\\Danyuan\\source\\repos\\XuanWuGame_C\\Xuanwu\\resource\\iron_mine.png";
		break;
	case MineType_Diamond:
		return "C:\\Users\\Danyuan\\source\\repos\\XuanWuGame_C\\Xuanwu\\resource\\diamond_mine.png";
		break;
	default:
		NULL;
	}
}
