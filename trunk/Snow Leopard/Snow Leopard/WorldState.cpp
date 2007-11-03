#include "WorldState.h"
#include "GameObject.h"


WorldState::WorldState()
{
	worldMatrix = new Matrix<GameObjectList>(100,100);
}


bool WorldState::insertObject(GameObject* gameObject, int location[2])
{
	try
	{
		GameObjectList currentList = (*worldMatrix)(location[0],location[1]);
		currentList.push_front(gameObject);
		return true;
	}
	catch(...)
	{
		return false;
	}
}

bool WorldState::deleteObject(GameObject* gameObject)
{
	try
	{
	GameObjectList currentList = (*worldMatrix)(gameObject->location[0],gameObject->location[1]);
	currentList.remove(gameObject);
	return true;
	}
	catch(...)
	{
		return false;
	}
}

bool WorldState::moveObject(GameObject* gameObject, int location[2])
{
	try
	{
		GameObjectList currentList = (*worldMatrix)(gameObject->location[0],gameObject->location[1]);
		currentList.remove(gameObject);
		GameObjectList newList = (*worldMatrix)(location[0],location[1]);
		newList.push_front(gameObject);
	}

	catch(...)
	{
		return false;

	}

}

bool WorldState::getEnvironment(int location[2], int size, Matrix<GameObjectList>* memory)
{
	
}

GameObjectList WorldState::getAtLocation(int location[2])
{
	return (*worldMatrix)(location[0],location[1]);
}