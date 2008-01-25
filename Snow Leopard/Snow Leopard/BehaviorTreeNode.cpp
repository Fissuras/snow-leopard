#include "BehaviorTreeNode.h"
#include "mtrand.h"
BEHAVIOR_STATUS SequentialNode::execute(GameObject* object)
	{
		BehaviorTreeNode* currentTask = children.at(currentPosition);
		BEHAVIOR_STATUS result = currentTask->execute(object);

		if (result == SUCCESS)
		{
			if (currentPosition == children.size()) //finished last task
			{
				return SUCCESS;
			}
			else
			{
				currentPosition++;
				return RUNNING;
			}
		}
		return result;
	}

BEHAVIOR_STATUS PrioritySelectorNode::execute(GameObject* object)
{
	if (*currentlyRunningNode) //there's one still running
	{
		BEHAVIOR_STATUS status = (*currentlyRunningNode)->execute(object);
		if (status == RUNNING)
			return RUNNING;
		else if (status == SUCCESS)
		{
			delete &currentlyRunningNode;
			return SUCCESS;
		}
	}

	else //need to choose one
	{
		currentlyRunningNode = children.begin();
		BEHAVIOR_STATUS status;
        while ((status = (*currentlyRunningNode)->execute(object)) == FAILURE) //keep trying children until one doesn't fail
        {
			currentlyRunningNode++;
            if (currentlyRunningNode == children.end()) //all of the children failed
                return FAILURE;
        }
		if (status == SUCCESS)
			delete &currentlyRunningNode;
        return status;
	}

}

bool ProbabilitySelectorNode::init(GameObject* object)
{
	totalSum = 0;
	return true;
}
bool ProbabilitySelectorNode::addChild(BehaviorTreeNode* node, double weighting)
{
	weightingMap[node] = weighting;
	totalSum += weighting;
	BehaviorTreeInternalNode::children.push_back(node);
	return true;
}

BEHAVIOR_STATUS ProbabilitySelectorNode::execute(GameObject *object)
{
	//check if we've already chosen a node to run
	if (&currentlyRunningNode)
	{
		BEHAVIOR_STATUS status = ((*currentlyRunningNode).first)->execute(object);
		if (status != RUNNING)
			delete &currentlyRunningNode;
		return status;
	}


	//move the generator to gamelogic and have a method that returns a pointer to it
	MTRand_closed random;
	double chosen = random() * totalSum; //generate a number between 0 and the sum of the weights

	double sum = 0;
	for (itr = weightingMap.begin() ; itr!=weightingMap.end() ; itr++)
	{
		sum += (*itr).second;
		if (sum >= chosen) //execute this node
		{
			BEHAVIOR_STATUS status = (*itr).first->execute(object);

			if (status == RUNNING)
				currentlyRunningNode = itr;
			return status;
		}
	}

	

	return SUCCESS;
}