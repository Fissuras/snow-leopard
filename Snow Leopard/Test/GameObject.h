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

	enum AbsoluteDirection { LEFT, RIGHT, UP, DOWN };
	enum RelativeDirection { TURN_LEFT,TURN_RIGHT,FORWARD,BACK};


	typedef std::list<GameObject*> GameObjectList;
	typedef std::set <GameObject*>::iterator GameObjectIter;
	bool operator<(GameObject &b);
	virtual bool doActions();
	bool registerCollision(GameObjectList collisions);
	virtual bool registerWallCollision();
	static int getID();
	GameObject::GameObject(std::string displayName = "", int faction=0);

	std::string displayName; 
	bool isPlayer; //right now only one ship can be a player
	
	//polar coordinates
	double heading;
	double accelerationHeading;
	double accelerationSpeed; // = accelForce / Mass of ship  (maybe should just have a real physics engine?)
	int faction;
	int displaySize;
	point location;
	int actionPriority;
	int renderPriority;
	std::string resourceName;
	std::string imageSource; //should eventually be removed and replaced with dynamic bitmap generator
	int ID;
	WorldState* worldState;
	double speed;

 protected:
	
	 bool processMovementPhysics();
 private:
	
	 static int IDCount;

};

#endif