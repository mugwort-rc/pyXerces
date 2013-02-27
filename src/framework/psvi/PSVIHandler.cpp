/*
 * PSVIHandler.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "PSVIHandler.h"

#include <boost/python.hpp>
#include <xercesc/framework/psvi/PSVIElement.hpp>		//!< for forward declaration
#include <xercesc/framework/psvi/PSVIAttributeList.hpp>	//!< for forward declaration
#include <xercesc/framework/psvi/PSVIHandler.hpp>

#include "../../util/XMLString.h"

namespace pyxerces {

class PSVIHandlerDefVisitor
: public boost::python::def_visitor<PSVIHandlerDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("handleElementPSVI", static_cast<void(*)(xercesc::PSVIHandler&, const XMLString&, const XMLString&, xercesc::PSVIElement*)>(&PSVIHandlerDefVisitor::handleElementPSVI))
	.def("handleElementPSVI", static_cast<void(*)(xercesc::PSVIHandler&, const std::string&, const std::string&, xercesc::PSVIElement*)>(&PSVIHandlerDefVisitor::handleElementPSVI))
	.def("handlePartialElementPSVI", static_cast<void(*)(xercesc::PSVIHandler&, const XMLString&, const XMLString&, xercesc::PSVIElement*)>(&PSVIHandlerDefVisitor::handlePartialElementPSVI))
	.def("handlePartialElementPSVI", static_cast<void(*)(xercesc::PSVIHandler&, const std::string&, const std::string&, xercesc::PSVIElement*)>(&PSVIHandlerDefVisitor::handlePartialElementPSVI))
	.def("handleAttributesPSVI", static_cast<void(*)(xercesc::PSVIHandler&, const XMLString&, const XMLString&, xercesc::PSVIAttributeList*)>(&PSVIHandlerDefVisitor::handleAttributesPSVI))
	.def("handleAttributesPSVI", static_cast<void(*)(xercesc::PSVIHandler&, const std::string&, const std::string&, xercesc::PSVIAttributeList*)>(&PSVIHandlerDefVisitor::handleAttributesPSVI))
	;
}

static void handleElementPSVI(xercesc::PSVIHandler& self, const XMLString& localName, const XMLString& uri, xercesc::PSVIElement* elementInfo) {
	self.handleElementPSVI(localName.ptr(), uri.ptr(), elementInfo);
}

static void handleElementPSVI(xercesc::PSVIHandler& self, const std::string& localName, const std::string& uri, xercesc::PSVIElement* elementInfo) {
	XMLString buff1(localName), buff2(uri);
	PSVIHandlerDefVisitor::handleElementPSVI(self, buff1, buff2, elementInfo);
}

static void handlePartialElementPSVI(xercesc::PSVIHandler& self, const XMLString& localName, const XMLString& uri, xercesc::PSVIElement* elementInfo) {
	self.handlePartialElementPSVI(localName.ptr(), uri.ptr(), elementInfo);
}

static void handlePartialElementPSVI(xercesc::PSVIHandler& self, const std::string& localName, const std::string& uri, xercesc::PSVIElement* elementInfo) {
	XMLString buff1(localName), buff2(uri);
	PSVIHandlerDefVisitor::handlePartialElementPSVI(self, buff1, buff2, elementInfo);
}

static void handleAttributesPSVI(xercesc::PSVIHandler& self, const XMLString& localName, const XMLString& uri, xercesc::PSVIAttributeList* psviAttributes) {
	self.handleAttributesPSVI(localName.ptr(), uri.ptr(), psviAttributes);
}

static void handleAttributesPSVI(xercesc::PSVIHandler& self, const std::string& localName, const std::string& uri, xercesc::PSVIAttributeList* psviAttributes) {
	XMLString buff1(localName), buff2(uri);
	PSVIHandlerDefVisitor::handleAttributesPSVI(self, buff1, buff2, psviAttributes);
}

};

void PSVIHandler_init(void) {
	//! xercesc::PSVIHandler
	boost::python::class_<xercesc::PSVIHandler, boost::noncopyable>("PSVIHandler", boost::python::no_init)
			.def(PSVIHandlerDefVisitor())
			.def("handleElementPSVI", &xercesc::PSVIHandler::handleElementPSVI)
			.def("handlePartialElementPSVI", &xercesc::PSVIHandler::handlePartialElementPSVI)
			.def("handleAttributesPSVI", &xercesc::PSVIHandler::handleAttributesPSVI)
			;
}

} /* namespace pyxerces */
