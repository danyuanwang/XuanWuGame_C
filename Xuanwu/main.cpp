#include "GameEngine.h"
#include"GameClient.h"
#include "Client.h"
#include "GameConnection.h"
#include "logger.h"

int main(int, char**) {
	std::string	str_host("127.0.0.1"), str_port("2014");

	std::string str_hostname = boost::asio::ip::host_name();

	std::unique_ptr<Client> up_client (new Client(str_host, str_port, GameConnection::GetSingleton()));

	std::unique_ptr<GameEngine> up_game_engine (new GameEngine);
	up_game_engine->Initialize();

	std::unique_ptr<GameClient> up_game (new GameClient(up_game_engine.get()));

	up_client->Start();

	up_game->Start();

	LOGTRACE("Xuanwu client starts on: %s:%s, connecting to: %s", str_hostname.c_str(), str_port.c_str(), str_host.c_str());

	SDL_Event e;
	e.type = SDL_FIRSTEVENT;

	while (e.type != SDL_QUIT) {
		std::unique_ptr< NetPackMsg> up_msg;
		while (GameConnection::GetSingleton()->PollMsg(up_msg))
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