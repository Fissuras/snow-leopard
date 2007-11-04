#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include <list>
#include <string>


class WorldState;
class GameObject{

	typedef std::list<GameObject*> GameObjectList;

public:
	bool doActions(WorldState* worldState);
	bool registerCollision(GameObjectList collisions);
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