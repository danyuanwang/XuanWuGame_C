#include "MapView.h"



MapView::MapView()
{
}


MapView::~MapView()
{
}

void MapView::Draw(const GameModel &gamemodel)
{
	for (auto iter = _vector_cell.begin(); iter < _vector_cell.end(); iter++) {
		(iter)->Draw(gamemodel);
	}
	for (auto iter = _vector_mine.begin(); iter < _vector_mine.end(); iter++) {
		(iter)->Draw(gamemodel);
	}
}
