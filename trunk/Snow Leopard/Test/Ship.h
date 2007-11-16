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
	typedef std::vector <Weapon*>::iterator WeaponIter;
	
	bool doActions();
	bool registerCollision(GameObjectList collisions);
	bool registerWallCollision();
	Ship::Ship(std::string resourceName, CL_ResourceManager* resources);
	virtual bool move();
	bool move(AbsoluteDirection dir);
	bool move(RelativeDirection dir);
	virtual bool shoot();
	WeaponList* weapons;
	void (*AI_Movement) (Ship* ship);
	void (*AI_Shooting) (Ship* ship);



};
#endif