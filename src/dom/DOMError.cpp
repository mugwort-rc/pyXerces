/*
 * DOMError.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "DOMError.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMLocator.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMError.hpp>

namespace pyxerces {

void DOMError_init(void) {
	//! xercesc::DOMError
	auto DOMError = boost::python::class_<xercesc::DOMError, boost::noncopyable>("DOMError", boost::python::no_init)
			.def("getSeverity", &xercesc::DOMError::getSeverity)
			.def("getMessage", &xercesc::DOMError::getMessage, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLocation", &xercesc::DOMError::getLocation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getRelatedException", &xercesc::DOMError::getRelatedException, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("getType", &xercesc::DOMError::getType, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getRelatedData", &xercesc::DOMError::getRelatedData, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			;
	boost::python::scope DOMErrorScope = DOMError;
	//! xercesc::DOMError::ErrorSeverity
	boost::python::enum_<xercesc::DOMError::ErrorSeverity>("ErrorSeverity")
			.value("DOM_SEVERITY_WARNING", xercesc::DOMError::DOM_SEVERITY_WARNING)
			.value("DOM_SEVERITY_ERROR", xercesc::DOMError::DOM_SEVERITY_ERROR)
			.value("DOM_SEVERITY_FATAL_ERROR", xercesc::DOMError::DOM_SEVERITY_FATAL_ERROR)
			.export_values()
			;
}

} /* namespace pyxerces */
