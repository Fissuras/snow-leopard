#include "Ship.h"


bool Ship::doActions(WorldState* worldState)
{

	move(worldState);
	shoot(worldState);
	return true;
	
}

bool Ship::move(WorldState* worldState)
{
	return true;
}

bool Ship::move(WorldState* worldState,Direction dir)
{
	if (dir == UP)
		worldState->moveObject(this,location.offset(0,-speed));
	if (dir == DOWN)
		worldState->moveObject(this,location.offset(0,speed));
	if (dir == LEFT)
		worldState->moveObject(this,location.offset(-speed,0));
	if (dir == RIGHT)
		worldState->moveObject(this,location.offset(speed,0));

	return true;
}

bool Ship::shoot(WorldState* worldState)
{
	return true;
}

Ship::Ship(std::string name, int fact) : GameObject(name,fact)
{
	actionPriority = ShipPriority;
}
	