#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include <list>
#include <string>

#include "WorldState.h"

class WorldState;

class GameObject{
public:
	bool doActions(WorldState* worldState);
	bool registerCollision(std::list<GameObject*> collisions);
	GameObject::GameObject();

	std::string displayName; 
	float velocity[2];
	int faction;
	int displaySize;
	int location[2];

	int displayID;
	int sourceSize;
	int displayOffset; // if there are multiple display frames in one bitmap, choose which one the GameObject has

};

#endif