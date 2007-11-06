#include "GameLogic.h"


GameLogic::GameLogic(WorldState* worldState)
{
	state=worldState;
}

bool GameLogic::step()
{
	GameObjectList* objects = state->getAllGameObjects();
	GameObjectIter itr;
	for(itr = objects->begin();itr !=objects->end();itr++)
	{
		GameObject* obj = *itr;
		obj->doActions(state);
	}
	return true;
}