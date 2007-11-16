#ifndef SHOTGUNCANNON_H_
#define SHOTGUNCANNON_H_
#include "WorldState.h"
#include "Weapon.h"
#include "SevnaMark40.h"

class ShotgunCannon:public Weapon
{
	public:
		static const int coolDownInterval = 600;
		void fire(WorldState* state, point location, double heading, double speed, CL_ResourceManager* resources)
		{
			for (int i=0;i<5;i++)
			{
			SevnaMark40* p = new SevnaMark40("SevnaMark40",resources);
			p->resourceName = "SevnaMark40";
			p->heading = heading - 24 + 6*i;
			p->speed = speed + .5;
			state->insertObject(p,location.offsetPolar(heading,2));
			}
			
			Weapon::timeLastFired = state->time;
		};
		ShotgunCannon::ShotgunCannon()
		{
			Weapon::timeLastFired = 0;
		};
};

#endif