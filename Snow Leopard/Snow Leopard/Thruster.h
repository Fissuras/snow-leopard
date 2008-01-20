#ifndef THRUSTER_H_
#define THRUSTER_H_
#include "WorldState.h"
#include "Component.h"
#include "xerces.h"

class Thruster:public Component
{
public:
	void activate(WorldState* state, point location, double displayHeading, double speed)
	{
	};
};

#endif