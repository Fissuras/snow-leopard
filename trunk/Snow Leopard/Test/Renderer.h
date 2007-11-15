#ifndef RENDERER_H_
#define RENDERER_H_

#include <map>
#include "boost/lexical_cast.hpp"
#include <stdlib.h>

class WorldState;
class GameObject;
class CL_DisplayWindow;
class CL_GraphicContext;
class CL_ResourceManager;

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