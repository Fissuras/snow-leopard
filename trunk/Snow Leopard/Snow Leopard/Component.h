#ifndef COMPONENT_H_
#define  COMPONENT_H_
#include "WorldState.h"


class WorldState;

class Component
{
	public:
		virtual void activate(WorldState* state, point location, CL_ResourceManager* resources)
		{};
		unsigned int timeLastActivated;
};

#endif