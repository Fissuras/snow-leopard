#include "Renderer.h"

//todo: use graphicContext features for translation, scaling, etc. instead of the naive SDL view
//will allow direct use of world coordinates instead of screen pixel coordinates, which would be pretty awesome

Renderer::Renderer(CL_DisplayWindow* window,CL_GraphicContext* gc_, WorldState* state_, CL_ResourceManager* res)
{
	gc = gc_;
	state = state_;
	resources = res;
	objects = state->getAllGameObjects();
	zoomLevel = 1.0; 
	screenStartX = 0.0;
	screenStartY = 0.0;
	screenWidth = window->get_width();
	screenHeight = window->get_height();
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
	gc->clear();

	screenStartX = zoomLevel * (((screenWidth - state->CoordinateSizeX / zoomLevel) * camera->location.x) / screenWidth); //puts it in the center
	screenStartY = zoomLevel * (((screenHeight - state->CoordinateSizeY / zoomLevel) * camera->location.y) / screenHeight);


	ConstGameObjectIter itr;
	for (itr = objects->begin(); itr!=objects->end();itr++)
	{
		GameObject* obj = *itr;
		CL_Sprite* sprite = spriteMap[obj->ID];
		sprite->set_scale(zoomLevel,zoomLevel);
		sprite->draw(*gc,zoomLevel * obj->location.x -screenStartX,
			(zoomLevel * obj->location.y - screenStartY));
	}
	
	return true;

}

bool Renderer::LoadSprites()
{
	ConstGameObjectIter itr;
	for (itr = objects->begin(); itr!=objects->end();itr++)
	{
		GameObject* obj = *itr;
		CL_Sprite* ptr = new CL_Sprite(obj->resourceName,resources,*gc);
		ptr->set_alignment(origin_center);
		ptr->set_rotation_hotspot(origin_center);
		ptr->set_base_angle(1.0);
		spriteMap[obj->ID] = ptr;
	}
	return true;
}