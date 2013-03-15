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

template <class STR>
class PSVIElementDefVisitor
: public boost::python::def_visitor<PSVIElementDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("reset", static_cast<void(*)(xercesc::PSVIElement&, const xercesc::PSVIItem::VALIDITY_STATE, const xercesc::PSVIItem::ASSESSMENT_TYPE, const STR&, bool, xercesc::XSElementDeclaration* const, xercesc::XSTypeDefinition* const, xercesc::XSSimpleTypeDefinition* const, xercesc::XSModel* const, const STR&, const STR&, STR&, xercesc::XSNotationDeclaration* const)>(&PSVIElementDefVisitor<STR>::reset))
	.def("reset", static_cast<void(*)(xercesc::PSVIElement&, const xercesc::PSVIItem::VALIDITY_STATE, const xercesc::PSVIItem::ASSESSMENT_TYPE, const STR&, bool, xercesc::XSElementDeclaration* const, xercesc::XSTypeDefinition* const, xercesc::XSSimpleTypeDefinition* const, xercesc::XSModel* const, const STR&, const STR&, STR&)>(&PSVIElementDefVisitor<STR>::reset))
	.def("reset", static_cast<void(*)(xercesc::PSVIElement&, const xercesc::PSVIItem::VALIDITY_STATE, const xercesc::PSVIItem::ASSESSMENT_TYPE, const STR&, bool, xercesc::XSElementDeclaration* const, xercesc::XSTypeDefinition* const, xercesc::XSSimpleTypeDefinition* const, xercesc::XSModel* const, const STR&, const STR&)>(&PSVIElementDefVisitor<STR>::reset))
	.def("reset", static_cast<void(*)(xercesc::PSVIElement&, const xercesc::PSVIItem::VALIDITY_STATE, const xercesc::PSVIItem::ASSESSMENT_TYPE, const STR&, bool, xercesc::XSElementDeclaration* const, xercesc::XSTypeDefinition* const, xercesc::XSSimpleTypeDefinition* const, xercesc::XSModel* const, const STR&)>(&PSVIElementDefVisitor<STR>::reset))
	;
}

static void reset(xercesc::PSVIElement& self, const xercesc::PSVIItem::VALIDITY_STATE validityState, const xercesc::PSVIItem::ASSESSMENT_TYPE assessmentType, const STR& validationContext, bool isSpecified, xercesc::XSElementDeclaration* const elemDecl, xercesc::XSTypeDefinition* const typeDef, xercesc::XSSimpleTypeDefinition* const memberType, xercesc::XSModel* const schemaInfo, const STR& defaultValue, const STR& normalizedValue, STR& canonicalValue, xercesc::XSNotationDeclaration* const notationDecl) {
	XMLString buff1(validationContext), buff2(defaultValue), buff3(normalizedValue), buff4(canonicalValue);
	self.reset(validityState, assessmentType, buff1.ptr(), isSpecified, elemDecl, typeDef, memberType, schemaInfo, buff2.ptr(), buff3.ptr(), buff4.ptr(), notationDecl);
}

static void reset(xercesc::PSVIElement& self, const xercesc::PSVIItem::VALIDITY_STATE validityState, const xercesc::PSVIItem::ASSESSMENT_TYPE assessmentType, const STR& validationContext, bool isSpecified, xercesc::XSElementDeclaration* const elemDecl, xercesc::XSTypeDefinition* const typeDef, xercesc::XSSimpleTypeDefinition* const memberType, xercesc::XSModel* const schemaInfo, const STR& defaultValue, const STR& normalizedValue, STR& canonicalValue) {
	XMLString buff1(validationContext), buff2(defaultValue), buff3(normalizedValue), buff4(canonicalValue);
	self.reset(validityState, assessmentType, buff1.ptr(), isSpecified, elemDecl, typeDef, memberType, schemaInfo, buff2.ptr(), buff3.ptr(), buff4.ptr(), nullptr);
}

static void reset(xercesc::PSVIElement& self, const xercesc::PSVIItem::VALIDITY_STATE validityState, const xercesc::PSVIItem::ASSESSMENT_TYPE assessmentType, const STR& validationContext, bool isSpecified, xercesc::XSElementDeclaration* const elemDecl, xercesc::XSTypeDefinition* const typeDef, xercesc::XSSimpleTypeDefinition* const memberType, xercesc::XSModel* const schemaInfo, const STR& defaultValue, const STR& normalizedValue) {
	XMLString buff1(validationContext), buff2(defaultValue), buff3(normalizedValue);
	self.reset(validityState, assessmentType, buff1.ptr(), isSpecified, elemDecl, typeDef, memberType, schemaInfo, buff2.ptr(), buff3.ptr(), nullptr, nullptr);
}

static void reset(xercesc::PSVIElement& self, const xercesc::PSVIItem::VALIDITY_STATE validityState, const xercesc::PSVIItem::ASSESSMENT_TYPE assessmentType, const STR& validationContext, bool isSpecified, xercesc::XSElementDeclaration* const elemDecl, xercesc::XSTypeDefinition* const typeDef, xercesc::XSSimpleTypeDefinition* const memberType, xercesc::XSModel* const schemaInfo, const STR& defaultValue) {
	XMLString buff1(validationContext), buff2(defaultValue);
	self.reset(validityState, assessmentType, buff1.ptr(), isSpecified, elemDecl, typeDef, memberType, schemaInfo, buff2.ptr(), nullptr, nullptr, nullptr);
}

};

void PSVIElement_init(void) {
	//! xercesc::PSVIElement
	boost::python::class_<xercesc::PSVIElement, boost::noncopyable, boost::python::bases<xercesc::PSVIItem> >("PSVIElement", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(PSVIElementDefVisitor<XMLString>())
			.def(PSVIElementDefVisitor<std::string>())
			.def("getElementDeclaration", &xercesc::PSVIElement::getElementDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNotationDeclaration", &xercesc::PSVIElement::getNotationDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getSchemaInformation", &xercesc::PSVIElement::getSchemaInformation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTypeDefinition", &xercesc::PSVIElement::getTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemberTypeDefinition", &xercesc::PSVIElement::getMemberTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("reset", &xercesc::PSVIElement::reset)
			;
}

} /* namespace pyxerces */
