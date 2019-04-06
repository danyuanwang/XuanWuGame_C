#include "Board.h"
#include"ErrorHandling.h"

Board::Board()
{

}


Board::~Board()
{
}

void Board::SetScreen(SDL_Surface* pScreen)
{
	m_pScreen = pScreen;
}

void Board::CheckSdlEvent(SDL_Event & e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
	{ //Select surfaces based on key press 
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: break;
		case SDLK_DOWN: break;
		case SDLK_LEFT: break;
		case SDLK_RIGHT:  break;
		default:break;
		}
	}
	default:
		break;
	}
}

void Board::TakeRequest(GamePlayRequest &gpr)
{

}

void Board::Draw()
{
	CHECK_VALUE(m_pScreen != NULL, XW_ERROR_CODE::BD_SDL_SURFACE_NOT_INITED, "Please call 'Board::SetScreen' to set screen");

}