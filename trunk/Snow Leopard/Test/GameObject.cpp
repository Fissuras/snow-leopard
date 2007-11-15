#include "GameObject.h"
#include "WorldState.h"

int GameObject::IDCount = 0;
GameObject::GameObject(std::string resName,CL_ResourceManager* res)
{
	displayName = "";
	faction = 0;
	ID = getID();
	speed=0.0;
	heading=0.0;
	accelerationForce = 0.0;
	accelerationHeading = 0.0;
	actionPriority = DefActionPriority;
	renderPriority = DefRenderPriority;
	resourceName = resName;
	resources = res;
	mass = 1;
	sprite = NULL;
	isPlayer = false;
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

bool GameObject::processMovementPhysics() //changes object's location as a side effect, but does not update to worldstate
{
	int newSpeed = speed + worldState->timeElapsed * accelerationForce; //vf = vi + a(delta)t
	worldState->moveObject(this,location.offsetPolar(heading,.5 * (speed + newSpeed) * worldState->timeElapsed));
	speed = newSpeed;
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