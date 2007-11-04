#include "GameObject.h"
#include "WorldState.h"


GameObject::GameObject()
{
}

bool GameObject::doActions(WorldState* worldState)
{
	return true;
}

bool GameObject::registerCollision(GameObjectList collisions)
{
	return true;
}