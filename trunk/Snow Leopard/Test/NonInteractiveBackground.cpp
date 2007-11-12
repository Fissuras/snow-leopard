#include "NonInteractiveBackground.h"


NonInteractiveBackground::NonInteractiveBackground(std::string resourceName,CL_ResourceManager* resources) : GameObject(resourceName,resources)
{
	actionPriority = BackgroundActionPriority;
	renderPriority = BackgroundRenderPriority;
}