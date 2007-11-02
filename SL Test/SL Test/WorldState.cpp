#include "WorldState.h"
#include "GameObject.h"

bool WorldState::insertObject(GameObject* gameObject, int location[2])
{
	return true;
}

bool WorldState::deleteObject(GameObject* gameObject)
{
	return true;
}

bool WorldState::moveObject(GameObject* gameObject, int location[2])
{
	return true;
}

bool WorldState::getEnvironment(int location[2], int size, MatrixType* memory)
{
	return true;
}

GameObjectList WorldState::getAtLocation(int location[2])
{
	GameObjectList empty;
	return empty;
}