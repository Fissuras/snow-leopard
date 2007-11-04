#ifndef WORLDSTATE_H_
#define WORLDSTATE_H_

#include <list>

#include "GameObject.h"
#include "point.h"
#include <set>

class GameObject;

typedef std::set<GameObject*> GameObjectList;
typedef std::set <GameObject*>::iterator GameObjectIter;

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