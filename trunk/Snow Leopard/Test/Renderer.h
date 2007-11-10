#ifndef RENDERER_H_
#define RENDERER_H_

#include "WorldState.h"
#include "GameObject.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>
#include <map>

class WorldState;
class GameObject;

class Renderer{
public:
	Renderer::Renderer(CL_GraphicContext* gc, WorldState* state,CL_ResourceManager* res);
	bool Renderer::Render();
	int screenWidth;
	int screenHeight;
	bool Renderer::LoadSprites();
	bool Renderer::setCamera(GameObject* obj);
	bool Renderer::setCameraZoomLevel(double level);

private:
	GameObject* camera;
	double zoomLevel;
	CL_GraphicContext* gc;
	WorldState* state;
	const GameObjectList* objects;
	std::map<int,CL_Sprite*> spriteMap;
	CL_ResourceManager* resources;
	double screenStartX;
	double screenStartY;

};

#endif