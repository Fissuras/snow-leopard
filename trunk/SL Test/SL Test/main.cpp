#include <SDL.h>
#include <SDL_TTF.h>
#include "Renderer.h"
#include <string>


int main( int argc, char* args[] )
{
	Renderer gameRenderer = Renderer();
	gameRenderer.init();

    SDL_Delay( 2000 );
    
    return 0;    
}
