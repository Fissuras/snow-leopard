#ifndef SALVAGEBREAM_H_
#define SALVAGEBREAM_H_
#include "WorldState.h"
#include "Component.h"
#include "xerces.h"
namespace SL
{

class SalvageBeam:public Component
{
public:
	void activate(WorldState* state, point location, double displayHeading, double speed)
	{
	};
};
}
#endif