#ifndef SHOTGUNCANNON_H_
#define SHOTGUNCANNON_H_
#include "WorldState.h"
#include "Weapon.h"
#include "SevnaMark40.h"
#include "Vector2D.h"

class ShotgunCannon:public Weapon
{
	public:
		static const int coolDownInterval = 1;
		void fire(WorldState* state, point location, Vector2D* vector, CL_ResourceManager* resources)
		{
			for (int i=0;i<5;i++)
			{
			SevnaMark40* p = new SevnaMark40("SevnaMark40",resources);
			p->resourceName = "SevnaMark40";
			p->moveVector->setAngle(vector->getAngle() - 24 + 6*i);
			p->moveVector->setLength(vector->getLength() + .2);
			state->insertObject(p,location.offsetPolar(vector->getAngle(),2));
			}
			
			Weapon::timeLastFired = state->time;
			delete vector;
		};
		ShotgunCannon::ShotgunCannon()
		{
			Weapon::timeLastFired = 0;
		};
};

#endif