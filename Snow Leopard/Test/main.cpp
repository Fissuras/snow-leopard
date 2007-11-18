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
#include <ctime>
#include "NonInteractiveBackground.h" 
#include "AI_Move_DoNothing.h"
#include "AI_Shoot_DoNothing.h"
#include "PulseCannon.h"
#include "ShotgunCannon.h"
#include "Vector2D.h"



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

	Ship *g = new Ship("Starfury",resources);
	GameObject* background = new NonInteractiveBackground("background",resources);
	//GameObject *f = new Starfury("Starfury",resources);

	g->AI_Movement = &AI_Move_DoNothing;
	g->AI_Shooting = &AI_Shoot_DoNothing;
	g->weapons->push_back(new PulseCannon());
	g->thrust = .08;

	WorldState *state = new WorldState();
	state->insertObject(g,point(320,240));
	state->insertObject(background,point(state->CoordinateSizeX / 2,state->CoordinateSizeY /2));
	//state->insertObject(f,point(200,100));

	
	Renderer* renderer = new Renderer(window,gc,state,resources);
	GameLogic *logic = new GameLogic(state,(Ship*)g,ic,renderer);

	renderer->setCamera(g);
	renderer->setCameraZoomLevel(1.0);

    CL_FramerateCounter* framerate = new CL_FramerateCounter();
	framerate->set_fps_limit(60);
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