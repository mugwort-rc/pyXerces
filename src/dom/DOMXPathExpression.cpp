/*
 * DOMXPathExpression.cpp
 *
 *  Created on: 2013/02/24
 *      Author: mugwort_rc
 */

#include "DOMXPathExpression.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNode.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMXPathExpression.hpp>

namespace pyxerces {

void DOMXPathExpression_init(void) {
	//! xercesc::DOMXPathExpression
	boost::python::class_<xercesc::DOMXPathExpression, boost::noncopyable>("DOMXPathExpression", boost::python::no_init)
			.def("evaluate", &xercesc::DOMXPathExpression::evaluate, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("release", &xercesc::DOMXPathExpression::release)
			;
}

} /* namespace pyxerces */
