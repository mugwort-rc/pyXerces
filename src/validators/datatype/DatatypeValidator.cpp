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

template <class STR>
class DatatypeValidatorDefVisitor
: public boost::python::def_visitor<DatatypeValidatorDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getCanonicalRepresentation", static_cast<const XMLCh*(*)(xercesc::DatatypeValidator&, const STR&, xercesc::MemoryManager*, bool)>(&DatatypeValidatorDefVisitor<STR>::getCanonicalRepresentation), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("getCanonicalRepresentation", static_cast<const XMLCh*(*)(xercesc::DatatypeValidator&, const STR&, xercesc::MemoryManager*)>(&DatatypeValidatorDefVisitor<STR>::getCanonicalRepresentation), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("getCanonicalRepresentation", static_cast<const XMLCh*(*)(xercesc::DatatypeValidator&, const STR&)>(&DatatypeValidatorDefVisitor<STR>::getCanonicalRepresentation), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("validate", static_cast<void(*)(xercesc::DatatypeValidator&, const STR&, xercesc::ValidationContext* const, xercesc::MemoryManager* const)>(&DatatypeValidatorDefVisitor<STR>::validate))
	.def("validate", static_cast<void(*)(xercesc::DatatypeValidator&, const STR&, xercesc::ValidationContext* const)>(&DatatypeValidatorDefVisitor<STR>::validate))
	.def("validate", static_cast<void(*)(xercesc::DatatypeValidator&, const STR&)>(&DatatypeValidatorDefVisitor<STR>::validate))
	.def("compare", static_cast<int(*)(xercesc::DatatypeValidator&, const STR&, const STR&, xercesc::MemoryManager* const)>(&DatatypeValidatorDefVisitor<STR>::compare))
	.def("compare", static_cast<int(*)(xercesc::DatatypeValidator&, const STR&, const STR&)>(&DatatypeValidatorDefVisitor<STR>::compare))
	.def("setTypeName", static_cast<void(*)(xercesc::DatatypeValidator&, const STR&)>(&DatatypeValidatorDefVisitor<STR>::setTypeName))
	.def("setTypeName", static_cast<void(*)(xercesc::DatatypeValidator&, const STR&, const STR&)>(&DatatypeValidatorDefVisitor<STR>::setTypeName))
	;
}

static const XMLCh* getCanonicalRepresentation(xercesc::DatatypeValidator& self, const STR& rawData, xercesc::MemoryManager* const memMgr, bool toValidate) {
	XMLString buff(rawData);
	return self.getCanonicalRepresentation(buff.ptr(), memMgr, toValidate);
}

static const XMLCh* getCanonicalRepresentation(xercesc::DatatypeValidator& self, const STR& rawData, xercesc::MemoryManager* const memMgr) {
	return DatatypeValidatorDefVisitor<STR>::getCanonicalRepresentation(self, rawData, memMgr, false);
}

static const XMLCh* getCanonicalRepresentation(xercesc::DatatypeValidator& self, const STR& rawData) {
	return DatatypeValidatorDefVisitor<STR>::getCanonicalRepresentation(self, rawData, nullptr);
}

static void validate(xercesc::DatatypeValidator& self, const STR& content, xercesc::ValidationContext* const context, xercesc::MemoryManager* const manager) {
	XMLString buff(content);
	self.validate(buff.ptr(), context, manager);
}

static void validate(xercesc::DatatypeValidator& self, const STR& content, xercesc::ValidationContext* const context) {
	DatatypeValidatorDefVisitor<STR>::validate(self, content, context, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static void validate(xercesc::DatatypeValidator& self, const STR& content) {
	DatatypeValidatorDefVisitor<STR>::validate(self, content, nullptr);
}

static int compare(xercesc::DatatypeValidator& self, const STR& value1, const STR& value2, xercesc::MemoryManager* const manager) {
	XMLString buff1(value1), buff2(value2);
	return self.compare(buff1.ptr(), buff2.ptr(), manager);
}

static int compare(xercesc::DatatypeValidator& self, const STR& value1, const STR& value2) {
	return DatatypeValidatorDefVisitor<STR>::compare(self, value1, value2, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static void setTypeName(xercesc::DatatypeValidator& self, const STR& typeName) {
	XMLString buff(typeName);
	self.setTypeName(buff.ptr());
}

static void setTypeName(xercesc::DatatypeValidator& self, const STR& name, const STR& uri) {
	XMLString buff1(name), buff2(uri);
	self.setTypeName(buff1.ptr(), buff2.ptr());
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
			.def(DatatypeValidatorDefVisitor<XMLString>())
			.def(DatatypeValidatorDefVisitor<std::string>())
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
