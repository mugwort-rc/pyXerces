/*
 * PSVIItem.cpp
 *
 *  Created on: 2013/03/14
 *      Author: mugwort_rc
 */

#include "PSVIItem.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSValue.hpp>

#include <xercesc/framework/psvi/PSVIItem.hpp>

#include "../../util/XMLString.h"

namespace pyxerces {

template <class STR>
class PSVIItemDefVisitor
: public boost::python::def_visitor<PSVIItemDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("reset", &PSVIItemDefVisitor<STR>::reset)
	;
}

static void reset(xercesc::PSVIItem& self, const STR& validationContext, const STR& normalizedValue, const xercesc::PSVIItem::VALIDITY_STATE validityState, const xercesc::PSVIItem::ASSESSMENT_TYPE assessmentType) {
	XMLString buff1(validationContext), buff2(normalizedValue);
	self.reset(buff1.ptr(), buff2.ptr(), validityState, assessmentType);
}

};

class PSVIItemWrapper
: public xercesc::PSVIItem, public boost::python::wrapper<xercesc::PSVIItem>
{
public:
PSVIItemWrapper(xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::PSVIItem(manager)
{}

~PSVIItemWrapper()
{}

xercesc::XSTypeDefinition *getTypeDefinition() {
	return this->get_override("getTypeDefinition")();
}

xercesc::XSSimpleTypeDefinition *getMemberTypeDefinition() {
	return this->get_override("getMemberTypeDefinition")();
}

};

void PSVIItem_init(void) {
	//! xercesc::PSVIItem
	auto PSVIItem = boost::python::class_<PSVIItemWrapper, boost::noncopyable>("PSVIItem", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(PSVIItemDefVisitor<XMLString>())
			.def(PSVIItemDefVisitor<std::string>())
			.def("getValidationContext", &xercesc::PSVIItem::getValidationContext, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getValidity", &xercesc::PSVIItem::getValidity)
			.def("getValidationAttempted", &xercesc::PSVIItem::getValidationAttempted)
			.def("getSchemaNormalizedValue", &xercesc::PSVIItem::getSchemaNormalizedValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getTypeDefinition", &xercesc::PSVIItem::getTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemberTypeDefinition", &xercesc::PSVIItem::getMemberTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getSchemaDefault", &xercesc::PSVIItem::getSchemaDefault, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getIsSchemaSpecified", &xercesc::PSVIItem::getIsSchemaSpecified)
			.def("getCanonicalRepresentation", &xercesc::PSVIItem::getCanonicalRepresentation, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getActualValue", &xercesc::PSVIItem::getActualValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setValidationAttempted", &xercesc::PSVIItem::setValidationAttempted)
			.def("setValidity", &xercesc::PSVIItem::setValidity)
			.def("reset", &xercesc::PSVIItem::reset)
			;
	boost::python::scope PSVIItemScope = PSVIItem;
	//! xercesc::PSVIItem::VALIDITY_STATE
	boost::python::enum_<xercesc::PSVIItem::VALIDITY_STATE>("VALIDITY_STATE")
			.value("VALIDITY_NOTKNOWN", xercesc::PSVIItem::VALIDITY_NOTKNOWN)
			.value("VALIDITY_INVALID", xercesc::PSVIItem::VALIDITY_INVALID)
			.value("VALIDITY_VALID", xercesc::PSVIItem::VALIDITY_VALID)
			.export_values()
			;
	//! xercesc::PSVIItem::ASSESSMENT_TYPE
	boost::python::enum_<xercesc::PSVIItem::ASSESSMENT_TYPE>("ASSESSMENT_TYPE")
			.value("VALIDATION_NONE", xercesc::PSVIItem::VALIDATION_NONE)
			.value("VALIDATION_PARTIAL", xercesc::PSVIItem::VALIDATION_PARTIAL)
			.value("VALIDATION_FULL", xercesc::PSVIItem::VALIDATION_FULL)
			.export_values()
			;
}

} /* namespace pyxerces */
