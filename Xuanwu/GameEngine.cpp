#include"Settings.h"
#include "GameEngine.h"
#include <SDL.h>

void GameEngine::Check_Initialized()
{
	CHECK_VALUE(m_initialized, XW_ERROR_CODE::GE_NOT_INITED, "Please call 'GameEngine::Initialize()' to initialize the engine first");
	CHECK_VALUE(m_sdlWindow != NULL, XW_ERROR_CODE::GE_NOT_INITED, "Please call 'GameEngine::Initialize()' to initialize the engine first");
	CHECK_VALUE(m_sdlScreenSurface != NULL, XW_ERROR_CODE::GE_NOT_INITED, "Please call 'GameEngine::Initialize()' to initialize the engine first");
}

GameEngine::GameEngine()
{

}


GameEngine::~GameEngine()
{
	if (m_initialized)
	{
		if (m_sdlWindow != NULL) {
			SDL_DestroyWindow(m_sdlWindow);
		}
		SDL_Quit();
	}
}

/*
	must be called before use any other member functions
*/
void GameEngine::Initialize()
{
	//TODO: need to lock the m_initialized for thread safe.
	if (!m_initialized) {
		m_initialized = (SDL_Init(SDL_INIT_VIDEO) >= 0);
		CHECK_VALUE(
			m_initialized,
			XW_ERROR_CODE::GE_INIT_FAILED,
			std::string("SDL could not be initialized! SDL_Error: %s", SDL_GetError())
		);
	}

	if (m_sdlWindow == NULL) {
		m_sdlWindow = SDL_CreateWindow(
			GameSettings::WindowCaption,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			GameSettings::WidthOfWindowX,
			GameSettings::HeightWindowY,
			SDL_WINDOW_SHOWN);

		CHECK_VALUE(
			m_sdlWindow != NULL,
			XW_ERROR_CODE::GE_SDL_WINDOW_CREATION_FAILED,
			std::string("Window could not be created! SDL_Error: %s", SDL_GetError())
		);
	}

	if (m_sdlScreenSurface == NULL) {
		m_sdlScreenSurface = SDL_GetWindowSurface(m_sdlWindow);
		CHECK_VALUE(
			m_sdlScreenSurface != NULL,
			XW_ERROR_CODE::GE_SDL_SURFACE_GETTING_FAILED,
			std::string("Surface could not be got! SDL_Error: %s", SDL_GetError())
		);
	}
	if (m_sdlRenderer == NULL) {
		m_sdlRenderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED);
		CHECK_VALUE(
			m_sdlRenderer != NULL,
			XW_ERROR_CODE::GE_SDL_RENDERER_CREATION_FAILED,
			std::string("renderer could not be created: %s", SDL_GetError())

		)
	}
	

	SDL_FillRect(
		m_sdlScreenSurface,
		NULL,
		SDL_MapRGB(
			m_sdlScreenSurface->format,
			GameSettings::BackgroundColor.Red,
			GameSettings::BackgroundColor.Green,
			GameSettings::BackgroundColor.Blue
		)
	);

	m_startTicks = SDL_GetTicks();
	
	m_intervalOfFlips = 1000 / GameSettings::FramePerSecond; 

	SDL_UpdateWindowSurface(m_sdlWindow);


}

int GameEngine::PollEvent(SDL_Event &e)
{
	Check_Initialized();
	return SDL_PollEvent(&e);
}

void GameEngine::BlitMe(SDL_Surface* xOut)
{
	Check_Initialized();
	SDL_BlitSurface(xOut, NULL, m_sdlScreenSurface, NULL);
	SDL_UpdateWindowSurface(m_sdlWindow);
}

void GameEngine::Flip()
{
	Check_Initialized();

	SDL_UpdateWindowSurface(m_sdlWindow);

	/* ensure the frame per second */
	Uint32 timeout = SDL_GetTicks() + m_intervalOfFlips;
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_intervalOfFlips)) {
		SDL_Delay(2);
	}

}
void GameEngine::DrawRect(int pos_x, int pos_y, int width, int height, XW_RGB_Color color)const
{
	SDL_Rect cell_rect = { pos_x, pos_y, width, height };
	SDL_SetRenderDrawColor(m_sdlRenderer, color.Red, color.Green, color.Blue, 0xFF);
	SDL_RenderFillRect(m_sdlRenderer, &cell_rect);
}
/*
	for test purpose
*/
std::string GameEngine::GetResourcePath(const std::string &subDir) {

	Check_Initialized();

	//We need to choose the path separator properly based on which
	//platform we're running on, since Windows uses a different
	//separator than most systems
#ifdef _WIN32
	const char PATH_SEP = '\\';
#else
	const char PATH_SEP = '/';
#endif
	//This will hold the base resource path: Lessons/res/
	//We give it static lifetime so that we'll only need to call
	//SDL_GetBasePath once to get the executable path
	static std::string baseRes;
	if (baseRes.empty()) {
		//SDL_GetBasePath will return NULL if something went wrong in retrieving the path
		char *basePath = SDL_GetBasePath();
		if (basePath) {
			baseRes = basePath;
			SDL_free(basePath);
		}

		CHECK_VALUE(basePath != NULL, XW_ERROR_CODE::GE_SDL_BASEPATH_FAILED, std::string("Error getting resource path: %d", SDL_GetError()));

		//We replace the last bin/ with res/ to get the the resource path
		size_t pos = baseRes.rfind("bin");
		baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
	}
	//If we want a specific subdirectory path in the resource directory
	//append it to the base path. This would be something like Lessons/res/Lesson0
	return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;

}