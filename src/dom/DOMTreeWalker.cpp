/*
 * DOMTreeWalker.cpp
 *
 *  Created on: 2013/02/26
 *      Author: mugwort_rc
 */

#include "DOMTreeWalker.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMTreeWalker.hpp>

namespace pyxerces {

void DOMTreeWalker_init(void) {
	//! xercesc::DOMTreeWalker
	boost::python::class_<xercesc::DOMTreeWalker, boost::noncopyable>("DOMTreeWalker", boost::python::no_init)
			.def("getRoot", &xercesc::DOMTreeWalker::getRoot, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getWhatToShow", &xercesc::DOMTreeWalker::getWhatToShow)
			.def("getFilter", &xercesc::DOMTreeWalker::getFilter, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getExpandEntityReferences", &xercesc::DOMTreeWalker::getExpandEntityReferences)
			.def("getCurrentNode", &xercesc::DOMTreeWalker::getCurrentNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("parentNode", &xercesc::DOMTreeWalker::parentNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("firstChild", &xercesc::DOMTreeWalker::firstChild, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("lastChild", &xercesc::DOMTreeWalker::lastChild, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("previousSibling", &xercesc::DOMTreeWalker::previousSibling, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("nextSibling", &xercesc::DOMTreeWalker::nextSibling, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("previousNode", &xercesc::DOMTreeWalker::previousNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("nextNode", &xercesc::DOMTreeWalker::nextNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setCurrentNode", &xercesc::DOMTreeWalker::setCurrentNode)
			.def("release", &xercesc::DOMTreeWalker::release)
			;
}

} /* namespace pyxerces */
