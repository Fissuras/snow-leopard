#ifndef PULSECANNON_H_
#define PULSECANNON_H_
#include "WorldState.h"
#include "Weapon.h"
#include "SevnaMark40.h"

class PulseCannon:public Weapon
{
	public:
		static const int coolDownInterval = 600;
		void fire(WorldState* state, point location, double heading, double speed, CL_ResourceManager* resources)
		{
			SevnaMark40* p = new SevnaMark40("SevnaMark40",resources);
			p->resourceName = "SevnaMark40";
			p->heading = heading;
			p->speed = speed + 2;
			state->insertObject(p,location.offsetPolar(heading,2));
			Weapon::timeLastFired = state->time;
		};
		PulseCannon::PulseCannon()
		{
			Weapon::timeLastFired = 0;
		};
};

#endif