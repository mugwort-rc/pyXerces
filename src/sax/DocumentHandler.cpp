/*
 * DocumentHandler.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "DocumentHandler.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax/AttributeList.hpp>
#include <xercesc/sax/Locator.hpp>

#include <xercesc/sax/DocumentHandler.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DocumentHandlerDefVisitor
: public boost::python::def_visitor<DocumentHandlerDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("characters", &DocumentHandlerDefVisitor::characters)
	.def("endElement", &DocumentHandlerDefVisitor::endElement)
	.def("ignorableWhitespace", &DocumentHandlerDefVisitor::ignorableWhitespace)
	.def("processingInstruction", &DocumentHandlerDefVisitor::processingInstruction)
	.def("startElement", &DocumentHandlerDefVisitor::startElement)
	;
}

static void characters(xercesc::DocumentHandler& self, const XMLString& chars) {
	self.characters(chars.ptr(), chars.size());
}

static void endElement(xercesc::DocumentHandler& self, const XMLString& name) {
	self.endElement(name.ptr());
}

static void ignorableWhitespace(xercesc::DocumentHandler& self, const XMLString& chars) {
	self.ignorableWhitespace(chars.ptr(), chars.size());
}

static void processingInstruction(xercesc::DocumentHandler& self, const XMLString& target, const XMLString& data) {
	self.processingInstruction(target.ptr(), data.ptr());
}

static void startElement(xercesc::DocumentHandler& self, const XMLString& name, xercesc::AttributeList& attrs) {
	self.startElement(name.ptr(), attrs);
}

};

class DocumentHandlerWrapper
: public xercesc::DocumentHandler, public boost::python::wrapper<xercesc::DocumentHandler>
{
public:
void characters(const XMLCh* const chars, const XMLSize_t length) {
	this->get_override("characters")(chars, length);
}

void endDocument () {
	this->get_override("endDocument")();
}

void endElement(const XMLCh* const name) {
	this->get_override("endElement")(name);
}

void ignorableWhitespace(const XMLCh* const chars, const XMLSize_t length) {
	this->get_override("ignorableWhitespace")(chars, length);
}

void processingInstruction(const XMLCh* const target, const XMLCh* const data) {
	this->get_override("processingInstruction")(target, data);
}

void resetDocument() {
	this->get_override("resetDocument")();
}

void setDocumentLocator(const xercesc::Locator* const locator) {
	this->get_override("setDocumentLocator")(locator);
}

void startDocument() {
	this->get_override("startDocument")();
}

void startElement(const XMLCh* const name, xercesc::AttributeList& attrs) {
	this->get_override("startElement")(name, &attrs);
}

};

void DocumentHandler_init(void) {
	//! xercesc::DocumentHandler
	boost::python::class_<DocumentHandlerWrapper, boost::noncopyable>("DocumentHandler")
			.def(DocumentHandlerDefVisitor())
			.def("characters", boost::python::pure_virtual(&xercesc::DocumentHandler::characters))
			.def("endDocument", boost::python::pure_virtual(&xercesc::DocumentHandler::endDocument))
			.def("endElement", boost::python::pure_virtual(&xercesc::DocumentHandler::endElement))
			.def("ignorableWhitespace", boost::python::pure_virtual(&xercesc::DocumentHandler::ignorableWhitespace))
			.def("processingInstruction", boost::python::pure_virtual(&xercesc::DocumentHandler::processingInstruction))
			.def("resetDocument", boost::python::pure_virtual(&xercesc::DocumentHandler::resetDocument))
			.def("setDocumentLocator", boost::python::pure_virtual(&xercesc::DocumentHandler::setDocumentLocator))
			.def("startDocument", boost::python::pure_virtual(&xercesc::DocumentHandler::startDocument))
			.def("startElement", boost::python::pure_virtual(&xercesc::DocumentHandler::startElement))
			;
}

} /* namespace pyxerces */
