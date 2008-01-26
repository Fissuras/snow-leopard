#ifndef POWERPLANT_H_
#define POWERPLANT_H_
#include "WorldState.h"
#include "Component.h"
#include "xerces.h"
namespace SL
{
class PowerPlant:public Component
{
public:
	void activate(WorldState* state, point location, double displayHeading, double speed)
	{
	};
};
}
#endif