#include <iostream>
#include "GameEngine.h"
#include"GameClient.h"
#include "Client.h"

int main(int, char**) {
	std::string	str_host("127.0.0.1"), str_port("2014");

	auto up_msp = std::unique_ptr<NetMsgPump>(new NetMsgPump);
	auto up_cnmgr = std::unique_ptr<ConnectionMgr>(new ConnectionMgr());
	auto up_client = std::unique_ptr<Client>(new Client(str_host, str_port, up_cnmgr.get()));

	auto up_game_engine = std::unique_ptr<GameEngine>(new GameEngine);
	up_game_engine->Initialize();

	auto up_game = std::unique_ptr<GameClient>(new GameClient(up_game_engine.get(), up_cnmgr.get()));

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

		//game_board.Draw();
		//game_engine.Flip();
	}

	up_client->Stop();
	return 0;
}