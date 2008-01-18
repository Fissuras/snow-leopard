#ifndef SHOTGUNCANNON_H_
#define SHOTGUNCANNON_H_
#include "WorldState.h"
#include "Weapon.h"
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

class ShotgunCannon:public Weapon
{
	public:
		static const int coolDownInterval = 600;
		void fire(WorldState* state, point location, double displayHeading, double speed, CL_ResourceManager* resources)
		{
			for (int i=0;i<5;i++)
			{
			/*SevnaMark40* p = new SevnaMark40("SevnaMark40",resources);
			p->resourceName = "SevnaMark40";
			p->heading = displayHeading - 24 + 6*i;
			p->speed = speed + .5;
			state->insertObject(p,location.offsetPolar(displayHeading,2));*/
			}
			
			Weapon::timeLastFired = state->time;
		};
		ShotgunCannon::ShotgunCannon()
		{
			Weapon::timeLastFired = 0;
		};
};

#endif