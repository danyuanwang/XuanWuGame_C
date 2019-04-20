#pragma once
#include<string>
#include "ErrorHandling.h"
#include "SDL.h"
#include <sdl_image.h>
#include <sdl_ttf.h>
#include <sdl_mixer.h>
#include "constants.h"

class GameEngine
{
private: 
	bool m_initialized = false;
	void Check_Initialized();

	//The window we'll be rendering to 
	SDL_Window* m_sdlWindow = NULL; 
	
	//The surface contained by the window 
	SDL_Surface* m_sdlScreenSurface = NULL;

	//renderer
	SDL_Renderer* m_sdlRenderer = NULL;

	int m_startTicks = 0;
	int m_intervalOfFlips = 0;
public:
	GameEngine();

	~GameEngine();

	std::string GetResourcePath(const std::string &subDir = "");
	void Initialize();
	int PollEvent(SDL_Event & e);
	void BlitMe(SDL_Surface* xOut);
	void Flip(void);
	void DrawRect(int pos_x, int pos_y, int width, int height, XW_RGB_Color color) const;
};

