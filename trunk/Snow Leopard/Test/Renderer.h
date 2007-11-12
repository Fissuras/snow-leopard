#ifndef RENDERER_H_
#define RENDERER_H_

#include "WorldState.h"
#include "GameObject.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>
#include <map>
#include "boost/lexical_cast.hpp"
#include <stdlib.h>

class WorldState;
class GameObject;

class Renderer{
public:
	Renderer::Renderer(CL_DisplayWindow* window,CL_GraphicContext* gc, WorldState* state,CL_ResourceManager* res);
	bool Renderer::Render();
	int screenWidth;
	int screenHeight;
	bool Renderer::setCamera(GameObject* obj);
	bool Renderer::setCameraZoomLevel(double level);

private:
	GameObject* camera;
	double zoomLevel;
	CL_GraphicContext* gc;
	WorldState* state;
	CL_ResourceManager* resources;
	double screenStartX;
	double screenStartY;

};

#endif