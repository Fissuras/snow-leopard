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
	SevnaMark40* p = new SevnaMark40("SevnaMark40",GameObject::resources);
	p->resourceName = "SevnaMark40";
	worldState->insertObject(p,location.offsetPolar(heading,2));
	return true;
}