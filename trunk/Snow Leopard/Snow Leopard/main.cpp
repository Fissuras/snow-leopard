#include <string>
#include <iostream>
#include "GameObject.h"
#include "WorldState.h"
#include "point.h"
#include "Renderer.h"
#include "GameLogic.h"
#include "Starfury.h"

int main( int argc, char* args[] )
{
	Renderer *gameRenderer = new Renderer();
	gameRenderer->init();
    
	GameObject *g = new Starfury("Starfury",1,new point(1,1));
	g->imageSource = "images/Chmmr.gif";

	WorldState *state = new WorldState();
	state->insertObject(g,new point(1,1));

	GameLogic *logic = new GameLogic(state);

	gameRenderer->LoadImages(state->getAllGameObjects());
	gameRenderer->Render(state);
	logic->step();
	gameRenderer->Render(state);

	system("pause");

    return 0;    
}
