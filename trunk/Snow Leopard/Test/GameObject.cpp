#include "GameObject.h"

int GameObject::IDCount = 0;
GameObject::GameObject(std::string resName,CL_ResourceManager* res)
{
	displayName = "";
	faction = 0;
	ID = getID();
	speed=0.0;
	heading=0.0;
	actionPriority = DefActionPriority;
	renderPriority = DefRenderPriority;
	resourceName = resName;
	resources = res;
	sprite = NULL;
}


bool GameObject::loadSprite() //temporary test. This should happed in the constructor
{
	sprite = new CL_Sprite(resourceName,resources);
	sprite->set_alignment(origin_center);
	sprite->set_rotation_hotspot(origin_center);
	return true;
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

bool GameObject::processMovementPhysics()
{
	return true;
}

bool GameObject::registerWallCollision()
{
	return true;
}

GameObject::~GameObject()
{
	delete sprite;
}