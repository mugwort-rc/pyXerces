/*
 * DOMImplementationList.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMImplementationList.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMImplementation.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMImplementationList.hpp>

namespace pyxerces {

void DOMImplementationList_init(void) {
	//! xercesc::DOMImplementationList
	boost::python::class_<xercesc::DOMImplementationList, boost::noncopyable>("DOMImplementationList", boost::python::no_init)
			.def("item", &xercesc::DOMImplementationList::item, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLength", &xercesc::DOMImplementationList::getLength)
			.def("release", &xercesc::DOMImplementationList::release)
			;
}

} /* namespace pyxerces */
