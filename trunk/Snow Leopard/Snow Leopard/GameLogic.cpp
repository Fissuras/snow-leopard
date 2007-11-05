#include "GameLogic.h"


GameLogic::GameLogic(WorldState* worldState)
{
	state=worldState;
}

bool GameLogic::step()
{
	GameObjectQueue* objectQueue = state->getAllGameObjects();
	for(unsigned i=0;i<objectQueue->size();i++)
	{
		GameObject* obj = objectQueue->top();
		objectQueue->pop(); //WHY?
		obj->doActions(state);
	}
	return true;
}