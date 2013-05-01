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

template <typename STR>
class ContentHandlerDefVisitor
: public boost::python::def_visitor<ContentHandlerDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("characters", &ContentHandlerDefVisitor<STR>::characters)
	.def("endElement", &ContentHandlerDefVisitor<STR>::endElement)
	.def("ignorableWhitespace", &ContentHandlerDefVisitor<STR>::ignorableWhitespace)
	.def("processingInstruction", &ContentHandlerDefVisitor<STR>::processingInstruction)
	.def("startElement", &ContentHandlerDefVisitor<STR>::startElement)
	.def("startPrefixMapping", &ContentHandlerDefVisitor<STR>::startPrefixMapping)
	.def("endPrefixMapping", &ContentHandlerDefVisitor<STR>::endPrefixMapping)
	.def("skippedEntity", &ContentHandlerDefVisitor<STR>::skippedEntity)
	;
}

static void characters(xercesc::ContentHandler& self, const STR chars, const XMLSize_t length) {
	XMLString buff(chars);
	self.characters(buff.ptr(), length);
}

static void endElement(xercesc::ContentHandler& self, const STR uri, const STR localname, const STR qname) {
	XMLString buff1(uri), buff2(localname), buff3(qname);
	self.endElement(buff1.ptr(), buff2.ptr(), buff3.ptr());
}

static void ignorableWhitespace(xercesc::ContentHandler& self, const STR chars, const XMLSize_t length) {
	XMLString buff(chars);
	self.ignorableWhitespace(buff.ptr(), length);
}

static void processingInstruction(xercesc::ContentHandler& self, const STR target, const STR data) {
	XMLString buff1(target), buff2(data);
	self.processingInstruction(buff1.ptr(), buff2.ptr());
}

static void startElement(xercesc::ContentHandler& self, const STR uri, const STR localname, const STR qname, const xercesc::Attributes& attrs) {
	XMLString buff1(uri), buff2(localname), buff3(qname);
	self.startElement(buff1.ptr(), buff2.ptr(), buff3.ptr(), attrs);
}

static void startPrefixMapping(xercesc::ContentHandler& self, const STR prefix, const STR uri) {
	XMLString buff1(prefix), buff2(uri);
	self.startPrefixMapping(buff1.ptr(), buff2.ptr());
}

static void endPrefixMapping(xercesc::ContentHandler& self, const STR prefix) {
	XMLString buff(prefix);
	self.endPrefixMapping(buff.ptr());
}

static void skippedEntity(xercesc::ContentHandler& self, const STR name) {
	XMLString buff(name);
	self.endPrefixMapping(buff.ptr());
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
			.def(ContentHandlerDefVisitor<XMLString&>())
			.def(ContentHandlerDefVisitor<char*>())
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
