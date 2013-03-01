/*
 * XMLValidator.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "XMLValidator.h"

#include <boost/python.hpp>
#include <xercesc/internal/ReaderMgr.hpp>			//!< for forward declaration
#include <xercesc/framework/XMLBufferMgr.hpp>		//!< for forward declaration
#include <xercesc/framework/XMLElementDecl.hpp>		//!< for forward declaration
#include <xercesc/internal/XMLScanner.hpp>			//!< for forward declaration
#include <xercesc/validators/common/Grammar.hpp>	//!< for forward declaration
#include <xercesc/framework/XMLValidator.hpp>

namespace pyxerces {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLValidatorEmitErrorOverloads, emitError, 2, 5)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLValidatorEmit2ErrorOverloads, emitError, 2, 6)

void XMLValidator_init(void) {
	//! xercesc::XMLValidator
	boost::python::class_<xercesc::XMLValidator, boost::noncopyable>("XMLValidator", boost::python::no_init)
			.def("checkContent", &xercesc::XMLValidator::checkContent)
			.def("faultInAttr", &xercesc::XMLValidator::faultInAttr)
			.def("preContentValidation", &xercesc::XMLValidator::preContentValidation)
			.def("postParseValidation", &xercesc::XMLValidator::postParseValidation)
			.def("reset", &xercesc::XMLValidator::reset)
			.def("requiresNamespaces", &xercesc::XMLValidator::requiresNamespaces)
			.def("validateAttrValue", &xercesc::XMLValidator::validateAttrValue)
			.def("validateElement", &xercesc::XMLValidator::validateElement)
			.def("getGrammar", &xercesc::XMLValidator::getGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setGrammar", &xercesc::XMLValidator::setGrammar)
			.def("handlesDTD", &xercesc::XMLValidator::handlesDTD)
			.def("handlesSchema", &xercesc::XMLValidator::handlesSchema)
			.def("setScannerInfo", &xercesc::XMLValidator::setScannerInfo)
			.def("setErrorReporter", &xercesc::XMLValidator::setErrorReporter)
			.def("emitError", static_cast<void(xercesc::XMLValidator::*)(const xercesc::XMLValid::Codes)>(&xercesc::XMLValidator::emitError))
			.def("emitError", static_cast<void(xercesc::XMLValidator::*)(const xercesc::XMLValid::Codes, const XMLCh* const, const XMLCh* const, const XMLCh* const, const XMLCh* const)>(&xercesc::XMLValidator::emitError), XMLValidatorEmitErrorOverloads())
			.def("emitError", static_cast<void(xercesc::XMLValidator::*)(const xercesc::XMLValid::Codes, const char* const, const char* const, const char* const, const char* const)>(&xercesc::XMLValidator::emitError), XMLValidatorEmitErrorOverloads())
			.def("emitError", static_cast<void(xercesc::XMLValidator::*)(const xercesc::XMLValid::Codes, const xercesc::XMLExcepts::Codes, const XMLCh* const, const XMLCh* const, const XMLCh* const, const XMLCh* const)>(&xercesc::XMLValidator::emitError), XMLValidatorEmit2ErrorOverloads())
			;
}

} /* namespace pyxerces */
