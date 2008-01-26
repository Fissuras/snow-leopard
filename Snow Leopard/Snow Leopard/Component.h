#ifndef COMPONENT_H_
#define  COMPONENT_H_
#include "WorldState.h"
#include <string>
#include "GameObject.h"

namespace SL
{

class WorldState;

class Component:public GameObject
{
	public:
		virtual void activate(WorldState* state, point location)
		{};
		unsigned int timeLastActivated;
		Component::Component(xerces DOMNode* rootNode):GameObject(rootNode)
		{};

};
}
#endif