#include "Renderer.h"

#include "GameObject.h"
#include "WorldState.h"

#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>

Renderer::Renderer(CL_DisplayWindow* window,CL_GraphicContext* gc_, WorldState* state_, CL_ResourceManager* res)
{
	gc = gc_;
	state = state_;
	resources = res;
	zoomLevel = 1.0; 
	screenStartX = 0.0;
	screenStartY = 0.0;
	screenWidth = window->get_width();
	screenHeight = window->get_height();
	font = new CL_Font("Times New Roman",30);
	font->set_color(255,0,0);
}
bool Renderer::setCamera(GameObject* obj)
{
	camera = obj;
	return true;
}
bool Renderer::setCameraZoomLevel(double level)
{
	zoomLevel = level;
	return true;
}

bool Renderer::Render()
{
	const GameObjectList* objects = state->getAllGameObjects(WorldState::RENDER_SORTED);
	gc->clear();

	screenStartX = (zoomLevel * (( abs(screenWidth - state->CoordinateSizeX / zoomLevel) * camera->location.x) / screenWidth)); //puts it in the center
	screenStartY = (zoomLevel * (( abs(screenHeight - state->CoordinateSizeY / zoomLevel) * camera->location.y) / screenHeight));


	ConstGameObjectIter itr;
	for (itr = objects->begin(); itr!=objects->end();itr++)
	{
		GameObject* obj = *itr;
		CL_Sprite* sprite = obj->sprite;
		sprite->set_scale(zoomLevel,zoomLevel);
		sprite->set_angle(obj->displayHeading);
		sprite->draw(zoomLevel * obj->location.x -screenStartX,
			(zoomLevel * obj->location.y - screenStartY),gc);
		obj->collisionOutline->draw_smallest_enclosing_disc(zoomLevel * obj->location.x -screenStartX,
			(zoomLevel * obj->location.y - screenStartY),CL_Color(255,255,255,128),gc);
	}

	itr = objects->begin();
	font->draw(1,1,(*(itr++))->location.toString());
	font->draw(1,50,(*(itr++))->location.toString());
	font->draw(1,100,(*(itr))->location.toString());
	
	return true;

}