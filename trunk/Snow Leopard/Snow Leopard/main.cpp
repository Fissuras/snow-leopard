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
	int main(int argc, CL_String::CharacterType** argv);
};

// Create global application object:
// You MUST include this line or the application start-up will fail to
// locate your application object.
DisplayApplication app;

int DisplayApplication::main(int argc, CL_String::CharacterType** argv)
{
	// Setup clanlib modules:

	CL_SetupCore setup_core;
	CL_SetupDisplay setup_display;
	CL_SetupGL setup_gl;
	
	CL_DisplayWindow window(cl_text("Snow Leopard"), 640, 480);
	CL_GraphicContext gc = window.get_gc();

	CL_ResourceManager* resources = new CL_ResourceManager(cl_text("resources.xml"));


	GameObject *g = new Starfury("Starfury",1,new point(25,100));
	g->imageSource = "Androsynth.png";
	WorldState *state = new WorldState();
	state->insertObject(g,new point(25,100));
	GameLogic *logic = new GameLogic(state);
	Renderer* renderer = new Renderer(&gc,state,resources);

	renderer->LoadSprites();

	CL_Font font_tahoma(gc, cl_text("Tahoma"), 16);
	gc.set_font(font_tahoma);
	gc.draw_text(10, 10, cl_text("Test"), CL_Colord::lemonchiffon);
	
	while (true)
	{
	renderer->Render();
	window.flip();
	logic->step();
	}
	
	
	return 0;
}