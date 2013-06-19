/*
 * DefaultHandler.cpp
 *
 *  Created on: 2013/03/09
 *      Author: mugwort_rc
 */

#include "DefaultHandler.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax/Locator.hpp>
#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax/InputSource.hpp>

#include <xercesc/sax2/DefaultHandler.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DefaultHandlerDefVisitor
: public boost::python::def_visitor<DefaultHandlerDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("characters", &DefaultHandlerDefVisitor::characters)
	.def("endElement", &DefaultHandlerDefVisitor::endElement)
	.def("ignorableWhitespace", &DefaultHandlerDefVisitor::ignorableWhitespace)
	.def("processingInstruction", &DefaultHandlerDefVisitor::processingInstruction)
	.def("startElement", &DefaultHandlerDefVisitor::startElement)
	.def("startPrefixMapping", &DefaultHandlerDefVisitor::startPrefixMapping)
	.def("endPrefixMapping", &DefaultHandlerDefVisitor::endPrefixMapping)
	.def("skippedEntity", &DefaultHandlerDefVisitor::skippedEntity)
	.def("resolveEntity", &DefaultHandlerDefVisitor::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("notationDecl", &DefaultHandlerDefVisitor::notationDecl)
	.def("unparsedEntityDecl", &DefaultHandlerDefVisitor::unparsedEntityDecl)
	.def("comment", &DefaultHandlerDefVisitor::comment)
	.def("endEntity", &DefaultHandlerDefVisitor::endEntity)
	.def("startDTD", &DefaultHandlerDefVisitor::startDTD)
	.def("startEntity", &DefaultHandlerDefVisitor::startEntity)
	.def("elementDecl", &DefaultHandlerDefVisitor::elementDecl)
	.def("attributeDecl", &DefaultHandlerDefVisitor::attributeDecl)
	.def("internalEntityDecl", &DefaultHandlerDefVisitor::internalEntityDecl)
	.def("externalEntityDecl", &DefaultHandlerDefVisitor::externalEntityDecl)
	;
}

static void characters(xercesc::DefaultHandler& self, const XMLString& chars, const XMLSize_t length) {
	self.characters(chars.ptr(), length);
}

static void endElement(xercesc::DefaultHandler& self, const XMLString& uri, const XMLString& localname, const XMLString& qname) {
	self.endElement(uri.ptr(), localname.ptr(), qname.ptr());
}

static void ignorableWhitespace(xercesc::DefaultHandler& self, const XMLString& chars, const XMLSize_t length) {
	self.ignorableWhitespace(chars.ptr(), length);
}

static void processingInstruction(xercesc::DefaultHandler& self, const XMLString& target, const XMLString& data) {
	self.processingInstruction(target.ptr(), data.ptr());
}

static void startElement(xercesc::DefaultHandler& self, const XMLString& uri, const XMLString& localname, const XMLString& qname, const xercesc::Attributes& attrs) {
	self.startElement(uri.ptr(), localname.ptr(), qname.ptr(), attrs);
}

static void startPrefixMapping(xercesc::DefaultHandler& self, const XMLString& prefix, const XMLString& uri) {
	self.startPrefixMapping(prefix.ptr(), uri.ptr());
}

static void endPrefixMapping(xercesc::DefaultHandler& self, const XMLString& prefix) {
	self.endPrefixMapping(prefix.ptr());
}

static void skippedEntity(xercesc::DefaultHandler& self, const XMLString& name) {
	self.endPrefixMapping(name.ptr());
}

static xercesc::InputSource* resolveEntity(xercesc::DefaultHandler& self, const XMLString& publicId, const XMLString& systemId) {
	return self.resolveEntity(publicId.ptr(), systemId.ptr());
}

static void notationDecl(xercesc::DefaultHandler& self, const XMLString& name, const XMLString& publicId, const XMLString& systemId) {
	self.notationDecl(name.ptr(), publicId.ptr(), systemId.ptr());
}

static void unparsedEntityDecl(xercesc::DefaultHandler& self, const XMLString& name, const XMLString& publicId, const XMLString& systemId, const XMLString& notationName) {
	self.unparsedEntityDecl(name.ptr(), publicId.ptr(), systemId.ptr(), notationName.ptr());
}

static void comment(xercesc::DefaultHandler& self, const XMLString& chars, const XMLSize_t length) {
	self.comment(chars.ptr(), length);
}

