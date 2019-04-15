#include "MapView.h"



MapView::MapView()
{
}


MapView::~MapView()
{
}

void MapView::Draw(const GameModel &gamemodel)
{
	for (int i = 0; i < gamemodel.GetBoard()->GetMap()->GetTotalCellNumber(); i++) {
		//gamemodel.GetBoard()->GetMap()->GetCell(i);
		CellView cellView(i);
		_vector_cell.push_back(cellView);
	}
	for (int i = 0; 1 < gamemodel.GetBoard()->GetMap()->GetTotalMineNumber(); i++) {
		MineView mineView(i);
		_vector_mine.push_back(mineView);
	}
	for (auto iter = _vector_cell.begin(); iter < _vector_cell.end(); iter++) {
		(iter)->Draw(gamemodel);
	}
	for (auto iter = _vector_mine.begin(); iter < _vector_mine.end(); iter++) {
		(iter)->Draw(gamemodel);
	}

}
