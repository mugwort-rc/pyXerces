/*
 * DTDValidator.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "DTDValidator.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/util/XMLMsgLoader.hpp>

#include <xercesc/validators/DTD/DTDValidator.hpp>

#include "../../util/XMLString.h"

namespace pyxerces {

class DTDValidatorWrapper
: public xercesc::DTDValidator, public boost::python::wrapper<xercesc::DTDValidator>
{
public:
DTDValidatorWrapper(xercesc::XMLErrorReporter* const errReporter = 0)
: xercesc::DTDValidator(errReporter)
{}

bool checkContent(xercesc::XMLElementDecl* const elemDecl, xercesc::QName** const children, XMLSize_t childCount, XMLSize_t* indexFailingChild) {
	if(boost::python::override checkContent = this->get_override("checkContent")){
		boost::python::list childrens;
		for(XMLSize_t i = 0; i < childCount; ++i){
			childrens.append(boost::python::ptr(children[i]));
		}
		boost::python::tuple result = checkContent(boost::python::ptr(elemDecl), childrens);
		*indexFailingChild = boost::python::extract<XMLSize_t>(result[1]);
		return boost::python::extract<bool>(result[0]);
	}else{
		return xercesc::DTDValidator::checkContent(elemDecl, children, childCount, indexFailingChild);
	}
}

void faultInAttr(xercesc::XMLAttr& toFill, const xercesc::XMLAttDef& attDef) const {
	if(boost::python::override faultInAttr = this->get_override("faultInAttr")){
		faultInAttr(boost::ref(toFill), boost::ref(attDef));
	}else{
		xercesc::DTDValidator::faultInAttr(toFill, attDef);
	}
}

void preContentValidation(bool reuseGrammar, bool validateDefAttr = false) {
	if(boost::python::override preContentValidation = this->get_override("preContentValidation")){
		preContentValidation(reuseGrammar, validateDefAttr);
	}else{
		xercesc::DTDValidator::preContentValidation(reuseGrammar, validateDefAttr);
	}
}

void postParseValidation() {
	if(boost::python::override postParseValidation = this->get_override("postParseValidation")){
		postParseValidation();
	}else{
		xercesc::DTDValidator::postParseValidation();
	}
}

void reset() {
	if(boost::python::override reset = this->get_override("reset")){
		reset();
	}else{
		xercesc::DTDValidator::reset();
	}
}

bool requiresNamespaces() const {
	if(boost::python::override requiresNamespaces = this->get_override("requiresNamespaces")){
		return requiresNamespaces();
	}else{
		return xercesc::DTDValidator::requiresNamespaces();
	}
}

void validateAttrValue(const xercesc::XMLAttDef* attDef, const XMLCh* const attrValue, bool preValidation = false, const xercesc::XMLElementDecl* elemDecl = 0) {
	if(boost::python::override validateAttrValue = this->get_override("validateAttrValue")){
		validateAttrValue(boost::python::ptr(attDef), XMLString(attrValue), preValidation, boost::python::ptr(elemDecl));
	}else{
		xercesc::DTDValidator::validateAttrValue(attDef, attrValue, preValidation, elemDecl);
	}
}

void validateElement(const xercesc::XMLElementDecl* elemDef) {
	if(boost::python::override validateElement = this->get_override("validateElement")){
		validateElement(boost::python::ptr(elemDef));
	}else{
		xercesc::DTDValidator::validateElement(elemDef);
	}
}

xercesc::Grammar* getGrammar() const {
	if(boost::python::override getGrammar = this->get_override("getGrammar")){
		return getGrammar();
	}else{
		return xercesc::DTDValidator::getGrammar();
	}
}

void setGrammar(xercesc::Grammar* aGrammar) {
	if(boost::python::override setGrammar = this->get_override("setGrammar")){
		setGrammar(boost::python::ptr(aGrammar));
	}else{
		xercesc::DTDValidator::setGrammar(aGrammar);
	}
}

bool handlesDTD() const {
	if(boost::python::override handlesDTD = this->get_override("handlesDTD")){
		return handlesDTD();
	}else{
		return xercesc::DTDValidator::handlesDTD();
	}
}

bool handlesSchema() const {
	if(boost::python::override handlesSchema = this->get_override("handlesSchema")){
		return handlesSchema();
	}else{
		return xercesc::DTDValidator::handlesSchema();
	}
}

};

xercesc::DTDValidator* makeDTDValidator(xercesc::XMLErrorReporter* const errReporter) {
	return new xercesc::DTDValidator(errReporter);
}

xercesc::DTDValidator* makeDTDValidator() {
	return new xercesc::DTDValidator();
}

void DTDValidator_init(void) {
	//! xercesc::DTDValidator
	boost::python::class_<DTDValidatorWrapper, boost::noncopyable, boost::python::bases<xercesc::XMLValidator> >("_DTDValidator", boost::python::init<boost::python::optional<xercesc::XMLErrorReporter* const> >())
			.def("checkContent", &xercesc::DTDValidator::checkContent)
			.def("faultInAttr", &xercesc::DTDValidator::faultInAttr)
			.def("preContentValidation", &xercesc::DTDValidator::preContentValidation)
			.def("postParseValidation", &xercesc::DTDValidator::postParseValidation)
			.def("reset", &xercesc::DTDValidator::reset)
			.def("requiresNamespaces", &xercesc::DTDValidator::requiresNamespaces)
			.def("validateAttrValue", &xercesc::DTDValidator::validateAttrValue)
			.def("validateElement", &xercesc::DTDValidator::validateElement)
			.def("getGrammar", &xercesc::DTDValidator::getGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setGrammar", &xercesc::DTDValidator::setGrammar)
			.def("handlesDTD", &xercesc::DTDValidator::handlesDTD)
			.def("handlesSchema", &xercesc::DTDValidator::handlesSchema)
			;
	//! SAXParser cleanup auto release
	boost::python::def("DTDValidator", static_cast<xercesc::DTDValidator*(*)(xercesc::XMLErrorReporter* const)>(&makeDTDValidator), boost::python::return_value_policy<boost::python::reference_existing_object>());
	boost::python::def("DTDValidator", static_cast<xercesc::DTDValidator*(*)()>(&makeDTDValidator), boost::python::return_value_policy<boost::python::reference_existing_object>());
}

} /* namespace pyxerces */
