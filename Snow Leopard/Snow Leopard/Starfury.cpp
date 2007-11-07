#include "Starfury.h"


Starfury::Starfury(std::string name,int fact,point* p):Ship(name,fact,p)
{
	speed = 5.0;
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