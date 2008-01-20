#ifndef PROJECTILE_H_
#define PROJECTILE_H_
#include <list>
#include <string>
#include "point.h"
#include <set>
#include "GameObject.h"



class WorldState;
class GameObject;

class Projectile: public GameObject {

public:
	bool doActions();
	bool registerCollision(GameObjectList collisions);
	bool registerWallCollision();
	Projectile::Projectile(xerces DOMNode* rootNode);
	virtual bool move();


};
#endif