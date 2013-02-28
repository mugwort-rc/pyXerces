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

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class DOMXPathEvaluatorDefVisitor
: public boost::python::def_visitor<DOMXPathEvaluatorDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createExpression", &DOMXPathEvaluatorDefVisitor::createExpression, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("evaluate", &DOMXPathEvaluatorDefVisitor::evaluate, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMXPathExpression* createExpression(xercesc::DOMXPathEvaluator& self, const STR& expression, const xercesc::DOMXPathNSResolver* resolver) {
	XMLString buff(expression);
	return self.createExpression(buff.ptr(), resolver);
}

static xercesc::DOMXPathResult* evaluate(xercesc::DOMXPathEvaluator& self, const STR& expression, const xercesc::DOMNode* contextNode, const xercesc::DOMXPathNSResolver* resolver, xercesc::DOMXPathResult::ResultType type, xercesc::DOMXPathResult* result) {
	XMLString buff(expression);
	return self.evaluate(buff.ptr(), contextNode, resolver, type, result);
}

};

void DOMXPathEvaluator_init(void) {
	//! xercesc::DOMXPathEvaluator
	boost::python::class_<xercesc::DOMXPathEvaluator, boost::noncopyable>("DOMXPathEvaluator", boost::python::no_init)
			.def(DOMXPathEvaluatorDefVisitor<XMLString>())
			.def(DOMXPathEvaluatorDefVisitor<std::string>())
			.def("createExpression", &xercesc::DOMXPathEvaluator::createExpression, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createNSResolver", &xercesc::DOMXPathEvaluator::createNSResolver, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("evaluate", &xercesc::DOMXPathEvaluator::evaluate, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
