#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>
#include <string>
#include <iostream>
#include "GameObject.h"
#include "WorldState.h"
#include "Renderer.h"
#include "point.h"
#include "GameLogic.h"
#include <ctime>
#include "NonInteractiveBackground.h" 
#include "AI_Move_DoNothing.h"
#include "AI_Shoot_DoNothing.h"
#include "PulseCannon.h"
#include "ShotgunCannon.h"

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
#include "Definitions.h"

XERCES_CPP_NAMESPACE_USE



class DisplayApplication : public CL_ClanApplication
{

public:
	int main(int argc, char** argv);
};

// Create global application object:
// You MUST include this line or the application start-up will fail to
// locate your application object.
DisplayApplication app;

int DisplayApplication::main(int argc,  char **argv)
{
	// Setup clanlib modules:

	CL_SetupCore setup_core;
	CL_SetupDisplay setup_display;
	CL_SetupGL setup_gl;
	
	XMLPlatformUtils::Initialize();

	CL_DisplayWindow* window = new CL_DisplayWindow("Snow Leopard", 640, 480);
	CL_GraphicContext* gc = window->get_gc();
	CL_InputContext* ic = window->get_ic();

	CL_InputDevice keyboard = ic->get_keyboard();
	CL_InputDevice mouse = ic->get_mouse();

	CL_ConsoleWindow* console = new CL_ConsoleWindow("Debugging");

#ifdef DEBUG
	console->redirect_stdio();
#endif
	
	
	std::cout << "Now Debugging...";
	
	static const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };
	DOMImplementation* impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder* parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS,0);

    parser->setFeature(XMLUni::fgDOMNamespaces,true);
    parser->setFeature(XMLUni::fgXercesSchema, true);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);
	
#define xerces XERCES_CPP_NAMESPACE_QUALIFIER
	std::string xmlFile = "Resources\\XML\\example.xml";
	xerces DOMNode* doc;
	doc = parser->parseURI(XercesString(xmlFile).xmlCh());

	WorldState *state = new WorldState(doc);
	
	Renderer* renderer = new Renderer(window,gc,state);
	GameLogic *logic = new GameLogic(state,ic,renderer);

	renderer->setCameraZoomLevel(1.0);

    CL_FramerateCounter* framerate = new CL_FramerateCounter();
	framerate->set_fps_limit(60);
	
	while (true)
	{
	renderer->Render();
	window->flip();
	CL_System::keep_alive();
 	logic->step();
	}
	
	XMLPlatformUtils::Terminate();
	return 0;
}