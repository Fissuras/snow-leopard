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
	typedef std::vector<Component*> ComponentList;
	typedef std::vector <Weapon*>::iterator WeaponIter;
	
	bool doActions();
	bool registerCollision(GameObjectList collisions);
	bool registerWallCollision();
	Ship::Ship(xerces DOMNode* rootNode);
	virtual bool move();
	bool move(AbsoluteDirection dir);
	bool move(RelativeDirection dir);
	virtual bool shoot();
	ComponentList* components;
	void (*AI_Movement) (Ship* ship);
	void (*AI_Shooting) (Ship* ship);



};
#endif