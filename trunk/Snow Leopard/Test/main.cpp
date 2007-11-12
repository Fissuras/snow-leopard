#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>
#include <string>
#include <iostream>
#include "GameObject.h"
#include "WorldState.h"
#include "Renderer.h"
#include "point.h"
#include "GameLogic.h"
#include "Starfury.h"
#include <ctime>

class DisplayApplication : public CL_ClanApplication
{

public:
	int main(int argc, char** argv);
};

// Create global application object:
// You MUST include this line or the application start-up will fail to
// locate your application object.
DisplayApplication app;

int DisplayApplication::main(int argc,  char **argv)
{
	// Setup clanlib modules:

	CL_SetupCore setup_core;
	CL_SetupDisplay setup_display;
	CL_SetupGL setup_gl;
	
	CL_DisplayWindow* window = new CL_DisplayWindow("Snow Leopard", 640, 480);
	CL_GraphicContext* gc = window->get_gc();
	CL_InputContext* ic = window->get_ic();

	CL_InputDevice keyboard = ic->get_keyboard();
	CL_InputDevice mouse = ic->get_mouse();


	CL_ResourceManager* resources = new CL_ResourceManager("resources.xml");

	GameObject *g = new Starfury("Starfury",resources);
	//GameObject *f = new Starfury("Starfury",resources);
	//f->speed = 0;
	g->speed = 10;

	g->heading = 180;
	WorldState *state = new WorldState();
	state->insertObject(g,point(320,240));
	//state->insertObject(f,point(200,100));

	
	Renderer* renderer = new Renderer(window,gc,state,resources);
	GameLogic *logic = new GameLogic(state,(Ship*)g,ic,renderer);

	renderer->setCamera(g);
	renderer->setCameraZoomLevel(1.0);

	//renderer->LoadSprites(state->getAllGameObjects()); currently sprites load when the corresponding object is inserted into the world
	
	while (true)
	{
	renderer->Render();
	window->flip();
	CL_System::keep_alive();
	logic->step();
	}
	
	
	return 0;
}