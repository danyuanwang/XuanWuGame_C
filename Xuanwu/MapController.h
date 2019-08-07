#pragma once
#include "BaseController.h"
#include "Map.h"
#include "MapView.h"
#include "CellController.h"
#include "MineController.h"
#include "ShopController.h"
#include "CastleController.h"
#include "ArmyController.h"
class MapController :
	public BaseController
{
private:
	MapView* GetMapView() const;
	Map* GetMapModel() const;

	std::vector<std::unique_ptr<CellController>> _cell_controllers;
	std::vector<std::unique_ptr<MineController>> _mine_controllers;
	std::unique_ptr<ShopController> _up_shop_controller;
	std::vector<std::unique_ptr<CastleController>> _castle_controllers;
	BaseController* _p_focused_controller;
	std::vector<std::unique_ptr<ArmyController>> _army_controllers;
public:
	MapController(MapView* p_view, Map* p_model);
	virtual ~MapController();

	virtual bool HandleSdlEvent(SDL_Event & e) override;
	BaseController* GetFocusedController() const override;
	void CaptureFocus(bool captured) override;

	void Invalidate() override;

};

