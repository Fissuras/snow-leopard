#ifndef SHIP_H_
#define SHIP_H_
#include <list>
#include <string>
#include "point.h"
#include <set>
#include "WorldState.h"
#include "GameObject.h"

class WorldState;



class Ship: public GameObject {

public:
	bool doActions();
	bool registerCollision(GameObjectList collisions);
	bool registerWallCollision();
	Ship::Ship(std::string resourceName, CL_ResourceManager* resources);
	virtual bool move();
	bool move(AbsoluteDirection dir);
	bool move(RelativeDirection dir);
	virtual bool shoot();



};
#endif