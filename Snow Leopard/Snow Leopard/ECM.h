#ifndef ECM_H_
#define ECM_H_
#include "WorldState.h"
#include "Component.h"
#include "xerces.h"
namespace SL
{
class ECM:public Component
{
public:
	void activate(WorldState* state, point location, double displayHeading, double speed)
	{
	};
};
}
#endif