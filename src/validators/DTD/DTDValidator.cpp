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

void DTDValidator_init(void) {
	//! xercesc::DTDValidator
	boost::python::class_<xercesc::DTDValidator, boost::noncopyable, boost::python::bases<xercesc::XMLValidator> >("DTDValidator", boost::python::init<boost::python::optional<xercesc::XMLErrorReporter* const> >())
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
}

} /* namespace pyxerces */
