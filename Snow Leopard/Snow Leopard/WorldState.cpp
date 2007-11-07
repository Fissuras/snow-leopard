#include "WorldState.h"
#include "GameObject.h"

#include <iostream>

//need to have a method that returns only what locations of objects changed during the last step,
//so the openGL renderer can translate efficiently

WorldState::WorldState()
{
	CoordinateSizeX = 500.0;
	CoordinateSizeY = 500.0;

	CellSizeX = CoordinateSizeX / coarseGraining ;
	CellSizeY = CoordinateSizeY / coarseGraining ;

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
		GameObjectList* currentList = worldMatrix[p->x / coarseGraining][p->y / coarseGraining];
		currentList->push_front(gameObject);
		gameObject->location = *p;
		allObjectList->push_front(gameObject);
		return true;
}

bool WorldState::deleteObject(GameObject* gameObject)
{
	GameObjectList* currentList = worldMatrix[gameObject->location.x/coarseGraining][gameObject->location.y/coarseGraining];
	currentList->remove(gameObject);
	allObjectList->remove(gameObject);
	//the renderer still has an association between the object's ID and a bitmap
	delete gameObject;
	return true;
}

bool WorldState::moveObject(GameObject* gameObject, point *p)
{

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

GameObjectList* WorldState::getAtLocation(point *p)
{
	return worldMatrix[p->x/ coarseGraining][p->y/ coarseGraining];
}

GameObjectList* WorldState::getAllGameObjects()
{
	return allObjectList;
}