#include "GameObject.h"
#include "WorldState.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>

int GameObject::IDCount = 0;
GameObject::GameObject(std::string resName,CL_ResourceManager* res)
{
	displayName = "";
	faction = 0;
	ID = getID();
	speed=0.0;
	heading=0.0;
	accelMagnitude = 0.0;
	accelHeading = 0.0;
	actionPriority = DefActionPriority;
	renderPriority = DefRenderPriority;
	resourceName = resName;
	resources = res;
	mass = 1;
	sprite = NULL;
	isPlayer = false;
	usesPhysics = false;
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
	if (usesPhysics)
		processMovementPhysics();
	return true;
}

bool GameObject::registerCollision(GameObjectList collisions)
{
	return true;
}

bool GameObject::processMovementPhysics() //changes object's location as a side effect, but does not update to worldstate
{
	worldState->moveObject(this,location.offsetPolar(heading,speed * worldState->timeElapsed));
	return true;

}

bool GameObject::registerWallCollision()
{
	return true;
}

void GameObject::applyForceRect(double x,double y)
{
	double oldX = accelMagnitude * cos(accelHeading * 3.14159/180);
	double oldY = accelMagnitude * sin(accelHeading *3.14159/180);
	//should probably be using vectors everywhere
	double newX = oldX + x;
	double newY = oldY + y;
	speed = .05 * (speed + sqrt(abs(newX * newX + newY + newY)));
	accelMagnitude = sqrt(newX*newX + newY*newY);
	accelHeading = (180 * atan2(newY,newX)) / 3.14159;
}

void GameObject::applyForcePolar(double heading, double magnitude)
{
	if (magnitude<0)
	{
		heading += 180;
		magnitude = abs(magnitude); 
	}

	double oldX = accelMagnitude * cos(accelHeading * 3.14159/180);
	double oldY = accelMagnitude * sin(accelHeading * 3.14159/180);
	//should probably be using vectors everywhere
	double newX = oldX + magnitude * cos(heading * 3.14159/180);
	double newY = oldY + magnitude * sin(heading * 3.14159/180);
	speed = .05 * (speed + sqrt(newX * newX + newY + newY));
	accelMagnitude = sqrt(newX*newX + newY*newY);
	accelHeading = (180 * atan2(newY,newX)) / 3.14159;

}

GameObject::~GameObject()
{
	delete sprite;
}