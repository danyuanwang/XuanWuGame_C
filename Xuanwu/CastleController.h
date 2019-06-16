#pragma once
#include "BaseController.h"
#include "CastleView.h"
#include "Castle.h"
class CastleController :
	public BaseController
{
private:
	CastleView* GetCastleView() const;
protected:
	virtual bool OnKeyUp(SDL_Event & e) override;
	virtual bool OnMouseMove(SDL_Event & e) override;
	virtual bool OnMouseButtonUp(SDL_Event & e) override;

public:
	CastleController(CastleView* p_view, Castle* p_model);
	virtual ~CastleController();
	bool HandleSdlEvent(SDL_Event & e) override;

	void Invalidate() override;
};

