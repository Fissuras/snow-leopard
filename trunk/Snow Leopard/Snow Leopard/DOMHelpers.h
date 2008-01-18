#ifndef DOMHELPERS_H_
#define DOMHELPERS_H_

#include <string>
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

static double getAttributeDouble(std::string attributeName,xerces DOMNamedNodeMap* attributes)
{
	return atof(XercesString(attributes->getNamedItem(XercesString(attributeName).xmlCh())->getNodeValue()).stdStr().c_str());
}

static int getAttributeInt(std::string attributeName,xerces DOMNamedNodeMap* attributes)
{
	return atoi(XercesString(attributes->getNamedItem(XercesString(attributeName).xmlCh())->getNodeValue()).stdStr().c_str());
}
static unsigned int getAttributeUnsignedInt(std::string attributeName,xerces DOMNamedNodeMap* attributes)
{
	return atoi(XercesString(attributes->getNamedItem(XercesString(attributeName).xmlCh())->getNodeValue()).stdStr().c_str());
}
static std::string getAttributeStr(std::string attributeName,xerces DOMNamedNodeMap* attributes)
{
	return XercesString(attributes->getNamedItem(XercesString(attributeName).xmlCh())->getNodeValue()).stdStr();
}
static bool getAttributeBool(std::string attributeName,xerces DOMNamedNodeMap* attributes)
{
	if (XercesString(attributes->getNamedItem(XercesString(attributeName).xmlCh())->getNodeValue()).stdStr()=="true")
		return true;
	else if (XercesString(attributes->getNamedItem(XercesString(attributeName).xmlCh())->getNodeValue()).stdStr()=="false")
		return false;
	else throw new std::exception("boolean value not true or false");
}


#endif