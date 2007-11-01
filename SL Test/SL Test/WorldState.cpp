#include <string>
using namespace std;
class WorldState
{
	typedef List<GameObject*>[][] MatrixType;
	private MatrixType worldMatrix; //2d array of gameobjects. (each x,y holds a list)

	bool insertObject(GameObject* gameObject, int[2] location)
	{

	}

	bool deleteObject(GameObject* gameObject)
	{

	}

	bool moveObject(GameObject* gameObject, int[2] location)
	{

	}

	bool getEnvironment(int[2] location, int size, MatrixType* memory)
	{

	}

	List<GameObject*> getAtLocation(int[2])
	{

	}



}