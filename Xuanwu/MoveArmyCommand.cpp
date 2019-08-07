#include "MoveArmyCommand.h"
#include "GamePlayRequest.h"
#include "GameConnection.h"
#include "Settings.h"



MoveArmyCommand::MoveArmyCommand(int row, int col, unsigned long id)
{
	_end_col = col;
	_end_row =row;
	_army_id =id;
}


MoveArmyCommand::~MoveArmyCommand()
{
}

void MoveArmyCommand::Execute()
{
	auto up_gpr = std::unique_ptr<GamePlayRequest>(
		new GamePlayRequest
		);

	up_gpr->SetScenario(GameScenario_Map);
	up_gpr->SetFromObject(GameObject_GameBoard);
	up_gpr->SetToObject(GameObject_GameModel);
	up_gpr->SetActionType(GameObjectAction_Move);
	up_gpr->AddKeyValue("end_col_index", std::to_string(_end_col));
	up_gpr->AddKeyValue("end_row_index", std::to_string(_end_row));
	up_gpr->AddKeyValue("client_name", GameSettings::client_name);
	up_gpr->AddKeyValue("army_id", std::to_string(_army_id));
	GameConnection::GetSingleton()->SendContent(up_gpr->ToJson().c_str());
}

