#include "Starfury.h"


bool Starfury::move(WorldState* worldState)
{
	worldState->moveObject(this,location.offset(1,0));
	return true;
}

bool Starfury::shoot(WorldState* worldState_)
{
	return true;
}

Starfury::Starfury(std::string name, int fact, point *p) : Ship(name,fact,p)
{}