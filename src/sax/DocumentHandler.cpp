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

template <class STR>
class DocumentHandlerDefVisitor
: public boost::python::def_visitor<DocumentHandlerDefVisitor<STR> >
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
	;
}

static void characters(xercesc::DocumentHandler& self, const STR& chars) {
	XMLString buff(chars);
	self.characters(buff.ptr(), buff.size());
}

static void endElement(xercesc::DocumentHandler& self, const STR& name) {
	XMLString buff(name);
	self.endElement(buff.ptr());
}

static void ignorableWhitespace(xercesc::DocumentHandler& self, const STR& chars) {
	XMLString buff(chars);
	self.ignorableWhitespace(buff.ptr(), buff.size());
}

static void processingInstruction(xercesc::DocumentHandler& self, const STR& target, const STR& data) {
	XMLString buff1(target), buff2(data);
	self.processingInstruction(buff1.ptr(), buff2.ptr());
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
	this->get_override("startElement")(name, attrs);
}

};

void DocumentHandler_init(void) {
	//! xercesc::DocumentHandler
	boost::python::class_<DocumentHandlerWrapper, boost::noncopyable>("DocumentHandler")
			.def(DocumentHandlerDefVisitor<XMLString>())
			.def(DocumentHandlerDefVisitor<std::string>())
			.def("characters", &xercesc::DocumentHandler::characters)
			.def("endDocument", &xercesc::DocumentHandler::endDocument)
			.def("endElement", &xercesc::DocumentHandler::endElement)
			.def("ignorableWhitespace", &xercesc::DocumentHandler::ignorableWhitespace)
			.def("processingInstruction", &xercesc::DocumentHandler::processingInstruction)
			.def("resetDocument", &xercesc::DocumentHandler::resetDocument)
			.def("setDocumentLocator", &xercesc::DocumentHandler::setDocumentLocator)
			.def("startDocument", &xercesc::DocumentHandler::startDocument)
			.def("startElement", &xercesc::DocumentHandler::startElement)
			;
}

} /* namespace pyxerces */
