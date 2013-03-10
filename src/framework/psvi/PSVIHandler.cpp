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

class PSVIHandlerWrapper
: public xercesc::PSVIHandler, public boost::python::wrapper<xercesc::PSVIHandler>
{
public:
void handleElementPSVI(const XMLCh* const localName, const XMLCh* const uri, xercesc::PSVIElement* elementInfo) {
	this->get_override("handleElementPSVI")(XMLString(localName), XMLString(uri), elementInfo);
}

void handlePartialElementPSVI(const XMLCh* const localName, const XMLCh* const uri, xercesc::PSVIElement* elementInfo) {
	if(boost::python::override handlePartialElementPSVI = this->get_override("handlePartialElementPSVI")){
		handlePartialElementPSVI(XMLString(localName), XMLString(uri), elementInfo);
	}else{
		xercesc::PSVIHandler::handlePartialElementPSVI(localName, uri, elementInfo);
	}
}

void handleAttributesPSVI(const XMLCh* const localName, const XMLCh* const uri, xercesc::PSVIAttributeList* psviAttributes) {
	this->get_override("handleAttributesPSVI")(XMLString(localName), XMLString(uri), psviAttributes);
}

};

void PSVIHandler_init(void) {
	//! xercesc::PSVIHandler
	boost::python::class_<PSVIHandlerWrapper, boost::noncopyable>("PSVIHandler", boost::python::no_init)
			.def(PSVIHandlerDefVisitor<XMLString>())
			.def(PSVIHandlerDefVisitor<std::string>())
			.def("handleElementPSVI", &xercesc::PSVIHandler::handleElementPSVI)
			.def("handlePartialElementPSVI", &xercesc::PSVIHandler::handlePartialElementPSVI)
			.def("handleAttributesPSVI", &xercesc::PSVIHandler::handleAttributesPSVI)
			;
}

} /* namespace pyxerces */
