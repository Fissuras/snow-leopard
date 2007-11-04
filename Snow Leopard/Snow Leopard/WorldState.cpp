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
		currentList->push_front(gameObject);
		return true;
}

bool WorldState::deleteObject(GameObject* gameObject)
{
	try
	{
	GameObjectList* currentList = worldMatrix[gameObject->location[0]][gameObject->location[1]];
	return true;
	}
	catch(...)
	{
		return false;
	}
}

bool WorldState::moveObject(GameObject* gameObject, point *p)
{
	try
	{
		GameObjectList* currentList = worldMatrix[gameObject->location[0]][gameObject->location[1]];
		GameObjectList* newList = worldMatrix[p->x][p->y];
		newList->push_front(gameObject);
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
