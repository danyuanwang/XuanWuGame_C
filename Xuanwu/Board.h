#pragma once
#include"SDL.h"
class Board
{
private:
	SDL_Surface* m_pScreen = NULL;

public:
	Board();
	~Board();
	void SetScreen(SDL_Surface* pScreen);
	void CheckEvent(SDL_Event &e);
	void Draw();
};

