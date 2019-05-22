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
	int cell_x = ((cell_index_col * (GameSettings::CellMarginX + GameSettings::CellWidth)) + GameSettings::MineMarginX)
		+(GameSettings::MarginOfBoardX +GameSettings::PanelWidth);
	int cell_y = ((cell_index_row * (GameSettings::CellMarginY + GameSettings::CellHeight)) + GameSettings::MineMarginY)
		+ GameSettings::MarginOfBoardY;
	p_game_engine->RenderPic(cell_x, cell_y, GameSettings::Minewidth,GameSettings::MineHeight, GetImagePath(mine_type));


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
