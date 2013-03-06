/*
 * XPathMatcher.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XPathMatcher.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/XMLElementDecl.hpp>
#include <xercesc/validators/schema/identity/XercesXPath.hpp>
#include <xercesc/validators/schema/identity/IdentityConstraint.hpp>
#include <xercesc/validators/datatype/DatatypeValidator.hpp>
#include <xercesc/util/StringPool.hpp>
#include <xercesc/framework/XMLAttr.hpp>
#include <xercesc/util/QName.hpp>
#include <xercesc/framework/ValidationContext.hpp>

#include <xercesc/validators/schema/identity/XPathMatcher.hpp>

#include "../../../util/XMLString.h"

namespace pyxerces {

template <class STR>
class XPathMatcherDefVisitor
: public boost::python::def_visitor<XPathMatcherDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("startElement", static_cast<void(*)(xercesc::XPathMatcher&, const xercesc::XMLElementDecl&, const unsigned int, const STR&, const xercesc::RefVectorOf<xercesc::XMLAttr>&, const XMLSize_t, xercesc::ValidationContext*)>(&XPathMatcherDefVisitor<STR>::startElement))
	.def("startElement", static_cast<void(*)(xercesc::XPathMatcher&, const xercesc::XMLElementDecl&, const unsigned int, const STR&, const xercesc::RefVectorOf<xercesc::XMLAttr>&, const XMLSize_t)>(&XPathMatcherDefVisitor<STR>::startElement))
	.def("endElement", static_cast<void(*)(xercesc::XPathMatcher&, const xercesc::XMLElementDecl&, const STR&, xercesc::ValidationContext*, xercesc::DatatypeValidator*)>(&XPathMatcherDefVisitor<STR>::endElement))
	.def("endElement", static_cast<void(*)(xercesc::XPathMatcher&, const xercesc::XMLElementDecl&, const STR&, xercesc::ValidationContext*)>(&XPathMatcherDefVisitor<STR>::endElement))
	.def("endElement", static_cast<void(*)(xercesc::XPathMatcher&, const xercesc::XMLElementDecl&, const STR&)>(&XPathMatcherDefVisitor<STR>::endElement))
	;
}

static void startElement(xercesc::XPathMatcher& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int urlId, const STR& elemPrefix, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, xercesc::ValidationContext* validationContext) {
	XMLString buff(elemPrefix);
	self.startElement(elemDecl, urlId, buff.ptr(), attrList, attrCount, validationContext);
}

static void startElement(xercesc::XPathMatcher& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int urlId, const STR& elemPrefix, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount) {
	XPathMatcherDefVisitor<STR>::startElement(self, elemDecl, urlId, elemPrefix, attrList, attrCount, nullptr);
}

static void endElement(xercesc::XPathMatcher& self, const xercesc::XMLElementDecl& elemDecl, const STR& elemContent, xercesc::ValidationContext* validationContext, xercesc::DatatypeValidator* actualValidator) {
	XMLString buff(elemContent);
	self.endElement(elemDecl, buff.ptr(), validationContext, actualValidator);
}

static void endElement(xercesc::XPathMatcher& self, const xercesc::XMLElementDecl& elemDecl, const STR& elemContent, xercesc::ValidationContext* validationContext) {
	XPathMatcherDefVisitor<STR>::endElement(self, elemDecl, elemContent, validationContext, nullptr);
}

static void endElement(xercesc::XPathMatcher& self, const xercesc::XMLElementDecl& elemDecl, const STR& elemContent) {
	XPathMatcherDefVisitor<STR>::endElement(self, elemDecl, elemContent, nullptr);
}

};

//! XPathMatcher
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XPathMatcherStartElementOverloads, startElement, 5, 6)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XPathMatcherEndElementOverloads, endElement, 2, 4)

void XPathMatcher_init(void) {
	//! xercesc::XPathMatcher
	boost::python::class_<xercesc::XPathMatcher, boost::noncopyable>("XPathMatcher", boost::python::init<xercesc::XercesXPath* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<xercesc::XercesXPath* const, xercesc::IdentityConstraint* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(XPathMatcherDefVisitor<XMLString>())
			.def(XPathMatcherDefVisitor<std::string>())
			.def("getIdentityConstraint", &xercesc::XPathMatcher::getIdentityConstraint, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemoryManager", &xercesc::XPathMatcher::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isMatched", &xercesc::XPathMatcher::isMatched)
			.def("getInitialDepth", &xercesc::XPathMatcher::getInitialDepth)
			.def("startDocumentFragment", &xercesc::XPathMatcher::startDocumentFragment)
			.def("startElement", &xercesc::XPathMatcher::startElement, XPathMatcherStartElementOverloads())
			.def("endElement", &xercesc::XPathMatcher::endElement, XPathMatcherEndElementOverloads())
			.setattr("XP_MATCHED", static_cast<int>(xercesc::XPathMatcher::XP_MATCHED))
			.setattr("XP_MATCHED_A", static_cast<int>(xercesc::XPathMatcher::XP_MATCHED_A))
			.setattr("XP_MATCHED_D", static_cast<int>(xercesc::XPathMatcher::XP_MATCHED_D))
			.setattr("XP_MATCHED_DP", static_cast<int>(xercesc::XPathMatcher::XP_MATCHED_DP))
			;
}

} /* namespace pyxerces */
