#ifndef RENDERER_H_
#define RENDERER_H_

#include "WorldState.h"
#include "GameObject.h"
#include "SDL.h"

class WorldState;
class GameObject;

class Renderer{
public:
	bool Render(WorldState* worldState);
	bool init();
	int screenWidth;
	int screenHeight;

};

#endif