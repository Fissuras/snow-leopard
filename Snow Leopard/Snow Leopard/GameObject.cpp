#include "GameObject.h"
#include "WorldState.h"


GameObject::GameObject(std::string name, int fact, point* p)
{
	displayName = name;
	faction = fact;
	location = *p;
	ID = 1; //make a static function to get a unique ID
	velocity[0] = 0.0;
	velocity[1] = 0.0;

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