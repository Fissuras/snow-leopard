#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

#include "GameObject.h"
#include "WorldState.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>
#include "Ship.h"

class WorldState;
class GameObject;





class GameLogic {

private:
	WorldState* state;
	Ship* playerShip;
	CL_InputDevice keyboard;
	CL_InputDevice mouse;
	void handleInput();
	

public:
		GameLogic::GameLogic(WorldState* worldState,Ship* ship,CL_InputContext* ic);
		bool GameLogic::step();

};
#endif