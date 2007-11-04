#ifndef WORLDSTATE_H_
#define WORLDSTATE_H_

#include <list>

#include "GameObject.h"
#include "point.h"
#include "Boost/multi_array.hpp"
#include <boost/ptr_container/ptr_list.hpp>

class GameObject;

typedef boost::ptr_list<GameObject> GameObjectList;

class WorldState
{
public:

int xsize;
int ysize;
WorldState::WorldState();
bool insertObject(GameObject* gameObject, point *p);
bool deleteObject(GameObject* gameObject);
bool moveObject(GameObject* gameObject, point *p);
bool getEnvironment(point *p, int size, GameObjectList** memory);
GameObjectList* getAtLocation(point *p);

private:
	GameObjectList*** worldMatrix;
};

#endif