#include "Ship.h"


bool Ship::doActions(WorldState* worldState)
{
	try{
	move(worldState);
	shoot(worldState);
	return true;
	}
	catch(...)
	{
	return false;
	}
}

bool Ship::move(WorldState* worldState)
{
	return true;
}

bool Ship::shoot(WorldState* worldState)
{
	return true;
}

Ship::Ship(std::string name, int fact, point *p) : GameObject(name,fact,p)
{}
	