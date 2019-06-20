#include "RestartCommand.h"
#include "GamePlayRequest.h"
#include "GameConnection.h"


RestartCommand::RestartCommand()
{
}


RestartCommand::~RestartCommand()
{
}

void RestartCommand::Execute()
{
	/*send game start request to server*/
	auto up_gpr = std::unique_ptr<GamePlayRequest>(
		new GamePlayRequest
		);

	up_gpr->SetScenario(GameScenario_GameBoard);
	up_gpr->SetFromObject(GameObject_GameView);
	up_gpr->SetToObject(GameObject_GameBoard);
	up_gpr->SetActionType(GameObjectAction_Restart);
	up_gpr->AddKeyValue("client_name", GameSettings::client_name);
	GameConnection::GetSingleton()->SendContent(up_gpr->ToJson().c_str());
}
