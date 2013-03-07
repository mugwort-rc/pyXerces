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

template <class STR>
class DTDHandlerDefVisitor
: public boost::python::def_visitor<DTDHandlerDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("notationDecl", &DTDHandlerDefVisitor<STR>::notationDecl)
	.def("unparsedEntityDecl", &DTDHandlerDefVisitor<STR>::unparsedEntityDecl)
	;
}

static void notationDecl(xercesc::DTDHandler& self, const STR& name, const STR& publicId, const STR& systemId) {
	XMLString buff1(name), buff2(publicId), buff3(systemId);
	self.notationDecl(buff1.ptr(), buff2.ptr(), buff3.ptr());
}

static void unparsedEntityDecl(xercesc::DTDHandler& self, const STR& name, const STR& publicId, const STR& systemId, const STR& notationName) {
	XMLString buff1(name), buff2(publicId), buff3(systemId), buff4(notationName);
	self.unparsedEntityDecl(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr());
}

};

void DTDHandler_init(void) {
	//! xercesc::DTDHandler
	boost::python::class_<DTDHandlerWrapper, boost::noncopyable>("DTDHandler")
			.def(DTDHandlerDefVisitor<XMLString>())
			.def(DTDHandlerDefVisitor<std::string>())
			.def("notationDecl", &xercesc::DTDHandler::notationDecl)
			.def("unparsedEntityDecl", &xercesc::DTDHandler::unparsedEntityDecl)
			.def("resetDocType", &xercesc::DTDHandler::resetDocType)
			;
}

} /* namespace pyxerces */
