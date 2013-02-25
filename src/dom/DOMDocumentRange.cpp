/*
 * DOMDocumentRange.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "DOMDocumentRange.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMRange.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMDocumentRange.hpp>

namespace pyxerces {

void DOMDocumentRange_init(void) {
	//! xercesc::DOMDocumentRange
	boost::python::class_<xercesc::DOMDocumentRange, boost::noncopyable>("DOMDocumentRange", boost::python::no_init)
			.def("createRange", &xercesc::DOMDocumentRange::createRange, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
