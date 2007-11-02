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
		std::list<GameObjectList> currentList = (worldMatrix[location[0]][location[1]]);
		currentList::push_front(gameObject);
		return true;
	}
	catch(...)
	{
		return false;
	}
}

bool WorldState::deleteObject(GameObject* gameObject)
{
	return true;
}

bool WorldState::moveObject(GameObject* gameObject, int location[2])
{
	return true;
}

bool WorldState::getEnvironment(int location[2], int size, Matrix<GameObjectList>* memory)
{
	return true;
}

GameObjectList WorldState::getAtLocation(int location[2])
{
	GameObjectList empty;
	return empty;
}