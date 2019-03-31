#include <iostream>
#include "GameEngine.h"
#include"Board.h"
#include "Client.h"
#include "GamePlayRequest.h"

int main(int, char**) {
	GameEngine game_engine;
	Board game_board;
	std::string	str_host("127.0.0.1"), str_port("2014");

	auto up_msp = std::unique_ptr<NetMsgPump>(new NetMsgPump);
	auto up_cnmgr = std::unique_ptr<ConnectionMgr>(new ConnectionMgr());
	auto up_client = std::unique_ptr<Client>(new Client(str_host, str_port, up_cnmgr.get()));

	up_cnmgr->AddMsgListener(up_msp.get());

	game_engine.Initialize();

	up_client->Start();

	/*for test purpose START >>*/
	auto up_gpr = std::unique_ptr<GamePlayRequest>(
		new GamePlayRequest
	{ 
		GameScenario_GameBoard, 
		GameOjbect_GameView , 
		GameOjbect_GameBoard, 
		GameOjbectAction_Restart 
	}
	);

	auto up_netMsg = std::unique_ptr<NetPackMsg>(
		new NetPackMsg{ up_gpr->ToJson().c_str() }
	);
	up_cnmgr->SendMsg(up_netMsg.get());

	/*<< END for test purpose*/



	SDL_Event e;
	e.type = SDL_FIRSTEVENT;

	while (e.type != SDL_QUIT) {
		std::unique_ptr< NetPackMsg> up_msg;
		while (up_msp->Poll(up_msg))
		{
			//handle network messages
			/*for test purpose START >>*/

			GamePlayRequest gpr{ (char*)up_msg->Body() };
			std::cout << gpr.ToJson();

			/*<< END for test purpose*/

		}

		//Handle events on queue 
		//while (game_engine.PollEvent(e) != 0) {
		//	game_board.CheckEvent(e);
		//}
		//game_board.Draw();
		//game_engine.Flip();
	}

	up_client->Stop();
	return 0;
}