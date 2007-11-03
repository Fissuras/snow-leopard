#ifndef WORLDSTATE_H_
#define WORLDSTATE_H_

#include <list>

#include "GameObject.h"
#include "Matrix.h"

class GameObject;

typedef std::list<GameObject*> GameObjectList;

class WorldState
{
public:

WorldState::WorldState();
bool insertObject(GameObject* gameObject, int location[2]);
bool deleteObject(GameObject* gameObject);
bool moveObject(GameObject* gameObject, int location[2]);
bool getEnvironment(int location[2], int size, Matrix<GameObjectList>* memory);
GameObjectList getAtLocation(int[2]);

private:
	Matrix<GameObjectList> *worldMatrix; //2d array of gameobjects. (each x,y holds a list)
};

#endif