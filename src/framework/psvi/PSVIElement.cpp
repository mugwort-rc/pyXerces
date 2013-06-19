/*
 * PSVIElement.cpp
 *
 *  Created on: 2013/03/15
 *      Author: mugwort_rc
 */

#include "PSVIElement.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSElementDeclaration.hpp>
#include <xercesc/framework/psvi/XSNotationDeclaration.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/PSVIElement.hpp>

#include "../../util/XMLString.h"

namespace pyxerces {

class PSVIElementDefVisitor
: public boost::python::def_visitor<PSVIElementDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("reset", static_cast<void(*)(xercesc::PSVIElement&, const xercesc::PSVIItem::VALIDITY_STATE, const xercesc::PSVIItem::ASSESSMENT_TYPE, const XMLString&, bool, xercesc::XSElementDeclaration* const, xercesc::XSTypeDefinition* const, xercesc::XSSimpleTypeDefinition* const, xercesc::XSModel* const, const XMLString&, const XMLString&, const XMLString&, xercesc::XSNotationDeclaration* const)>(&PSVIElementDefVisitor::reset))
	.def("reset", static_cast<void(*)(xercesc::PSVIElement&, const xercesc::PSVIItem::VALIDITY_STATE, const xercesc::PSVIItem::ASSESSMENT_TYPE, const XMLString&, bool, xercesc::XSElementDeclaration* const, xercesc::XSTypeDefinition* const, xercesc::XSSimpleTypeDefinition* const, xercesc::XSModel* const, const XMLString&, const XMLString&, const XMLString&)>(&PSVIElementDefVisitor::reset))
	.def("reset", static_cast<void(*)(xercesc::PSVIElement&, const xercesc::PSVIItem::VALIDITY_STATE, const xercesc::PSVIItem::ASSESSMENT_TYPE, const XMLString&, bool, xercesc::XSElementDeclaration* const, xercesc::XSTypeDefinition* const, xercesc::XSSimpleTypeDefinition* const, xercesc::XSModel* const, const XMLString&, const XMLString&)>(&PSVIElementDefVisitor::reset))
	.def("reset", static_cast<void(*)(xercesc::PSVIElement&, const xercesc::PSVIItem::VALIDITY_STATE, const xercesc::PSVIItem::ASSESSMENT_TYPE, const XMLString&, bool, xercesc::XSElementDeclaration* const, xercesc::XSTypeDefinition* const, xercesc::XSSimpleTypeDefinition* const, xercesc::XSModel* const, const XMLString&)>(&PSVIElementDefVisitor::reset))
	;
}

static void reset(xercesc::PSVIElement& self, const xercesc::PSVIItem::VALIDITY_STATE validityState, const xercesc::PSVIItem::ASSESSMENT_TYPE assessmentType, const XMLString& validationContext, bool isSpecified, xercesc::XSElementDeclaration* const elemDecl, xercesc::XSTypeDefinition* const typeDef, xercesc::XSSimpleTypeDefinition* const memberType, xercesc::XSModel* const schemaInfo, const XMLString& defaultValue, const XMLString& normalizedValue, const XMLString& canonicalValue, xercesc::XSNotationDeclaration* const notationDecl) {
	self.reset(validityState, assessmentType, validationContext.ptr(), isSpecified, elemDecl, typeDef, memberType, schemaInfo, defaultValue.ptr(), normalizedValue.ptr(), canonicalValue.ptr(), notationDecl);
}

static void reset(xercesc::PSVIElement& self, const xercesc::PSVIItem::VALIDITY_STATE validityState, const xercesc::PSVIItem::ASSESSMENT_TYPE assessmentType, const XMLString& validationContext, bool isSpecified, xercesc::XSElementDeclaration* const elemDecl, xercesc::XSTypeDefinition* const typeDef, xercesc::XSSimpleTypeDefinition* const memberType, xercesc::XSModel* const schemaInfo, const XMLString& defaultValue, const XMLString& normalizedValue, const XMLString& canonicalValue) {
	self.reset(validityState, assessmentType, validationContext.ptr(), isSpecified, elemDecl, typeDef, memberType, schemaInfo, defaultValue.ptr(), normalizedValue.ptr(), canonicalValue.ptr(), nullptr);
}

static void reset(xercesc::PSVIElement& self, const xercesc::PSVIItem::VALIDITY_STATE validityState, const xercesc::PSVIItem::ASSESSMENT_TYPE assessmentType, const XMLString& validationContext, bool isSpecified, xercesc::XSElementDeclaration* const elemDecl, xercesc::XSTypeDefinition* const typeDef, xercesc::XSSimpleTypeDefinition* const memberType, xercesc::XSModel* const schemaInfo, const XMLString& defaultValue, const XMLString& normalizedValue) {
	self.reset(validityState, assessmentType, validationContext.ptr(), isSpecified, elemDecl, typeDef, memberType, schemaInfo, defaultValue.ptr(), normalizedValue.ptr(), nullptr, nullptr);
}

static void reset(xercesc::PSVIElement& self, const xercesc::PSVIItem::VALIDITY_STATE validityState, const xercesc::PSVIItem::ASSESSMENT_TYPE assessmentType, const XMLString& validationContext, bool isSpecified, xercesc::XSElementDeclaration* const elemDecl, xercesc::XSTypeDefinition* const typeDef, xercesc::XSSimpleTypeDefinition* const memberType, xercesc::XSModel* const schemaInfo, const XMLString& defaultValue) {
	self.reset(validityState, assessmentType, validationContext.ptr(), isSpecified, elemDecl, typeDef, memberType, schemaInfo, defaultValue.ptr(), nullptr, nullptr, nullptr);
}

};

void PSVIElement_init(void) {
	//! xercesc::PSVIElement
	boost::python::class_<xercesc::PSVIElement, boost::noncopyable, boost::python::bases<xercesc::PSVIItem> >("PSVIElement", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(PSVIElementDefVisitor())
			.def("getElementDeclaration", &xercesc::PSVIElement::getElementDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNotationDeclaration", &xercesc::PSVIElement::getNotationDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getSchemaInformation", &xercesc::PSVIElement::getSchemaInformation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTypeDefinition", &xercesc::PSVIElement::getTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemberTypeDefinition", &xercesc::PSVIElement::getMemberTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("reset", &xercesc::PSVIElement::reset)
			;
}

} /* namespace pyxerces */
