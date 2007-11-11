#include "WorldState.h"
#include "GameObject.h"

#include <iostream>

//need to have a method that returns only what locations of objects changed during the last step,
//so the openGL renderer can translate efficiently

WorldState::WorldState()
{
	CoordinateSizeX = 1024.0;
	CoordinateSizeY = 768.0;

	CellSizeX = CoordinateSizeX / coarseGraining ;
	CellSizeY = CoordinateSizeY / coarseGraining ;

	deleteList = new GameObjectList();
	allObjectList = new GameObjectList();
	worldMatrix = new GameObjectList**[CellSizeX];
	for (int i = 0; i < CellSizeX; ++i)
        worldMatrix[i] = new GameObjectList*[CellSizeY];

	for (int i=0;i<CellSizeX;i++)
	{
		for (int j=0;j<CellSizeY;j++)
		{
			worldMatrix[i][j] = new GameObjectList();
		}
	}
}


bool WorldState::insertObject(GameObject* gameObject, point *p)
{
	if (pointOutofBounds(p))
		return false;

	GameObjectList* currentList = worldMatrix[p->x / coarseGraining][p->y / coarseGraining];
	currentList->push_front(gameObject);
	gameObject->location = *p;
	allObjectList->push_front(gameObject);
	gameObject->worldState = this;
	return true;
}

bool WorldState::deleteObject(GameObject* gameObject)
{
	GameObjectList* currentList = worldMatrix[gameObject->location.x/coarseGraining][gameObject->location.y/coarseGraining];
	deleteList->push_front(gameObject);
	return true;
}

bool WorldState::moveObject(GameObject* gameObject, point *p)
{
	//replace with pixel perfect collision code
	if (pointOutofBounds(p))
	{
		gameObject->registerWallCollision();
		return false;
	}

		GameObjectList* currentList = worldMatrix[gameObject->location.x / coarseGraining][gameObject->location.y/ coarseGraining];
		GameObjectList* newList = worldMatrix[p->x/ coarseGraining][p->y/ coarseGraining];
		gameObject->location=*p;
		if (currentList==newList)
			return true;
		newList->push_front(gameObject);
		currentList->remove(gameObject);
		gameObject->location=*p;

		return true;

}

GameObjectList* WorldState::getAtCell(point *p)
{
	if (pointOutofBounds(p))
		return NULL;
	return worldMatrix[p->x/ coarseGraining][p->y/ coarseGraining];
}

const GameObjectList* WorldState::getAllGameObjects()
{
	return  allObjectList; //can't change the contents of the list, but _can_ change the properties of the objects
}

bool WorldState::cleanup()
{
	GameObjectIter itr;
	for (itr=deleteList->begin();itr!=deleteList->end();itr++)
	{
		GameObject* obj = *itr;
		allObjectList->remove(obj);
		GameObjectList* currentList = worldMatrix[obj->location.x / coarseGraining][obj->location.y/ coarseGraining];
		currentList->remove(obj);
		delete obj;
	}

	deleteList->clear();

	return true;
}

bool WorldState::pointOutofBounds(point* p)
{
	if (p->x / coarseGraining>=CellSizeX || p->x<0 || p->y / coarseGraining>=CellSizeY || p->y<0)
		return true;
	return false;

}