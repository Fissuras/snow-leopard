#ifndef BEAMCANNON_H_
#define BEAMCANNON_H_
#include "WorldState.h"
#include "Weapon.h"
#include "xerces.h"

namespace SL
{
class BeamCannon:public Weapon
{
	public:
		void fire(WorldState* state, point location, double heading, double speed)
		{
			/*SevnaMark40* p = new SevnaMark40("SevnaMark40",resources);
			p->resourceName = "SevnaMark40";
			p->heading = heading;
			p->speed = speed + .5;
			state->insertObject(p,location.offsetPolar(heading,2));
			Weapon::timeLastFired = state->time;*/
		};
		BeamCannon::BeamCannon(xerces DOMNode* rootNode):Weapon(xerces DOMNode* rootNode)
		{
		};
};
}
#endif