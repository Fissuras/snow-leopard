#include "GameObject.h"
#include "WorldState.h"

int GameObject::IDCount = 0;
GameObject::GameObject(std::string name, int fact)
{
	displayName = name;
	faction = fact;
	ID = getID();
	speed=0.0;
	heading=0.0;
	actionPriority = DefPriority;
}

int GameObject::getID()
{
	IDCount++;
	return IDCount;
}

bool GameObject::doActions()
{
	return true;
}

bool GameObject::registerCollision(GameObjectList collisions)
{
	return true;
}

bool GameObject::operator<(GameObject &b)
{
	return actionPriority<b.actionPriority;
}

bool GameObject::processMovementPhysics()
{
	return true;
}

bool GameObject::registerWallCollision()
{
	return true;
}