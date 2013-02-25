/*
 * DOMRange.cpp
 *
 *  Created on: 2013/02/26
 *      Author: mugwort_rc
 */

#include "DOMRange.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNode.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMDocumentFragment.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMRange.hpp>

namespace pyxerces {

void DOMRange_init(void) {
	//! xercesc::DOMRange
	auto DOMRange = boost::python::class_<xercesc::DOMRange, boost::noncopyable>("DOMRange", boost::python::no_init)
			.def("getStartContainer", &xercesc::DOMRange::getStartContainer, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getStartOffset", &xercesc::DOMRange::getStartOffset)
			.def("getEndContainer", &xercesc::DOMRange::getEndContainer, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEndOffset", &xercesc::DOMRange::getEndOffset)
			.def("getCollapsed", &xercesc::DOMRange::getCollapsed)
			.def("getCommonAncestorContainer", &xercesc::DOMRange::getCommonAncestorContainer, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setStart", &xercesc::DOMRange::setStart)
			.def("setEnd", &xercesc::DOMRange::setEnd)
			.def("setStartBefore", &xercesc::DOMRange::setStartBefore)
			.def("setStartAfter", &xercesc::DOMRange::setStartAfter)
			.def("setEndBefore", &xercesc::DOMRange::setEndBefore)
			.def("setEndAfter", &xercesc::DOMRange::setEndAfter)
			.def("collapse", &xercesc::DOMRange::collapse)
			.def("selectNode", &xercesc::DOMRange::selectNode)
			.def("selectNodeContents", &xercesc::DOMRange::selectNodeContents)
			.def("compareBoundaryPoints", &xercesc::DOMRange::compareBoundaryPoints)
			.def("deleteContents", &xercesc::DOMRange::deleteContents)
			.def("extractContents", &xercesc::DOMRange::extractContents, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("cloneContents", &xercesc::DOMRange::cloneContents, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("insertNode", &xercesc::DOMRange::insertNode)
			.def("surroundContents", &xercesc::DOMRange::surroundContents)
			.def("cloneRange", &xercesc::DOMRange::cloneRange, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("toString", &xercesc::DOMRange::toString, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("detach", &xercesc::DOMRange::detach)
			.def("release", &xercesc::DOMRange::release)
			;
	boost::python::scope DOMRangeScope = DOMRange;
	//! xercesc::DOMRange::CompareHow
	boost::python::enum_<xercesc::DOMRange::CompareHow>("CompareHow")
			.value("START_TO_START", xercesc::DOMRange::START_TO_START)
			.value("START_TO_END", xercesc::DOMRange::START_TO_END)
			.value("END_TO_END", xercesc::DOMRange::END_TO_END)
			.value("END_TO_START", xercesc::DOMRange::END_TO_START)
			;
}

} /* namespace pyxerces */