static void endEntity(xercesc::DefaultHandler& self, const XMLString& name) {
	self.endEntity(name.ptr());
}

static void startDTD(xercesc::DefaultHandler& self, const XMLString& name, const XMLString& publicId, const XMLString& systemId) {
	self.startDTD(name.ptr(), publicId.ptr(), systemId.ptr());
}

static void startEntity(xercesc::DefaultHandler& self, const XMLString& name) {
	self.startEntity(name.ptr());
}

static void elementDecl(xercesc::DefaultHandler& self, const XMLString& name, const XMLString& model) {
	self.elementDecl(name.ptr(), model.ptr());
}

static void attributeDecl(xercesc::DefaultHandler& self, const XMLString& eName, const XMLString& aName, const XMLString& type, const XMLString& mode, const XMLString& value) {
	self.attributeDecl(eName.ptr(), aName.ptr(), type.ptr(), mode.ptr(), value.ptr());
}

static void internalEntityDecl(xercesc::DefaultHandler& self, const XMLString& name, const XMLString& value) {
	self.internalEntityDecl(name.ptr(), value.ptr());
}

static void externalEntityDecl(xercesc::DefaultHandler& self, const XMLString& name, const XMLString& publicId, const XMLString& systemId) {
	self.externalEntityDecl(name.ptr(), publicId.ptr(), systemId.ptr());
}

};

class DefaultHandlerWrapper
: public xercesc::DefaultHandler, public boost::python::wrapper<xercesc::DefaultHandler>
{
public:
void characters(const XMLCh* const chars, const XMLSize_t length) {
	if(boost::python::override characters = this->get_override("characters")){
		characters(XMLString(chars), length);
	}else{
		xercesc::DefaultHandler::characters(chars, length);
	}
}

void endDocument () {
	if(boost::python::override endDocument = this->get_override("endDocument")){
		endDocument();
	}else{
		xercesc::DefaultHandler::endDocument();
	}
}

void endElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname) {
	if(boost::python::override endElement = this->get_override("endElement")){
		endElement(XMLString(uri), XMLString(localname), XMLString(qname));
	}else{
		xercesc::DefaultHandler::endElement(uri, localname, qname);
	}
}

void ignorableWhitespace(const XMLCh* const chars, const XMLSize_t length) {
	if(boost::python::override ignorableWhitespace = this->get_override("ignorableWhitespace")){
		ignorableWhitespace(XMLString(chars), length);
	}else{
		xercesc::DefaultHandler::ignorableWhitespace(chars, length);
	}
}

void processingInstruction(const XMLCh* const target, const XMLCh* const data) {
	if(boost::python::override processingInstruction = this->get_override("processingInstruction")){
		processingInstruction(XMLString(target), XMLString(data));
	}else{
		xercesc::DefaultHandler::processingInstruction(target, data);
	}
}

void resetDocument() {
	if(boost::python::override resetDocument = this->get_override("resetDocument")){
		resetDocument();
	}else{
		xercesc::DefaultHandler::resetDocument();
	}
}

void setDocumentLocator(const xercesc::Locator* const locator) {
	if(boost::python::override setDocumentLocator = this->get_override("setDocumentLocator")){
		setDocumentLocator(boost::python::ptr(locator));
	}else{
		xercesc::DefaultHandler::setDocumentLocator(locator);
	}
}

void startDocument() {
	if(boost::python::override startDocument = this->get_override("startDocument")){
		startDocument();
	}else{
		xercesc::DefaultHandler::startDocument();
	}
}

void startElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname, const xercesc::Attributes& attrs) {
	if(boost::python::override startElement = this->get_override("startElement")){
		startElement(XMLString(uri), XMLString(localname), XMLString(qname), boost::ref(attrs));
	}else{
		xercesc::DefaultHandler::startElement(uri, localname, qname, attrs);
	}
}

void startPrefixMapping(const XMLCh* const prefix, const XMLCh* const uri) {
	if(boost::python::override startPrefixMapping = this->get_override("startPrefixMapping")){
		startPrefixMapping(XMLString(prefix), XMLString(uri));
	}else{
		xercesc::DefaultHandler::startPrefixMapping(prefix, uri);
	}
}

void endPrefixMapping(const XMLCh* const prefix) {
	if(boost::python::override endPrefixMapping = this->get_override("endPrefixMapping")){
		endPrefixMapping(XMLString(prefix));
	}else{
		xercesc::DefaultHandler::endPrefixMapping(prefix);
	}
}

