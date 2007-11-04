#include <string>
#include <iostream>
#include "GameObject.h"
#include "WorldState.h"
#include "point.h"

int main( int argc, char* args[] )
{
	/*Renderer gameRenderer = Renderer();
	gameRenderer.init();
	SDL_Delay( 2000 );*/
    
	GameObject *g = new GameObject();
	g->displayName = "Test";

	WorldState *state = new WorldState();
	point *p = new point();
	p->x = 4;
	p->y = 4;
	state->insertObject(g,p);

	GameObjectList* list = new GameObjectList();
	list->push_front(g);
	std::cout << (list->pop_front())->displayName;

	system("pause");

    return 0;    
}
