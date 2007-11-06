#include "GameObject.h"
#include "WorldState.h"

int GameObject::IDCount = 0;
GameObject::GameObject(std::string name, int fact, point* p)
{
	displayName = name;
	faction = fact;
	location = *p;
	ID = getID();
	velocity[0] = 0.0;
	velocity[1] = 0.0;

}

int GameObject::getID()
{
	IDCount++;
	return IDCount;
}

bool GameObject::doActions(WorldState* worldState)
{
	return true;
}

bool GameObject::registerCollision(GameObjectList collisions)
{
	return true;
}

bool GameObject::operator<(GameObject &b)
{
	return priority<b.priority;
}