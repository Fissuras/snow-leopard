#include "Starfury.h"


Starfury::Starfury(std::string resourceName,CL_ResourceManager* resources):Ship(resourceName,resources)
{
	pulseCannon = new PulseCannon();
}
bool Starfury::move()
{
	GameObject::processMovementPhysics();
	worldState->moveObject(this,location.offsetRect(speed,0));
	return true;
}

bool Starfury::shoot()
{
	int time = GameObject::worldState->time;

	if ((pulseCannon->timeLastFired==0) || (pulseCannon->timeLastFired + pulseCannon->coolDownInterval <= GameObject::worldState->time))
	{
		pulseCannon->fire(worldState,location,heading,speed,GameObject::resources);
	}
	return true;
}