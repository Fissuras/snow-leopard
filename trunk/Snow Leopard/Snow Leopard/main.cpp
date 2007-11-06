#include <string>
#include <iostream>
#include "GameObject.h"
#include "WorldState.h"
#include "point.h"
#include "Renderer.h"
#include "GameLogic.h"
#include "Starfury.h"
#include <ctime>


int main( int argc, char* args[] )
{
	Renderer *gameRenderer = new Renderer();
	gameRenderer->init();
    
	GameObject *g = new Starfury("Starfury",1,new point(25,100));
	g->imageSource = "images/Earthling.gif";


	GameObject *f = new Starfury("1",1,new point(50,100));
	f->imageSource = "images/Chenjesu.gif";


	GameObject *m = new Starfury("2",1,new point(100,50));
	m->imageSource = "images/Melnorme.gif";

	WorldState *state = new WorldState();
	state->insertObject(g,new point(25,100));
	state->insertObject(f,new point(50,100));
	state->insertObject(m,new point(100,50));
	state->deleteObject(g);

	GameLogic *logic = new GameLogic(state);

	gameRenderer->LoadImages(state->getAllGameObjects());
	
	clock_t start,stop;
	start = clock();
	for (int x = 0; x<200 ; x++)
	{
	gameRenderer->Render(state);
	logic->step();
	}
	stop=clock();
	std::cout << (double(stop)-double(start));
	system("pause");

    return 0;    
}
