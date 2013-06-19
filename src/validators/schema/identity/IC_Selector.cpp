/*
 * IC_Selector.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "IC_Selector.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/schema/identity/FieldActivator.hpp>
#include <xercesc/framework/XMLElementDecl.hpp>
#include <xercesc/validators/datatype/DatatypeValidator.hpp>
#include <xercesc/framework/ValidationContext.hpp>
#include <xercesc/validators/schema/identity/IdentityConstraint.hpp>
#include <xercesc/validators/schema/identity/XercesXPath.hpp>

#include <xercesc/validators/schema/identity/IC_Selector.hpp>

#include "../../../internal/XSerializable.h"
#include "../../../util/XMLString.h"

namespace pyxerces {

class SelectorMatcherDefVisitor
: public boost::python::def_visitor<SelectorMatcherDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("startElement", static_cast<void(*)(xercesc::SelectorMatcher&, const xercesc::XMLElementDecl&, const unsigned int, const XMLString&, const xercesc::RefVectorOf<xercesc::XMLAttr>&, const XMLSize_t, xercesc::ValidationContext*)>(&SelectorMatcherDefVisitor::startElement))
	.def("startElement", static_cast<void(*)(xercesc::SelectorMatcher&, const xercesc::XMLElementDecl&, const unsigned int, const XMLString&, const xercesc::RefVectorOf<xercesc::XMLAttr>&, const XMLSize_t)>(&SelectorMatcherDefVisitor::startElement))
	.def("endElement", static_cast<void(*)(xercesc::SelectorMatcher&, const xercesc::XMLElementDecl&, const XMLString&, xercesc::ValidationContext*, xercesc::DatatypeValidator*)>(&SelectorMatcherDefVisitor::endElement))
	.def("endElement", static_cast<void(*)(xercesc::SelectorMatcher&, const xercesc::XMLElementDecl&, const XMLString&, xercesc::ValidationContext*)>(&SelectorMatcherDefVisitor::endElement))
	.def("endElement", static_cast<void(*)(xercesc::SelectorMatcher&, const xercesc::XMLElementDecl&, const XMLString&)>(&SelectorMatcherDefVisitor::endElement))
	;
}

static void startElement(xercesc::SelectorMatcher& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int urlId, const XMLString& elemPrefix, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, xercesc::ValidationContext* validationContext) {
	self.startElement(elemDecl, urlId, elemPrefix.ptr(), attrList, attrCount, validationContext);
}

static void startElement(xercesc::SelectorMatcher& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int urlId, const XMLString& elemPrefix, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount) {
	SelectorMatcherDefVisitor::startElement(self, elemDecl, urlId, elemPrefix, attrList, attrCount, nullptr);
}

static void endElement(xercesc::SelectorMatcher& self, const xercesc::XMLElementDecl& elemDecl, const XMLString& elemContent, xercesc::ValidationContext* validationContext, xercesc::DatatypeValidator* actualValidator) {
	self.endElement(elemDecl, elemContent.ptr(), validationContext, actualValidator);
}

static void endElement(xercesc::SelectorMatcher& self, const xercesc::XMLElementDecl& elemDecl, const XMLString& elemContent, xercesc::ValidationContext* validationContext) {
	SelectorMatcherDefVisitor::endElement(self, elemDecl, elemContent, validationContext, nullptr);
}

static void endElement(xercesc::SelectorMatcher& self, const xercesc::XMLElementDecl& elemDecl, const XMLString& elemContent) {
	SelectorMatcherDefVisitor::endElement(self, elemDecl, elemContent, nullptr);
}

};

//! IC_Selector
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(IC_SelectorCreateMatcherOverloads, createMatcher, 2, 3)

//! SelectorMatcher
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SelectorMatcherStartElementOverloads, startElement, 5, 6)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SelectorMatcherEndElementOverloads, endElement, 2, 4)

void IC_Selector_init(void) {
	//! xercesc::IC_Selector
	boost::python::class_<xercesc::IC_Selector, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("IC_Selector", boost::python::init<xercesc::XercesXPath* const, xercesc::IdentityConstraint* const>())
			.def(boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def("__eq__", &xercesc::IC_Selector::operator ==)
			.def("__ne__", &xercesc::IC_Selector::operator !=)
			.def("getXPath", &xercesc::IC_Selector::getXPath, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getIdentityConstraint", &xercesc::IC_Selector::getIdentityConstraint, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createMatcher", &xercesc::IC_Selector::createMatcher, IC_SelectorCreateMatcherOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			PyDECL_XSERIALIZABLE(IC_Selector)
			;
	//! xercesc::SelectorMatcher
	boost::python::class_<xercesc::SelectorMatcher, boost::noncopyable, boost::python::bases<xercesc::XPathMatcher> >("SelectorMatcher", boost::python::no_init)
			.def(SelectorMatcherDefVisitor())
			.def("getInitialDepth", &xercesc::SelectorMatcher::getInitialDepth)
			.def("startDocumentFragment", &xercesc::SelectorMatcher::startDocumentFragment)
			.def("startElement", &xercesc::SelectorMatcher::startElement, SelectorMatcherStartElementOverloads())
			.def("endElement", &xercesc::SelectorMatcher::endElement, SelectorMatcherEndElementOverloads())
			;
}

} /* namespace pyxerces */
