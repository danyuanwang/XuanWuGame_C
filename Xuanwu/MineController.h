#pragma once
#include "BaseController.h"
#include "MineView.h"
#include "Mine.h"

class MineController :
	public BaseController
{
private:
	MineView* GetMineView() const;

protected:
	virtual bool OnKeyUp(SDL_Event & e) override;
	virtual bool OnMouseMove(SDL_Event & e) override;
	virtual bool OnMouseButtonUp(SDL_Event & e) override;

public:
	MineController(MineView* p_view, Mine* p_model);
	virtual ~MineController();

	bool HandleSdlEvent(SDL_Event & e) override;

	void Invalidate() override;

};

