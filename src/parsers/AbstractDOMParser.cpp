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

template <class STR>
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

static void useScanner(xercesc::AbstractDOMParser& self, const STR& scannerName) {
	XMLString buff(scannerName);
	self.useScanner(buff.ptr());
}

static void useImplementation(xercesc::AbstractDOMParser& self, const STR& implementationFeatures) {
	XMLString buff(implementationFeatures);
	self.useImplementation(buff.ptr());
}

static void handleElementPSVI(xercesc::AbstractDOMParser& self, const STR& localName, const STR& uri, xercesc::PSVIElement* elementInfo) {
	XMLString buff1(localName), buff2(uri);
	self.handleElementPSVI(buff1.ptr(), buff2.ptr(), elementInfo);
}

static void handlePartialElementPSVI(xercesc::AbstractDOMParser& self, const STR& localName, const STR& uri, xercesc::PSVIElement* elementInfo) {
	XMLString buff1(localName), buff2(uri);
	self.handlePartialElementPSVI(buff1.ptr(), buff2.ptr(), elementInfo);
}

static void handleAttributesPSVI(xercesc::AbstractDOMParser& self, const STR& localName, const STR& uri, xercesc::PSVIAttributeList* psviAttributes) {
	XMLString buff1(localName), buff2(uri);
	self.handleAttributesPSVI(buff1.ptr(), buff2.ptr(), psviAttributes);
}

static void docCharacters(xercesc::AbstractDOMParser& self, const STR& chars, const bool cdataSection) {
	XMLString buff(chars);
	self.docCharacters(buff.ptr(), buff.size(), cdataSection);
}

static void docComment(xercesc::AbstractDOMParser& self, const STR& comment) {
	XMLString buff(comment);
	self.docComment(buff.ptr());
}

static void docPI(xercesc::AbstractDOMParser& self, const STR& target, const STR& data) {
	XMLString buff1(target), buff2(data);
	self.docPI(buff1.ptr(), buff2.ptr());
}

static void endElement(xercesc::AbstractDOMParser& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const bool isRoot, const STR& prefixName) {
	XMLString buff(prefixName);
	self.endElement(elemDecl, uriId, isRoot, buff.ptr());
}

static void ignorableWhitespace(xercesc::AbstractDOMParser& self, const STR& chars, const bool cdataSection) {
	XMLString buff(chars);
	self.ignorableWhitespace(buff.ptr(), buff.size(), cdataSection);
}

static void startElement(xercesc::AbstractDOMParser& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const STR& prefixName, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, const bool isEmpty, const bool isRoot) {
	XMLString buff(prefixName);
	self.startElement(elemDecl, uriId, buff.ptr(), attrList, attrCount, isEmpty, isRoot);
}

static void XMLDecl(xercesc::AbstractDOMParser& self, const STR& versionStr, const STR& encodingStr, const STR& standaloneStr, const STR& autoEncodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr), buff3(standaloneStr), buff4(autoEncodingStr);
	self.XMLDecl(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr());
}

static void doctypeComment(xercesc::AbstractDOMParser& self, const STR& comment) {
	XMLString buff(comment);
	self.doctypeComment(buff.ptr());
}

static void doctypeDecl(xercesc::AbstractDOMParser& self, const xercesc::DTDElementDecl& elemDecl, const STR& publicId, const STR& systemId, const bool hasIntSubset, const bool hasExtSubset) {
	XMLString buff1(publicId), buff2(systemId);
	self.doctypeDecl(elemDecl, buff1.ptr(), buff2.ptr(), hasIntSubset, hasExtSubset);
}

static void doctypePI(xercesc::AbstractDOMParser& self, const STR& target, const STR& data) {
	XMLString buff1(target), buff2(data);
	self.doctypePI(buff1.ptr(), buff2.ptr());
}

static void doctypeWhitespace(xercesc::AbstractDOMParser& self, const STR& chars) {
	XMLString buff(chars);
	self.doctypeWhitespace(buff.ptr(), buff.size());
}

static void TextDecl(xercesc::AbstractDOMParser& self, const STR& versionStr, const STR& encodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr);
	self.TextDecl(buff1.ptr(), buff2.ptr());
}

};

void AbstractDOMParser_init(void) {
	//! xercesc::AbstractDOMParser
	auto AbstractDOMParser = boost::python::class_<xercesc::AbstractDOMParser, boost::noncopyable, boost::python::bases<xercesc::XMLDocumentHandler, xercesc::XMLErrorReporter, xercesc::XMLEntityHandler, xercesc::DocTypeHandler, xercesc::PSVIHandler> >("AbstractDOMParser", boost::python::no_init)
			.def(AbstractDOMParserDefVisitor<XMLString>())
			.def(AbstractDOMParserDefVisitor<std::string>())
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
