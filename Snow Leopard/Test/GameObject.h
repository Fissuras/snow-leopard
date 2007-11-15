#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include <list>
#include <string>
#include "point.h"
#include <set>
#include "GameObjectPriorities.h"

class WorldState; //need to forward declare class to avoid crazy recursion
class CL_Sprite;
class CL_ResourceManager;


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
	GameObject::GameObject(std::string resourceName,CL_ResourceManager* resources);
	CL_Sprite* sprite;
	bool GameObject::loadSprite();
	GameObject::~GameObject();
	CL_ResourceManager* resources;

	std::string displayName; 
	bool isPlayer; //right now only one ship can be a player
	
	//polar coordinates
	double heading;
	double accelerationHeading;
	double accelerationForce;
	double mass;
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