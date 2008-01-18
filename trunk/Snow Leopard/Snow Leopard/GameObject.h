#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include <list>
#include <string>
#include "point.h"
#include <set>
#include "GameObjectPriorities.h"

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/AbstractDOMParser.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMImplementationRegistry.hpp>
#include <xercesc/dom/DOMBuilder.hpp>
#include <xercesc/dom/DOMException.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMError.hpp>
#include <xercesc/dom/DOMLocator.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/framework/LocalFileInputSource.hpp>
#include <xercesc/util/XMLString.hpp>
#include "XercesString.h"
#include "xercesc/framework/Wrapper4InputSource.hpp"
#define xerces XERCES_CPP_NAMESPACE_QUALIFIER

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
	static int getID();
	GameObject::GameObject(xerces DOMNode* rootNode);
	CL_Sprite* sprite;
	GameObject::~GameObject();
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

 protected:
	
	 bool processMovementPhysics();
 private:
	
	 static int IDCount;

};

#endif