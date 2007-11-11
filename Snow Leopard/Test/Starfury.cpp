#include "Starfury.h"


Starfury::Starfury(std::string name,int fact):Ship(name,fact)
{
	speed = 2;
}
bool Starfury::move(WorldState* worldState)
{
	worldState->moveObject(this,location.offset(speed,0));
	return true;
}

bool Starfury::shoot(WorldState* worldState_)
{
	return true;
}