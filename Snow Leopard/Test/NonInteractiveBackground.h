#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include <list>
#include <string>
#include "point.h"
#include <set>
#include "WorldState.h"
#include "GameObject.h"

class WorldState;
class NonInteractiveBackground: public GameObject {

public:
	NonInteractiveBackground::NonInteractiveBackground(std::string resourceName, CL_ResourceManager* resources);

};
#endif