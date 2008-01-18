#include "GameObject.h"
#include "WorldState.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>


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
#include "DOMHelpers.h"
#define xerces XERCES_CPP_NAMESPACE_QUALIFIER

int GameObject::IDCount = 0;
GameObject::GameObject(xerces DOMNode* rootNode)
{
	xerces DOMNamedNodeMap* attributes =  rootNode->getAttributes();
	displayName = getAttributeStr("Name",attributes);
	displayHeading = getAttributeStr("current_angle",attributes;
	faction = getAttributeStr("faction",attributes);
	ID = getAttributeStr("id",attributes);
	speed=getAttributeDouble("movementSpeed",attributes);
	heading=getAttributeDouble("movementHeading",attributes);
	accelMagnitude = getAttributeDouble("AccelerationMagnitude",attributes);
	accelHeading = 0.0;
	actionPriority = DefActionPriority;
	renderPriority = DefRenderPriority;
	mass = 1;
	rotationalInertia = 1;
	isPlayer = false;
	usesPhysics = false;

	sprite = new CL_Sprite();
	sprite->set_alignment(origin_center);
	sprite->set_rotation_hotspot(origin_center);

	collisionOutline = new CL_CollisionOutline((sprite->get_frame_pixeldata(0)));
	collisionOutline->set_alignment(origin_center);
	collisionOutline->set_rotation_hotspot(origin_center);
}
int GameObject::getID()
{
	IDCount++;
	return IDCount;
}

bool GameObject::doActions()
{
	if (usesPhysics)
		processMovementPhysics();
	return true;
}

bool GameObject::registerCollision(GameObject* collidedObject)
{
	std::cout << displayName <<  " Collided with " << collidedObject->displayName << "\n";
	std::cout << "MyPosition: " << collisionOutline->get_translation()<< "\n";
	std::cout << "TheirPosition: " << collidedObject->collisionOutline->get_translation()<< "\n";
	return true;
}

bool GameObject::processMovementPhysics()
{
	//new velocity components
	double newX = .5 * accelMagnitude * cos(accelHeading * 3.14159/180) * worldState->timeElapsed
		+ speed * cos(heading * 3.14159/180);
	double newY = .5 * accelMagnitude * sin(accelHeading *3.14159/180) * worldState->timeElapsed
		+ speed * sin(heading * 3.14159/180); 

	speed = sqrt((newX)*(newX) + (newY)*(newY));
	heading = (180 * atan2(newY,newX)) / 3.14159;

	/*std::cout << this->displayName << "Physics Update: \n";
	std::cout << "Velocity Heading: " << this->heading << "\n";
	std::cout << "Speed: " << this->speed << "\n";
	std::cout << "AccelHeading: " << this->accelHeading << "\n";
	std::cout << "AccelMagnitude: " << this->accelMagnitude << "\n\n";*/

	worldState->moveObject(this,location.offsetPolar(heading,speed * worldState->timeElapsed));
	
	accelHeading = 0; //should allow applied forces to have durations. Until then, everything gets re-composited every tick
	accelMagnitude = 0;
	return true;

}

bool GameObject::registerWallCollision()
{
	std::cout << "Collided with wall";
	return true;
}

bool GameObject::rotate(double angle)
{
	displayHeading += angle;
	collisionOutline->rotate(angle);
	return true;
}

//cleanup and adapt polar to use Rect's code
void GameObject::applyForceRect(double x,double y)
{
	double oldX = accelMagnitude * cos(accelHeading * 3.14159/180);
	double oldY = accelMagnitude * sin(accelHeading *3.14159/180);
	//should probably be using vectors everywhere
	double newX = oldX + x;
	double newY = oldY + y;
	accelMagnitude = sqrt(newX*newX + newY*newY);
	accelHeading = (180 * atan2(newY,newX)) / 3.14159;
}

void GameObject::applyForcePolar(double heading, double magnitude)
{
	double X = magnitude * cos(heading * 3.14159/180);
	double Y = magnitude * sin(heading * 3.14159/180);
	applyForceRect(X,Y);
}

GameObject::~GameObject()
{
	delete sprite;
}