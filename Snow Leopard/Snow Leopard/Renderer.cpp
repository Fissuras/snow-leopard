#include "GameObject.h"
#include "WorldState.h"
#include <SDL.h>
#include <SDL_TTF.h>
#include "Renderer.h"
#include <iostream>

//Low end version
bool Renderer::Render(WorldState* state)
{
	for (int x = 0;x<state->xsize;x++)
	{
		for (int y = 0;y<state->ysize;y++)
		{
			GameObjectList* list = state->getAtLocation(new point(x,y));
			GameObjectIter itr;
			for (itr = list->begin();itr!=list->end();itr++)
			{
				GameObject* obj = *itr;
				std::cout << obj->displayName;
				std::cout << " " << obj->location.toString() << "\n";
			}
		}
	}
	return true;
}

bool Renderer::init()
{
	//try
	//{
	//SDL_Init(SDL_INIT_EVERYTHING);
	//TTF_Init();
 //   atexit(TTF_Quit);
	//atexit(SDL_Quit);

	//SDL_WM_SetCaption( "Snow Leopard", NULL );
 //   
	//SDL_Surface *screen = NULL;
 //   screen = SDL_SetVideoMode( 0, 0, 0, SDL_FULLSCREEN | SDL_HWSURFACE | SDL_DOUBLEBUF); //0 means current mode
	//int screenWidth = SDL_GetVideoInfo()->current_w;
	//int screenHeight = SDL_GetVideoInfo()->current_h;
	//return true;
	//}
	//catch(...)
	//{
	//	return false;
	//}
	
	return true;
}
