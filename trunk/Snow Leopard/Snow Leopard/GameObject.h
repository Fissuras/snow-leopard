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


#include "xerces.h"

class WorldState; //need to forward declare class to avoid crazy recursion
class CL_Sprite;
class CL_CollisionOutline;
class DOMNode;


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
	GameObject::GameObject(xerces DOMNode* rootNode);
	CL_Sprite* sprite;
	GameObject::~GameObject();
	void applyForceRect(double x, double y);
	void applyForcePolar(double heading, double magnitude);
	bool rotate(double angle);

	static int GameObject::getID()
{
	IDCount++;
	return IDCount;
}


	std::string displayName; 
	bool isPlayer; //right now only one ship can be a player
	
	//polar coordinates
	double heading;
	double displayHeading;
	CL_CollisionOutline* collisionOutline;
	double mass;
	double rotationalInertia;
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
	std::string ID;
	WorldState* worldState;
	double speed;
	bool usesPhysics;

	//stupid hack to convert between the CL_Origin enum and string values
	
	//static std::string origin_type_map[] = {"origin_top_left","origin_top_center","origin_top_right","origin_center_left","origin_center","origin_center_right","origin_bottom_left","origin_bottom_center","origin_bottom_right"};
	static CL_Origin GameObject::getOriginfromString(std::string str)
	{
		if (str== "origin_top_left")
			return origin_top_left;
		else if (str== "origin_top_left")
			return origin_top_left;
		else if (str== "origin_top_center")
			return origin_top_center;
		else if (str== "origin_top_right")
			return origin_top_right;
		else if (str== "origin_center_left")
			return origin_center_left;
		else if (str== "origin_center")
			return origin_center;
		else if (str== "origin_center_right")
			return origin_center_right;
		else if (str== "origin_bottom_left")
			return origin_bottom_left;
		else if (str== "origin_bottom_center")
			return origin_bottom_center;
		else if (str== "origin_bottom_right")
			return origin_bottom_right;
	}

 protected:
	
	 bool processMovementPhysics();
 private:
	
	 static int IDCount;

};

#endif