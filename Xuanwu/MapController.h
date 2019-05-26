#pragma once
#include "BaseController.h"
#include "Map.h"
#include "MapView.h"
#include "CellController.h"
#include "MineController.h"
class MapController :
	public BaseController
{
private:
	MapView* GetMapView() const;
	Map* GetMapModel() const;

	std::vector<CellController> _cell_controllers;
	std::vector<MineController> _mine_controllers;

	BaseController* _p_focused_controller;

public:
	MapController(MapView* p_view, Map* p_model);
	virtual ~MapController();

	virtual bool HandleSdlEvent(SDL_Event & e) override;
	BaseController* GetFocusedController() const override;
	void CaptureFocus(bool captured) override;

	void Invalidate() override;

};

