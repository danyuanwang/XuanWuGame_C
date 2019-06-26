#include "ServerGameState.h"
#include"ServerGameController.h"


ServerGameState::ServerGameState()
{
}


ServerGameState::~ServerGameState()
{
}

void ServerGameState::HandleGameRequest(ServerBaseController * p_controller, GamePlayRequest & gpr)
{
	ServerGameController* p_game_controller = static_cast<ServerGameController*>(p_controller);

	p_game_controller->_change_state();
}