void skippedEntity(const XMLCh* const name) {
	if(boost::python::override skippedEntity = this->get_override("skippedEntity")){
		skippedEntity(XMLString(name));
	}else{
		xercesc::DefaultHandler::skippedEntity(name);
	}
}

xercesc::InputSource* resolveEntity(const XMLCh* const publicId, const XMLCh* const systemId) {
	if(boost::python::override resolveEntity = this->get_override("resolveEntity")){
		return resolveEntity(XMLString(publicId), XMLString(systemId));
	}else{
		return xercesc::DefaultHandler::resolveEntity(publicId, systemId);
	}
}

void error(const xercesc::SAXParseException& exc) {
	if(boost::python::override error = this->get_override("error")){
		error(boost::ref(exc));
	}else{
		xercesc::DefaultHandler::error(exc);
	}
}

void fatalError(const xercesc::SAXParseException& exc) {
	if(boost::python::override fatalError = this->get_override("fatalError")){
		fatalError(boost::ref(exc));
	}else{
		xercesc::DefaultHandler::fatalError(exc);
	}
}

void warning(const xercesc::SAXParseException& exc) {
	if(boost::python::override warning = this->get_override("warning")){
		warning(boost::ref(exc));
	}else{
		xercesc::DefaultHandler::warning(exc);
	}
}

void resetErrors() {
	if(boost::python::override resetErrors = this->get_override("resetErrors")){
		resetErrors();
	}else{
		xercesc::DefaultHandler::resetErrors();
	}
}

void notationDecl(const XMLCh* const name, const XMLCh* const publicId, const XMLCh* const systemId) {
	if(boost::python::override notationDecl = this->get_override("notationDecl")){
		notationDecl(XMLString(name), XMLString(publicId), XMLString(systemId));
	}else{
		xercesc::DefaultHandler::notationDecl(name, publicId, systemId);
	}
}

void unparsedEntityDecl(const XMLCh* const name, const XMLCh* const publicId, const XMLCh* const systemId, const XMLCh* const notationName) {
	if(boost::python::override unparsedEntityDecl = this->get_override("unparsedEntityDecl")){
		unparsedEntityDecl(XMLString(name), XMLString(publicId), XMLString(systemId), XMLString(notationName));
	}else{
		xercesc::DefaultHandler::unparsedEntityDecl(name, publicId, systemId, notationName);
	}
}

void resetDocType() {
	if(boost::python::override resetDocType = this->get_override("resetDocType")){
		resetDocType();
	}else{
		xercesc::DefaultHandler::resetDocType();
	}
}

void comment(const XMLCh* const chars, const XMLSize_t length) {
	if(boost::python::override comment = this->get_override("comment")){
		comment(XMLString(chars), length);
	}else{
		xercesc::DefaultHandler::comment(chars, length);
	}
}

void endCDATA () {
	if(boost::python::override endCDATA = this->get_override("endCDATA")){
		endCDATA();
	}else{
		xercesc::DefaultHandler::endCDATA();
	}
}

void endDTD () {
	if(boost::python::override endDTD = this->get_override("endDTD")){
		endDTD();
	}else{
		xercesc::DefaultHandler::endDTD();
	}
}

void endEntity (const XMLCh* const name) {
	if(boost::python::override endEntity = this->get_override("endEntity")){
		endEntity(XMLString(name));
	}else{
		xercesc::DefaultHandler::endEntity(name);
	}
}

void startCDATA () {
	if(boost::python::override startCDATA = this->get_override("startCDATA")){
		startCDATA();
	}else{
		xercesc::DefaultHandler::startCDATA();
	}
}

void startDTD(const XMLCh* const name, const XMLCh* const publicId, const XMLCh* const systemId) {
	if(boost::python::override startDTD = this->get_override("startDTD")){
		startDTD(XMLString(name), XMLString(publicId), XMLString(systemId));
	}else{
		xercesc::DefaultHandler::startDTD(name, publicId, systemId);
	}
}

void startEntity (const XMLCh* const name) {
	if(boost::python::override startEntity = this->get_override("startEntity")){
		startEntity(XMLString(name));
	}else{
		xercesc::DefaultHandler::startEntity(name);
	}
}

