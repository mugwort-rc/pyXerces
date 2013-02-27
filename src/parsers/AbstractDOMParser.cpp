/*
 * AbstractDOMParser.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "AbstractDOMParser.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLValidator.hpp>			//!< for forward declaration
#include <xercesc/sax/InputSource.hpp>					//!< for forward declaration
#include <xercesc/framework/XMLPScanToken.hpp>			//!< for forward declaration
#include <xercesc/framework/psvi/PSVIElement.hpp>		//!< for forward declaration
#include <xercesc/framework/psvi/PSVIAttributeList.hpp>	//!< for forward declaration
#include <xercesc/parsers/AbstractDOMParser.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class AbstractDOMParserDefVisitor
: public boost::python::def_visitor<AbstractDOMParserDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("useScanner", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&)>(&AbstractDOMParserDefVisitor::useScanner))
	.def("useScanner", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&)>(&AbstractDOMParserDefVisitor::useScanner))
	.def("useImplementation", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&)>(&AbstractDOMParserDefVisitor::useImplementation))
	.def("useImplementation", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&)>(&AbstractDOMParserDefVisitor::useImplementation))
	.def("handleElementPSVI", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&, const XMLString&, xercesc::PSVIElement*)>(&AbstractDOMParserDefVisitor::handleElementPSVI))
	.def("handleElementPSVI", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&, const std::string&, xercesc::PSVIElement*)>(&AbstractDOMParserDefVisitor::handleElementPSVI))
	.def("handlePartialElementPSVI", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&, const XMLString&, xercesc::PSVIElement*)>(&AbstractDOMParserDefVisitor::handlePartialElementPSVI))
	.def("handlePartialElementPSVI", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&, const std::string&, xercesc::PSVIElement*)>(&AbstractDOMParserDefVisitor::handlePartialElementPSVI))
	.def("handleAttributesPSVI", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&, const XMLString&, xercesc::PSVIAttributeList*)>(&AbstractDOMParserDefVisitor::handleAttributesPSVI))
	.def("handleAttributesPSVI", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&, const std::string&, xercesc::PSVIAttributeList*)>(&AbstractDOMParserDefVisitor::handleAttributesPSVI))
	.def("docCharacters", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&, const bool)>(&AbstractDOMParserDefVisitor::docCharacters))
	.def("docCharacters", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&, const bool)>(&AbstractDOMParserDefVisitor::docCharacters))
	.def("docComment", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&)>(&AbstractDOMParserDefVisitor::docComment))
	.def("docComment", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&)>(&AbstractDOMParserDefVisitor::docComment))
	.def("docPI", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&, const XMLString&)>(&AbstractDOMParserDefVisitor::docPI))
	.def("docPI", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&, const std::string&)>(&AbstractDOMParserDefVisitor::docPI))
	.def("endElement", static_cast<void(*)(xercesc::AbstractDOMParser&, const xercesc::XMLElementDecl&, const unsigned int, const bool, const XMLString&)>(&AbstractDOMParserDefVisitor::endElement))
	.def("endElement", static_cast<void(*)(xercesc::AbstractDOMParser&, const xercesc::XMLElementDecl&, const unsigned int, const bool, const std::string&)>(&AbstractDOMParserDefVisitor::endElement))
	.def("ignorableWhitespace", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&, const bool)>(&AbstractDOMParserDefVisitor::ignorableWhitespace))
	.def("ignorableWhitespace", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&, const bool)>(&AbstractDOMParserDefVisitor::ignorableWhitespace))
	.def("startElement", static_cast<void(*)(xercesc::AbstractDOMParser&, const xercesc::XMLElementDecl&, const unsigned int, const XMLString&, const xercesc::RefVectorOf<xercesc::XMLAttr>&, const XMLSize_t, const bool, const bool)>(&AbstractDOMParserDefVisitor::startElement))
	.def("startElement", static_cast<void(*)(xercesc::AbstractDOMParser&, const xercesc::XMLElementDecl&, const unsigned int, const std::string&, const xercesc::RefVectorOf<xercesc::XMLAttr>&, const XMLSize_t, const bool, const bool)>(&AbstractDOMParserDefVisitor::startElement))
	.def("XMLDecl", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&, const XMLString&, const XMLString&, const XMLString&)>(&AbstractDOMParserDefVisitor::XMLDecl))
	.def("XMLDecl", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&, const std::string&, const std::string&, const std::string&)>(&AbstractDOMParserDefVisitor::XMLDecl))
	.def("doctypeComment", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&)>(&AbstractDOMParserDefVisitor::doctypeComment))
	.def("doctypeComment", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&)>(&AbstractDOMParserDefVisitor::doctypeComment))
	.def("doctypeDecl", static_cast<void(*)(xercesc::AbstractDOMParser&, const xercesc::DTDElementDecl&, const XMLString&, const XMLString&, const bool, const bool)>(&AbstractDOMParserDefVisitor::doctypeDecl))
	.def("doctypeDecl", static_cast<void(*)(xercesc::AbstractDOMParser&, const xercesc::DTDElementDecl&, const std::string&, const std::string&, const bool, const bool)>(&AbstractDOMParserDefVisitor::doctypeDecl))
	.def("doctypePI", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&, const XMLString&)>(&AbstractDOMParserDefVisitor::doctypePI))
	.def("doctypePI", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&, const std::string&)>(&AbstractDOMParserDefVisitor::doctypePI))
	.def("doctypeWhitespace", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&)>(&AbstractDOMParserDefVisitor::doctypeWhitespace))
	.def("doctypeWhitespace", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&)>(&AbstractDOMParserDefVisitor::doctypeWhitespace))
	.def("TextDecl", static_cast<void(*)(xercesc::AbstractDOMParser&, const XMLString&, const XMLString&)>(&AbstractDOMParserDefVisitor::TextDecl))
	.def("TextDecl", static_cast<void(*)(xercesc::AbstractDOMParser&, const std::string&, const std::string&)>(&AbstractDOMParserDefVisitor::TextDecl))
	;
}

static void useScanner(xercesc::AbstractDOMParser& self, const XMLString& scannerName) {
	self.useScanner(scannerName.ptr());
}

static void useScanner(xercesc::AbstractDOMParser& self, const std::string& scannerName) {
	XMLString buff(scannerName);
	AbstractDOMParserDefVisitor::useScanner(self, buff);
}

static void useImplementation(xercesc::AbstractDOMParser& self, const XMLString& implementationFeatures) {
	self.useImplementation(implementationFeatures.ptr());
}

static void useImplementation(xercesc::AbstractDOMParser& self, const std::string& implementationFeatures) {
	XMLString buff(implementationFeatures);
	AbstractDOMParserDefVisitor::useImplementation(self, buff);
}

static void handleElementPSVI(xercesc::AbstractDOMParser& self, const XMLString& localName, const XMLString& uri, xercesc::PSVIElement* elementInfo) {
	self.handleElementPSVI(localName.ptr(), uri.ptr(), elementInfo);
}

static void handleElementPSVI(xercesc::AbstractDOMParser& self, const std::string& localName, const std::string& uri, xercesc::PSVIElement* elementInfo) {
	XMLString buff1(localName), buff2(uri);
	AbstractDOMParserDefVisitor::handleElementPSVI(self, buff1, buff2, elementInfo);
}

static void handlePartialElementPSVI(xercesc::AbstractDOMParser& self, const XMLString& localName, const XMLString& uri, xercesc::PSVIElement* elementInfo) {
	self.handlePartialElementPSVI(localName.ptr(), uri.ptr(), elementInfo);
}

static void handlePartialElementPSVI(xercesc::AbstractDOMParser& self, const std::string& localName, const std::string& uri, xercesc::PSVIElement* elementInfo) {
	XMLString buff1(localName), buff2(uri);
	AbstractDOMParserDefVisitor::handlePartialElementPSVI(self, buff1, buff2, elementInfo);
}

static void handleAttributesPSVI(xercesc::AbstractDOMParser& self, const XMLString& localName, const XMLString& uri, xercesc::PSVIAttributeList* psviAttributes) {
	self.handleAttributesPSVI(localName.ptr(), uri.ptr(), psviAttributes);
}

static void handleAttributesPSVI(xercesc::AbstractDOMParser& self, const std::string& localName, const std::string& uri, xercesc::PSVIAttributeList* psviAttributes) {
	XMLString buff1(localName), buff2(uri);
	AbstractDOMParserDefVisitor::handleAttributesPSVI(self, buff1, buff2, psviAttributes);
}

static void docCharacters(xercesc::AbstractDOMParser& self, const XMLString& chars, const bool cdataSection) {
	self.docCharacters(chars.ptr(), chars.size(), cdataSection);
}

static void docCharacters(xercesc::AbstractDOMParser& self, const std::string& chars, const bool cdataSection) {
	XMLString buff(chars);
	AbstractDOMParserDefVisitor::docCharacters(self, buff, cdataSection);
}

static void docComment(xercesc::AbstractDOMParser& self, const XMLString& comment) {
	self.docComment(comment.ptr());
}

static void docComment(xercesc::AbstractDOMParser& self, const std::string& comment) {
	XMLString buff(comment);
	AbstractDOMParserDefVisitor::docComment(self, buff);
}

static void docPI(xercesc::AbstractDOMParser& self, const XMLString& target, const XMLString& data) {
	self.docPI(target.ptr(), data.ptr());
}

static void docPI(xercesc::AbstractDOMParser& self, const std::string& target, const std::string& data) {
	XMLString buff1(target), buff2(data);
	AbstractDOMParserDefVisitor::docPI(self, buff1, buff2);
}

static void endElement(xercesc::AbstractDOMParser& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const bool isRoot, const XMLString& prefixName) {
	self.endElement(elemDecl, uriId, isRoot, prefixName.ptr());
}

static void endElement(xercesc::AbstractDOMParser& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const bool isRoot, const std::string& prefixName) {
	XMLString buff(prefixName);
	AbstractDOMParserDefVisitor::endElement(self, elemDecl, uriId, isRoot, buff);
}

static void ignorableWhitespace(xercesc::AbstractDOMParser& self, const XMLString& chars, const bool cdataSection) {
	self.ignorableWhitespace(chars.ptr(), chars.size(), cdataSection);
}

static void ignorableWhitespace(xercesc::AbstractDOMParser& self, const std::string& chars, const bool cdataSection) {
	XMLString buff(chars);
	AbstractDOMParserDefVisitor::ignorableWhitespace(self, buff, cdataSection);
}

static void startElement(xercesc::AbstractDOMParser& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const XMLString& prefixName, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, const bool isEmpty, const bool isRoot) {
	self.startElement(elemDecl, uriId, prefixName.ptr(), attrList, attrCount, isEmpty, isRoot);
}

static void startElement(xercesc::AbstractDOMParser& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const std::string& prefixName, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, const bool isEmpty, const bool isRoot) {
	XMLString buff(prefixName);
	AbstractDOMParserDefVisitor::startElement(self, elemDecl, uriId, buff, attrList, attrCount, isEmpty, isRoot);
}

static void XMLDecl(xercesc::AbstractDOMParser& self, const XMLString& versionStr, const XMLString& encodingStr, const XMLString& standaloneStr, const XMLString& autoEncodingStr) {
	self.XMLDecl(versionStr.ptr(), encodingStr.ptr(), standaloneStr.ptr(), autoEncodingStr.ptr());
}

static void XMLDecl(xercesc::AbstractDOMParser& self, const std::string& versionStr, const std::string& encodingStr, const std::string& standaloneStr, const std::string& autoEncodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr), buff3(standaloneStr), buff4(autoEncodingStr);
	AbstractDOMParserDefVisitor::XMLDecl(self, buff1, buff2, buff3, buff4);
}

static void doctypeComment(xercesc::AbstractDOMParser& self, const XMLString& comment) {
	self.doctypeComment(comment.ptr());
}

static void doctypeComment(xercesc::AbstractDOMParser& self, const std::string& comment) {
	XMLString buff(comment);
	AbstractDOMParserDefVisitor::doctypeComment(self, buff);
}

static void doctypeDecl(xercesc::AbstractDOMParser& self, const xercesc::DTDElementDecl& elemDecl, const XMLString& publicId, const XMLString& systemId, const bool hasIntSubset, const bool hasExtSubset) {
	self.doctypeDecl(elemDecl, publicId.ptr(), systemId.ptr(), hasIntSubset, hasExtSubset);
}

static void doctypeDecl(xercesc::AbstractDOMParser& self, const xercesc::DTDElementDecl& elemDecl, const std::string& publicId, const std::string& systemId, const bool hasIntSubset, const bool hasExtSubset) {
	XMLString buff1(publicId), buff2(systemId);
	AbstractDOMParserDefVisitor::doctypeDecl(self, elemDecl, buff1, buff2, hasIntSubset, hasExtSubset);
}

static void doctypePI(xercesc::AbstractDOMParser& self, const XMLString& target, const XMLString& data) {
	self.doctypePI(target.ptr(), data.ptr());
}

static void doctypePI(xercesc::AbstractDOMParser& self, const std::string& target, const std::string& data) {
	XMLString buff1(target), buff2(data);
	AbstractDOMParserDefVisitor::doctypePI(self, buff1, buff2);
}

static void doctypeWhitespace(xercesc::AbstractDOMParser& self, const XMLString& chars) {
	self.doctypeWhitespace(chars.ptr(), chars.size());
}

static void doctypeWhitespace(xercesc::AbstractDOMParser& self, const std::string& chars) {
	XMLString buff(chars);
	AbstractDOMParserDefVisitor::doctypeWhitespace(self, buff);
}

static void TextDecl(xercesc::AbstractDOMParser& self, const XMLString& versionStr, const XMLString& encodingStr) {
	self.TextDecl(versionStr.ptr(), encodingStr.ptr());
}

static void TextDecl(xercesc::AbstractDOMParser& self, const std::string& versionStr, const std::string& encodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr);
	AbstractDOMParserDefVisitor::TextDecl(self, buff1, buff2);
}

};

void AbstractDOMParser_init(void) {
	//! xercesc::AbstractDOMParser
	auto AbstractDOMParser = boost::python::class_<xercesc::AbstractDOMParser, boost::noncopyable, boost::python::bases<xercesc::XMLDocumentHandler, xercesc::XMLErrorReporter, xercesc::XMLEntityHandler, xercesc::DocTypeHandler, xercesc::PSVIHandler> >("AbstractDOMParser", boost::python::no_init)
			.def(AbstractDOMParserDefVisitor())
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
