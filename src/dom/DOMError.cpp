/*
 * DOMError.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "DOMError.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMLocator.hpp>

#include <xercesc/dom/DOMError.hpp>

namespace pyxerces {

class DOMErrorWrapper
: public xercesc::DOMError, public boost::python::wrapper<xercesc::DOMError>
{
public:
ErrorSeverity getSeverity() const {
	return this->get_override("getSeverity")();
}

const XMLCh* getMessage() const {
	return this->get_override("getMessage")();
}

xercesc::DOMLocator* getLocation() const {
	return this->get_override("getLocation")();
}

void* getRelatedException() const {
	return this->get_override("getRelatedException")();
}

const XMLCh* getType() const {
	return this->get_override("getType")();
}

void* getRelatedData() const {
	return this->get_override("getRelatedData")();
}

};

void DOMError_init(void) {
	//! xercesc::DOMError
	auto DOMError = boost::python::class_<DOMErrorWrapper, boost::noncopyable>("DOMError")
			.def("getSeverity", boost::python::pure_virtual(&xercesc::DOMError::getSeverity))
			.def("getMessage", boost::python::pure_virtual(&xercesc::DOMError::getMessage), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLocation", boost::python::pure_virtual(&xercesc::DOMError::getLocation), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getRelatedException", boost::python::pure_virtual(&xercesc::DOMError::getRelatedException), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("getType", boost::python::pure_virtual(&xercesc::DOMError::getType), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getRelatedData", boost::python::pure_virtual(&xercesc::DOMError::getRelatedData), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
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
