#ifndef SEVNAMARK40_H_
#define SEVNAMARK40_H_
#include <list>
#include <string>
#include "point.h"
#include <set>
#include "WorldState.h"
#include "GameObject.h"
#include "Ship.h"
#include "Projectile.h"
 
class WorldState;
class Projectile;
class SevnaMark40: public Projectile {

public:
	SevnaMark40::SevnaMark40(std::string name, int fact);

protected:
	bool move();

};


#endif