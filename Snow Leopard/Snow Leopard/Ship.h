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
	bool doActions(WorldState* worldState);
	bool registerCollision(GameObjectList collisions);
	Ship::Ship(std::string name, int fact, point* p);

protected:
	virtual bool move(WorldState* worldState);
	virtual bool shoot(WorldState* worldState);


};
#endif