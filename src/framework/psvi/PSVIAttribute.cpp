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

class PSVIAttributeDefVisitor
: public boost::python::def_visitor<PSVIAttributeDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("reset", &PSVIAttributeDefVisitor::reset)
	.def("setValue", &PSVIAttributeDefVisitor::setValue)
	;
}

static void reset(xercesc::PSVIAttribute& self, const XMLString& valContext, const xercesc::PSVIItem::VALIDITY_STATE state, const xercesc::PSVIItem::ASSESSMENT_TYPE assessmentType, xercesc::XSSimpleTypeDefinition* validatingType, xercesc::XSSimpleTypeDefinition* memberType, const XMLString& defaultValue, const bool isSpecified, xercesc::XSAttributeDeclaration* attrDecl, xercesc::DatatypeValidator* dv) {
	self.reset(valContext.ptr(), state, assessmentType, validatingType, memberType, defaultValue.ptr(), isSpecified, attrDecl, dv);
}

static void setValue(xercesc::PSVIAttribute& self, const XMLString& normalizedValue) {
	self.setValue(normalizedValue.ptr());
}

};

void PSVIAttribute_init(void) {
	//! xercesc::PSVIAttribute
	boost::python::class_<xercesc::PSVIAttribute, boost::noncopyable, boost::python::bases<xercesc::PSVIItem> >("PSVIAttribute", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(PSVIAttributeDefVisitor())
			.def("getAttributeDeclaration", &xercesc::PSVIAttribute::getAttributeDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTypeDefinition", &xercesc::PSVIAttribute::getTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemberTypeDefinition", &xercesc::PSVIAttribute::getMemberTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("reset", &xercesc::PSVIAttribute::reset)
			.def("setValue", &xercesc::PSVIAttribute::setValue)
			.def("updateValidity", &xercesc::PSVIAttribute::updateValidity)
			;
}

} /* namespace pyxerces */
