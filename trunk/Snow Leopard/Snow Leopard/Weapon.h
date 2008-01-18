#ifndef WEAPON_H_
#define WEAPON_H_
#include "WorldState.h"
#include "Component.h"

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/AbstractDOMParser.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMImplementationRegistry.hpp>
#include <xercesc/dom/DOMBuilder.hpp>
#include <xercesc/dom/DOMException.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMError.hpp>
#include <xercesc/dom/DOMLocator.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/framework/LocalFileInputSource.hpp>
#include <xercesc/util/XMLString.hpp>
#include "XercesString.h"
#include "xercesc/framework/Wrapper4InputSource.hpp"
#define xerces XERCES_CPP_NAMESPACE_QUALIFIER

class WorldState;

class Weapon:public Component
{
	public:
		const int coolDownInterval;
		virtual void fire(WorldState* state, point location, double heading, double speed)
		{};
		unsigned int timeLastFired;
		Weapon::Weapon(int interval = 600) : coolDownInterval(interval)
		{};
};

#endif