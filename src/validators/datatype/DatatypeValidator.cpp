/*
 * DatatypeValidator.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "DatatypeValidator.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/validators/datatype/DatatypeValidator.hpp>

#include "../../internal/XSerializable.h"
#include "../../util/XMLString.h"

namespace pyxerces {

class DatatypeValidatorDefVisitor
: public boost::python::def_visitor<DatatypeValidatorDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getCanonicalRepresentation", static_cast<const XMLCh*(*)(xercesc::DatatypeValidator&, const XMLString&, xercesc::MemoryManager*, bool)>(&DatatypeValidatorDefVisitor::getCanonicalRepresentation), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("getCanonicalRepresentation", static_cast<const XMLCh*(*)(xercesc::DatatypeValidator&, const XMLString&, xercesc::MemoryManager*)>(&DatatypeValidatorDefVisitor::getCanonicalRepresentation), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("getCanonicalRepresentation", static_cast<const XMLCh*(*)(xercesc::DatatypeValidator&, const XMLString&)>(&DatatypeValidatorDefVisitor::getCanonicalRepresentation), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("validate", static_cast<void(*)(xercesc::DatatypeValidator&, const XMLString&, xercesc::ValidationContext* const, xercesc::MemoryManager* const)>(&DatatypeValidatorDefVisitor::validate))
	.def("validate", static_cast<void(*)(xercesc::DatatypeValidator&, const XMLString&, xercesc::ValidationContext* const)>(&DatatypeValidatorDefVisitor::validate))
	.def("validate", static_cast<void(*)(xercesc::DatatypeValidator&, const XMLString&)>(&DatatypeValidatorDefVisitor::validate))
	.def("compare", static_cast<int(*)(xercesc::DatatypeValidator&, const XMLString&, const XMLString&, xercesc::MemoryManager* const)>(&DatatypeValidatorDefVisitor::compare))
	.def("compare", static_cast<int(*)(xercesc::DatatypeValidator&, const XMLString&, const XMLString&)>(&DatatypeValidatorDefVisitor::compare))
	.def("setTypeName", static_cast<void(*)(xercesc::DatatypeValidator&, const XMLString&)>(&DatatypeValidatorDefVisitor::setTypeName))
	.def("setTypeName", static_cast<void(*)(xercesc::DatatypeValidator&, const XMLString&, const XMLString&)>(&DatatypeValidatorDefVisitor::setTypeName))
	;
}

static const XMLCh* getCanonicalRepresentation(xercesc::DatatypeValidator& self, const XMLString& rawData, xercesc::MemoryManager* const memMgr, bool toValidate) {
	return self.getCanonicalRepresentation(rawData.ptr(), memMgr, toValidate);
}

static const XMLCh* getCanonicalRepresentation(xercesc::DatatypeValidator& self, const XMLString& rawData, xercesc::MemoryManager* const memMgr) {
	return DatatypeValidatorDefVisitor::getCanonicalRepresentation(self, rawData, memMgr, false);
}

static const XMLCh* getCanonicalRepresentation(xercesc::DatatypeValidator& self, const XMLString& rawData) {
	return DatatypeValidatorDefVisitor::getCanonicalRepresentation(self, rawData, nullptr);
}

static void validate(xercesc::DatatypeValidator& self, const XMLString& content, xercesc::ValidationContext* const context, xercesc::MemoryManager* const manager) {
	self.validate(content.ptr(), context, manager);
}

static void validate(xercesc::DatatypeValidator& self, const XMLString& content, xercesc::ValidationContext* const context) {
	DatatypeValidatorDefVisitor::validate(self, content, context, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static void validate(xercesc::DatatypeValidator& self, const XMLString& content) {
	DatatypeValidatorDefVisitor::validate(self, content, nullptr);
}

static int compare(xercesc::DatatypeValidator& self, const XMLString& value1, const XMLString& value2, xercesc::MemoryManager* const manager) {
	return self.compare(value1.ptr(), value2.ptr(), manager);
}

static int compare(xercesc::DatatypeValidator& self, const XMLString& value1, const XMLString& value2) {
	return DatatypeValidatorDefVisitor::compare(self, value1, value2, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static void setTypeName(xercesc::DatatypeValidator& self, const XMLString& typeName) {
	self.setTypeName(typeName.ptr());
}

static void setTypeName(xercesc::DatatypeValidator& self, const XMLString& name, const XMLString& uri) {
	self.setTypeName(name.ptr(), uri.ptr());
}

};

class DatatypeValidatorWrapper
: public xercesc::DatatypeValidator, public boost::python::wrapper<xercesc::DatatypeValidator>
{
public:
const xercesc::RefArrayVectorOf<XMLCh>* getEnumString(void) const {
	return this->get_override("getEnumString")();
}

void validate(const XMLCh* const content, xercesc::ValidationContext* const context = nullptr, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	this->get_override("validate")(XMLString(content), boost::python::ptr(context), boost::python::ptr(manager));
}

DatatypeValidator* newInstance(xercesc::RefHashTableOf<xercesc::KVStringPair>* const facets, xercesc::RefArrayVectorOf<XMLCh>* const enums, const int finalSet, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	return this->get_override("newInstance")(boost::python::ptr(facets), boost::python::ptr(enums), finalSet, boost::python::ptr(manager));
}

};

void DatatypeValidator_init(void) {
	//! xercesc::DatatypeValidator
	auto DatatypeValidator = boost::python::class_<xercesc::DatatypeValidator, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("DatatypeValidator", boost::python::no_init)
			.def(DatatypeValidatorDefVisitor())
			.def("getFinalSet", &xercesc::DatatypeValidator::getFinalSet)
			.def("getFacets", &xercesc::DatatypeValidator::getFacets, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getWSFacet", &xercesc::DatatypeValidator::getWSFacet)
			.def("getBaseValidator", &xercesc::DatatypeValidator::getBaseValidator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getType", &xercesc::DatatypeValidator::getType)
			.def("isAtomic", &xercesc::DatatypeValidator::isAtomic)
			.def("getEnumString", boost::python::pure_virtual(&xercesc::DatatypeValidator::getEnumString), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAnonymous", &xercesc::DatatypeValidator::getAnonymous)
			.def("setAnonymous", &xercesc::DatatypeValidator::setAnonymous)
			.def("getOrdered", &xercesc::DatatypeValidator::getOrdered)
			.def("getFinite", &xercesc::DatatypeValidator::getFinite)
			.def("getBounded", &xercesc::DatatypeValidator::getBounded)
			.def("getNumeric", &xercesc::DatatypeValidator::getNumeric)
			.def("getCanonicalRepresentation", &xercesc::DatatypeValidator::getCanonicalRepresentation, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("validate", boost::python::pure_virtual(&xercesc::DatatypeValidator::validate))
			.def("isSubstitutableBy", &xercesc::DatatypeValidator::isSubstitutableBy)
			.def("compare", &xercesc::DatatypeValidator::compare)
			.def("newInstance", boost::python::pure_virtual(&xercesc::DatatypeValidator::newInstance), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTypeName", &xercesc::DatatypeValidator::getTypeName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setTypeName", static_cast<void(xercesc::DatatypeValidator::*)(const XMLCh* const)>(&xercesc::DatatypeValidator::setTypeName))
			.def("setTypeName", static_cast<void(xercesc::DatatypeValidator::*)(const XMLCh* const, const XMLCh* const)>(&xercesc::DatatypeValidator::setTypeName))
			.def("getTypeUri", &xercesc::DatatypeValidator::getTypeUri, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getTypeLocalName", &xercesc::DatatypeValidator::getTypeLocalName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getMemoryManager", &xercesc::DatatypeValidator::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			PyDECL_XSERIALIZABLE(DatatypeValidator)
			.def("storeDV", &xercesc::DatatypeValidator::storeDV)
			.def("loadDV", &xercesc::DatatypeValidator::loadDV, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.staticmethod("storeDV")
			.staticmethod("loadDV")
			;
	boost::python::scope DatatypeValidatorScope = DatatypeValidator;
	//! xercesc::DatatypeValidator::ValidatorType
}

} /* namespace pyxerces */
