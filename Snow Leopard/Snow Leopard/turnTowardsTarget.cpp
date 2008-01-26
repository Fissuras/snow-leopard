#include "turnTowardsTarget.h"
#include "point.h"
#include "GameObject.h"
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>

using namespace SL;

bool turnTowardsTarget::init(SL::GameObject *object)
{
	return true;
};
BehaviorTreeNode::BEHAVIOR_STATUS turnTowardsTarget::execute(GameObject *object)
{
	GameObject* target = object->targetPriorities.at(0); //highest priority target
	CL_Vector targetPosition(target->location.x,target->location.y);
	CL_Vector currentPosition(object->location.x,object->location.y);

	double angle = currentPosition.angle(targetPosition) - object->heading;

	std::cout << angle << "\n";
	if (angle > 10)
	{
		object->rotate(.01);
		return SL_RUNNING;
	}
	else if (angle <10)
	{
		object->rotate(-.01);
		return SL_RUNNING;
	}

	else return SL_SUCCESS;

}