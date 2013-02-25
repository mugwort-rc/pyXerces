/*
 * DOMNodeIterator.cpp
 *
 *  Created on: 2013/02/26
 *      Author: mugwort_rc
 */

#include "DOMNodeIterator.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>

namespace pyxerces {

void DOMNodeIterator_init(void) {
	//! xercesc::DOMNodeIterator
	boost::python::class_<xercesc::DOMNodeIterator, boost::noncopyable>("DOMNodeIterator", boost::python::no_init)
			.def("getRoot", &xercesc::DOMNodeIterator::getRoot, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getWhatToShow", &xercesc::DOMNodeIterator::getWhatToShow)
			.def("getFilter", &xercesc::DOMNodeIterator::getFilter, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getExpandEntityReferences", &xercesc::DOMNodeIterator::getExpandEntityReferences)
			.def("nextNode", &xercesc::DOMNodeIterator::nextNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("previousNode", &xercesc::DOMNodeIterator::previousNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("detach", &xercesc::DOMNodeIterator::detach)
			.def("release", &xercesc::DOMNodeIterator::release)
			;
}

} /* namespace pyxerces */
