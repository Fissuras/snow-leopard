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
typedef std::list <GameObject*>::const_iterator ConstGameObjectIter;
#define coarseGraining 100

class WorldState
{
public:

int CellSizeX;
int CellSizeY;
double CoordinateSizeX;
double CoordinateSizeY;

WorldState::WorldState();
bool insertObject(GameObject* gameObject, point p);
bool deleteObject(GameObject* gameObject);
bool moveObject(GameObject* gameObject, point p);
GameObjectList* getAtCell(point p);
const GameObjectList* getAllGameObjects();

private:
	GameObjectList*** worldMatrix;
	GameObjectList* allObjectList;
	bool pointOutofBounds(point p);
};

#endif