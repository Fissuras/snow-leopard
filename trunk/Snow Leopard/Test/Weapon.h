#ifndef WEAPON_H_
#define WEAPON
#include "WorldState.h"

virtual class Weapon
{
	public:
		const int coolDownInterval;
		void fire(WorldState* state, point location, double heading,CL_ResourceManager* resources)
		{};
		int timeLastFired;
		Weapon::Weapon(int interval = 600) : coolDownInterval(interval)
		{};
};

#endif