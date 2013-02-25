/*
 * DOMImplementationRegistry.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMImplementationRegistry.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMImplementation.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMImplementationSource.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMImplementationList.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMImplementationRegistry.hpp>

namespace pyxerces {

void DOMImplementationRegistry_init(void) {
	//! xercesc::DOMImplementationRegistry
	boost::python::class_<xercesc::DOMImplementationRegistry, boost::noncopyable>("DOMImplementationRegistry", boost::python::no_init)
			.def("getDOMImplementation", &xercesc::DOMImplementationRegistry::getDOMImplementation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDOMImplementationList", &xercesc::DOMImplementationRegistry::getDOMImplementationList, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("addSource", &xercesc::DOMImplementationRegistry::addSource)
			.staticmethod("getDOMImplementation")
			.staticmethod("getDOMImplementationList")
			.staticmethod("addSource")
			;
}

} /* namespace pyxerces */
