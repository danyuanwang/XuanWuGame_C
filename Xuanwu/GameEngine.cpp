#include"Settings.h"
#include "GameEngine.h"
#include <SDL.h>
#include "SDL_image.h"


void GameEngine::Check_Initialized() const
{
	CHECK_VALUE(m_initialized, XW_ERROR_CODE::GE_NOT_INITED, "Please call 'GameEngine::Initialize()' to initialize the engine first");
	CHECK_VALUE(m_sdlWindow != NULL, XW_ERROR_CODE::GE_NOT_INITED, "Please call 'GameEngine::Initialize()' to initialize the engine first");
	CHECK_VALUE(m_sdlScreenSurface != NULL, XW_ERROR_CODE::GE_NOT_INITED, "Please call 'GameEngine::Initialize()' to initialize the engine first");
}

SDL_Texture * GameEngine::LoadTexture(std::string path) const

{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	newTexture = SDL_CreateTextureFromSurface(m_sdlRenderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return newTexture;
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
	if (m_ttf_inited == false){
		if (TTF_Init() != -1) {
			m_ttf_inited = true;
		}
		CHECK_VALUE(
			m_ttf_inited == true,
			XW_ERROR_CODE::GE_TTF_INITIALIZATION_FAILED,
			std::string("TTF could not be initialized: %s", SDL_GetError())
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

	//SDL_UpdateWindowSurface(m_sdlWindow);
	SDL_RenderPresent(m_sdlRenderer);

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

void GameEngine::RenderPic(int pos_x, int pos_y, int width, int height, const char* relative_picture_path) const
{
	std::string res_path = GetResourcePath(std::string()) + std::string(relative_picture_path);

	SDL_Texture* texture = NULL;
	texture = LoadTexture(res_path);
	const SDL_Rect position = { pos_x, pos_y, width,  height };
	SDL_RenderCopy(m_sdlRenderer, texture, NULL, &position);
	SDL_DestroyTexture(texture);

}
void GameEngine::RenderText(const char* text, XW_RGB_Color color, int pos_x, int pos_y, int width, int height) const {
	std::string res_path = GetResourcePath(std::string()) + std::string("Walkway_Bold.ttf");
	TTF_Font* font = TTF_OpenFont(res_path.c_str(), 16);
	SDL_Color sdl_color;
	sdl_color.r = color.Red;
	sdl_color.g = color.Green;
	sdl_color.b = color.Blue;
	const SDL_Rect position = { pos_x, pos_y, width, height };
	SDL_Surface* ttf_surface = TTF_RenderText_Solid(font, text, sdl_color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_sdlRenderer, ttf_surface);
	SDL_RenderCopy(m_sdlRenderer, texture, NULL, &position);
	//freeing surfaces
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(ttf_surface);
	TTF_CloseFont(font);
}

/*
	retrieve the absolute path for a resource file
*/
std::string GameEngine::GetResourcePath(const std::string &subDir) const
{

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
		baseRes = baseRes.substr(0, pos) + "resource" + PATH_SEP;
	}
	//If we want a specific subdirectory path in the resource directory
	//append it to the base path. This would be something like Lessons/res/Lesson0
	return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;

}