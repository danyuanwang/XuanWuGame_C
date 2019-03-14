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

void Board::CheckEvent(SDL_Event & e)
{
}

void Board::Draw()
{
	CHECK_VALUE(m_pScreen != NULL, XW_ERROR_CODE::BD_SDL_SURFACE_NOT_INITED, "Please call 'Board::SetScreen' to set screen");
	
}