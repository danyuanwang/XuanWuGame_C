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
	void Check_Initialized() const;

	//The window we'll be rendering to 
	SDL_Window* m_sdlWindow = NULL; 
	
	//The surface contained by the window 
	SDL_Surface* m_sdlScreenSurface = NULL;

	//renderer
	SDL_Renderer* m_sdlRenderer = NULL;

	int m_startTicks = 0;
	int m_intervalOfFlips = 0;
	SDL_Texture* LoadTexture(std::string path) const;
	bool m_ttf_inited = false;

public:
	GameEngine();

	~GameEngine();

	std::string GetResourcePath(const std::string &subDir = "") const;
	void Initialize();
	int PollEvent(SDL_Event & e);
	void BlitMe(SDL_Surface* xOut);
	void Flip(void);
	void DrawRect(int pos_x, int pos_y, int width, int height, XW_RGB_Color color) const;
	void DrawRect(int pos_x, int pos_y, int width, int height, XW_RGB_Color color, unsigned char alpha) const;

	void RenderPic(int pos_x, int pos_y, int width, int height, const char* picture_path) const;
	void RenderText(const char* text, XW_RGB_Color color, int pos_x, int pos_y, int width, int height) const;
	
};

