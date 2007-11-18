#ifndef PULSECANNON_H_
#define PULSECANNON_H_
#include "WorldState.h"
#include "Weapon.h"
#include "SevnaMark40.h"
#include "Vector2D.h"

class PulseCannon:public Weapon
{
	public:
		static const int coolDownInterval = 1;
		void fire(WorldState* state, point location, Vector2D* vector, CL_ResourceManager* resources)
		{
			SevnaMark40* p = new SevnaMark40("SevnaMark40",resources);
			p->resourceName = "SevnaMark40";
			vector->setLength(vector->getLength() + 2);
			p->moveVector = vector;
			state->insertObject(p,location.offsetPolar(p->moveVector->getAngle(),2));
			Weapon::timeLastFired = state->time;
			delete vector;
		};
		PulseCannon::PulseCannon()
		{
			Weapon::timeLastFired = 0;
		};
};

#endif