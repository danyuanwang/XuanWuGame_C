#include "ServerBoardController.h"
#include "GameModel.h"



ServerBoardController::ServerBoardController(ModelObject* p_model)
	: ServerBaseController(p_model)
{
	const Board* p_board = static_cast<Board*>(p_model);
	_up_servermapcontroller = std::move(std::unique_ptr<ServerMapController>{ new ServerMapController(const_cast <Map*>(p_board->GetMap())) });
	_up_serverpanelcontroller = std::move(std::unique_ptr<ServerPanelController>{ new ServerPanelController(const_cast <Panel*>(p_board->GetPanel())) });
}


ServerBoardController::~ServerBoardController()
{
}

void ServerBoardController::HandleGameRequest(GamePlayRequest & gpr)
{
	_up_servermapcontroller->HandleGameRequest(gpr);
	_up_serverpanelcontroller->HandleGameRequest(gpr);

}

const ServerMapController * ServerBoardController::GetServerMapController() const
{
	return _up_servermapcontroller.get();
}

const ServerPanelController * ServerBoardController::GetServerPanelController() const
{
	return _up_serverpanelcontroller.get();
}
