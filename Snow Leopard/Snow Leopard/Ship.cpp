#include "Ship.h"
#include "AI_Move_DoNothing.h"
#include "AI_Shoot_DoNothing.h"
#include "PulseCannon.h"
#include "ShotgunCannon.h"
#include "Definitions.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>

bool Ship::doActions()
{

	move();
	shoot();
	return true;
	
}

bool Ship::move()
{
#ifdef PHYSICS
	GameObject::processMovementPhysics();
#endif
	if (!(GameObject::isPlayer))
	{
	AI_Movement(this);
	}
	return true;
}

bool Ship::move(AbsoluteDirection dir)
{
	if (dir == UP)
		worldState->moveObject(this,location.offsetRect(0,-speed));
	if (dir == DOWN)
		worldState->moveObject(this,location.offsetRect(0,speed));
	if (dir == LEFT)
		worldState->moveObject(this,location.offsetRect(-speed,0));
	if (dir == RIGHT)
		worldState->moveObject(this,location.offsetRect(speed,0));

	return true;
}

bool Ship::move(RelativeDirection dir)
{
	if (dir == FORWARD)
		worldState->moveObject(this,location.offsetPolar(heading,speed));
	if (dir == BACK)
		worldState->moveObject(this,location.offsetPolar(heading,-speed));
	if (dir == TURN_LEFT)
		heading -= 1;
	if (dir == TURN_RIGHT)
		heading += 1;

	return true;
}

bool Ship::shoot()
{
	if (!(GameObject::isPlayer))
	{
	AI_Shooting(this);
	}
	return true;
}

Ship::Ship(std::string resourceName,CL_ResourceManager* resources) : GameObject(resourceName,resources)
{
	actionPriority = ShipActionPriority;
	renderPriority = ShipRenderPriority;
	AI_Movement = &AI_Move_DoNothing;
	AI_Shooting = &AI_Shoot_DoNothing;
	components = new ComponentList();
	GameObject::usesPhysics = true;
}
	
bool Ship::registerWallCollision()
{
	//cancel accelerations
	accelMagnitude = 0;
	speed = 0;
	return true;
}
