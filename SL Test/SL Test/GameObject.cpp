#include <string>
using namespace std;
class GameObject
{
	string displayName; 
	private float velocity [2];
	int faction;
	int displaySize;
	int[2] location;

	int displayID;
	int sourceSize;
	int displayOffset; // if there are multiple display frames in one bitmap, choose which one the GameObject has

	

	bool doActions(WorldState* worldState)
	{
		return true;
	}

	bool registerCollision(list<GameObject*> collisions)
	{
		return true;
	}


}

