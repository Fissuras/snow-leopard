#include "GameObject.h"
#include "WorldState.h"
#include <SDL.h>
#include <SDL_TTF.h>
#include "Renderer.h"


bool Renderer::Render(WorldState* worldState)
{
	return true;
}

bool Renderer::init()
{
	try
	{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
    atexit(TTF_Quit);
	atexit(SDL_Quit);

	SDL_WM_SetCaption( "Snow Leopard", NULL );
    
	SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode( 0, 0, 0, SDL_FULLSCREEN | SDL_HWSURFACE | SDL_DOUBLEBUF); //0 means current mode
	int screenWidth = SDL_GetVideoInfo()->current_w;
	int screenHeight = SDL_GetVideoInfo()->current_h;
	return true;
	}
	catch(...)
	{
		return false;
	}
}
