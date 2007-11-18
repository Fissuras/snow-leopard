#include "Ship.h"
#include "AI_Move_DoNothing.h"
#include "AI_Shoot_DoNothing.h"
#include "PulseCannon.h"
#include "ShotgunCannon.h"
#include "Definitions.h"


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
		worldState->moveObject(this,location.offsetRect(0,-thrust));
	if (dir == DOWN)
		worldState->moveObject(this,location.offsetRect(0,thrust));
	if (dir == LEFT)
		worldState->moveObject(this,location.offsetRect(-thrust,0));
	if (dir == RIGHT)
		worldState->moveObject(this,location.offsetRect(thrust,0));

	return true;
}

bool Ship::move(RelativeDirection dir)
{
	if (dir == FORWARD)
		worldState->moveObject(this,location.offsetPolar(moveVector->getAngle(),thrust));
	if (dir == BACK)
		worldState->moveObject(this,location.offsetPolar(moveVector->getAngle(),-thrust));
	if (dir == TURN_LEFT)
	{
		moveVector->setAngle(moveVector->getAngle() - 1);
		displayHeading -=1;
	}
	if (dir == TURN_RIGHT)
	{
		moveVector->setAngle(moveVector->getAngle() + 1);
		displayHeading +=1;
	}

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
	weapons = new WeaponList();
	GameObject::usesPhysics = true;
}
	
bool Ship::registerWallCollision()
{
	//cancel accelerations
	GameObject::accelVector->setX(0);
	GameObject::accelVector->setY(0);
	GameObject::moveVector->setX(0);
	GameObject::moveVector->setY(0);
	return true;
}
