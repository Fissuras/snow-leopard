#ifndef ECCM_H_
#define ECCM_H_
#include "WorldState.h"
#include "Component.h"
#include "xerces.h"

class ECCM:public Component
{
public:
	void activate(WorldState* state, point location, double displayHeading, double speed)
	{
	};
};

#endif