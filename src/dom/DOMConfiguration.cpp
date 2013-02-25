/*
 * DOMConfiguration.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMConfiguration.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMConfiguration.hpp>

namespace pyxerces {

void DOMConfiguration_init(void) {
	//! xercesc::DOMConfiguration
	boost::python::class_<xercesc::DOMConfiguration, boost::noncopyable>("DOMConfiguration", boost::python::no_init)
			.def("setParameter", static_cast<void(xercesc::DOMConfiguration::*)(const XMLCh*, const void*)>(&xercesc::DOMConfiguration::setParameter))
			.def("setParameter", static_cast<void(xercesc::DOMConfiguration::*)(const XMLCh*, bool)>(&xercesc::DOMConfiguration::setParameter))
			.def("getParameter", &xercesc::DOMConfiguration::getParameter, boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("canSetParameter", static_cast<bool(xercesc::DOMConfiguration::*)(const XMLCh*, const void*) const>(&xercesc::DOMConfiguration::canSetParameter))
			.def("canSetParameter", static_cast<bool(xercesc::DOMConfiguration::*)(const XMLCh*, bool) const>(&xercesc::DOMConfiguration::canSetParameter))
			.def("getParameterNames", &xercesc::DOMConfiguration::getParameterNames, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
