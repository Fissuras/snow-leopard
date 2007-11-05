#ifndef WORLDSTATE_H_
#define WORLDSTATE_H_

#include <list>
#include <queue>
#include "GameObject.h"
#include "point.h"
#include <set>

class GameObject;

typedef std::list<GameObject*> GameObjectList;
typedef std::list <GameObject*>::iterator GameObjectIter;
typedef std::priority_queue<GameObject*> GameObjectQueue;

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
GameObjectQueue* getAllGameObjects();

private:
	GameObjectList*** worldMatrix;
};

#endif