/*
 * DOMNotation.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMNotation.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNotation.hpp>

namespace pyxerces {

void DOMNotation_init(void) {
	//! xercesc::DOMNotation
	boost::python::class_<xercesc::DOMNotation, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMNotation", boost::python::no_init)
			.def("getPublicId", &xercesc::DOMNotation::getPublicId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::DOMNotation::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxerces */
