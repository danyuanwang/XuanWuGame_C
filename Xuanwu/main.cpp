#include <iostream>
#include "GameEngine.h"
#include"Board.h"
int main(int, char**) {
	GameEngine game_engine;
	Board game_board;

	game_engine.Initialize();

	SDL_Event e;
	e.type = SDL_FIRSTEVENT;

	while (e.type != SDL_QUIT) {
		//Handle events on queue 
		while (game_engine.PollEvent(e) != 0) {
			game_board.CheckEvent(e);
		}
		game_board.Draw();
		game_engine.Flip();
	}
	return 0;
}