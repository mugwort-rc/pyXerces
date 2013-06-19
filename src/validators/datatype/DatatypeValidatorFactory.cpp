/*
 * DatatypeValidatorFactory.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "DatatypeValidatorFactory.h"

#include <boost/python.hpp>
#include <xercesc/validators/datatype/DatatypeValidatorFactory.hpp>

#include "../../internal/XSerializable.h"
#include "../../util/XMLString.h"

namespace pyxerces {

class DatatypeValidatorFactoryDefVisitor
: public boost::python::def_visitor<DatatypeValidatorFactoryDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getDatatypeValidator", &DatatypeValidatorFactoryDefVisitor::getDatatypeValidator, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const XMLString&, xercesc::DatatypeValidator* const, xercesc::RefHashTableOf<xercesc::KVStringPair>* const, xercesc::RefArrayVectorOf<XMLCh>* const, const bool, const int, const bool, xercesc::MemoryManager* const)>(&DatatypeValidatorFactoryDefVisitor::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const XMLString&, xercesc::DatatypeValidator* const, xercesc::RefHashTableOf<xercesc::KVStringPair>* const, xercesc::RefArrayVectorOf<XMLCh>* const, const bool, const int, const bool)>(&DatatypeValidatorFactoryDefVisitor::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const XMLString&, xercesc::DatatypeValidator* const, xercesc::RefHashTableOf<xercesc::KVStringPair>* const, xercesc::RefArrayVectorOf<XMLCh>* const, const bool, const int)>(&DatatypeValidatorFactoryDefVisitor::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const XMLString&, xercesc::DatatypeValidator* const, xercesc::RefHashTableOf<xercesc::KVStringPair>* const, xercesc::RefArrayVectorOf<XMLCh>* const, const bool)>(&DatatypeValidatorFactoryDefVisitor::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const XMLString&, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const, const int, const bool, xercesc::MemoryManager* const)>(&DatatypeValidatorFactoryDefVisitor::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const XMLString&, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const, const int, const bool)>(&DatatypeValidatorFactoryDefVisitor::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const XMLString&, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const, const int)>(&DatatypeValidatorFactoryDefVisitor::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DatatypeValidator* getDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const XMLString& dvType) {
	return self.getDatatypeValidator(dvType.ptr());
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const XMLString& typeName, xercesc::DatatypeValidator* const baseValidator, xercesc::RefHashTableOf<xercesc::KVStringPair>* const facets, xercesc::RefArrayVectorOf<XMLCh>* const enums, const bool isDerivedByList, const int finalSet, const bool isUserDefined, xercesc::MemoryManager* const manager) {
	return self.createDatatypeValidator(typeName.ptr(), baseValidator, facets, enums, isDerivedByList, finalSet, isUserDefined, manager);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const XMLString& typeName, xercesc::DatatypeValidator* const baseValidator, xercesc::RefHashTableOf<xercesc::KVStringPair>* const facets, xercesc::RefArrayVectorOf<XMLCh>* const enums, const bool isDerivedByList, const int finalSet, const bool isUserDefined) {
	return DatatypeValidatorFactoryDefVisitor::createDatatypeValidator(self, typeName, baseValidator, facets, enums, isDerivedByList, finalSet, isUserDefined, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const XMLString& typeName, xercesc::DatatypeValidator* const baseValidator, xercesc::RefHashTableOf<xercesc::KVStringPair>* const facets, xercesc::RefArrayVectorOf<XMLCh>* const enums, const bool isDerivedByList, const int finalSet) {
	return DatatypeValidatorFactoryDefVisitor::createDatatypeValidator(self, typeName, baseValidator, facets, enums, isDerivedByList, finalSet, true);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const XMLString& typeName, xercesc::DatatypeValidator* const baseValidator, xercesc::RefHashTableOf<xercesc::KVStringPair>* const facets, xercesc::RefArrayVectorOf<XMLCh>* const enums, const bool isDerivedByList) {
	return DatatypeValidatorFactoryDefVisitor::createDatatypeValidator(self, typeName, baseValidator, facets, enums, isDerivedByList, 0);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const XMLString& typeName, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const validators, const int finalSet, const bool isUserDefined, xercesc::MemoryManager* const manager) {
	return self.createDatatypeValidator(typeName.ptr(), validators, finalSet, isUserDefined, manager);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const XMLString& typeName, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const validators, const int finalSet, const bool isUserDefined) {
	return DatatypeValidatorFactoryDefVisitor::createDatatypeValidator(self, typeName, validators, finalSet, isUserDefined, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const XMLString& typeName, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const validators, const int finalSet) {
	return DatatypeValidatorFactoryDefVisitor::createDatatypeValidator(self, typeName, validators, finalSet, true);
}

};

void DatatypeValidatorFactory_init(void) {
	//! xercesc::DatatypeValidatorFactory
	boost::python::class_<xercesc::DatatypeValidatorFactory, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("DatatypeValidatorFactory", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(DatatypeValidatorFactoryDefVisitor())
			.def("getDatatypeValidator", &xercesc::DatatypeValidatorFactory::getDatatypeValidator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getUserDefinedRegistry", &xercesc::DatatypeValidatorFactory::getUserDefinedRegistry, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getBuiltInRegistry", &xercesc::DatatypeValidatorFactory::getBuiltInRegistry, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("initCanRepRegistory", &xercesc::DatatypeValidatorFactory::initCanRepRegistory)
			.def("getCanRepGroup", &xercesc::DatatypeValidatorFactory::getCanRepGroup)
			.def("getBuiltInBaseValidator", &xercesc::DatatypeValidatorFactory::getBuiltInBaseValidator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.staticmethod("getBuiltInRegistry")
			.staticmethod("getCanRepGroup")
			.staticmethod("getBuiltInBaseValidator")
			.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(xercesc::DatatypeValidatorFactory::*)(const XMLCh* const, xercesc::DatatypeValidator* const, xercesc::RefHashTableOf<xercesc::KVStringPair>* const, xercesc::RefArrayVectorOf<XMLCh>* const, const bool, const int, const bool, xercesc::MemoryManager* const)>(&xercesc::DatatypeValidatorFactory::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(xercesc::DatatypeValidatorFactory::*)(const XMLCh* const, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const, const int, const bool, xercesc::MemoryManager* const)>(&xercesc::DatatypeValidatorFactory::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("resetRegistry", &xercesc::DatatypeValidatorFactory::resetRegistry)
			PyDECL_XSERIALIZABLE(DatatypeValidatorFactory)
			;
}

} /* namespace pyxerces */
