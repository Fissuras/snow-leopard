#include "Starfury.h"


Starfury::Starfury(std::string name,int fact):Ship(name,fact)
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
	SevnaMark40* p = new SevnaMark40("Sevna",Projectile::PROJECTILE_FACT);
	p->resourceName = "SevnaMark40";
	worldState->insertObject(p,location.offsetPolar(heading,2));
	return true;
}