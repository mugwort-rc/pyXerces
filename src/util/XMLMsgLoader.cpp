/*
 * XMLMsgLoader.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "XMLMsgLoader.h"

#include <boost/python.hpp>
#include <xercesc/util/XMLMsgLoader.hpp>

#include "XMLString.h"

namespace pyxerces {

class XMLMsgLoaderWrapper
: public xercesc::XMLMsgLoader, public boost::python::wrapper<xercesc::XMLMsgLoader>
{
public:
bool loadMsg(const XMLMsgId msgToLoad, XMLCh* const toFill, const XMLSize_t maxChars) {
	return this->get_override("loadMsg")(msgToLoad, XMLString(toFill), maxChars);
}

bool loadMsg(const XMLMsgId msgToLoad, XMLCh* const toFill, const XMLSize_t maxChars, const XMLCh* const repText1, const XMLCh* const repText2 = 0, const XMLCh* const repText3 = 0, const XMLCh* const repText4 = 0, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	return this->get_override("loadMsg")(msgToLoad, XMLString(toFill), maxChars, XMLString(repText1), XMLString(repText2), XMLString(repText3), XMLString(repText4), boost::python::ptr(manager));
}

bool loadMsg(const XMLMsgId msgToLoad, XMLCh* const toFill, const XMLSize_t maxChars, const char* const repText1, const char* const repText2 = 0, const char* const repText3 = 0, const char* const repText4 = 0, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	return this->get_override("loadMsg")(msgToLoad, XMLString(toFill), maxChars, repText1, repText2, repText3, repText4, boost::python::ptr(manager));
}

};

//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLMsgLoaderLoadMsgOverloads, loadMsg, 4, 7)

void XMLMsgLoader_init(void) {
	//! xercesc::XMLMsgLoader
	boost::python::class_<XMLMsgLoaderWrapper, boost::noncopyable>("XMLMsgLoader")
			.def("loadMsg", boost::python::pure_virtual(static_cast<bool(xercesc::XMLMsgLoader::*)(const xercesc::XMLMsgLoader::XMLMsgId, XMLCh* const, const XMLSize_t)>(&xercesc::XMLMsgLoader::loadMsg)))
			.def("loadMsg", boost::python::pure_virtual(static_cast<bool(xercesc::XMLMsgLoader::*)(const xercesc::XMLMsgLoader::XMLMsgId, XMLCh* const, const XMLSize_t, const XMLCh* const, const XMLCh* const, const XMLCh* const, const XMLCh* const, xercesc::MemoryManager* const)>(&xercesc::XMLMsgLoader::loadMsg)))
			.def("loadMsg", boost::python::pure_virtual(static_cast<bool(xercesc::XMLMsgLoader::*)(const xercesc::XMLMsgLoader::XMLMsgId, XMLCh* const, const XMLSize_t, const char* const, const char* const, const char* const, const char* const, xercesc::MemoryManager* const)>(&xercesc::XMLMsgLoader::loadMsg)))
			.def("setLocale", &xercesc::XMLMsgLoader::setLocale)
			.def("getLocale", &xercesc::XMLMsgLoader::getLocale)
			.def("setNLSHome", &xercesc::XMLMsgLoader::setNLSHome)
			.def("getNLSHome", &xercesc::XMLMsgLoader::getNLSHome)
			.staticmethod("setLocale")
			.staticmethod("getLocale")
			.staticmethod("setNLSHome")
			.staticmethod("getNLSHome")
			;
}

} /* namespace pyxerces */
