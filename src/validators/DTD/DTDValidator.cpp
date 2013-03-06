/*
 * DTDValidator.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "DTDValidator.h"

#include <boost/python.hpp>
#include <xercesc/util/XMLMsgLoader.hpp>			//!< for forward declaration
#include <xercesc/validators/DTD/DTDValidator.hpp>

namespace pyxerces {

xercesc::DTDValidator* makeDTDValidator(xercesc::XMLErrorReporter* const errReporter) {
	return new xercesc::DTDValidator(errReporter);
}

xercesc::DTDValidator* makeDTDValidator() {
	return new xercesc::DTDValidator();
}

void DTDValidator_init(void) {
	//! xercesc::DTDValidator
	boost::python::class_<xercesc::DTDValidator, boost::noncopyable, boost::python::bases<xercesc::XMLValidator> >("_DTDValidator", boost::python::init<boost::python::optional<xercesc::XMLErrorReporter* const> >())
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
