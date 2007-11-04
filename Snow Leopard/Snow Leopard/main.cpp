#include <string>
#include <iostream>
#include "GameObject.h"
#include "WorldState.h"
#include "point.h"
#include "Renderer.h"

int main( int argc, char* args[] )
{
	Renderer gameRenderer = Renderer();
	gameRenderer.init();
    
	GameObject *g = new GameObject("Arbiter",0);
	g->displayID = "images/Chmmr.gif"

	WorldState *state = new WorldState();
	state->insertObject(g,new point(4,4));

	gameRenderer.Render(state);

	system("pause");

    return 0;    
}
