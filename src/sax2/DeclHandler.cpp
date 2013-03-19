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

template <class STR>
class DeclHandlerDefVisitor
: public boost::python::def_visitor<DeclHandlerDefVisitor<STR> >
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

static void elementDecl(xercesc::DeclHandler& self, const STR& name, const STR& model) {
	XMLString buff1(name), buff2(model);
	self.elementDecl(buff1.ptr(), buff2.ptr());
}

static void attributeDecl(xercesc::DeclHandler& self, const STR& eName, const STR& aName, const STR& type, const STR& mode, const STR& value) {
	XMLString buff1(eName), buff2(aName), buff3(type), buff4(mode), buff5(value);
	self.attributeDecl(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr(), buff5.ptr());
}

static void internalEntityDecl(xercesc::DeclHandler& self, const STR& name, const STR& value) {
	XMLString buff1(name), buff2(value);
	self.internalEntityDecl(buff1.ptr(), buff2.ptr());
}

static void externalEntityDecl(xercesc::DeclHandler& self, const STR& name, const STR& publicId, const STR& systemId) {
	XMLString buff1(name), buff2(publicId), buff3(systemId);
	self.externalEntityDecl(buff1.ptr(), buff2.ptr(), buff3.ptr());
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
			.def(DeclHandlerDefVisitor<XMLString>())
			.def(DeclHandlerDefVisitor<std::string>())
			.def("elementDecl", boost::python::pure_virtual(&xercesc::DeclHandler::elementDecl))
			.def("attributeDecl", boost::python::pure_virtual(&xercesc::DeclHandler::attributeDecl))
			.def("internalEntityDecl", boost::python::pure_virtual(&xercesc::DeclHandler::internalEntityDecl))
			.def("externalEntityDecl", boost::python::pure_virtual(&xercesc::DeclHandler::externalEntityDecl))
			;
}

} /* namespace pyxerces */
