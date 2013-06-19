/*
 * ContentHandler.cpp
 *
 *  Created on: 2013/03/10
 *      Author: mugwort_rc
 */

#include "ContentHandler.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax/Locator.hpp>
#include <xercesc/sax2/Attributes.hpp>

#include <xercesc/sax2/ContentHandler.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class ContentHandlerDefVisitor
: public boost::python::def_visitor<ContentHandlerDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("characters", &ContentHandlerDefVisitor::characters)
	.def("endElement", &ContentHandlerDefVisitor::endElement)
	.def("ignorableWhitespace", &ContentHandlerDefVisitor::ignorableWhitespace)
	.def("processingInstruction", &ContentHandlerDefVisitor::processingInstruction)
	.def("startElement", &ContentHandlerDefVisitor::startElement)
	.def("startPrefixMapping", &ContentHandlerDefVisitor::startPrefixMapping)
	.def("endPrefixMapping", &ContentHandlerDefVisitor::endPrefixMapping)
	.def("skippedEntity", &ContentHandlerDefVisitor::skippedEntity)
	;
}

static void characters(xercesc::ContentHandler& self, const XMLString& chars, const XMLSize_t length) {
	self.characters(chars.ptr(), length);
}

static void endElement(xercesc::ContentHandler& self, const XMLString& uri, const XMLString& localname, const XMLString& qname) {
	self.endElement(uri.ptr(), localname.ptr(), qname.ptr());
}

static void ignorableWhitespace(xercesc::ContentHandler& self, const XMLString& chars, const XMLSize_t length) {
	self.ignorableWhitespace(chars.ptr(), length);
}

static void processingInstruction(xercesc::ContentHandler& self, const XMLString& target, const XMLString& data) {
	self.processingInstruction(target.ptr(), data.ptr());
}

static void startElement(xercesc::ContentHandler& self, const XMLString& uri, const XMLString& localname, const XMLString& qname, const xercesc::Attributes& attrs) {
	self.startElement(uri.ptr(), localname.ptr(), qname.ptr(), attrs);
}

static void startPrefixMapping(xercesc::ContentHandler& self, const XMLString& prefix, const XMLString& uri) {
	self.startPrefixMapping(prefix.ptr(), uri.ptr());
}

static void endPrefixMapping(xercesc::ContentHandler& self, const XMLString& prefix) {
	self.endPrefixMapping(prefix.ptr());
}

static void skippedEntity(xercesc::ContentHandler& self, const XMLString& name) {
	self.endPrefixMapping(name.ptr());
}

};

class ContentHandlerWrapper
: public xercesc::ContentHandler, public boost::python::wrapper<xercesc::ContentHandler>
{
public:
void characters(const XMLCh* const chars, const XMLSize_t length) {
	this->get_override("characters")(XMLString(chars), length);
}

void endDocument () {
	this->get_override("endDocument")();
}

void endElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname) {
	this->get_override("endElement")(XMLString(uri), XMLString(localname), XMLString(qname));
}

void ignorableWhitespace(const XMLCh* const chars, const XMLSize_t length) {
	this->get_override("ignorableWhitespace")(XMLString(chars), length);
}

void processingInstruction(const XMLCh* const target, const XMLCh* const data) {
	this->get_override("processingInstruction")(XMLString(target), XMLString(data));
}

void setDocumentLocator(const xercesc::Locator* const locator) {
	this->get_override("setDocumentLocator")(boost::python::ptr(locator));
}

void startDocument() {
	this->get_override("startDocument")();
}

void startElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname, const xercesc::Attributes& attrs) {
	this->get_override("startElement")(XMLString(uri), XMLString(localname), XMLString(qname), boost::ref(attrs));
}

void startPrefixMapping(const XMLCh* const prefix, const XMLCh* const uri) {
	this->get_override("startPrefixMapping")(XMLString(prefix), XMLString(uri));
}

void endPrefixMapping(const XMLCh* const prefix) {
	this->get_override("endPrefixMapping")(XMLString(prefix));
}

void skippedEntity(const XMLCh* const name) {
	this->get_override("skippedEntity")(XMLString(name));
}

};

void ContentHandler_init(void) {
	//! xercesc::ContentHandler
	boost::python::class_<ContentHandlerWrapper, boost::noncopyable>("ContentHandler")
			.def(ContentHandlerDefVisitor())
			.def("characters", boost::python::pure_virtual(&xercesc::ContentHandler::characters))
			.def("endDocument", boost::python::pure_virtual(&xercesc::ContentHandler::endDocument))
			.def("endElement", boost::python::pure_virtual(&xercesc::ContentHandler::endElement))
			.def("ignorableWhitespace", boost::python::pure_virtual(&xercesc::ContentHandler::ignorableWhitespace))
			.def("processingInstruction", boost::python::pure_virtual(&xercesc::ContentHandler::processingInstruction))
			.def("setDocumentLocator", boost::python::pure_virtual(&xercesc::ContentHandler::setDocumentLocator))
			.def("startDocument", boost::python::pure_virtual(&xercesc::ContentHandler::startDocument))
			.def("startElement", boost::python::pure_virtual(&xercesc::ContentHandler::startElement))
			.def("startPrefixMapping", boost::python::pure_virtual(&xercesc::ContentHandler::startPrefixMapping))
			.def("endPrefixMapping", boost::python::pure_virtual(&xercesc::ContentHandler::endPrefixMapping))
			.def("skippedEntity", boost::python::pure_virtual(&xercesc::ContentHandler::skippedEntity))
			;
}

} /* namespace pyxerces */
