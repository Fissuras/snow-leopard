#include "SevnaMark40.h"

SevnaMark40::SevnaMark40(std::string resourceName,CL_ResourceManager* resources):Projectile(resourceName,resources)
{
	speed = 2;
}
bool SevnaMark40::move()
{
	GameObject::processMovementPhysics();
	worldState->moveObject(this,location.offsetPolar(heading,speed));
	return true;
}