#ifndef SHIP_H_
#define SHIP_H_
#include <list>
#include <vector>
#include <string>
#include "point.h"
#include <set>
#include "GameObject.h"



#include "Weapon.h"

class WorldState;
class CL_ResourceManager;


class Ship: public GameObject {

public:
	typedef std::vector<Weapon*> WeaponList;
	
	bool doActions();
	bool registerCollision(GameObjectList collisions);
	bool registerWallCollision();
	Ship::Ship(std::string resourceName, CL_ResourceManager* resources);
	virtual bool move();
	bool move(AbsoluteDirection dir);
	bool move(RelativeDirection dir);
	virtual bool shoot();
	void (*AI_Movement) (WorldState* );
	void (*AI_Shooting) (WorldState* ,WeaponList*);



};
#endif