/*
 * DOMXPathEvaluator.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "DOMXPathEvaluator.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMXPathNSResolver.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMXPathExpression.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMNode.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMXPathEvaluator.hpp>

namespace pyxerces {

void DOMXPathEvaluator_init(void) {
	//! xercesc::DOMXPathEvaluator
	boost::python::class_<xercesc::DOMXPathEvaluator, boost::noncopyable>("DOMXPathEvaluator", boost::python::no_init)
			.def("createExpression", &xercesc::DOMXPathEvaluator::createExpression, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createNSResolver", &xercesc::DOMXPathEvaluator::createNSResolver, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("evaluate", &xercesc::DOMXPathEvaluator::evaluate, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
