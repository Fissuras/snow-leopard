#include "GameLogic.h"


GameLogic::GameLogic(WorldState* worldState)
{
	state=worldState;
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