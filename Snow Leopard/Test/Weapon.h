#ifndef WEAPON_H_
#define WEAPON_H_
#include "WorldState.h"
#include "Component.h"


class WorldState;

class Weapon:public Component
{
	public:
		const int coolDownInterval;
		virtual void fire(WorldState* state, point location, double heading, double speed, CL_ResourceManager* resources)
		{};
		unsigned int timeLastFired;
		Weapon::Weapon(int interval = 600) : coolDownInterval(interval)
		{};
};

#endif