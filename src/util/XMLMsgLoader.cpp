/*
 * XMLMsgLoader.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "XMLMsgLoader.h"

#include <boost/python.hpp>
#include <xercesc/util/XMLMsgLoader.hpp>

namespace pyxerces {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLMsgLoaderLoadMsgOverloads, loadMsg, 4, 7)

void XMLMsgLoader_init(void) {
	//! xercesc::XMLMsgLoader
	boost::python::class_<xercesc::XMLMsgLoader, boost::noncopyable>("XMLMsgLoader", boost::python::no_init)
			.def("loadMsg", static_cast<bool(xercesc::XMLMsgLoader::*)(const xercesc::XMLMsgLoader::XMLMsgId, XMLCh* const, const XMLSize_t)>(&xercesc::XMLMsgLoader::loadMsg))
			.def("loadMsg", static_cast<bool(xercesc::XMLMsgLoader::*)(const xercesc::XMLMsgLoader::XMLMsgId, XMLCh* const, const XMLSize_t, const XMLCh* const, const XMLCh* const, const XMLCh* const, const XMLCh* const, xercesc::MemoryManager* const)>(&xercesc::XMLMsgLoader::loadMsg), XMLMsgLoaderLoadMsgOverloads())
			.def("loadMsg", static_cast<bool(xercesc::XMLMsgLoader::*)(const xercesc::XMLMsgLoader::XMLMsgId, XMLCh* const, const XMLSize_t, const char* const, const char* const, const char* const, const char* const, xercesc::MemoryManager* const)>(&xercesc::XMLMsgLoader::loadMsg), XMLMsgLoaderLoadMsgOverloads())
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
