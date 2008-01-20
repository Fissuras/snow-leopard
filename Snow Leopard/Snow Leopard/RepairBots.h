#ifndef REPAIRBOTS_H_
#define REPAIRBOTS_H_
#include "WorldState.h"
#include "Component.h"
#include "xerces.h"

class RepairBots:public Component
{
public:
	void activate(WorldState* state, point location, double displayHeading, double speed)
	{
	};
};

#endif