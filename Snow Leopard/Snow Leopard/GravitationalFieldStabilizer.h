#ifndef GRAVITATIONALFIELDSTABILIZER_H_
#define GRAVITATIONALFIELDSTABILIZER_H_
#include "WorldState.h"
#include "Component.h"
#include "xerces.h"
namespace SL
{
class GravitationalFieldStabilizer:public Component
{
public:
	void activate(WorldState* state, point location, double displayHeading, double speed)
	{
	};
};
}
#endif