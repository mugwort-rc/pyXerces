/*
 * DTDHandler.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "DTDHandler.h"

#include <boost/python.hpp>
#include <xercesc/sax/DTDHandler.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DTDHandlerWrapper
: public xercesc::DTDHandler, public boost::python::wrapper<xercesc::DTDHandler>
{
public:
DTDHandlerWrapper()
: xercesc::DTDHandler()
{}
~DTDHandlerWrapper()
{}

void notationDecl(const XMLCh* const name, const XMLCh* const publicId, const XMLCh* const systemId) {
	this->get_override("notationDecl")(name, publicId, systemId);
}
void unparsedEntityDecl(const XMLCh* const name, const XMLCh* const publicId, const XMLCh* const systemId, const XMLCh* const notationName) {
	this->get_override("unparsedEntityDecl")(name, publicId, systemId, notationName);
}

void resetDocType() {
	this->get_override("resetDocType")();
}

};

class DTDHandlerDefVisitor
: public boost::python::def_visitor<DTDHandlerDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("notationDecl", &DTDHandlerDefVisitor::notationDecl)
	.def("unparsedEntityDecl", &DTDHandlerDefVisitor::unparsedEntityDecl)
	;
}

static void notationDecl(xercesc::DTDHandler& self, const XMLString& name, const XMLString& publicId, const XMLString& systemId) {
	self.notationDecl(name.ptr(), publicId.ptr(), systemId.ptr());
}

static void unparsedEntityDecl(xercesc::DTDHandler& self, const XMLString& name, const XMLString& publicId, const XMLString& systemId, const XMLString& notationName) {
	self.unparsedEntityDecl(name.ptr(), publicId.ptr(), systemId.ptr(), notationName.ptr());
}

};

void DTDHandler_init(void) {
	//! xercesc::DTDHandler
	boost::python::class_<DTDHandlerWrapper, boost::noncopyable>("DTDHandler")
			.def(DTDHandlerDefVisitor())
			.def("notationDecl", boost::python::pure_virtual(&xercesc::DTDHandler::notationDecl))
			.def("unparsedEntityDecl", boost::python::pure_virtual(&xercesc::DTDHandler::unparsedEntityDecl))
			.def("resetDocType", boost::python::pure_virtual(&xercesc::DTDHandler::resetDocType))
			;
}

} /* namespace pyxerces */
