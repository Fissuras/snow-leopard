#ifndef WEAPON_H_
#define WEAPON_H_
#include "WorldState.h"


class WorldState;

class Weapon
{
	public:
		const int coolDownInterval;
		void fire(WorldState* state, point location, double heading,CL_ResourceManager* resources)
		{};
		unsigned int timeLastFired;
		Weapon::Weapon(int interval = 600) : coolDownInterval(interval)
		{};
};

#endif