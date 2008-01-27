#ifndef HULL_H_
#define HULL_H_
#include "WorldState.h"
#include "Component.h"
#include "xerces.h"
namespace SL
{
class Hull:public Component
{
public:
	void activate(WorldState* state, point location, double displayHeading, double speed)
	{
	};
};
}
#endif