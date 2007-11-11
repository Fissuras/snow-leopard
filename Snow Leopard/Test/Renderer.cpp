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

	screenStartX = std::abs(zoomLevel * (((screenWidth - state->CoordinateSizeX / zoomLevel) * camera->location.x) / screenWidth)); //puts it in the center
	screenStartY = std::abs(zoomLevel * (((screenHeight - state->CoordinateSizeY / zoomLevel) * camera->location.y) / screenHeight));


	ConstGameObjectIter itr;
	for (itr = objects->begin(); itr!=objects->end();itr++)
	{
		GameObject* obj = *itr;
		CL_Sprite* sprite = spriteMap[obj->ID];
		if (sprite == NULL)
		{
			loadSprite(obj);
			sprite = spriteMap[obj->ID];
		}
		sprite->set_scale(zoomLevel,zoomLevel);
		sprite->set_angle(obj->heading);
		sprite->draw(zoomLevel * obj->location.x -screenStartX,
			(zoomLevel * obj->location.y - screenStartY),gc);
	}
	
	return true;

}

bool Renderer::loadSprites(const GameObjectList* list)
{
	ConstGameObjectIter itr;
	for (itr = list->begin(); itr!=list->end();itr++)
	{
		GameObject* obj = *itr;
		//if (spriteMap.find(obj->ID) != spriteMap.end()) //already loaded
		//	continue;
		CL_Sprite* ptr = new CL_Sprite(obj->resourceName,resources);
		ptr->set_alignment(origin_center);
		ptr->set_rotation_hotspot(origin_center);
		ptr->set_base_angle(1.0);
		spriteMap[obj->ID] = ptr;
	}
	return true;
}

bool Renderer::loadSprite(GameObject* obj)
{
	//if (spriteMap.find(obj->ID) != spriteMap.end()) //already loaded
	//	return true;
	CL_Sprite* ptr = new CL_Sprite(obj->resourceName,resources);
	ptr->set_alignment(origin_center);
	ptr->set_rotation_hotspot(origin_center);
	ptr->set_base_angle(1.0);
	spriteMap[obj->ID] = ptr;
	return true;
}