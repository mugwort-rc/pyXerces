/*
 * XMLValidator.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "XMLValidator.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/internal/ReaderMgr.hpp>
#include <xercesc/framework/XMLBufferMgr.hpp>
#include <xercesc/framework/XMLElementDecl.hpp>
#include <xercesc/internal/XMLScanner.hpp>
#include <xercesc/validators/common/Grammar.hpp>

#include <xercesc/framework/XMLValidator.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class XMLValidatorWrapper
: public xercesc::XMLValidator, public boost::python::wrapper<xercesc::XMLValidator>
{
public:
bool checkContent(xercesc::XMLElementDecl* const elemDecl, xercesc::QName** const children, XMLSize_t childCount, XMLSize_t* indexFailingChild) {
	boost::python::list childrens;
	for(XMLSize_t i = 0; i < childCount; ++i){
		childrens.append(boost::python::ptr(children[i]));
	}
	boost::python::tuple result = this->get_override("checkContent")(boost::python::ptr(elemDecl), childrens);
	*indexFailingChild = boost::python::extract<XMLSize_t>(result[1]);
	return boost::python::extract<bool>(result[0]);
}

void faultInAttr(xercesc::XMLAttr& toFill, const xercesc::XMLAttDef& attDef) const {
	this->get_override("faultInAttr")(boost::ref(toFill), boost::ref(attDef));
}

void preContentValidation(bool reuseGrammar, bool validateDefAttr = false) {
	this->get_override("preContentValidation")(reuseGrammar, validateDefAttr);
}

void postParseValidation() {
	this->get_override("postParseValidation")();
}

void reset() {
	this->get_override("reset")();
}

bool requiresNamespaces() const {
	return this->get_override("requiresNamespaces")();
}

void validateAttrValue(const xercesc::XMLAttDef* attDef, const XMLCh* const attrValue, bool preValidation = false, const xercesc::XMLElementDecl* elemDecl = 0) {
	this->get_override("validateAttrValue")(boost::python::ptr(attDef), XMLString(attrValue), preValidation, boost::python::ptr(elemDecl));
}

void validateElement(const xercesc::XMLElementDecl* elemDef) {
	this->get_override("validateElement")(boost::python::ptr(elemDef));
}

xercesc::Grammar* getGrammar() const {
	return this->get_override("getGrammar")();
}

void setGrammar(xercesc::Grammar* aGrammar) {
	this->get_override("setGrammar")(boost::python::ptr(aGrammar));
}

bool handlesDTD() const {
	return this->get_override("handlesDTD")();
}

bool handlesSchema() const {
	return this->get_override("handlesSchema")();
}

};

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLValidatorEmitErrorOverloads, emitError, 2, 5)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLValidatorEmit2ErrorOverloads, emitError, 2, 6)

void XMLValidator_init(void) {
	//! xercesc::XMLValidator
	boost::python::class_<XMLValidatorWrapper, boost::noncopyable>("XMLValidator")
			.def("checkContent", boost::python::pure_virtual(&xercesc::XMLValidator::checkContent))
			.def("faultInAttr", boost::python::pure_virtual(&xercesc::XMLValidator::faultInAttr))
			.def("preContentValidation", boost::python::pure_virtual(&xercesc::XMLValidator::preContentValidation))
			.def("postParseValidation", boost::python::pure_virtual(&xercesc::XMLValidator::postParseValidation))
			.def("reset", boost::python::pure_virtual(&xercesc::XMLValidator::reset))
			.def("requiresNamespaces", boost::python::pure_virtual(&xercesc::XMLValidator::requiresNamespaces))
			.def("validateAttrValue", boost::python::pure_virtual(&xercesc::XMLValidator::validateAttrValue))
			.def("validateElement", boost::python::pure_virtual(&xercesc::XMLValidator::validateElement))
			.def("getGrammar", boost::python::pure_virtual(&xercesc::XMLValidator::getGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setGrammar", boost::python::pure_virtual(&xercesc::XMLValidator::setGrammar))
			.def("handlesDTD", boost::python::pure_virtual(&xercesc::XMLValidator::handlesDTD))
			.def("handlesSchema", boost::python::pure_virtual(&xercesc::XMLValidator::handlesSchema))
			.def("setScannerInfo", &xercesc::XMLValidator::setScannerInfo)
			.def("setErrorReporter", &xercesc::XMLValidator::setErrorReporter)
			.def("emitError", static_cast<void(xercesc::XMLValidator::*)(const xercesc::XMLValid::Codes)>(&xercesc::XMLValidator::emitError))
			.def("emitError", static_cast<void(xercesc::XMLValidator::*)(const xercesc::XMLValid::Codes, const XMLCh* const, const XMLCh* const, const XMLCh* const, const XMLCh* const)>(&xercesc::XMLValidator::emitError), XMLValidatorEmitErrorOverloads())
			.def("emitError", static_cast<void(xercesc::XMLValidator::*)(const xercesc::XMLValid::Codes, const char* const, const char* const, const char* const, const char* const)>(&xercesc::XMLValidator::emitError), XMLValidatorEmitErrorOverloads())
			.def("emitError", static_cast<void(xercesc::XMLValidator::*)(const xercesc::XMLValid::Codes, const xercesc::XMLExcepts::Codes, const XMLCh* const, const XMLCh* const, const XMLCh* const, const XMLCh* const)>(&xercesc::XMLValidator::emitError), XMLValidatorEmit2ErrorOverloads())
			;
}

} /* namespace pyxerces */
