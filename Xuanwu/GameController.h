#pragma once
#include "GameEngine.h"

class GameController
{
public:
	GameController();
	virtual ~GameController();

	void CheckSdlEvent(SDL_Event & e);
};

