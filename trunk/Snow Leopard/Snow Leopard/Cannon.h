#ifndef SHOTGUNCANNON_H_
#define SHOTGUNCANNON_H_
#include "WorldState.h"
#include "Weapon.h"
#include "xerces.h"

//capable of any ammo type, number of shots, shot density, angle of shooting, etc.
class Cannon:public Weapon
{
public:
	static const int coolDownInterval = 600;
	void fire(WorldState* state, point location, double displayHeading, double speed)
	{
		for (int i=0;i<5;i++)
		{
			/*SevnaMark40* p = new SevnaMark40("SevnaMark40",resources);
			p->resourceName = "SevnaMark40";
			p->heading = displayHeading - 24 + 6*i;
			p->speed = speed + .5;
			state->insertObject(p,location.offsetPolar(displayHeading,2));*/
		}

		Weapon::timeLastFired = state->time;
	};
	ShotgunCannon::ShotgunCannon()
	{
		Weapon::timeLastFired = 0;
	};
};

#endif