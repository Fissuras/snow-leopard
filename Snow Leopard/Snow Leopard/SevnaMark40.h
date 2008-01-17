#ifndef SEVNAMARK40_H_
#define SEVNAMARK40_H_
#include "point.h"
#include "WorldState.h"
#include "Projectile.h"
 
class WorldState;
class Projectile;
class SevnaMark40: public Projectile {

public:
	SevnaMark40::SevnaMark40(std::string resourceName, CL_ResourceManager* resources);

protected:
	bool move();

};


#endif