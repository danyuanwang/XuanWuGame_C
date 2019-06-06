#include "GameEngine.h"
#include"GameClient.h"
#include "Client.h"

int main(int, char**) {
	std::string	str_host("127.0.0.1"), str_port("2014");

	std::unique_ptr<NetMsgPump> up_msp (new NetMsgPump);
	std::unique_ptr<ConnectionMgr> up_cnmgr (new ConnectionMgr());
	std::unique_ptr<Client> up_client (new Client(str_host, str_port, up_cnmgr.get()));

	std::unique_ptr<GameEngine> up_game_engine (new GameEngine);
	up_game_engine->Initialize();

	std::unique_ptr<GameClient> up_game (new GameClient(up_game_engine.get(), up_cnmgr.get()));

	up_cnmgr->AddMsgListener(up_msp.get());
	up_client->Start();

	SDL_Event e;
	e.type = SDL_FIRSTEVENT;

	while (e.type != SDL_QUIT) {
		std::unique_ptr< NetPackMsg> up_msg;
		while (up_msp->Poll(up_msg))
		{
			//handle network messages
			GamePlayRequest gpr{ up_msg->GetContent() };
			up_game->ProcessGameRequest(gpr);
		}

		//Handle events on queue 
		while (up_game_engine->PollEvent(e) != 0) {
			up_game->CheckSdlEvent(e);
		}

		up_game_engine->Flip();
	}

	up_client->Stop();
	return 0;
}