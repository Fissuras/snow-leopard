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


class Render
{
public:
bool operator() (GameObject* lhs, GameObject* rhs) {
return lhs->renderPriority < rhs->renderPriority;
}
};

class Action
{
public:
bool operator() ( GameObject* lhs,  GameObject* rhs) {
return lhs->actionPriority < rhs->actionPriority;
}
};



class WorldState
{
public:

enum SortPreference {ACTION_SORTED,RENDER_SORTED,UNSORTED};
int CellSizeX;
int CellSizeY;
double CoordinateSizeX;
double CoordinateSizeY;

WorldState::WorldState();
bool insertObject(GameObject* gameObject, point p);
bool deleteObject(GameObject* gameObject);
bool moveObject(GameObject* gameObject, point p);
GameObjectList* getAtCell(point p);
const GameObjectList* WorldState::getAllGameObjects(SortPreference p = UNSORTED);

private:
	GameObjectList*** worldMatrix;
	GameObjectList* allObjectList;
	bool pointOutofBounds(point p);
	GameObjectList* WorldState::getListFromPoint(point p);
};

#endif