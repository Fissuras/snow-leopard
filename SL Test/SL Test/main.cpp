#include <SDL.h>
#include <SDL_TTF.h>
#include <string>


int main( int argc, char* args[] )
{
    SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
    atexit(TTF_Quit);
    
	SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode( 0, 0, 0, SDL_FULLSCREEN | SDL_HWSURFACE | SDL_DOUBLEBUF); //0 means current mode
	int screenWidth = SDL_GetVideoInfo()->current_w;
	int screenHeight = SDL_GetVideoInfo()->current_h;

    SDL_WM_SetCaption( "Snow Leopard", NULL );


	TTF_Font *fntArial = TTF_OpenFont( "arial.ttf", 128 );
	SDL_Color blue = {0,0,255,0};
	SDL_Surface *sText = TTF_RenderText_Solid( fntArial, "Snow Leopard", blue );
    SDL_Rect rcDest = {screenWidth/2 - sText->w/2,0,0,0};
    SDL_BlitSurface( sText,NULL, screen,&rcDest );

	SDL_Flip(screen);
    SDL_Delay( 2000 );
    SDL_Quit();
    
    return 0;    
}