void elementDecl(const XMLCh* const name, const XMLCh* const model) {
	if(boost::python::override elementDecl = this->get_override("elementDecl")){
		elementDecl(XMLString(name), XMLString(model));
	}else{
		xercesc::DefaultHandler::elementDecl(name, model);
	}
}

void attributeDecl(const XMLCh* const eName, const XMLCh* const aName, const XMLCh* const type, const XMLCh* const mode, const XMLCh* const value) {
	if(boost::python::override attributeDecl = this->get_override("attributeDecl")){
		attributeDecl(XMLString(eName), XMLString(aName), XMLString(type), XMLString(mode), XMLString(value));
	}else{
		xercesc::DefaultHandler::attributeDecl(eName, aName, type, mode, value);
	}
}

void internalEntityDecl(const XMLCh* const name, const XMLCh* const value) {
	if(boost::python::override internalEntityDecl = this->get_override("internalEntityDecl")){
		internalEntityDecl(XMLString(name), XMLString(value));
	}else{
		xercesc::DefaultHandler::internalEntityDecl(name, value);
	}
}

void externalEntityDecl(const XMLCh* const name, const XMLCh* const publicId, const XMLCh* const systemId) {
	if(boost::python::override externalEntityDecl = this->get_override("externalEntityDecl")){
		externalEntityDecl(XMLString(name), XMLString(publicId), XMLString(systemId));
	}else{
		xercesc::DefaultHandler::externalEntityDecl(name, publicId, systemId);
	}
}

};

void DefaultHandler_init(void) {
	//! xercesc::DefaultHandler
	boost::python::class_<DefaultHandlerWrapper, boost::noncopyable, boost::python::bases<xercesc::EntityResolver, xercesc::DTDHandler, xercesc::ContentHandler, xercesc::ErrorHandler, xercesc::LexicalHandler, xercesc::DeclHandler> >("DefaultHandler")
			.def(DefaultHandlerDefVisitor())
			.def("characters", &xercesc::DefaultHandler::characters)
			.def("endDocument", &xercesc::DefaultHandler::endDocument)
			.def("endElement", &xercesc::DefaultHandler::endElement)
			.def("ignorableWhitespace", &xercesc::DefaultHandler::ignorableWhitespace)
			.def("processingInstruction", &xercesc::DefaultHandler::processingInstruction)
			.def("resetDocument", &xercesc::DefaultHandler::resetDocument)
			.def("setDocumentLocator", &xercesc::DefaultHandler::setDocumentLocator)
			.def("startDocument", &xercesc::DefaultHandler::startDocument)
			.def("startElement", &xercesc::DefaultHandler::startElement)
			.def("startPrefixMapping", &xercesc::DefaultHandler::startPrefixMapping)
			.def("endPrefixMapping", &xercesc::DefaultHandler::endPrefixMapping)
			.def("skippedEntity", &xercesc::DefaultHandler::skippedEntity)
			.def("resolveEntity", &xercesc::DefaultHandler::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("error", &xercesc::DefaultHandler::error)
			.def("fatalError", &xercesc::DefaultHandler::fatalError)
			.def("warning", &xercesc::DefaultHandler::warning)
			.def("resetErrors", &xercesc::DefaultHandler::resetErrors)
			.def("notationDecl", &xercesc::DefaultHandler::notationDecl)
			.def("resetDocType", &xercesc::DefaultHandler::resetDocType)
			.def("unparsedEntityDecl", &xercesc::DefaultHandler::unparsedEntityDecl)
			.def("comment", &xercesc::DefaultHandler::comment)
			.def("endCDATA", &xercesc::DefaultHandler::endCDATA)
			.def("endDTD", &xercesc::DefaultHandler::endDTD)
			.def("endEntity", &xercesc::DefaultHandler::endEntity)
			.def("startCDATA", &xercesc::DefaultHandler::startCDATA)
			.def("startDTD", &xercesc::DefaultHandler::startDTD)
			.def("startEntity", &xercesc::DefaultHandler::startEntity)
			.def("elementDecl", &xercesc::DefaultHandler::elementDecl)
			.def("attributeDecl", &xercesc::DefaultHandler::attributeDecl)
			.def("internalEntityDecl", &xercesc::DefaultHandler::internalEntityDecl)
			.def("externalEntityDecl", &xercesc::DefaultHandler::externalEntityDecl)
			;
}

} /* namespace pyxerces */
