#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_



class WorldState;
class GameObject;
class Ship;
class Renderer;
class CL_InputContext;
class CL_InputDevice;


class GameLogic {

private:
	WorldState* state;
	Ship* playerShip;
	CL_InputDevice* keyboard;
	CL_InputDevice* mouse;
	void handleInput();
	Renderer* renderer;
	
	

public:
		GameLogic::GameLogic(WorldState* worldState,Ship* ship,CL_InputContext* ic,Renderer* renderer);
		bool GameLogic::step();

};
#endif