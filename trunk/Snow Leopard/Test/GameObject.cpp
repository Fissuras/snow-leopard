#include "GameObject.h"
#include "WorldState.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>
#include "Vector2D.h"

int GameObject::IDCount = 0;
GameObject::GameObject(std::string resName,CL_ResourceManager* res)
{
	displayName = "";
	faction = 0;
	ID = getID();
	speed=0.0;
	actionPriority = DefActionPriority;
	renderPriority = DefRenderPriority;
	resourceName = resName;
	resources = res;
	mass = 1;
	sprite = NULL;
	isPlayer = false;
	usesPhysics = false;
	displayHeading = 0.0;
	accelVector = new Vector2D();
	moveVector = new Vector2D();
}


bool GameObject::loadSprite()
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
	if (usesPhysics)
		processMovementPhysics();
	return true;
}

bool GameObject::registerCollision(GameObjectList collisions)
{
	return true;
}

void GameObject::rotate(double angle)
{
	displayHeading += angle;
}

bool GameObject::processMovementPhysics()
{
	worldState->moveObject(this,location.offsetPolar(moveVector->getAngle(),speed * worldState->timeElapsed));
	return true;

}

bool GameObject::registerWallCollision()
{
	return true;
}

void GameObject::applyForce(Vector2D* vector, double time)
{
	*accelVector = *accelVector + *vector;
	delete vector;
}

GameObject::~GameObject()
{
	delete sprite;
}