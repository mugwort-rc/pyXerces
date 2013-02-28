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

template <class STR>
class PSVIHandlerDefVisitor
: public boost::python::def_visitor<PSVIHandlerDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("handleElementPSVI", &PSVIHandlerDefVisitor::handleElementPSVI)
	.def("handlePartialElementPSVI", &PSVIHandlerDefVisitor::handlePartialElementPSVI)
	.def("handleAttributesPSVI", &PSVIHandlerDefVisitor::handleAttributesPSVI)
	;
}

static void handleElementPSVI(xercesc::PSVIHandler& self, const STR& localName, const STR& uri, xercesc::PSVIElement* elementInfo) {
	XMLString buff1(localName), buff2(uri);
	self.handleElementPSVI(buff1.ptr(), buff2.ptr(), elementInfo);
}

static void handlePartialElementPSVI(xercesc::PSVIHandler& self, const STR& localName, const STR& uri, xercesc::PSVIElement* elementInfo) {
	XMLString buff1(localName), buff2(uri);
	self.handlePartialElementPSVI(buff1.ptr(), buff2.ptr(), elementInfo);
}

static void handleAttributesPSVI(xercesc::PSVIHandler& self, const STR& localName, const STR& uri, xercesc::PSVIAttributeList* psviAttributes) {
	XMLString buff1(localName), buff2(uri);
	self.handleAttributesPSVI(buff1.ptr(), buff2.ptr(), psviAttributes);
}

};

void PSVIHandler_init(void) {
	//! xercesc::PSVIHandler
	boost::python::class_<xercesc::PSVIHandler, boost::noncopyable>("PSVIHandler", boost::python::no_init)
			.def(PSVIHandlerDefVisitor<XMLString>())
			.def(PSVIHandlerDefVisitor<std::string>())
			.def("handleElementPSVI", &xercesc::PSVIHandler::handleElementPSVI)
			.def("handlePartialElementPSVI", &xercesc::PSVIHandler::handlePartialElementPSVI)
			.def("handleAttributesPSVI", &xercesc::PSVIHandler::handleAttributesPSVI)
			;
}

} /* namespace pyxerces */
