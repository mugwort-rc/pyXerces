/*
 * AbstractDOMParser.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "AbstractDOMParser.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/XMLValidator.hpp>
#include <xercesc/sax/InputSource.hpp>
#include <xercesc/framework/XMLPScanToken.hpp>
#include <xercesc/framework/psvi/PSVIElement.hpp>
#include <xercesc/framework/psvi/PSVIAttributeList.hpp>
//! XMLEntityHandler
#include <xercesc/sax/InputSource.hpp>
#include <xercesc/framework/XMLBuffer.hpp>
#include <xercesc/util/XMLResourceIdentifier.hpp>

#include <xercesc/parsers/AbstractDOMParser.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class AbstractDOMParserDefVisitor
: public boost::python::def_visitor<AbstractDOMParserDefVisitor<STR> > {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("useScanner", &AbstractDOMParserDefVisitor::useScanner)
	.def("useImplementation", &AbstractDOMParserDefVisitor::useImplementation)
	.def("handleElementPSVI", &AbstractDOMParserDefVisitor::handleElementPSVI)
	.def("handlePartialElementPSVI", &AbstractDOMParserDefVisitor::handlePartialElementPSVI)
	.def("handleAttributesPSVI", &AbstractDOMParserDefVisitor::handleAttributesPSVI)
	.def("docCharacters", &AbstractDOMParserDefVisitor::docCharacters)
	.def("docComment", &AbstractDOMParserDefVisitor::docComment)
	.def("docPI", &AbstractDOMParserDefVisitor::docPI)
	.def("endElement", &AbstractDOMParserDefVisitor::endElement)
	.def("ignorableWhitespace", &AbstractDOMParserDefVisitor::ignorableWhitespace)
	.def("startElement", &AbstractDOMParserDefVisitor::startElement)
	.def("XMLDecl", &AbstractDOMParserDefVisitor::XMLDecl)
	.def("doctypeComment", &AbstractDOMParserDefVisitor::doctypeComment)
	.def("doctypeDecl", &AbstractDOMParserDefVisitor::doctypeDecl)
	.def("doctypePI", &AbstractDOMParserDefVisitor::doctypePI)
	.def("doctypeWhitespace", &AbstractDOMParserDefVisitor::doctypeWhitespace)
	.def("TextDecl", &AbstractDOMParserDefVisitor::TextDecl)
	;
}

static void useScanner(xercesc::AbstractDOMParser& self, const STR scannerName) {
	XMLString buff(scannerName);
	self.useScanner(buff.ptr());
}

static void useImplementation(xercesc::AbstractDOMParser& self, const STR implementationFeatures) {
	XMLString buff(implementationFeatures);
	self.useImplementation(buff.ptr());
}

static void handleElementPSVI(xercesc::AbstractDOMParser& self, const STR localName, const STR uri, xercesc::PSVIElement* elementInfo) {
	XMLString buff1(localName), buff2(uri);
	self.handleElementPSVI(buff1.ptr(), buff2.ptr(), elementInfo);
}

static void handlePartialElementPSVI(xercesc::AbstractDOMParser& self, const STR localName, const STR uri, xercesc::PSVIElement* elementInfo) {
	XMLString buff1(localName), buff2(uri);
	self.handlePartialElementPSVI(buff1.ptr(), buff2.ptr(), elementInfo);
}

static void handleAttributesPSVI(xercesc::AbstractDOMParser& self, const STR localName, const STR uri, xercesc::PSVIAttributeList* psviAttributes) {
	XMLString buff1(localName), buff2(uri);
	self.handleAttributesPSVI(buff1.ptr(), buff2.ptr(), psviAttributes);
}

static void docCharacters(xercesc::AbstractDOMParser& self, const STR chars, const bool cdataSection) {
	XMLString buff(chars);
	self.docCharacters(buff.ptr(), buff.size(), cdataSection);
}

static void docComment(xercesc::AbstractDOMParser& self, const STR comment) {
	XMLString buff(comment);
	self.docComment(buff.ptr());
}

static void docPI(xercesc::AbstractDOMParser& self, const STR target, const STR data) {
	XMLString buff1(target), buff2(data);
	self.docPI(buff1.ptr(), buff2.ptr());
}

static void endElement(xercesc::AbstractDOMParser& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const bool isRoot, const STR prefixName) {
	XMLString buff(prefixName);
	self.endElement(elemDecl, uriId, isRoot, buff.ptr());
}

static void ignorableWhitespace(xercesc::AbstractDOMParser& self, const STR chars, const bool cdataSection) {
	XMLString buff(chars);
	self.ignorableWhitespace(buff.ptr(), buff.size(), cdataSection);
}

static void startElement(xercesc::AbstractDOMParser& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const STR prefixName, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, const bool isEmpty, const bool isRoot) {
	XMLString buff(prefixName);
	self.startElement(elemDecl, uriId, buff.ptr(), attrList, attrCount, isEmpty, isRoot);
}

static void XMLDecl(xercesc::AbstractDOMParser& self, const STR versionStr, const STR encodingStr, const STR standaloneStr, const STR autoEncodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr), buff3(standaloneStr), buff4(autoEncodingStr);
	self.XMLDecl(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr());
}

static void doctypeComment(xercesc::AbstractDOMParser& self, const STR comment) {
	XMLString buff(comment);
	self.doctypeComment(buff.ptr());
}

static void doctypeDecl(xercesc::AbstractDOMParser& self, const xercesc::DTDElementDecl& elemDecl, const STR publicId, const STR systemId, const bool hasIntSubset, const bool hasExtSubset) {
	XMLString buff1(publicId), buff2(systemId);
	self.doctypeDecl(elemDecl, buff1.ptr(), buff2.ptr(), hasIntSubset, hasExtSubset);
}

static void doctypePI(xercesc::AbstractDOMParser& self, const STR target, const STR data) {
	XMLString buff1(target), buff2(data);
	self.doctypePI(buff1.ptr(), buff2.ptr());
}

static void doctypeWhitespace(xercesc::AbstractDOMParser& self, const STR chars) {
	XMLString buff(chars);
	self.doctypeWhitespace(buff.ptr(), buff.size());
}

static void TextDecl(xercesc::AbstractDOMParser& self, const STR versionStr, const STR encodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr);
	self.TextDecl(buff1.ptr(), buff2.ptr());
}

};

class AbstractDOMParserWrapper
: public xercesc::AbstractDOMParser, public boost::python::wrapper<xercesc::AbstractDOMParser>
{
public:
void setPSVIHandler(PSVIHandler* const handler) {
	if(boost::python::override setPSVIHandler = this->get_override("setPSVIHandler")){
		setPSVIHandler(boost::python::ptr(handler));
	}else{
		xercesc::AbstractDOMParser::setPSVIHandler(handler);
	}
}

// ---------- PSVIHandler ----------
void handleElementPSVI(const XMLCh* const localName, const XMLCh* const uri, xercesc::PSVIElement* elementInfo) {
	if(boost::python::override handleElementPSVI = this->get_override("handleElementPSVI")){
		handleElementPSVI(XMLString(localName), XMLString(uri), boost::python::ptr(elementInfo));
	}else{
		xercesc::AbstractDOMParser::handleElementPSVI(localName, uri, elementInfo);
	}
}

void handlePartialElementPSVI(const XMLCh* const localName, const XMLCh* const uri, xercesc::PSVIElement* elementInfo) {
	if(boost::python::override handlePartialElementPSVI = this->get_override("handlePartialElementPSVI")){
		handlePartialElementPSVI(XMLString(localName), XMLString(uri), boost::python::ptr(elementInfo));
	}else{
		xercesc::PSVIHandler::handlePartialElementPSVI(localName, uri, elementInfo);
	}
}

void handleAttributesPSVI(const XMLCh* const localName, const XMLCh* const uri, xercesc::PSVIAttributeList* psviAttributes) {
	if(boost::python::override handleAttributesPSVI = this->get_override("handleAttributesPSVI")){
		handleAttributesPSVI(XMLString(localName), XMLString(uri), boost::python::ptr(psviAttributes));
	}else{
		xercesc::AbstractDOMParser::handleAttributesPSVI(localName, uri, psviAttributes);
	}
}

// ---------- XMLDocumentHandler ----------
void docCharacters(const XMLCh* const chars, const XMLSize_t length, const bool cdataSection) {
	if(boost::python::override docCharacters = this->get_override("docCharacters")){
		docCharacters(XMLString(chars), length, cdataSection);
	}else{
		xercesc::AbstractDOMParser::docCharacters(chars, length, cdataSection);
	}
}

void docComment(const XMLCh* const comment) {
	if(boost::python::override docComment = this->get_override("docComment")){
		docComment(XMLString(comment));
	}else{
		xercesc::AbstractDOMParser::docComment(comment);
	}
}

void docPI(const XMLCh* const target, const XMLCh* const data) {
	if(boost::python::override docPI = this->get_override("docPI")){
		docPI(XMLString(target), XMLString(data));
	}else{
		xercesc::AbstractDOMParser::docPI(target, data);
	}
}

void endDocument() {
	if(boost::python::override endDocument = this->get_override("endDocument")){
		endDocument();
	}else{
		xercesc::AbstractDOMParser::endDocument();
	}
}

void endElement(const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const bool isRoot, const XMLCh* const prefixName = 0) {
	if(boost::python::override endElement = this->get_override("endElement")){
		endElement(boost::ref(elemDecl), uriId, isRoot, XMLString(prefixName));
	}else{
		xercesc::AbstractDOMParser::endElement(elemDecl, uriId, isRoot, prefixName);
	}
}

void endEntityReference(const xercesc::XMLEntityDecl& entDecl) {
	if(boost::python::override endEntityReference = this->get_override("endEntityReference")){
		endEntityReference(boost::ref(entDecl));
	}else{
		xercesc::AbstractDOMParser::endEntityReference(entDecl);
	}
}

void ignorableWhitespace(const XMLCh* const chars, const XMLSize_t length, const bool cdataSection) {
	if(boost::python::override ignorableWhitespace = this->get_override("ignorableWhitespace")){
		ignorableWhitespace(XMLString(chars), length, cdataSection);
	}else{
		xercesc::AbstractDOMParser::ignorableWhitespace(chars, length, cdataSection);
	}
}

void resetDocument() {
	if(boost::python::override resetDocument = this->get_override("resetDocument")){
		resetDocument();
	}else{
		xercesc::AbstractDOMParser::resetDocument();
	}
}

void startDocument() {
	if(boost::python::override startDocument = this->get_override("startDocument")){
		startDocument();
	}else{
		xercesc::AbstractDOMParser::startDocument();
	}
}

void startElement(const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const XMLCh* const prefixName, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, const bool isEmpty, const bool isRoot) {
	if(boost::python::override startElement = this->get_override("startElement")){
		startElement(boost::ref(elemDecl), uriId, XMLString(prefixName), boost::ref(attrList), attrCount, isEmpty, isRoot);
	}else{
		xercesc::AbstractDOMParser::startElement(elemDecl, uriId, prefixName, attrList, attrCount, isEmpty, isRoot);
	}
}

void startEntityReference(const xercesc::XMLEntityDecl& entDecl) {
	if(boost::python::override startEntityReference = this->get_override("startEntityReference")){
		startEntityReference(boost::ref(entDecl));
	}else{
		xercesc::AbstractDOMParser::startEntityReference(entDecl);
	}
}

void XMLDecl(const XMLCh* const versionStr, const XMLCh* const encodingStr, const XMLCh* const standaloneStr, const XMLCh* const autoEncodingStr) {
	if(boost::python::override XMLDecl = this->get_override("XMLDecl")){
		XMLDecl(XMLString(versionStr), XMLString(encodingStr), XMLString(standaloneStr), XMLString(autoEncodingStr));
	}else{
		xercesc::AbstractDOMParser::XMLDecl(versionStr, encodingStr, standaloneStr, autoEncodingStr);
	}
}

// ---------- DocTypeHandler ----------
void attDef(const xercesc::DTDElementDecl& elemDecl, const xercesc::DTDAttDef& attDef, const bool ignoring) {
	if(boost::python::override _attDef = this->get_override("attDef")){
		_attDef(boost::ref(elemDecl), boost::ref(attDef), ignoring);
	}else{
		xercesc::AbstractDOMParser::attDef(elemDecl, attDef, ignoring);
	}
}

void doctypeComment(const XMLCh* const comment) {
	if(boost::python::override doctypeComment = this->get_override("doctypeComment")){
		doctypeComment(XMLString(comment));
	}else{
		xercesc::AbstractDOMParser::doctypeComment(comment);
	}
}

void doctypeDecl(const xercesc::DTDElementDecl& elemDecl, const XMLCh* const publicId, const XMLCh* const systemId, const bool hasIntSubset, const bool hasExtSubset = false) {
	if(boost::python::override doctypeDecl = this->get_override("doctypeDecl")){
		doctypeDecl(boost::ref(elemDecl), XMLString(publicId), XMLString(systemId), hasIntSubset, hasExtSubset);
	}else{
		xercesc::AbstractDOMParser::doctypeDecl(elemDecl, publicId, systemId, hasIntSubset, hasExtSubset);
	}
}

void doctypePI(const XMLCh* const target, const XMLCh* const data) {
	if(boost::python::override doctypePI = this->get_override("doctypePI")){
		doctypePI(XMLString(target), XMLString(data));
	}else{
		xercesc::AbstractDOMParser::doctypePI(target, data);
	}
}

void doctypeWhitespace(const XMLCh* const chars, const XMLSize_t length) {
	if(boost::python::override doctypeWhitespace = this->get_override("doctypeWhitespace")){
		doctypeWhitespace(XMLString(chars), length);
	}else{
		xercesc::AbstractDOMParser::doctypeWhitespace(chars, length);
	}
}

void elementDecl(const xercesc::DTDElementDecl& decl, const bool isIgnored) {
	if(boost::python::override elementDecl = this->get_override("elementDecl")){
		elementDecl(boost::ref(decl), isIgnored);
	}else{
		xercesc::AbstractDOMParser::elementDecl(decl, isIgnored);
	}
}

void endAttList(const xercesc::DTDElementDecl& elemDecl) {
	if(boost::python::override endAttList = this->get_override("endAttList")){
		endAttList(boost::ref(elemDecl));
	}else{
		xercesc::AbstractDOMParser::endAttList(elemDecl);
	}
}

void endIntSubset() {
	if(boost::python::override endIntSubset = this->get_override("endIntSubset")){
		endIntSubset();
	}else{
		xercesc::AbstractDOMParser::endIntSubset();
	}
}

void endExtSubset() {
	if(boost::python::override endExtSubset = this->get_override("endExtSubset")){
		endExtSubset();
	}else{
		xercesc::AbstractDOMParser::endExtSubset();
	}
}

void entityDecl(const xercesc::DTDEntityDecl& entityDecl, const bool isPEDecl, const bool isIgnored) {
	if(boost::python::override _entityDecl = this->get_override("entityDecl")){
		_entityDecl(boost::ref(entityDecl), isPEDecl, isIgnored);
	}else{
		xercesc::AbstractDOMParser::entityDecl(entityDecl, isPEDecl, isIgnored);
	}
}

void resetDocType() {
	if(boost::python::override resetDocType = this->get_override("resetDocType")){
		resetDocType();
	}else{
		xercesc::AbstractDOMParser::resetDocType();
	}
}

void notationDecl(const xercesc::XMLNotationDecl& notDecl, const bool isIgnored) {
	if(boost::python::override notationDecl = this->get_override("notationDecl")){
		notationDecl(boost::ref(notDecl), isIgnored);
	}else{
		xercesc::AbstractDOMParser::notationDecl(notDecl, isIgnored);
	}
}

void startAttList(const xercesc::DTDElementDecl& elemDecl) {
	if(boost::python::override startAttList = this->get_override("startAttList")){
		startAttList(boost::ref(elemDecl));
	}else{
		xercesc::AbstractDOMParser::startAttList(elemDecl);
	}
}

void startIntSubset() {
	if(boost::python::override startIntSubset = this->get_override("startIntSubset")){
		startIntSubset();
	}else{
		xercesc::AbstractDOMParser::startIntSubset();
	}
}

void startExtSubset() {
	if(boost::python::override startExtSubset = this->get_override("startExtSubset")){
		startExtSubset();
	}else{
		xercesc::AbstractDOMParser::startExtSubset();
	}
}

void TextDecl(const XMLCh* const versionStr, const XMLCh* const encodingStr) {
	if(boost::python::override TextDecl = this->get_override("TextDecl")){
		TextDecl(XMLString(versionStr), XMLString(encodingStr));
	}else{
		xercesc::AbstractDOMParser::TextDecl(versionStr, encodingStr);
	}
}

// ---------- XMLErrorReporter ----------
void error(const unsigned int errCode, const XMLCh* const errDomain, const xercesc::XMLErrorReporter::ErrTypes type, const XMLCh* const errorText, const XMLCh* const systemId, const XMLCh* const publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	this->get_override("error")(errCode, XMLString(errDomain), type, XMLString(errorText), XMLString(systemId), XMLString(publicId), lineNum, colNum);
}

void resetErrors() {
	this->get_override("resetErrors")();
}

// ---------- XMLEntityHandler ----------
void endInputSource(const xercesc::InputSource& inputSource) {
	this->get_override("endInputSource")(boost::ref(inputSource));
}

bool expandSystemId(const XMLCh* const systemId, xercesc::XMLBuffer& toFill) {
	return this->get_override("expandSystemId")(XMLString(systemId), boost::ref(toFill));
}

void resetEntities() {
	this->get_override("resetEntities")();
}

xercesc::InputSource* resolveEntity(xercesc::XMLResourceIdentifier* resourceIdentifier) {
	return this->get_override("resolveEntity")(boost::python::ptr(resourceIdentifier));
}

void startInputSource(const xercesc::InputSource& inputSource) {
	this->get_override("startInputSource")(boost::ref(inputSource));
}

};

void AbstractDOMParser_init(void) {
	//! xercesc::AbstractDOMParser
	auto AbstractDOMParser = boost::python::class_<AbstractDOMParserWrapper, boost::noncopyable, boost::python::bases<xercesc::XMLDocumentHandler, xercesc::XMLErrorReporter, xercesc::XMLEntityHandler, xercesc::DocTypeHandler, xercesc::PSVIHandler> >("AbstractDOMParser")
			.def(AbstractDOMParserDefVisitor<XMLString&>())
			.def(AbstractDOMParserDefVisitor<char*>())
			.def("reset", &xercesc::AbstractDOMParser::reset)
			.def("adoptDocument", &xercesc::AbstractDOMParser::adoptDocument, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDocument", &xercesc::AbstractDOMParser::getDocument, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getValidator", &xercesc::AbstractDOMParser::getValidator, boost::python::return_internal_reference<>())
			.def("getValidationScheme", &xercesc::AbstractDOMParser::getValidationScheme)
			.def("getDoSchema", &xercesc::AbstractDOMParser::getDoSchema)
			.def("getValidationSchemaFullChecking", &xercesc::AbstractDOMParser::getValidationSchemaFullChecking)
			.def("getIdentityConstraintChecking", &xercesc::AbstractDOMParser::getIdentityConstraintChecking)
			.def("getErrorCount", &xercesc::AbstractDOMParser::getErrorCount)
			.def("getDoNamespaces", &xercesc::AbstractDOMParser::getDoNamespaces)
			.def("getExitOnFirstFatalError", &xercesc::AbstractDOMParser::getExitOnFirstFatalError)
			.def("getValidationConstraintFatal", &xercesc::AbstractDOMParser::getValidationConstraintFatal)
			.def("getCreateEntityReferenceNodes", &xercesc::AbstractDOMParser::getCreateEntityReferenceNodes)
			.def("getIncludeIgnorableWhitespace", &xercesc::AbstractDOMParser::getIncludeIgnorableWhitespace)
			.def("getExternalSchemaLocation", &xercesc::AbstractDOMParser::getExternalSchemaLocation, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getExternalNoNamespaceSchemaLocation", &xercesc::AbstractDOMParser::getExternalNoNamespaceSchemaLocation, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSecurityManager", &xercesc::AbstractDOMParser::getSecurityManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLowWaterMark", &xercesc::AbstractDOMParser::getLowWaterMark, boost::python::return_value_policy<boost::python::copy_const_reference>())
			.def("getLoadExternalDTD", &xercesc::AbstractDOMParser::getLoadExternalDTD)
			.def("getLoadSchema", &xercesc::AbstractDOMParser::getLoadSchema)
			.def("getCreateCommentNodes", &xercesc::AbstractDOMParser::getCreateCommentNodes)
			.def("getCalculateSrcOfs", &xercesc::AbstractDOMParser::getCalculateSrcOfs)
			.def("getStandardUriConformant", &xercesc::AbstractDOMParser::getStandardUriConformant)
			.def("getPSVIHandler", static_cast<xercesc::PSVIHandler*(xercesc::AbstractDOMParser::*)(void)>(&xercesc::AbstractDOMParser::getPSVIHandler), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getCreateSchemaInfo", &xercesc::AbstractDOMParser::getCreateSchemaInfo)
			.def("getDoXInclude", &xercesc::AbstractDOMParser::getDoXInclude)
			.def("getGenerateSyntheticAnnotations", &xercesc::AbstractDOMParser::getGenerateSyntheticAnnotations)
			.def("getValidateAnnotations", &xercesc::AbstractDOMParser::getValidateAnnotations)
			.def("getIgnoreAnnotations", &xercesc::AbstractDOMParser::getIgnoreAnnotations)
			.def("getDisableDefaultEntityResolution", &xercesc::AbstractDOMParser::getDisableDefaultEntityResolution)
			.def("getSkipDTDValidation", &xercesc::AbstractDOMParser::getSkipDTDValidation)
			.def("getHandleMultipleImports", &xercesc::AbstractDOMParser::getHandleMultipleImports)
			.def("setGenerateSyntheticAnnotations", &xercesc::AbstractDOMParser::setGenerateSyntheticAnnotations)
			.def("setValidateAnnotations", &xercesc::AbstractDOMParser::setValidateAnnotations)
			.def("setDoNamespaces", &xercesc::AbstractDOMParser::setDoNamespaces)
			.def("setExitOnFirstFatalError", &xercesc::AbstractDOMParser::setExitOnFirstFatalError)
			.def("setValidationConstraintFatal", &xercesc::AbstractDOMParser::setValidationConstraintFatal)
			.def("setCreateEntityReferenceNodes", &xercesc::AbstractDOMParser::setCreateEntityReferenceNodes)
			.def("setIncludeIgnorableWhitespace", &xercesc::AbstractDOMParser::setIncludeIgnorableWhitespace)
			.def("setValidationScheme", &xercesc::AbstractDOMParser::setValidationScheme)
			.def("setDoSchema", &xercesc::AbstractDOMParser::setDoSchema)
			.def("setValidationSchemaFullChecking", &xercesc::AbstractDOMParser::setValidationSchemaFullChecking)
			.def("setIdentityConstraintChecking", &xercesc::AbstractDOMParser::setIdentityConstraintChecking)
			.def("setExternalSchemaLocation", static_cast<void(xercesc::AbstractDOMParser::*)(const XMLCh* const)>(&xercesc::AbstractDOMParser::setExternalSchemaLocation))
			.def("setExternalSchemaLocation", static_cast<void(xercesc::AbstractDOMParser::*)(const char* const)>(&xercesc::AbstractDOMParser::setExternalSchemaLocation))
			.def("setExternalNoNamespaceSchemaLocation", static_cast<void(xercesc::AbstractDOMParser::*)(const XMLCh* const)>(&xercesc::AbstractDOMParser::setExternalNoNamespaceSchemaLocation))
			.def("setExternalNoNamespaceSchemaLocation", static_cast<void(xercesc::AbstractDOMParser::*)(const char* const)>(&xercesc::AbstractDOMParser::setExternalNoNamespaceSchemaLocation))
			.def("setSecurityManager", &xercesc::AbstractDOMParser::setSecurityManager)
			.def("setLowWaterMark", &xercesc::AbstractDOMParser::setLowWaterMark)
			.def("setLoadExternalDTD", &xercesc::AbstractDOMParser::setLoadExternalDTD)
			.def("setLoadSchema", &xercesc::AbstractDOMParser::setLoadSchema)
			.def("setCreateCommentNodes", &xercesc::AbstractDOMParser::setCreateCommentNodes)
			.def("setCalculateSrcOfs", &xercesc::AbstractDOMParser::setCalculateSrcOfs)
			.def("setStandardUriConformant", &xercesc::AbstractDOMParser::setStandardUriConformant)
			.def("useScanner", &xercesc::AbstractDOMParser::useScanner)
			.def("useImplementation", &xercesc::AbstractDOMParser::useImplementation)
			.def("setPSVIHandler", &xercesc::AbstractDOMParser::setPSVIHandler)
			.def("setCreateSchemaInfo", &xercesc::AbstractDOMParser::setCreateSchemaInfo)
			.def("setDoXInclude", &xercesc::AbstractDOMParser::setDoXInclude)
			.def("setIgnoreAnnotations", &xercesc::AbstractDOMParser::setIgnoreAnnotations)
			.def("setDisableDefaultEntityResolution", &xercesc::AbstractDOMParser::setDisableDefaultEntityResolution)
			.def("setSkipDTDValidation", &xercesc::AbstractDOMParser::setSkipDTDValidation)
			.def("setHandleMultipleImports", &xercesc::AbstractDOMParser::setHandleMultipleImports)
			.def("parse", static_cast<void(xercesc::AbstractDOMParser::*)(const xercesc::InputSource&)>(&xercesc::AbstractDOMParser::parse))
			.def("parse", static_cast<void(xercesc::AbstractDOMParser::*)(const XMLCh* const)>(&xercesc::AbstractDOMParser::parse))
			.def("parse", static_cast<void(xercesc::AbstractDOMParser::*)(const char* const)>(&xercesc::AbstractDOMParser::parse))
			.def("parseFirst", static_cast<bool(xercesc::AbstractDOMParser::*)(const XMLCh* const, xercesc::XMLPScanToken&)>(&xercesc::AbstractDOMParser::parseFirst))
			.def("parseFirst", static_cast<bool(xercesc::AbstractDOMParser::*)(const char* const, xercesc::XMLPScanToken&)>(&xercesc::AbstractDOMParser::parseFirst))
			.def("parseFirst", static_cast<bool(xercesc::AbstractDOMParser::*)(const xercesc::InputSource&, xercesc::XMLPScanToken&)>(&xercesc::AbstractDOMParser::parseFirst))
			.def("parseNext", &xercesc::AbstractDOMParser::parseNext)
			.def("parseReset", &xercesc::AbstractDOMParser::parseReset)
			.def("handleElementPSVI", &xercesc::AbstractDOMParser::handleElementPSVI)
			.def("handlePartialElementPSVI", &xercesc::AbstractDOMParser::handlePartialElementPSVI)
			.def("handleAttributesPSVI", &xercesc::AbstractDOMParser::handleAttributesPSVI)
			.def("docCharacters", &xercesc::AbstractDOMParser::docCharacters)
			.def("docComment", &xercesc::AbstractDOMParser::docComment)
			.def("docPI", &xercesc::AbstractDOMParser::docPI)
			.def("endDocument", &xercesc::AbstractDOMParser::endDocument)
			.def("endElement", &xercesc::AbstractDOMParser::endElement)
			.def("endEntityReference", &xercesc::AbstractDOMParser::endEntityReference)
			.def("ignorableWhitespace", &xercesc::AbstractDOMParser::ignorableWhitespace)
			.def("resetDocument", &xercesc::AbstractDOMParser::resetDocument)
			.def("startDocument", &xercesc::AbstractDOMParser::startDocument)
			.def("startElement", &xercesc::AbstractDOMParser::startElement)
			.def("startEntityReference", &xercesc::AbstractDOMParser::startEntityReference)
			.def("XMLDecl", &xercesc::AbstractDOMParser::XMLDecl)
			.def("attDef", &xercesc::AbstractDOMParser::attDef)
			.def("doctypeComment", &xercesc::AbstractDOMParser::doctypeComment)
			.def("doctypeDecl", &xercesc::AbstractDOMParser::doctypeDecl)
			.def("doctypePI", &xercesc::AbstractDOMParser::doctypePI)
			.def("doctypeWhitespace", &xercesc::AbstractDOMParser::doctypeWhitespace)
			.def("elementDecl", &xercesc::AbstractDOMParser::elementDecl)
			.def("endAttList", &xercesc::AbstractDOMParser::endAttList)
			.def("endIntSubset", &xercesc::AbstractDOMParser::endIntSubset)
			.def("endExtSubset", &xercesc::AbstractDOMParser::endExtSubset)
			.def("entityDecl", &xercesc::AbstractDOMParser::entityDecl)
			.def("resetDocType", &xercesc::AbstractDOMParser::resetDocType)
			.def("notationDecl", &xercesc::AbstractDOMParser::notationDecl)
			.def("startAttList", &xercesc::AbstractDOMParser::startAttList)
			.def("startIntSubset", &xercesc::AbstractDOMParser::startIntSubset)
			.def("startExtSubset", &xercesc::AbstractDOMParser::startExtSubset)
			.def("TextDecl", &xercesc::AbstractDOMParser::TextDecl)
			;
	boost::python::scope AbstractDOMParserScope = AbstractDOMParser;
	//! xercesc::AbstractDOMParser::ValSchemes
	boost::python::enum_<xercesc::AbstractDOMParser::ValSchemes>("ValSchemes")
			.value("Val_Never", xercesc::AbstractDOMParser::Val_Never)
			.value("Val_Always", xercesc::AbstractDOMParser::Val_Always)
			.value("Val_Auto", xercesc::AbstractDOMParser::Val_Auto)
			.export_values()
			;
}

} /* namespace pyxerces */
