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

namespace pyxerces {

void AbstractDOMParser_init(void) {
	//! xercesc::AbstractDOMParser
	auto AbstractDOMParser = boost::python::class_<xercesc::AbstractDOMParser, boost::noncopyable, boost::python::bases<xercesc::XMLDocumentHandler, xercesc::XMLErrorReporter, xercesc::XMLEntityHandler, xercesc::DocTypeHandler, xercesc::PSVIHandler> >("AbstractDOMParser", boost::python::no_init)
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
