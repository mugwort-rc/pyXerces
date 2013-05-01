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

template <typename STR>
class SelectorMatcherDefVisitor
: public boost::python::def_visitor<SelectorMatcherDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("startElement", static_cast<void(*)(xercesc::SelectorMatcher&, const xercesc::XMLElementDecl&, const unsigned int, const STR, const xercesc::RefVectorOf<xercesc::XMLAttr>&, const XMLSize_t, xercesc::ValidationContext*)>(&SelectorMatcherDefVisitor<STR>::startElement))
	.def("startElement", static_cast<void(*)(xercesc::SelectorMatcher&, const xercesc::XMLElementDecl&, const unsigned int, const STR, const xercesc::RefVectorOf<xercesc::XMLAttr>&, const XMLSize_t)>(&SelectorMatcherDefVisitor<STR>::startElement))
	.def("endElement", static_cast<void(*)(xercesc::SelectorMatcher&, const xercesc::XMLElementDecl&, const STR, xercesc::ValidationContext*, xercesc::DatatypeValidator*)>(&SelectorMatcherDefVisitor<STR>::endElement))
	.def("endElement", static_cast<void(*)(xercesc::SelectorMatcher&, const xercesc::XMLElementDecl&, const STR, xercesc::ValidationContext*)>(&SelectorMatcherDefVisitor<STR>::endElement))
	.def("endElement", static_cast<void(*)(xercesc::SelectorMatcher&, const xercesc::XMLElementDecl&, const STR)>(&SelectorMatcherDefVisitor<STR>::endElement))
	;
}

static void startElement(xercesc::SelectorMatcher& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int urlId, const STR elemPrefix, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, xercesc::ValidationContext* validationContext) {
	XMLString buff(elemPrefix);
	self.startElement(elemDecl, urlId, buff.ptr(), attrList, attrCount, validationContext);
}

static void startElement(xercesc::SelectorMatcher& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int urlId, const STR elemPrefix, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount) {
	SelectorMatcherDefVisitor<STR>::startElement(self, elemDecl, urlId, elemPrefix, attrList, attrCount, nullptr);
}

static void endElement(xercesc::SelectorMatcher& self, const xercesc::XMLElementDecl& elemDecl, const STR elemContent, xercesc::ValidationContext* validationContext, xercesc::DatatypeValidator* actualValidator) {
	XMLString buff(elemContent);
	self.endElement(elemDecl, buff.ptr(), validationContext, actualValidator);
}

static void endElement(xercesc::SelectorMatcher& self, const xercesc::XMLElementDecl& elemDecl, const STR elemContent, xercesc::ValidationContext* validationContext) {
	SelectorMatcherDefVisitor<STR>::endElement(self, elemDecl, elemContent, validationContext, nullptr);
}

static void endElement(xercesc::SelectorMatcher& self, const xercesc::XMLElementDecl& elemDecl, const STR elemContent) {
	SelectorMatcherDefVisitor<STR>::endElement(self, elemDecl, elemContent, nullptr);
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
			.def(SelectorMatcherDefVisitor<XMLString&>())
			.def(SelectorMatcherDefVisitor<char*>())
			.def("getInitialDepth", &xercesc::SelectorMatcher::getInitialDepth)
			.def("startDocumentFragment", &xercesc::SelectorMatcher::startDocumentFragment)
			.def("startElement", &xercesc::SelectorMatcher::startElement, SelectorMatcherStartElementOverloads())
			.def("endElement", &xercesc::SelectorMatcher::endElement, SelectorMatcherEndElementOverloads())
			;
}

} /* namespace pyxerces */
