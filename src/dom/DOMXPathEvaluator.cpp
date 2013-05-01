/*
 * DOMXPathEvaluator.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "DOMXPathEvaluator.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMXPathNSResolver.hpp>
#include <xercesc/dom/DOMXPathExpression.hpp>
#include <xercesc/dom/DOMNode.hpp>

#include <xercesc/dom/DOMXPathEvaluator.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
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

static xercesc::DOMXPathExpression* createExpression(xercesc::DOMXPathEvaluator& self, const STR expression, const xercesc::DOMXPathNSResolver* resolver) {
	XMLString buff(expression);
	return self.createExpression(buff.ptr(), resolver);
}

static xercesc::DOMXPathResult* evaluate(xercesc::DOMXPathEvaluator& self, const STR expression, const xercesc::DOMNode* contextNode, const xercesc::DOMXPathNSResolver* resolver, xercesc::DOMXPathResult::ResultType type, xercesc::DOMXPathResult* result) {
	XMLString buff(expression);
	return self.evaluate(buff.ptr(), contextNode, resolver, type, result);
}

};

class DOMXPathEvaluatorWrapper
: public xercesc::DOMXPathEvaluator, public boost::python::wrapper<xercesc::DOMXPathEvaluator>
{
public:
xercesc::DOMXPathExpression* createExpression(const XMLCh *expression, const xercesc::DOMXPathNSResolver *resolver) {
	return this->get_override("createExpression")(XMLString(expression), boost::python::ptr(resolver));
}

xercesc::DOMXPathNSResolver* createNSResolver(const xercesc::DOMNode *nodeResolver) {
	return this->get_override("createNSResolver")(boost::python::ptr(nodeResolver));
}

xercesc::DOMXPathResult* evaluate(const XMLCh *expression, const xercesc::DOMNode *contextNode, const xercesc::DOMXPathNSResolver *resolver, xercesc::DOMXPathResult::ResultType type, xercesc::DOMXPathResult* result) {
	return this->get_override("evaluate")(XMLString(expression), boost::python::ptr(contextNode), boost::python::ptr(resolver), type, boost::python::ptr(result));
}

};

void DOMXPathEvaluator_init(void) {
	//! xercesc::DOMXPathEvaluator
	boost::python::class_<DOMXPathEvaluatorWrapper, boost::noncopyable>("DOMXPathEvaluator")
			.def(DOMXPathEvaluatorDefVisitor<XMLString&>())
			.def(DOMXPathEvaluatorDefVisitor<char*>())
			.def("createExpression", boost::python::pure_virtual(&xercesc::DOMXPathEvaluator::createExpression), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createNSResolver", boost::python::pure_virtual(&xercesc::DOMXPathEvaluator::createNSResolver), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("evaluate", boost::python::pure_virtual(&xercesc::DOMXPathEvaluator::evaluate), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
