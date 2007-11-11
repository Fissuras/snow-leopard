#include "SevnaMark40.h"

SevnaMark40::SevnaMark40(std::string name,int fact):Projectile(name,fact)
{
	speed = 2;
}
bool SevnaMark40::move()
{
	GameObject::processMovementPhysics();
	worldState->moveObject(this,location.offsetRect(speed,0));
	return true;
}