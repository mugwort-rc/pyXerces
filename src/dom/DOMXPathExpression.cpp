/*
 * DOMXPathExpression.cpp
 *
 *  Created on: 2013/02/24
 *      Author: mugwort_rc
 */

#include "DOMXPathExpression.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMNode.hpp>

#include <xercesc/dom/DOMXPathExpression.hpp>

namespace pyxerces {

class DOMXPathExpressionWrapper
: public xercesc::DOMXPathExpression, public boost::python::wrapper<xercesc::DOMXPathExpression>
{
public:
xercesc::DOMXPathResult* evaluate(const xercesc::DOMNode *contextNode, xercesc::DOMXPathResult::ResultType type, xercesc::DOMXPathResult* result) const {
	return this->get_override("evaluate")(boost::python::ptr(contextNode), type, boost::python::ptr(result));
}

void release() {
	this->get_override("release")();
}

};

void DOMXPathExpression_init(void) {
	//! xercesc::DOMXPathExpression
	boost::python::class_<DOMXPathExpressionWrapper, boost::noncopyable>("DOMXPathExpression")
			.def("evaluate", boost::python::pure_virtual(&xercesc::DOMXPathExpression::evaluate), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("release", boost::python::pure_virtual(&xercesc::DOMXPathExpression::release))
			;
}

} /* namespace pyxerces */
