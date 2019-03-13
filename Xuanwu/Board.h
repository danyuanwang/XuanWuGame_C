#pragma once
#include"SDL.h"
class Board
{
private:
	SDL_Surface* m_screen = NULL;

public:
	Board();
	~Board();
	void CheckEvent(SDL_Event &e);
	void Draw(void);
};

