#include "GameLogic.h"


GameLogic::GameLogic(WorldState* worldState,GameObject* ship,CL_InputContext* ic)
{
	state=worldState;
	keyboard = ic->get_keyboard();
	mouse = ic->get_mouse();
	playerShip = ship;
}

bool GameLogic::step()
{
	
	const GameObjectList* objects = state->getAllGameObjects();
	ConstGameObjectIter itr;
	for(itr = objects->begin();itr !=objects->end();itr++)
	{
		GameObject* obj = *itr;
		obj->doActions(state);
	}
	return true;
}