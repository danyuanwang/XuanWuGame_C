#include "ServerArmyController.h"



ServerArmyController::ServerArmyController(ModelObject* p_model)
	: ServerBaseController(p_model)
{
}


ServerArmyController::~ServerArmyController()
{
}

void ServerArmyController::HandleGameRequest(GamePlayRequest & gpr)
{
	switch (gpr.GetActionType())
	{
	case GameObjectAction_Move:
	{
		Army* p_army = static_cast<Army*>(_p_model);
		int end_col = gpr.GetKeyValue<int>("end_col_index");
		int end_row = gpr.GetKeyValue<int>("end_row_index");
		int army_id = gpr.GetKeyValue<int>("army_id");
		if (army_id == p_army->GetModelObjectID()) 
		{
			p_army->SetEndIndex(end_row, end_col);
		}
		break;
	}
	case GameObjectAction_UpdateDataModel:
	{
		Army* p_army = static_cast<Army*>(_p_model);
		p_army->UpdateData();
		
		break;
	}
	default:
		break;
	}
}
