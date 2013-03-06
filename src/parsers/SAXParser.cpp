/*
 * SAXParser.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "SAXParser.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax/DocumentHandler.hpp>
#include <xercesc/sax/EntityResolver.hpp>
#include <xercesc/framework/XMLPScanToken.hpp>
#include <xercesc/internal/XMLScanner.hpp>
#include <xercesc/framework/XMLValidator.hpp>
#include <xercesc/validators/common/GrammarResolver.hpp>
#include <xercesc/framework/XMLGrammarPool.hpp>
#include <xercesc/util/XMLEntityResolver.hpp>
#include <xercesc/util/XMLResourceIdentifier.hpp>
#include <xercesc/framework/psvi/PSVIHandler.hpp>
#include <xercesc/sax/DTDHandler.hpp>
#include <xercesc/sax/InputSource.hpp>
#include <xercesc/sax/ErrorHandler.hpp>

#include <xercesc/parsers/SAXParser.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class SAXParserDefVisitor
: public boost::python::def_visitor<SAXParserDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getGrammar", &SAXParserDefVisitor::getGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("useScanner", &SAXParserDefVisitor::useScanner)
	.def("docCharacters", &SAXParserDefVisitor::docCharacters)
	.def("docComment", &SAXParserDefVisitor::docComment)
	.def("docPI", &SAXParserDefVisitor::docPI)
	.def("endElement", &SAXParserDefVisitor::endElement)
	.def("ignorableWhitespace", &SAXParserDefVisitor::ignorableWhitespace)
	.def("startElement", &SAXParserDefVisitor::startElement)
	.def("XMLDecl", &SAXParserDefVisitor::XMLDecl)
	.def("error", &SAXParserDefVisitor::error)
	.def("expandSystemId", &SAXParserDefVisitor::expandSystemId)
	.def("doctypeComment", &SAXParserDefVisitor::doctypeComment)
	.def("doctypeDecl", &SAXParserDefVisitor::doctypeDecl)
	.def("doctypePI", &SAXParserDefVisitor::doctypePI)
	.def("doctypeWhitespace", &SAXParserDefVisitor::doctypeWhitespace)
	.def("TextDecl", &SAXParserDefVisitor::TextDecl)
	;
}

static xercesc::Grammar* getGrammar(xercesc::SAXParser& self, const STR& nameSpaceKey) {
	XMLString buff(nameSpaceKey);
	return self.getGrammar(buff.ptr());
}

static void useScanner(xercesc::SAXParser& self, const STR& scannerName) {
	XMLString buff(scannerName);
	return self.useScanner(buff.ptr());
}

static void docCharacters(xercesc::SAXParser& self, const STR& chars, const bool cdataSection) {
	XMLString buff(chars);
	self.docCharacters(buff.ptr(), buff.size(), cdataSection);
}

static void docComment(xercesc::SAXParser& self, const STR& comment) {
	XMLString buff(comment);
	self.docComment(buff.ptr());
}

static void docPI(xercesc::SAXParser& self, const STR& target, const STR& data) {
	XMLString buff1(target), buff2(data);
	self.docPI(buff1.ptr(), buff2.ptr());
}

static void endElement(xercesc::SAXParser& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const bool isRoot, const STR& prefixName) {
	XMLString buff(prefixName);
	self.endElement(elemDecl, uriId, isRoot, buff.ptr());
}

static void ignorableWhitespace(xercesc::SAXParser& self, const XMLString& chars, const bool cdataSection) {
	XMLString buff(chars);
	self.ignorableWhitespace(buff.ptr(), buff.size(), cdataSection);
}

static void startElement(xercesc::SAXParser& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const STR& prefixName, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, const bool isEmpty, const bool isRoot) {
	XMLString buff(prefixName);
	self.startElement(elemDecl, uriId, buff.ptr(), attrList, attrCount, isEmpty, isRoot);
}

static void XMLDecl(xercesc::SAXParser& self, const STR& versionStr, const STR& encodingStr, const STR& standaloneStr, const STR& autoEncodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr), buff3(standaloneStr), buff4(autoEncodingStr);
	self.XMLDecl(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr());
}

static void error(xercesc::SAXParser& self, const unsigned int errCode, const STR& errDomain, const xercesc::XMLErrorReporter::ErrTypes type, const STR& errorText, const STR& systemId, const STR& publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	XMLString buff1(errDomain), buff2(errorText), buff3(systemId), buff4(publicId);
	self.error(errCode, buff1.ptr(), type, buff2.ptr(), buff3.ptr(), buff4.ptr(), lineNum, colNum);
}

static bool expandSystemId(xercesc::SAXParser& self, const STR& systemId, xercesc::XMLBuffer& toFill) {
	XMLString buff(systemId);
	return self.expandSystemId(buff.ptr(), toFill);
}

static void doctypeComment(xercesc::SAXParser& self, const STR& comment) {
	XMLString buff(comment);
	self.doctypeComment(buff.ptr());
}

static void doctypeDecl(xercesc::SAXParser& self, const xercesc::DTDElementDecl& elemDecl, const STR& publicId, const STR& systemId, const bool hasIntSubset, const bool hasExtSubset) {
	XMLString buff1(publicId), buff2(systemId);
	self.doctypeDecl(elemDecl, buff1.ptr(), buff2.ptr(), hasIntSubset, hasExtSubset);
}

static void doctypePI(xercesc::SAXParser& self, const STR& target, const STR& data) {
	XMLString buff1(target), buff2(data);
	self.doctypePI(buff1.ptr(), buff2.ptr());
}

static void doctypeWhitespace(xercesc::SAXParser& self, const STR& chars) {
	XMLString buff(chars);
	self.doctypeWhitespace(buff.ptr(), buff.size());
}

static void TextDecl(xercesc::SAXParser& self, const XMLString& versionStr, const XMLString& encodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr);
	self.TextDecl(buff1.ptr(), buff2.ptr());
}

};

class SAXParserXMLStringDefVisitor
: public boost::python::def_visitor<SAXParserXMLStringDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setExternalSchemaLocation", &SAXParserXMLStringDefVisitor::setExternalSchemaLocation)
	.def("setExternalNoNamespaceSchemaLocation", &SAXParserXMLStringDefVisitor::setExternalNoNamespaceSchemaLocation)
	.def("parseFirst", &SAXParserXMLStringDefVisitor::parseFirst)
	.def("loadGrammar", static_cast<xercesc::Grammar*(*)(xercesc::SAXParser&, const XMLString& systemId, const xercesc::Grammar::GrammarType, const bool)>(&SAXParserXMLStringDefVisitor::loadGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("loadGrammar", static_cast<xercesc::Grammar*(*)(xercesc::SAXParser&, const XMLString& systemId, const xercesc::Grammar::GrammarType)>(&SAXParserXMLStringDefVisitor::loadGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("parse", &SAXParserXMLStringDefVisitor::parse)
	;
}

static void setExternalSchemaLocation(xercesc::SAXParser& self, const XMLString& schemaLocation) {
	self.setExternalSchemaLocation(schemaLocation.ptr());
}

static void setExternalNoNamespaceSchemaLocation(xercesc::SAXParser& self, const XMLString& noNamespaceSchemaLocation) {
	self.setExternalNoNamespaceSchemaLocation(noNamespaceSchemaLocation.ptr());
}

static bool parseFirst(xercesc::SAXParser& self, const XMLString& systemId, xercesc::XMLPScanToken& toFill) {
	return self.parseFirst(systemId.ptr(), toFill);
}

static xercesc::Grammar* loadGrammar(xercesc::SAXParser& self, const XMLString& systemId, const xercesc::Grammar::GrammarType grammarType, const bool toCache) {
	return self.loadGrammar(systemId.ptr(), grammarType, toCache);
}

static xercesc::Grammar* loadGrammar(xercesc::SAXParser& self, const XMLString& systemId, const xercesc::Grammar::GrammarType grammarType) {
	return SAXParserXMLStringDefVisitor::loadGrammar(self, systemId, grammarType, false);
}

static void parse(xercesc::SAXParser& self, const XMLString& systemId) {
	self.parse(systemId.ptr());
}

};

void SAXParser_init(void) {
	//! xercesc::SAXParser
	auto SAXParser = boost::python::class_<xercesc::SAXParser, boost::noncopyable, boost::python::bases<xercesc::Parser, xercesc::XMLDocumentHandler, xercesc::XMLErrorReporter, xercesc::XMLEntityHandler, xercesc::DocTypeHandler> >("SAXParser", boost::python::init<boost::python::optional<xercesc::XMLValidator* const, xercesc::MemoryManager* const, xercesc::XMLGrammarPool* const> >())
			.def(SAXParserDefVisitor<XMLString>())
			.def(SAXParserDefVisitor<std::string>())
			.def(SAXParserXMLStringDefVisitor())
			.def("getDocumentHandler", static_cast<xercesc::DocumentHandler*(xercesc::SAXParser::*)(void)>(&xercesc::SAXParser::getDocumentHandler), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEntityResolver", static_cast<xercesc::EntityResolver*(xercesc::SAXParser::*)(void)>(&xercesc::SAXParser::getEntityResolver), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getXMLEntityResolver", static_cast<xercesc::XMLEntityResolver*(xercesc::SAXParser::*)(void)>(&xercesc::SAXParser::getXMLEntityResolver), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getErrorHandler", static_cast<xercesc::ErrorHandler*(xercesc::SAXParser::*)(void)>(&xercesc::SAXParser::getErrorHandler), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPSVIHandler", static_cast<xercesc::PSVIHandler*(xercesc::SAXParser::*)(void)>(&xercesc::SAXParser::getPSVIHandler), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getValidator", &xercesc::SAXParser::getValidator, boost::python::return_internal_reference<>())
			.def("getValidationScheme", &xercesc::SAXParser::getValidationScheme)
			.def("getDoSchema", &xercesc::SAXParser::getDoSchema)
			.def("getValidationSchemaFullChecking", &xercesc::SAXParser::getValidationSchemaFullChecking)
			.def("getIdentityConstraintChecking", &xercesc::SAXParser::getIdentityConstraintChecking)
			.def("getErrorCount", &xercesc::SAXParser::getErrorCount)
			.def("getDoNamespaces", &xercesc::SAXParser::getDoNamespaces)
			.def("getExitOnFirstFatalError", &xercesc::SAXParser::getExitOnFirstFatalError)
			.def("getValidationConstraintFatal", &xercesc::SAXParser::getValidationConstraintFatal)
			.def("getExternalSchemaLocation", &xercesc::SAXParser::getExternalSchemaLocation, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getExternalNoNamespaceSchemaLocation", &xercesc::SAXParser::getExternalNoNamespaceSchemaLocation, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSecurityManager", &xercesc::SAXParser::getSecurityManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLowWaterMark", &xercesc::SAXParser::getLowWaterMark)
			.def("getLoadExternalDTD", &xercesc::SAXParser::getLoadExternalDTD)
			.def("getLoadSchema", &xercesc::SAXParser::getLoadSchema)
			.def("isCachingGrammarFromParse", &xercesc::SAXParser::isCachingGrammarFromParse)
			.def("isUsingCachedGrammarInParse", &xercesc::SAXParser::isUsingCachedGrammarInParse)
			.def("getCalculateSrcOfs", &xercesc::SAXParser::getCalculateSrcOfs)
			.def("getStandardUriConformant", &xercesc::SAXParser::getStandardUriConformant)
			.def("getGrammar", &xercesc::SAXParser::getGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getRootGrammar", &xercesc::SAXParser::getRootGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURIText", &xercesc::SAXParser::getURIText, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSrcOffset", &xercesc::SAXParser::getSrcOffset)
			.def("getGenerateSyntheticAnnotations", &xercesc::SAXParser::getGenerateSyntheticAnnotations)
			.def("getValidateAnnotations", &xercesc::SAXParser::getValidateAnnotations)
			.def("getIgnoreCachedDTD", &xercesc::SAXParser::getIgnoreCachedDTD)
			.def("getIgnoreAnnotations", &xercesc::SAXParser::getIgnoreAnnotations)
			.def("getDisableDefaultEntityResolution", &xercesc::SAXParser::getDisableDefaultEntityResolution)
			.def("getSkipDTDValidation", &xercesc::SAXParser::getSkipDTDValidation)
			.def("getHandleMultipleImports", &xercesc::SAXParser::getHandleMultipleImports)
			.def("setGenerateSyntheticAnnotations", &xercesc::SAXParser::setGenerateSyntheticAnnotations)
			.def("setValidateAnnotations", &xercesc::SAXParser::setValidateAnnotations)
			.def("setDoNamespaces", &xercesc::SAXParser::setDoNamespaces)
			.def("setValidationScheme", &xercesc::SAXParser::setValidationScheme)
			.def("setDoSchema", &xercesc::SAXParser::setDoSchema)
			.def("setValidationSchemaFullChecking", &xercesc::SAXParser::setValidationSchemaFullChecking)
			.def("setIdentityConstraintChecking", &xercesc::SAXParser::setIdentityConstraintChecking)
			.def("setExitOnFirstFatalError", &xercesc::SAXParser::setExitOnFirstFatalError)
			.def("setValidationConstraintFatal", &xercesc::SAXParser::setValidationConstraintFatal)
			.def("setExternalSchemaLocation", static_cast<void(xercesc::SAXParser::*)(const XMLCh* const)>(&xercesc::SAXParser::setExternalSchemaLocation))
			.def("setExternalSchemaLocation", static_cast<void(xercesc::SAXParser::*)(const char* const)>(&xercesc::SAXParser::setExternalSchemaLocation))
			.def("setExternalNoNamespaceSchemaLocation", static_cast<void(xercesc::SAXParser::*)(const XMLCh* const)>(&xercesc::SAXParser::setExternalNoNamespaceSchemaLocation))
			.def("setExternalNoNamespaceSchemaLocation", static_cast<void(xercesc::SAXParser::*)(const char* const)>(&xercesc::SAXParser::setExternalNoNamespaceSchemaLocation))
			.def("setSecurityManager", &xercesc::SAXParser::setSecurityManager)
			.def("setLowWaterMark", &xercesc::SAXParser::setLowWaterMark)
			.def("setLoadExternalDTD", &xercesc::SAXParser::setLoadExternalDTD)
			.def("setLoadSchema", &xercesc::SAXParser::setLoadSchema)
			.def("cacheGrammarFromParse", &xercesc::SAXParser::cacheGrammarFromParse)
			.def("useCachedGrammarInParse", &xercesc::SAXParser::useCachedGrammarInParse)
			.def("setCalculateSrcOfs", &xercesc::SAXParser::setCalculateSrcOfs)
			.def("useScanner", &xercesc::SAXParser::useScanner)
			.def("setInputBufferSize", &xercesc::SAXParser::setInputBufferSize)
			.def("setIgnoreCachedDTD", &xercesc::SAXParser::setIgnoreCachedDTD)
			.def("setIgnoreAnnotations", &xercesc::SAXParser::setIgnoreAnnotations)
			.def("setDisableDefaultEntityResolution", &xercesc::SAXParser::setDisableDefaultEntityResolution)
			.def("setSkipDTDValidation", &xercesc::SAXParser::setSkipDTDValidation)
			.def("setHandleMultipleImports", &xercesc::SAXParser::setHandleMultipleImports)
			.def("installAdvDocHandler", &xercesc::SAXParser::installAdvDocHandler)
			.def("removeAdvDocHandler", &xercesc::SAXParser::removeAdvDocHandler)
			.def("parseFirst", static_cast<bool(xercesc::SAXParser::*)(const XMLCh* const, xercesc::XMLPScanToken&)>(&xercesc::SAXParser::parseFirst))
			.def("parseFirst", static_cast<bool(xercesc::SAXParser::*)(const char* const, xercesc::XMLPScanToken&)>(&xercesc::SAXParser::parseFirst))
			.def("parseFirst", static_cast<bool(xercesc::SAXParser::*)(const xercesc::InputSource&, xercesc::XMLPScanToken&)>(&xercesc::SAXParser::parseFirst))
			.def("parseNext", &xercesc::SAXParser::parseNext)
			.def("parseReset", &xercesc::SAXParser::parseReset)
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::SAXParser::*)(const xercesc::InputSource&, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::SAXParser::loadGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::SAXParser::*)(const XMLCh* const, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::SAXParser::loadGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::SAXParser::*)(const char* const, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::SAXParser::loadGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("resetCachedGrammarPool", &xercesc::SAXParser::resetCachedGrammarPool)
			.def("parse", static_cast<void(xercesc::SAXParser::*)(const XMLCh* const)>(&xercesc::SAXParser::parse))
			.def("parse", static_cast<void(xercesc::SAXParser::*)(const char* const)>(&xercesc::SAXParser::parse))
			.def("parse", static_cast<void(xercesc::SAXParser::*)(const xercesc::InputSource&)>(&xercesc::SAXParser::parse))
			.def("setDocumentHandler", &xercesc::SAXParser::setDocumentHandler)
			.def("setDTDHandler", &xercesc::SAXParser::setDTDHandler)
			.def("setErrorHandler", &xercesc::SAXParser::setErrorHandler)
			.def("setPSVIHandler", &xercesc::SAXParser::setPSVIHandler)
			.def("setEntityResolver", &xercesc::SAXParser::setEntityResolver)
			.def("setXMLEntityResolver", &xercesc::SAXParser::setXMLEntityResolver)
			.def("docCharacters", &xercesc::SAXParser::docCharacters)
			.def("docComment", &xercesc::SAXParser::docComment)
			.def("docPI", &xercesc::SAXParser::docPI)
			.def("endDocument", &xercesc::SAXParser::endDocument)
			.def("endElement", &xercesc::SAXParser::endElement)
			.def("endEntityReference", &xercesc::SAXParser::endEntityReference)
			.def("ignorableWhitespace", &xercesc::SAXParser::ignorableWhitespace)
			.def("resetDocument", &xercesc::SAXParser::resetDocument)
			.def("startDocument", &xercesc::SAXParser::startDocument)
			.def("startElement", &xercesc::SAXParser::startElement)
			.def("startEntityReference", &xercesc::SAXParser::startEntityReference)
			.def("XMLDecl", &xercesc::SAXParser::XMLDecl)
			.def("error", &xercesc::SAXParser::error)
			.def("resetErrors", &xercesc::SAXParser::resetErrors)
			.def("endInputSource", &xercesc::SAXParser::endInputSource)
			.def("expandSystemId", &xercesc::SAXParser::expandSystemId)
			.def("resetEntities", &xercesc::SAXParser::resetEntities)
			.def("resolveEntity", &xercesc::SAXParser::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("startInputSource", &xercesc::SAXParser::startInputSource)
			.def("attDef", &xercesc::SAXParser::attDef)
			.def("doctypeComment", &xercesc::SAXParser::doctypeComment)
			.def("doctypeDecl", &xercesc::SAXParser::doctypeDecl)
			.def("doctypePI", &xercesc::SAXParser::doctypePI)
			.def("doctypeWhitespace", &xercesc::SAXParser::doctypeWhitespace)
			.def("elementDecl", &xercesc::SAXParser::elementDecl)
			.def("endAttList", &xercesc::SAXParser::endAttList)
			.def("endIntSubset", &xercesc::SAXParser::endIntSubset)
			.def("endExtSubset", &xercesc::SAXParser::endExtSubset)
			.def("entityDecl", &xercesc::SAXParser::entityDecl)
			.def("resetDocType", &xercesc::SAXParser::resetDocType)
			.def("notationDecl", &xercesc::SAXParser::notationDecl)
			.def("startAttList", &xercesc::SAXParser::startAttList)
			.def("startIntSubset", &xercesc::SAXParser::startIntSubset)
			.def("startExtSubset", &xercesc::SAXParser::startExtSubset)
			.def("TextDecl", &xercesc::SAXParser::TextDecl)
			;
	boost::python::scope SAXParserScope = SAXParser;
	//! xercesc::SAXParser::ValSchemes
	boost::python::enum_<xercesc::SAXParser::ValSchemes>("ValSchemes")
			.value("Val_Never", xercesc::SAXParser::Val_Never)
			.value("Val_Always", xercesc::SAXParser::Val_Always)
			.value("Val_Auto", xercesc::SAXParser::Val_Auto)
			.export_values()
			;
}

} /* namespace pyxerces */
