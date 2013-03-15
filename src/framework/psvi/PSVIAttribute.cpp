/*
 * PSVIAttribute.cpp
 *
 *  Created on: 2013/03/14
 *      Author: mugwort_rc
 */

#include "PSVIAttribute.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAttributeDeclaration.hpp>

#include <xercesc/framework/psvi/PSVIAttribute.hpp>

#include "../../util/XMLString.h"

namespace pyxerces {

template <class STR>
class PSVIAttributeDefVisitor
: public boost::python::def_visitor<PSVIAttributeDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("reset", &PSVIAttributeDefVisitor<STR>::reset)
	;
}

static void reset(xercesc::PSVIAttribute& self, const STR& valContext, const xercesc::PSVIItem::VALIDITY_STATE state, const xercesc::PSVIItem::ASSESSMENT_TYPE assessmentType, xercesc::XSSimpleTypeDefinition* validatingType, xercesc::XSSimpleTypeDefinition* memberType, const STR& defaultValue, const bool isSpecified, xercesc::XSAttributeDeclaration* attrDecl, xercesc::DatatypeValidator* dv) {
	XMLString buff1(valContext), buff2(defaultValue);
	self.reset(buff1.ptr(), state, assessmentType, validatingType, memberType, buff2.ptr(), isSpecified, attrDecl, dv);
}

static void setValue(xercesc::PSVIAttribute& self, const STR& normalizedValue) {
	XMLString buff(normalizedValue);
	self.setValue(buff.ptr());
}

};

void PSVIAttribute_init(void) {
	//! xercesc::PSVIAttribute
	boost::python::class_<xercesc::PSVIAttribute, boost::noncopyable, boost::python::bases<xercesc::PSVIItem> >("PSVIAttribute", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(PSVIAttributeDefVisitor<XMLString>())
			.def(PSVIAttributeDefVisitor<std::string>())
			.def("getAttributeDeclaration", &xercesc::PSVIAttribute::getAttributeDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTypeDefinition", &xercesc::PSVIAttribute::getTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemberTypeDefinition", &xercesc::PSVIAttribute::getMemberTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("reset", &xercesc::PSVIAttribute::reset)
			.def("setValue", &xercesc::PSVIAttribute::setValue)
			.def("updateValidity", &xercesc::PSVIAttribute::updateValidity)
			;
}

} /* namespace pyxerces */
