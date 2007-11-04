#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include <list>
#include <string>
#include "point.h"
#include <set>


class WorldState;
class GameObject{

	typedef std::list<GameObject*> GameObjectList;
	typedef std::set <GameObject*>::iterator GameObjectIter;

public:
	bool doActions(WorldState* worldState);
	bool registerCollision(GameObjectList collisions);
	GameObject::GameObject(std::string displayName = "", int faction=0, point* p=new point(0,0));

	std::string displayName; 
	float velocity[2];
	int faction;
	int displaySize;
	point location;

	std::string displayID;
	int sourceSize;
	int displayOffset; // if there are multiple display frames in one bitmap, choose which one the GameObject has

};

#endif