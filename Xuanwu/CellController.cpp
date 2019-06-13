#include "CellController.h"



CellController::CellController(CellView* p_view, Cell* p_model) :
	BaseController(p_view, p_model)
{
	Invalidate();
}


CellController::~CellController()
{
}

bool CellController::HandleSdlEvent(SDL_Event & e)
{
	return BaseController::HandleSdlEvent(e);
}

void CellController::Invalidate()
{
	BaseController::Invalidate();
}

CellType CellController::GetCellType()
{
	Cell* p_cell = static_cast<Cell*>(_p_model);
	return p_cell->GetCellType();
}

int CellController::GetColIndex()
{
	return static_cast<Cell*>(_p_model)->GetColIndex();
}

int CellController::GetRowIndex()
{
	return static_cast<Cell*>(_p_model)->GetRowIndex();
}

CellView * CellController::GetCellView() const
{
	return static_cast<CellView*>(_p_view);
}

bool CellController::OnKeyUp(SDL_Event & e)
{
	return false;
}

bool CellController::OnMouseMove(SDL_Event & e)
{
	return false;
}

bool CellController::OnMouseButtonUp(SDL_Event & e)
{
	return GetCellView()->intercepts(e.button.x, e.button.y);
}