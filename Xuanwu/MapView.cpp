#include "MapView.h"
#include "Map.h"


MapView::MapView()
{
}


MapView::~MapView()
{
}

void MapView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{

	_vector_cell.clear();
	_vector_mine.clear();

	const Map* p_map = static_cast<const Map*>(p_gamemodel);

	for (int i = 0; i < p_map->GetTotalCellNumber(); i++) {
		CellView cellView(i);
		_vector_cell.push_back(cellView);
		cellView.Draw(p_map->GetCell(i), p_game_engine);
	}

	for (int i = 0; 1 < p_map->GetTotalMineNumber(); i++) {
		MineView mineView(i);
		_vector_mine.push_back(mineView);
		mineView.Draw(p_map->GetMine(i), p_game_engine);
	}

}
