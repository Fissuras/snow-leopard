#include "Renderer.h"

Renderer::Renderer(CL_GraphicContext* gc_, WorldState* state_, CL_ResourceManager* res)
{
	gc = gc_;
	state = state_;
	resources = res;
	objects = state->getAllGameObjects();
	zoomLevel = 1.0; //will zoom in holding the top left the same (not the center)
	screenStartX = 0.0;
	screenStartY = 0.0;
}

bool Renderer::Render()
{
	gc->clear();
	ConstGameObjectIter itr;
	for (itr = objects->begin(); itr!=objects->end();itr++)
	{
		GameObject* obj = *itr;
		CL_Sprite* sprite = spriteMap[obj->ID];
		sprite->set_scale(zoomLevel,zoomLevel);
		sprite->draw(*gc,(obj->location.x/zoomLevel)-screenStartX,(obj->location.y/zoomLevel)-screenStartY);
	}
	
	return true;

}

bool Renderer::LoadSprites()
{
	ConstGameObjectIter itr;
	for (itr = objects->begin(); itr!=objects->end();itr++)
	{
		GameObject* obj = *itr;
		CL_Sprite* ptr = new CL_Sprite(cl_text("Starfury"),resources,*gc);
		spriteMap[obj->ID] = ptr;
	}
	return true;
}