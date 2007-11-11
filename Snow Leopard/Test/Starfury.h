#ifndef STARFURY_H_
#define STARFURY_H_
#include <list>
#include <string>
#include "point.h"
#include <set>
#include "WorldState.h"
#include "GameObject.h"
#include "Ship.h"
 
class WorldState;
class Ship;
class Starfury: public Ship {

public:
	Starfury::Starfury(std::string name, int fact);

protected:
	bool move(WorldState* worldState);
	bool shoot(WorldState* worldState);

};


#endif