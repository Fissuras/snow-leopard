#ifndef BEHAVIORTREENODE_H_
#define BEHAVIORTREENODE_H_

#include <vector>
#include <map>

class GameObject;

//error will completely reevaluate the tree
 enum BEHAVIOR_STATUS {SUCCESS,FAILURE,ERROR,RUNNING};

class BehaviorTreeNode
{
public:
	virtual BEHAVIOR_STATUS execute(GameObject* object);
	virtual bool init(GameObject* object);
	BehaviorTreeNode* deepCopy();
};

typedef std::vector<BehaviorTreeNode*> BehaviorTreeList;
typedef BehaviorTreeList::iterator BehaviorTreeListIter;

class BehaviorTreeInternalNode:public BehaviorTreeNode
{
	
protected:
	BehaviorTreeList children;
	
	bool BehaviorTreeInternalNode::addChild(BehaviorTreeNode* newChild)
	{
		children.push_back(newChild);
	};
};


class SequentialNode:public BehaviorTreeInternalNode
{
	BEHAVIOR_STATUS execute(GameObject* object);

	private: int currentPosition;
};

class PrioritySelectorNode:public BehaviorTreeInternalNode
{
	BEHAVIOR_STATUS execute(GameObject* object);

	BehaviorTreeListIter currentlyRunningNode;

};

class ProbabilitySelectorNode:public BehaviorTreeInternalNode
{
private:
	double totalSum;
	std::map<BehaviorTreeNode*,double>::iterator currentlyRunningNode;
	std::map<BehaviorTreeNode*,double> weightingMap;
	std::map<BehaviorTreeNode*,double>::iterator itr;
public:
	bool init(GameObject* object);
	BEHAVIOR_STATUS execute(GameObject* object);
	bool addChild( BehaviorTreeNode* node,double weighting);
};

#endif