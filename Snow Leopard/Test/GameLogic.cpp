#include "GameLogic.h"


GameLogic::GameLogic(WorldState* worldState,Ship* ship,CL_InputContext* ic)
{
	state=worldState;
	keyboard = ic->get_keyboard();
	mouse = ic->get_mouse();
	playerShip = ship;
}

bool GameLogic::step()
{
	//should handle input with event callbacks, but I can't get them to work
	handleInput();
	
	const GameObjectList* objects = state->getAllGameObjects();
	ConstGameObjectIter itr;
	for(itr = objects->begin();itr !=objects->end();itr++)
	{
		GameObject* obj = *itr;
		if (obj == playerShip)
		{
			continue;
		}
		 //not very efficient. Should make the playership first or last and then not check
		obj->doActions(state);
	}
	return true;
}

void GameLogic::handleInput()
{
	 if (keyboard.get_keycode(CL_KEY_SPACE))
	 {
		 playerShip->shoot(state);
	 }

	 if (keyboard.get_keycode(CL_KEY_UP))
	 {
		 playerShip->move(state,GameObject::UP);
	 }

	 if (keyboard.get_keycode(CL_KEY_DOWN))
	 {
		 playerShip->move(state,GameObject::DOWN);
	 }

	 if (keyboard.get_keycode(CL_KEY_LEFT))
	 {
		playerShip->move(state,GameObject::LEFT);
	 }

	 if (keyboard.get_keycode(CL_KEY_RIGHT))
	 {
		playerShip->move(state,GameObject::RIGHT);
	 }

	 if (keyboard.get_keycode(CL_KEY_ESCAPE))
	 {
		 exit(0);
	 }
}