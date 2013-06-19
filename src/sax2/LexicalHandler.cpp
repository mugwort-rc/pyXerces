/*
 * LexicalHandler.cpp
 *
 *  Created on: 2013/03/10
 *      Author: mugwort_rc
 */

#include "LexicalHandler.h"

#include <boost/python.hpp>
#include <xercesc/sax2/LexicalHandler.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class LexicalHandlerDefVisitor
: public boost::python::def_visitor<LexicalHandlerDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("comment", &LexicalHandlerDefVisitor::comment)
	.def("endEntity", &LexicalHandlerDefVisitor::endEntity)
	.def("startDTD", &LexicalHandlerDefVisitor::startDTD)
	.def("startEntity", &LexicalHandlerDefVisitor::startEntity)
	;
}

static void comment(xercesc::LexicalHandler& self, const XMLString& chars, const XMLSize_t length) {
	self.comment(chars.ptr(), length);
}

static void endEntity(xercesc::LexicalHandler& self, const XMLString& name) {
	self.endEntity(name.ptr());
}

static void startDTD(xercesc::LexicalHandler& self, const XMLString& name, const XMLString& publicId, const XMLString& systemId) {
	self.startDTD(name.ptr(), publicId.ptr(), systemId.ptr());
}

static void startEntity(xercesc::LexicalHandler& self, const XMLString& name) {
	self.startEntity(name.ptr());
}

};

class LexicalHandlerWrapper
: public xercesc::LexicalHandler, public boost::python::wrapper<xercesc::LexicalHandler>
{
public:
void comment(const XMLCh* const chars, const XMLSize_t length) {
	this->get_override("comment")(XMLString(chars), length);
}

void endCDATA () {
	this->get_override("endCDATA")();
}

void endDTD () {
	this->get_override("endDTD")();
}

void endEntity (const XMLCh* const name) {
	this->get_override("endEntity")(XMLString(name));
}

void startCDATA () {
	this->get_override("startCDATA")();
}

void startDTD(const XMLCh* const name, const XMLCh* const publicId, const XMLCh* const systemId) {
	this->get_override("startDTD")(XMLString(name), XMLString(publicId), XMLString(systemId));
}

void startEntity (const XMLCh* const name) {
	this->get_override("startEntity")(XMLString(name));
}

};

void LexicalHandler_init(void) {
	//! xercesc::LexicalHandler
	boost::python::class_<LexicalHandlerWrapper, boost::noncopyable>("LexicalHandler")
			.def(LexicalHandlerDefVisitor())
			.def("comment", boost::python::pure_virtual(&xercesc::LexicalHandler::comment))
			.def("endCDATA", boost::python::pure_virtual(&xercesc::LexicalHandler::endCDATA))
			.def("endDTD", boost::python::pure_virtual(&xercesc::LexicalHandler::endDTD))
			.def("endEntity", boost::python::pure_virtual(&xercesc::LexicalHandler::endEntity))
			.def("startCDATA", boost::python::pure_virtual(&xercesc::LexicalHandler::startCDATA))
			.def("startDTD", boost::python::pure_virtual(&xercesc::LexicalHandler::startDTD))
			.def("startEntity", boost::python::pure_virtual(&xercesc::LexicalHandler::startEntity))
			;
}

} /* namespace pyxerces */
