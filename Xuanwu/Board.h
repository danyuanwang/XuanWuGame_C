#pragma once
#include"SDL.h"
#include "GamePlayRequest.h"

class Board
{
private:
	SDL_Surface* m_pScreen = NULL;

public:
	Board();
	~Board();
	void SetScreen(SDL_Surface* pScreen);
	void CheckSdlEvent(SDL_Event &e);
	void TakeRequest(GamePlayRequest &gpr);
	void Draw();
};

