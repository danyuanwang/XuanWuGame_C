#pragma once
#include "BaseController.h"
#include "Cell.h"
#include "CellView.h"
class CellController :
	public BaseController
{
private:
	CellView* GetCellView() const;

protected:
	virtual bool OnKeyUp(SDL_Event & e) override;
	virtual bool OnMouseMove(SDL_Event & e) override;
	virtual bool OnMouseButtonUp(SDL_Event & e) override;

public:
	CellController(CellView* p_view, Cell* p_model);
	virtual ~CellController();

	bool HandleSdlEvent(SDL_Event & e) override;

	void Invalidate() override;
	CellType GetCellType();
	int GetColIndex();
	int GetRowIndex();

};

