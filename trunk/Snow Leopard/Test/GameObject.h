#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include <list>
#include <string>
#include "point.h"
#include <set>
#include "GameObjectPriorities.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>

class WorldState;
 class GameObject{

public:

	typedef std::list<GameObject*> GameObjectList;
	typedef std::set <GameObject*>::iterator GameObjectIter;
	bool operator<(GameObject &b);
	virtual bool doActions(WorldState* worldState);
	bool registerCollision(GameObjectList collisions);
	static int getID();
	GameObject::GameObject(std::string displayName = "", int faction=0, point* p=new point(0,0));

	std::string displayName; 
	
	//polar coordinates
	double heading;
	
	int faction;
	int displaySize;
	point location;
	int actionPriority;
	int renderPriority;
	std::string resourceName;
	std::string imageSource; //should eventually be removed and replaced with dynamic bitmap generator
	int ID;

 protected:
	 double speed;
 private:
	
	 static int IDCount;

};

#endif