/*
 * DOMLocator.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "DOMLocator.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNode.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMLocator.hpp>

namespace pyxerces {

void DOMLocator_init(void) {
	//! xercesc::DOMLocator
	boost::python::class_<xercesc::DOMLocator, boost::noncopyable>("DOMLocator", boost::python::no_init)
			.def("getLineNumber", &xercesc::DOMLocator::getLineNumber)
			.def("getColumnNumber", &xercesc::DOMLocator::getColumnNumber)
			.def("getByteOffset", &xercesc::DOMLocator::getByteOffset)
			.def("getUtf16Offset", &xercesc::DOMLocator::getUtf16Offset)
			.def("getRelatedNode", &xercesc::DOMLocator::getRelatedNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURI", &xercesc::DOMLocator::getURI, boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxerces */
