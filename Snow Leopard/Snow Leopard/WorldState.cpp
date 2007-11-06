#include "WorldState.h"

#include <iostream>



WorldState::WorldState()
{
	xsize = 5;
	ysize = 5;

	worldMatrix = new envArray(xsize,ysize);
}


bool WorldState::insertObject(GameObject* gameObject, point *p)
{
		GameObjectList* currentList = (*worldMatrix)(p->x,p->y);
		if (currentList == NULL)
		{
			currentList = new GameObjectList();
			(*worldMatrix).insert_element(p->x,p->y,currentList);
		}
		currentList->push_front(gameObject);
		(*worldMatrix)(p->x,p->y) == currentList;
		gameObject->location = *p;
		return true;
}

bool WorldState::deleteObject(GameObject* gameObject)
{
	return true;
}

bool WorldState::moveObject(GameObject* gameObject, point *p)
{

		GameObjectList* currentList = (*worldMatrix)(gameObject->location.x,gameObject->location.y);
		GameObjectList* newList = (*worldMatrix)(p->x,p->y);
		if (newList==NULL)
		{
			newList = new GameObjectList();
			worldMatrix->insert_element(p->x,p->y,newList);
		}
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
	if (!(*worldMatrix)(p->x,p->y))
	{
		return new GameObjectList();
	}
	else
	{
		return (*worldMatrix)(p->x,p->y);
	}
}

GameObjectQueue* WorldState::getAllGameObjects()
{
	GameObjectQueue* objects = new GameObjectQueue();
	rowIter row;
	columnIter col;
	for (row = worldMatrix->begin1();row!=worldMatrix->end1();row++)
			{
				for (col = row.begin();col!=row.end();col++)
				{
					GameObjectList* list = *col;
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