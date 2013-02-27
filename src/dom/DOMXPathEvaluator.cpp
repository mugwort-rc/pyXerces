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

class DOMXPathEvaluatorDefVisitor
: public boost::python::def_visitor<DOMXPathEvaluatorDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createExpression", static_cast<xercesc::DOMXPathExpression*(*)(xercesc::DOMXPathEvaluator&, const XMLString&, const xercesc::DOMXPathNSResolver*)>(&DOMXPathEvaluatorDefVisitor::createExpression), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createExpression", static_cast<xercesc::DOMXPathExpression*(*)(xercesc::DOMXPathEvaluator&, const std::string&, const xercesc::DOMXPathNSResolver*)>(&DOMXPathEvaluatorDefVisitor::createExpression), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("evaluate", static_cast<xercesc::DOMXPathResult*(*)(xercesc::DOMXPathEvaluator&, const XMLString&, const xercesc::DOMNode*, const xercesc::DOMXPathNSResolver*, xercesc::DOMXPathResult::ResultType, xercesc::DOMXPathResult*)>(&DOMXPathEvaluatorDefVisitor::evaluate), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("evaluate", static_cast<xercesc::DOMXPathResult*(*)(xercesc::DOMXPathEvaluator&, const std::string&, const xercesc::DOMNode*, const xercesc::DOMXPathNSResolver*, xercesc::DOMXPathResult::ResultType, xercesc::DOMXPathResult*)>(&DOMXPathEvaluatorDefVisitor::evaluate), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMXPathExpression* createExpression(xercesc::DOMXPathEvaluator& self, const XMLString& expression, const xercesc::DOMXPathNSResolver* resolver) {
	return self.createExpression(expression.ptr(), resolver);
}

static xercesc::DOMXPathExpression* createExpression(xercesc::DOMXPathEvaluator& self, const std::string& expression, const xercesc::DOMXPathNSResolver* resolver) {
	XMLString buff(expression);
	return DOMXPathEvaluatorDefVisitor::createExpression(self, buff, resolver);
}

static xercesc::DOMXPathResult* evaluate(xercesc::DOMXPathEvaluator& self, const XMLString& expression, const xercesc::DOMNode* contextNode, const xercesc::DOMXPathNSResolver* resolver, xercesc::DOMXPathResult::ResultType type, xercesc::DOMXPathResult* result) {
	return self.evaluate(expression.ptr(), contextNode, resolver, type, result);
}

static xercesc::DOMXPathResult* evaluate(xercesc::DOMXPathEvaluator& self, const std::string& expression, const xercesc::DOMNode* contextNode, const xercesc::DOMXPathNSResolver* resolver, xercesc::DOMXPathResult::ResultType type, xercesc::DOMXPathResult* result) {
	XMLString buff(expression);
	return DOMXPathEvaluatorDefVisitor::evaluate(self, buff, contextNode, resolver, type, result);
}
};

void DOMXPathEvaluator_init(void) {
	//! xercesc::DOMXPathEvaluator
	boost::python::class_<xercesc::DOMXPathEvaluator, boost::noncopyable>("DOMXPathEvaluator", boost::python::no_init)
			.def(DOMXPathEvaluatorDefVisitor())
			.def("createExpression", &xercesc::DOMXPathEvaluator::createExpression, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createNSResolver", &xercesc::DOMXPathEvaluator::createNSResolver, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("evaluate", &xercesc::DOMXPathEvaluator::evaluate, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
