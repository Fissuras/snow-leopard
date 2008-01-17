#ifndef PROJECTILE_H_
#define PROJECTILE_H_
#include <list>
#include <string>
#include "point.h"
#include <set>
#include "GameObject.h"

class WorldState;
class GameObject;
class CL_ResourceManager;

class Projectile: public GameObject {

public:
	bool doActions();
	bool registerCollision(GameObjectList collisions);
	bool registerWallCollision();
	Projectile::Projectile(std::string resourceName, CL_ResourceManager* resources);
	virtual bool move();
	bool move(AbsoluteDirection dir);


};
#endif