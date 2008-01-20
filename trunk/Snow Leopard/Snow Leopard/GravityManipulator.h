#ifndef GRAVITYMANIPULATOR_H_
#define GRAVITYMANIPULATOR_H_
#include "WorldState.h"
#include "Component.h"
#include "xerces.h"

class GravityManipulator:public Component
{
public:
	void activate(WorldState* state, point location, double displayHeading, double speed)
	{
	};
};

#endif