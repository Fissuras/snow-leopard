#include "Starfury.h"


Starfury::Starfury(std::string resourceName,CL_ResourceManager* resources):Ship(resourceName,resources)
{
}
bool Starfury::move()
{
	GameObject::processMovementPhysics();
	worldState->moveObject(this,location.offsetRect(speed,0));
	return true;
}

bool Starfury::shoot()
{
	
	return true;
}