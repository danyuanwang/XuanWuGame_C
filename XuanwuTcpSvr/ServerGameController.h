#pragma once
#include "ServerBaseController.h"
#include "ServerBoardController.h"
#include "ServerPlayerController.h"
#include <map>
#include "ServerGameState.h"
class ServerGameController :
	public ServerBaseController
{
public:
	ServerGameController(ModelObject* p_model);
	virtual ~ServerGameController();
	void HandleGameRequest(GamePlayRequest& gpr) override;
	const ServerBoardController* GetServerBoardController() const;

private:
	std::unique_ptr<ServerBoardController> _up_serverboardcontroller;
	std::map<std::string, std::unique_ptr<ServerPlayerController>> _map_serverplayercontroller;

	enum ServerGameStateValue
	{
		idle = 0,

		//...

		total_number_of_states
	};

	std::unique_ptr<ServerGameState> _state_machine[total_number_of_states];
	ServerGameStateValue _state_value;
	void _change_state();

	friend class ServerGameState;
	friend class ServerGameStateIdle;

};

