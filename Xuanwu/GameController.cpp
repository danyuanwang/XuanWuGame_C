#include "GameController.h"



GameController::GameController()
{
}


GameController::~GameController()
{
}

void GameController::CheckSdlEvent(SDL_Event & e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
	{ //Select surfaces based on key press 
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
		{
			break;
		}
		case SDLK_DOWN:
		{
			break;
		}
		case SDLK_LEFT:
		{
			break;
		}
		case SDLK_RIGHT:
		{
			break;
		}
		default:
		{
			break;
		}
		}
	}
	default:
	{
		break;
	}
	}

}