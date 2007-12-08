#include "GameObject.h"
#include "WorldState.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>

int GameObject::IDCount = 0;
GameObject::GameObject(std::string resName,CL_ResourceManager* res)
{
	displayName = "";
	displayHeading = 0.0;
	faction = 0;
	ID = getID();
	speed=0.0;
	heading=0.0;
	accelMagnitude = 0.0;
	accelHeading = 0.0;
	actionPriority = DefActionPriority;
	renderPriority = DefRenderPriority;
	resourceName = resName;
	resources = res;
	mass = 1;
	isPlayer = false;
	usesPhysics = false;

	sprite = new CL_Sprite(resourceName,resources);
	sprite->set_alignment(origin_center);
	sprite->set_rotation_hotspot(origin_center);

	collisionOutline = new CL_CollisionOutline((sprite->get_frame_surface(0).get_pixeldata()));
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