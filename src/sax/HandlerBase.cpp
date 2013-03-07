/*
 * HandlerBase.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "HandlerBase.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax/Locator.hpp>
#include <xercesc/sax/AttributeList.hpp>
#include <xercesc/sax/InputSource.hpp>

#include <xercesc/sax/HandlerBase.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class HandlerBaseDefVisitor
: public boost::python::def_visitor<HandlerBaseDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("characters", &HandlerBaseDefVisitor::characters)
	.def("endElement", &HandlerBaseDefVisitor::endElement)
	.def("ignorableWhitespace", &HandlerBaseDefVisitor::ignorableWhitespace)
	.def("processingInstruction", &HandlerBaseDefVisitor::processingInstruction)
	.def("startElement", &HandlerBaseDefVisitor::startElement)
	.def("resolveEntity", &HandlerBaseDefVisitor::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("notationDecl", &HandlerBaseDefVisitor<STR>::notationDecl)
	.def("unparsedEntityDecl", &HandlerBaseDefVisitor<STR>::unparsedEntityDecl)
	;
}

static void characters(xercesc::HandlerBase& self, const STR& chars) {
	XMLString buff(chars);
	self.characters(buff.ptr(), buff.size());
}

static void endElement(xercesc::HandlerBase& self, const STR& name) {
	XMLString buff(name);
	self.endElement(buff.ptr());
}

static void ignorableWhitespace(xercesc::HandlerBase& self, const STR& chars) {
	XMLString buff(chars);
	self.ignorableWhitespace(buff.ptr(), buff.size());
}

static void processingInstruction(xercesc::HandlerBase& self, const STR& target, const STR& data) {
	XMLString buff1(target), buff2(data);
	self.processingInstruction(buff1.ptr(), buff2.ptr());
}

static void startElement(xercesc::HandlerBase& self, const STR& name, xercesc::AttributeList& attrs) {
	XMLString buff(name);
	self.startElement(buff.ptr(), attrs);
}

static xercesc::InputSource* resolveEntity(xercesc::HandlerBase& self, const STR& publicId, const STR& systemId) {
	XMLString buff1(publicId), buff2(systemId);
	return self.resolveEntity(buff1.ptr(), buff2.ptr());
}

static void notationDecl(xercesc::HandlerBase& self, const STR& name, const STR& publicId, const STR& systemId) {
	XMLString buff1(name), buff2(publicId), buff3(systemId);
	self.notationDecl(buff1.ptr(), buff2.ptr(), buff3.ptr());
}

static void unparsedEntityDecl(xercesc::HandlerBase& self, const STR& name, const STR& publicId, const STR& systemId, const STR& notationName) {
	XMLString buff1(name), buff2(publicId), buff3(systemId), buff4(notationName);
	self.unparsedEntityDecl(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr());
}

};

class HandlerBaseWrapper
: public xercesc::HandlerBase, public boost::python::wrapper<xercesc::HandlerBase>
{
public:
void characters(const XMLCh* const chars, const XMLSize_t length) {
	if (boost::python::override characters = this->get_override("characters")) {
		characters(XMLString(chars), length);
	}else{
		xercesc::HandlerBase::characters(chars, length);
	}
}

void endDocument () {
	if (boost::python::override endDocument = this->get_override("endDocument")) {
		endDocument();
	}else{
		xercesc::HandlerBase::endDocument();
	}
}

void endElement(const XMLCh* const name) {
	if (boost::python::override endElement = this->get_override("endElement")) {
		endElement(name);
	}else{
		xercesc::HandlerBase::endElement(XMLString(name));
	}
}

void ignorableWhitespace(const XMLCh* const chars, const XMLSize_t length) {
	if (boost::python::override ignorableWhitespace = this->get_override("ignorableWhitespace")) {
		ignorableWhitespace(XMLString(chars), length);
	}else{
		xercesc::HandlerBase::ignorableWhitespace(chars, length);
	}
}

void processingInstruction(const XMLCh* const target, const XMLCh* const data) {
	if (boost::python::override processingInstruction = this->get_override("processingInstruction")) {
		processingInstruction(XMLString(target), XMLString(data));
	}else{
		xercesc::HandlerBase::processingInstruction(target, data);
	}
}

void resetDocument() {
	if (boost::python::override resetDocument = this->get_override("resetDocument")) {
		resetDocument();
	}else{
		xercesc::HandlerBase::resetDocument();
	}
}

void setDocumentLocator(const xercesc::Locator* const locator) {
	if (boost::python::override setDocumentLocator = this->get_override("setDocumentLocator")) {
		setDocumentLocator(locator);
	}else{
		xercesc::HandlerBase::setDocumentLocator(locator);
	}
}

void startDocument() {
	if (boost::python::override startDocument = this->get_override("startDocument")) {
		startDocument();
	}else{
		xercesc::HandlerBase::startDocument();
	}
}

void startElement(const XMLCh* const name, xercesc::AttributeList& attrs) {
	if (boost::python::override startElement = this->get_override("startElement")) {
		startElement(XMLString(name), boost::ref(attrs));
	}else{
		xercesc::HandlerBase::startElement(name, attrs);
	}
}

xercesc::InputSource* resolveEntity(const XMLCh* const publicId, const XMLCh* const systemId) {
	if (boost::python::override resolveEntity = this->get_override("resolveEntity")) {
		return resolveEntity(XMLString(publicId), XMLString(systemId));
	}else{
		return xercesc::HandlerBase::resolveEntity(publicId, systemId);
	}
}

void warning(const xercesc::SAXParseException& exc) {
	if (boost::python::override warning = this->get_override("warning")) {
		warning(exc);
	}else{
		xercesc::HandlerBase::warning(exc);
	}
}

void error(const xercesc::SAXParseException& exc) {
	if (boost::python::override error = this->get_override("error")) {
		error(exc);
	}else{
		xercesc::HandlerBase::error(exc);
	}
}

void fatalError(const xercesc::SAXParseException& exc) {
	if (boost::python::override fatalError = this->get_override("fatalError")) {
		fatalError(exc);
	}else{
		xercesc::HandlerBase::fatalError(exc);
	}
}

void resetErrors() {
	if (boost::python::override resetErrors = this->get_override("resetErrors")) {
		resetErrors();
	}else{
		xercesc::HandlerBase::resetErrors();
	}
}

void notationDecl(const XMLCh* const name, const XMLCh* const publicId, const XMLCh* const systemId) {
	if (boost::python::override notationDecl = this->get_override("notationDecl")) {
		notationDecl(XMLString(name), XMLString(publicId), XMLString(systemId));
	}else{
		xercesc::HandlerBase::notationDecl(name, publicId, systemId);
	}
}
void unparsedEntityDecl(const XMLCh* const name, const XMLCh* const publicId, const XMLCh* const systemId, const XMLCh* const notationName) {
	if (boost::python::override unparsedEntityDecl = this->get_override("unparsedEntityDecl")) {
		unparsedEntityDecl(XMLString(name), XMLString(publicId), XMLString(systemId), XMLString(notationName));
	}else{
		xercesc::HandlerBase::unparsedEntityDecl(name, publicId, systemId, notationName);
	}
}

void resetDocType() {
	if (boost::python::override resetDocType = this->get_override("resetDocType")) {
		resetDocType();
	}else{
		xercesc::HandlerBase::resetDocType();
	}
}

};

void HandlerBase_init(void) {
	//! xercesc::HandlerBase
	boost::python::class_<HandlerBaseWrapper, boost::noncopyable, boost::python::bases<xercesc::EntityResolver, xercesc::DTDHandler, xercesc::DocumentHandler, xercesc::ErrorHandler> >("HandlerBase")
			.def(HandlerBaseDefVisitor<XMLString>())
			.def(HandlerBaseDefVisitor<std::string>())
			.def("characters", &xercesc::HandlerBase::characters)
			.def("endDocument", &xercesc::HandlerBase::endDocument)
			.def("endElement", &xercesc::HandlerBase::endElement)
			.def("ignorableWhitespace", &xercesc::HandlerBase::ignorableWhitespace)
			.def("processingInstruction", &xercesc::HandlerBase::processingInstruction)
			.def("resetDocument", &xercesc::HandlerBase::resetDocument)
			.def("setDocumentLocator", &xercesc::HandlerBase::setDocumentLocator)
			.def("startDocument", &xercesc::HandlerBase::startDocument)
			.def("startElement", &xercesc::HandlerBase::startElement)
			.def("resolveEntity", &xercesc::HandlerBase::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("warning", &xercesc::HandlerBase::warning)
			.def("error", &xercesc::HandlerBase::error)
			.def("fatalError", &xercesc::HandlerBase::fatalError)
			.def("resetErrors", &xercesc::HandlerBase::resetErrors)
			.def("notationDecl", &xercesc::HandlerBase::notationDecl)
			.def("unparsedEntityDecl", &xercesc::HandlerBase::unparsedEntityDecl)
			.def("resetDocType", &xercesc::HandlerBase::resetDocType)
			;
}

} /* namespace pyxerces */
