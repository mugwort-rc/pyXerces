/*
 * DeclHandler.cpp
 *
 *  Created on: 2013/03/10
 *      Author: mugwort_rc
 */

#include "DeclHandler.h"

#include <boost/python.hpp>
#include <xercesc/sax2/DeclHandler.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DeclHandlerDefVisitor
: public boost::python::def_visitor<DeclHandlerDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("elementDecl", &DeclHandlerDefVisitor::elementDecl)
	.def("attributeDecl", &DeclHandlerDefVisitor::attributeDecl)
	.def("internalEntityDecl", &DeclHandlerDefVisitor::internalEntityDecl)
	.def("externalEntityDecl", &DeclHandlerDefVisitor::externalEntityDecl)
	;
}

static void elementDecl(xercesc::DeclHandler& self, const XMLString& name, const XMLString& model) {
	self.elementDecl(name.ptr(), model.ptr());
}

static void attributeDecl(xercesc::DeclHandler& self, const XMLString& eName, const XMLString& aName, const XMLString& type, const XMLString& mode, const XMLString& value) {
	self.attributeDecl(eName.ptr(), aName.ptr(), type.ptr(), mode.ptr(), value.ptr());
}

static void internalEntityDecl(xercesc::DeclHandler& self, const XMLString& name, const XMLString& value) {
	self.internalEntityDecl(name.ptr(), value.ptr());
}

static void externalEntityDecl(xercesc::DeclHandler& self, const XMLString& name, const XMLString& publicId, const XMLString& systemId) {
	self.externalEntityDecl(name.ptr(), publicId.ptr(), systemId.ptr());
}

};

class DeclHandlerWrapper
: public xercesc::DeclHandler, public boost::python::wrapper<xercesc::DeclHandler>
{
public:
void elementDecl(const XMLCh* const name, const XMLCh* const model) {
	this->get_override("elementDecl")(XMLString(name), XMLString(model));
}

void attributeDecl(const XMLCh* const eName, const XMLCh* const aName, const XMLCh* const type, const XMLCh* const mode, const XMLCh* const value) {
	this->get_override("attributeDecl")(XMLString(eName), XMLString(aName), XMLString(type), XMLString(mode), XMLString(value));
}

void internalEntityDecl(const XMLCh* const name, const XMLCh* const value) {
	this->get_override("internalEntityDecl")(XMLString(name), XMLString(value));
}

void externalEntityDecl(const XMLCh* const name, const XMLCh* const publicId, const XMLCh* const systemId) {
	this->get_override("externalEntityDecl")(XMLString(name), XMLString(publicId), XMLString(systemId));
}

};

void DeclHandler_init(void) {
	//! xercesc::DeclHandler
	boost::python::class_<DeclHandlerWrapper, boost::noncopyable>("DeclHandler")
			.def(DeclHandlerDefVisitor())
			.def("elementDecl", boost::python::pure_virtual(&xercesc::DeclHandler::elementDecl))
			.def("attributeDecl", boost::python::pure_virtual(&xercesc::DeclHandler::attributeDecl))
			.def("internalEntityDecl", boost::python::pure_virtual(&xercesc::DeclHandler::internalEntityDecl))
			.def("externalEntityDecl", boost::python::pure_virtual(&xercesc::DeclHandler::externalEntityDecl))
			;
}

} /* namespace pyxerces */
