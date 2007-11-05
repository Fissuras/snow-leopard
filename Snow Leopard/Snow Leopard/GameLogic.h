#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

#include "GameObject.h"
#include "WorldState.h"

class WorldState;
class GameObject;

class GameLogic {

private:
	WorldState* state;

public:
		GameLogic::GameLogic(WorldState* worldState);
		bool GameLogic::step();

};
#endif