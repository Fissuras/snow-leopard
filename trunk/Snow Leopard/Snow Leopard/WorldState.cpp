#include "WorldState.h"
#include "GameObject.h"

#include <iostream>



WorldState::WorldState()
{
	CoordinateSizeX = 500.0;
	CoordinateSizeY = 500.0;

	CellSizeX = CoordinateSizeX / coarseGraining ;
	CellSizeY = CoordinateSizeY / coarseGraining ;

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
		return true;
}

bool WorldState::deleteObject(GameObject* gameObject)
{
	return true;
}

bool WorldState::moveObject(GameObject* gameObject, point *p)
{

		GameObjectList* currentList = worldMatrix[gameObject->location.x / coarseGraining][gameObject->location.y/ coarseGraining];
		GameObjectList* newList = worldMatrix[p->x/ coarseGraining][p->y/ coarseGraining];

		newList->push_front(gameObject);
		currentList->remove(gameObject);
		gameObject->location=*p;

		return true;

}

bool WorldState::getEnvironment(point *p, int size, GameObjectList** memory)
{
	return true;
}

GameObjectList* WorldState::getAtLocation(point *p)
{
	return worldMatrix[p->x/ coarseGraining][p->y/ coarseGraining];
}

GameObjectQueue* WorldState::getAllGameObjects()
{
GameObjectQueue* objects = new GameObjectQueue();
	for (int x = 0;x<CellSizeX;x++)
	{
		for (int y = 0;y<CellSizeY;y++)
		{
			GameObjectList* list = worldMatrix[x][y];
			GameObjectIter itr;
			for (itr = list->begin();itr!=list->end();itr++)
			{
				GameObject* obj = *itr;
				objects->push(obj);
			}
		}
	}
	return objects;
}