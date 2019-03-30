#include <iostream>
#include "GameEngine.h"
#include"Board.h"
#include "Client.h"

int main(int, char**) {
	GameEngine game_engine;
	Board game_board;
	std::string	str_host("192.168.0.105"), str_port("2014");

	auto up_msp = std::unique_ptr<NetMsgPump>(new NetMsgPump);
	auto up_cnmgr = std::unique_ptr<ConnectionMgr>(new ConnectionMgr());
	auto up_client = std::unique_ptr<Client>(new Client(str_host, str_port, up_cnmgr.get()));

	up_cnmgr->AddMsgListener(up_msp.get());

	game_engine.Initialize();

	up_client->Start();

	SDL_Event e;
	e.type = SDL_FIRSTEVENT;

	while (e.type != SDL_QUIT) {
		std::unique_ptr< NetPackMsg> up_msg;
		while (up_msp->Poll(up_msg))
		{
			//handle network messages

		}

		//Handle events on queue 
		while (game_engine.PollEvent(e) != 0) {
			game_board.CheckEvent(e);
		}
		game_board.Draw();
		game_engine.Flip();
	}

	up_client->Stop();
	return 0;
}