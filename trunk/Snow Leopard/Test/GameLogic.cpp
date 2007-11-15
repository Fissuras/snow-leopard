#include "GameLogic.h"

#include "GameObject.h"
#include "WorldState.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>
#include "Ship.h"
#include "Renderer.h"


GameLogic::GameLogic(WorldState* worldState,Ship* ship,CL_InputContext* ic,Renderer* rend)
{
	state=worldState;
	keyboard = &ic->get_keyboard();
	mouse = &ic->get_mouse();
	playerShip = ship;
	renderer = rend;
}

bool GameLogic::step()
{

	state->deleteQueued();
	unsigned int currentTime = CL_System::get_time();
	state->timeElapsed = currentTime - state->time;
	state->time = currentTime;

	//should handle input with event callbacks, but I can't get them to work
	handleInput();
	
	const GameObjectList* objects = state->getAllGameObjects();
	ConstGameObjectIter itr;
	for(itr = objects->begin();itr !=objects->end();)
	{
		int objectID = (*itr)->ID;
		if (*itr == playerShip)
		{
			itr++;
			continue;
		}
		 //not very efficient. Should make the playership first or last and then not check
 		(*itr++)->doActions(); //if the object gets deleted during this, it's ok because the iterator is already incremented
	}
	return true;
}

void GameLogic::handleInput()
{
	 if (keyboard->get_keycode(CL_KEY_SPACE))
	 {
		 playerShip->shoot();
	 }

#define RELATIVE_MOVEMENT
#define NOPHYSICS
#ifdef ABSOLUTE_MOVEMENT
	 if (keyboard->get_keycode(CL_KEY_UP))
	 {
		 playerShip->move(GameObject::UP);
	 }

	 if (keyboard->get_keycode(CL_KEY_DOWN))
	 {
		 playerShip->move(GameObject::DOWN);
	 }

	 if (keyboard->get_keycode(CL_KEY_LEFT))
	 {
		playerShip->move(GameObject::LEFT);
	 }

	 if (keyboard->get_keycode(CL_KEY_RIGHT))
	 {
		playerShip->move(GameObject::RIGHT);
	 }
#endif

	 #ifdef RELATIVE_MOVEMENT
#ifdef NOPHYSICS
	 if (keyboard->get_keycode(CL_KEY_UP))
	 {
		 playerShip->move(GameObject::FORWARD);
	 }

	 if (keyboard->get_keycode(CL_KEY_DOWN))
	 {
		 playerShip->move(GameObject::BACK);
	 }

	 if (keyboard->get_keycode(CL_KEY_LEFT))
	 {
		 playerShip->move(GameObject::TURN_LEFT);
	 }

	 if (keyboard->get_keycode(CL_KEY_RIGHT))
	 {
		 playerShip->move(GameObject::TURN_RIGHT);
	 }
#endif
#ifdef PHYSICS
	 if (keyboard->get_keycode(CL_KEY_UP))
	 {
		 playerShip->move(GameObject::FORWARD); //crap, need real vector addition
	 }

	 if (keyboard->get_keycode(CL_KEY_DOWN))
	 {
		 playerShip->move(GameObject::BACK);
	 }

	 if (keyboard->get_keycode(CL_KEY_LEFT))
	 {
		 playerShip->move(GameObject::TURN_LEFT);
	 }

	 if (keyboard->get_keycode(CL_KEY_RIGHT))
	 {
		 playerShip->move(GameObject::TURN_RIGHT);
	 }
#endif
#endif


	 if (keyboard->get_keycode(CL_KEY_ESCAPE))
	 {
		exit(0);
	 }

	 if (keyboard->get_keycode(CL_KEY_SUBTRACT))
	 {
		 renderer->setCameraZoomLevel(1);
	 }

	  if (keyboard->get_keycode(CL_KEY_ADD))
	 {
		 renderer->setCameraZoomLevel(2);
	 }

}