#include "GameObject.h"
#include "WorldState.h"


GameObject::GameObject(std::string name, int fact, point* p)
{
	displayName = name;
	faction = fact;
	location = *p;

}

bool GameObject::doActions(WorldState* worldState)
{
	return true;
}

bool GameObject::registerCollision(GameObjectList collisions)
{
	return true;
}