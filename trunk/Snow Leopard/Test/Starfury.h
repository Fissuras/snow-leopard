#ifndef STARFURY_H_
#define STARFURY_H_
#include <list>
#include <string>
#include "point.h"
#include <set>
#include "WorldState.h"
#include "GameObject.h"
#include "Ship.h"
#include "Projectile.h"
#include "SevnaMark40.h"
#include "Weapon.h"
#include "PulseCannon.h"
#include "ShotgunCannon.h"
 
class WorldState;
class Ship;
class Starfury: public Ship {

public:
	Starfury::Starfury(std::string resourceName,CL_ResourceManager* resources);

protected:
	bool move();
	bool shoot();
	PulseCannon* pulseCannon;
	ShotgunCannon* shotgunCannon;

};


#endif