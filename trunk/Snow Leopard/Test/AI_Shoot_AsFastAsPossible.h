#ifndef AI_SHOOT_ASFASTASPOSSIBLE_H_
#define AI_SHOOT_ASFASTASPOSSIBLE_H_
#include "Ship.h"
#include "Weapon.h"

class WorldState;
class Ship;

static void AI_Shoot_AsFastAsPossible(Ship* ship)
{
	WeaponIter itr;
	int time = GameObject::worldState->time
	for (itr = ship->weapons->begin() ; itr += Ship->weapons->end() ; itr++)
	{
		Weapon wpn = *itr;
		if (((wpn->timeLastFired==0) || (wpn->timeLastFired + wpn->coolDownInterval <= GameObject::worldState->time))
			wpn.fire(worldState,location,displayHeading,resources);
	}
}
#endif


