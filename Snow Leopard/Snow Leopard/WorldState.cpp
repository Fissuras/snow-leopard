#include "WorldState.h"
#include "GameObject.h"

#include <iostream>



WorldState::WorldState()
{
	xsize = 5;
	ysize = 5;

	worldMatrix = new GameObjectList**[xsize];
	for (int i = 0; i < xsize; ++i)
        worldMatrix[i] = new GameObjectList*[ysize];

	for (int i=0;i<xsize;i++)
	{
		for (int j=0;j<ysize;j++)
		{
			worldMatrix[i][j] = new GameObjectList();
		}
	}
}


bool WorldState::insertObject(GameObject* gameObject, point *p)
{
		GameObjectList* currentList = worldMatrix[p->x][p->y];
		currentList->insert(gameObject);
		gameObject->location = *p;
		return true;
}

bool WorldState::deleteObject(GameObject* gameObject)
{
	return true;
}

bool WorldState::moveObject(GameObject* gameObject, point *p)
{
	try
	{
		GameObjectList* currentList = worldMatrix[gameObject->location.x][gameObject->location.y];
		GameObjectList* newList = worldMatrix[p->x][p->y];
		return true;
	}

	catch(...)
	{
		return false;

	}

}

bool WorldState::getEnvironment(point *p, int size, GameObjectList** memory)
{
	return true;
}

GameObjectList* WorldState::getAtLocation(point *p)
{
	return worldMatrix[p->x][p->y];
}
