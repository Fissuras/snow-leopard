#include "NonInteractiveBackground.h"


NonInteractiveBackground::NonInteractiveBackground(xerces DOMNode* rootNode) : GameObject(rootNode)
{
	actionPriority = BackgroundActionPriority;
	renderPriority = BackgroundRenderPriority;
}