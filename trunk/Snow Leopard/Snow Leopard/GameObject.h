#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include <list>
#include <string>
#include "point.h"
#include <set>
#include "GameObjectPriorities.h"

class WorldState; //need to forward declare class to avoid crazy recursion
class CL_Sprite;
class CL_CollisionOutline;
class CL_ResourceManager;


 class GameObject{

public:

	enum AbsoluteDirection { LEFT, RIGHT, UP, DOWN };
	enum RelativeDirection { TURN_LEFT,TURN_RIGHT,FORWARD,BACK};


	typedef std::list<GameObject*> GameObjectList;
	typedef std::set <GameObject*>::iterator GameObjectIter;
	bool operator<(GameObject &b);
	virtual bool doActions();
	virtual bool registerCollision(GameObject* collidedObject);
	virtual bool registerWallCollision();
	static int getID();
	GameObject::GameObject(std::string resourceName,CL_ResourceManager* resources);
	CL_Sprite* sprite;
	GameObject::~GameObject();
	CL_ResourceManager* resources;
	void applyForceRect(double x, double y);
	void applyForcePolar(double heading, double magnitude);
	bool rotate(double angle);

	std::string displayName; 
	bool isPlayer; //right now only one ship can be a player
	
	//polar coordinates
	double heading;
	double displayHeading;
	CL_CollisionOutline* collisionOutline;
	double mass;
	double accelHeading;
	double accelMagnitude;
	double thrust; //force the object can apply on itself. thrust / mass = acceleration
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
	bool usesPhysics;

 protected:
	
	 bool processMovementPhysics();
 private:
	
	 static int IDCount;

};

#endif