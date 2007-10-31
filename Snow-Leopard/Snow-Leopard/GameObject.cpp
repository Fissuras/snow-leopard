#include <string>
using namespace std;
class GameObject
{
	string displayName; 
	private float velocity [2];
	int displayID;
	int[2] location;

	bool doActions(WorldState* worldState)
	{
		return true;
	}

	bool registerCollision(list<GameObject*> collisions)
	{
		return true;
	}


}

