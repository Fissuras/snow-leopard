#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include <list>
#include <string>
#include "point.h"
#include <set>


class WorldState;
 class GameObject{

public:

	typedef std::list<GameObject*> GameObjectList;
	typedef std::set <GameObject*>::iterator GameObjectIter;
	bool operator<(GameObject &b);
	virtual bool doActions(WorldState* worldState);
	bool registerCollision(GameObjectList collisions);
	GameObject::GameObject(std::string displayName = "", int faction=0, point* p=new point(0,0));

	std::string displayName; 
	double velocity[2];
	int faction;
	int displaySize;
	point location;
	int priority;
	std::string imageSource; //should eventually be removed and replaced with dynamic bitmap generator
	int ID;
	int sourceSize;
	int displayOffset; // if there are multiple display frames in one bitmap, choose which one the GameObject has

};

#endif