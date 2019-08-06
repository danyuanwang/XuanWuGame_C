#pragma once
#include "BaseController.h"
#include "ArmyView.h"
#include "Army.h"
class ArmyController :
	public BaseController
{
private:
	ArmyView* GetArmyView() const;
protected:
	virtual bool OnKeyUp(SDL_Event & e) override;
	virtual bool OnMouseMove(SDL_Event & e) override;
	virtual bool OnMouseButtonUp(SDL_Event & e) override;

public:
	ArmyController(ArmyView* p_view, Army* p_model);
	virtual ~ArmyController();
	bool HandleSdlEvent(SDL_Event & e) override;

	void Invalidate() override;
};

