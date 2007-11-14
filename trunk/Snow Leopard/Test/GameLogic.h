#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

#include "GameObject.h"
#include "WorldState.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>
#include "Ship.h"
#include "Renderer.h"

class WorldState;
class GameObject;





class GameLogic {

private:
	WorldState* state;
	Ship* playerShip;
	CL_InputDevice keyboard;
	CL_InputDevice mouse;
	void handleInput();
	Renderer* renderer;
	
	

public:
		unsigned int time;
		GameLogic::GameLogic(WorldState* worldState,Ship* ship,CL_InputContext* ic,Renderer* renderer);
		bool GameLogic::step();

};
#endif