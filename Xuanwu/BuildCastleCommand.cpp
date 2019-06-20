#include "BuildCastleCommand.h"
#include "GamePlayRequest.h"
#include "GameConnection.h"
#include "Settings.h"




BuildCastleCommand::BuildCastleCommand(int row, int col)
{
	_row = row;
	_col = col;
}


BuildCastleCommand::~BuildCastleCommand()
{
}

void BuildCastleCommand::Execute()
{
	/*send game start request to server*/
	auto up_gpr = std::unique_ptr<GamePlayRequest>(
		new GamePlayRequest
		);
	
	up_gpr->SetScenario(GameScenario_Map);
	up_gpr->SetFromObject(GameObject_GameBoard);
	up_gpr->SetToObject(GameObject_GameModel);
	up_gpr->SetActionType(GameObjectAction_BuildCastle);
	up_gpr->AddKeyValue("col_index", std::to_string(_col));
	up_gpr->AddKeyValue("row_index", std::to_string(_row));
	up_gpr->AddKeyValue("client_name", GameSettings::client_name);
	GameConnection::GetSingleton()->SendContent(up_gpr->ToJson().c_str());
}
