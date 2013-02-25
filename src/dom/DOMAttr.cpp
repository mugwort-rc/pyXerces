/*
 * DOMAttr.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMAttr.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMElement.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMTypeInfo.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMAttr.hpp>

namespace pyxerces {

void DOMAttr_init(void) {
	//! xercesc::DOMAttr
	boost::python::class_<xercesc::DOMAttr, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMAttr", boost::python::no_init)
			.def("getName", &xercesc::DOMAttr::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSpecified", &xercesc::DOMAttr::getSpecified)
			.def("getValue", &xercesc::DOMAttr::getValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setValue", &xercesc::DOMAttr::setValue)
			.def("getOwnerElement", &xercesc::DOMAttr::getOwnerElement, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isId", &xercesc::DOMAttr::isId)
			.def("getSchemaTypeInfo", &xercesc::DOMAttr::getSchemaTypeInfo, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
