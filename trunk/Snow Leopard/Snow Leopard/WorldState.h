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
#define coarseGraining 20

class WorldState
{
public:

int CellSizeX;
int CellSizeY;
double CoordinateSizeX;
double CoordinateSizeY;

WorldState::WorldState();
bool insertObject(GameObject* gameObject, point *p);
bool deleteObject(GameObject* gameObject);
bool moveObject(GameObject* gameObject, point *p);
bool getEnvironment(point *p, int size, GameObjectList** memory);
GameObjectList* getAtLocation(point *p);
GameObjectList* getAllGameObjects();
GameObjectList* getAllGameObjects_Unsorted();

private:
	GameObjectList*** worldMatrix;
	GameObjectList* allObjectList;
};

#endif