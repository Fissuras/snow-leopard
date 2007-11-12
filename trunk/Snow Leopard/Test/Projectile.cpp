#include "Projectile.h"


bool Projectile::doActions()
{

	move();
	return true;
	
}

bool Projectile::move()
{
	return true;
}

bool Projectile::move(AbsoluteDirection dir)
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

Projectile::Projectile(std::string resourceName,CL_ResourceManager* resources) : GameObject(resourceName,resources)
{
	actionPriority = ProjectilePriority;
}
	
bool Projectile::registerWallCollision()
{
	worldState->deleteObject(this);
	return true;
}
