#include "Renderer.h"

Renderer::Renderer(CL_GraphicContext* gc_, WorldState* state_, CL_ResourceManager* res)
{
	gc = gc_;
	state = state_;
	resources = res;
	objects = state->getAllGameObjects();
}

bool Renderer::Render()
{
	gc->clear();
	ConstGameObjectIter itr;
	for (itr = objects->begin(); itr!=objects->end();itr++)
	{
		GameObject* obj = *itr;
		CL_Sprite* sprite = spriteMap[obj->ID];
		sprite->draw(*gc,obj->location.x,obj->location.y);
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

		//might want to make sourceSize have height and width,
		//to support rectangles instead of just squares
		obj->sourceSize = ptr->get_width();
		obj->displaySize = ptr->get_width();
		
		spriteMap[obj->ID] = ptr;
	}
	return true;
}