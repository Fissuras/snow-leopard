#ifndef WORLDSTATE_H_
#define WORLDSTATE_H_

#include <list>

#include "GameObject.h"

class GameObject;

typedef std::list<GameObject*>** MatrixType;
typedef std::list<GameObject*> GameObjectList;

class WorldState
{
public:

bool insertObject(GameObject* gameObject, int location[2]);
bool deleteObject(GameObject* gameObject);
bool moveObject(GameObject* gameObject, int location[2]);
bool getEnvironment(int location[2], int size, MatrixType* memory);
GameObjectList getAtLocation(int[2]);

private:
	MatrixType worldMatrix; //2d array of gameobjects. (each x,y holds a list)
};

#endif