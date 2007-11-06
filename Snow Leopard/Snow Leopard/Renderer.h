#ifndef RENDERER_H_
#define RENDERER_H_

#include "WorldState.h"
#include "GameObject.h"
#include "SDL.h"
#include <map>

class WorldState;
class GameObject;

class Renderer{
public:
	bool Render(WorldState* worldState);
	bool init();
	int screenWidth;
	int screenHeight;
	bool LoadImages(GameObjectList* list);

private:
	SDL_Surface* load_image( std::string filename ) ;
	std::map<int,SDL_Surface*> imageMap;
	SDL_Surface* screen;

};

#endif