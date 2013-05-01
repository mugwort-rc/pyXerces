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

template <typename STR>
class DatatypeValidatorFactoryDefVisitor
: public boost::python::def_visitor<DatatypeValidatorFactoryDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getDatatypeValidator", &DatatypeValidatorFactoryDefVisitor<STR>::getDatatypeValidator, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const STR, xercesc::DatatypeValidator* const, xercesc::RefHashTableOf<xercesc::KVStringPair>* const, xercesc::RefArrayVectorOf<XMLCh>* const, const bool, const int, const bool, xercesc::MemoryManager* const)>(&DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const STR, xercesc::DatatypeValidator* const, xercesc::RefHashTableOf<xercesc::KVStringPair>* const, xercesc::RefArrayVectorOf<XMLCh>* const, const bool, const int, const bool)>(&DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const STR, xercesc::DatatypeValidator* const, xercesc::RefHashTableOf<xercesc::KVStringPair>* const, xercesc::RefArrayVectorOf<XMLCh>* const, const bool, const int)>(&DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const STR, xercesc::DatatypeValidator* const, xercesc::RefHashTableOf<xercesc::KVStringPair>* const, xercesc::RefArrayVectorOf<XMLCh>* const, const bool)>(&DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const STR, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const, const int, const bool, xercesc::MemoryManager* const)>(&DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const STR, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const, const int, const bool)>(&DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDatatypeValidator", static_cast<xercesc::DatatypeValidator*(*)(xercesc::DatatypeValidatorFactory&, const STR, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const, const int)>(&DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DatatypeValidator* getDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const STR& dvType) {
	XMLString buff(dvType);
	return self.getDatatypeValidator(buff.ptr());
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const STR typeName, xercesc::DatatypeValidator* const baseValidator, xercesc::RefHashTableOf<xercesc::KVStringPair>* const facets, xercesc::RefArrayVectorOf<XMLCh>* const enums, const bool isDerivedByList, const int finalSet, const bool isUserDefined, xercesc::MemoryManager* const manager) {
	XMLString buff(typeName);
	return self.createDatatypeValidator(buff.ptr(), baseValidator, facets, enums, isDerivedByList, finalSet, isUserDefined, manager);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const STR typeName, xercesc::DatatypeValidator* const baseValidator, xercesc::RefHashTableOf<xercesc::KVStringPair>* const facets, xercesc::RefArrayVectorOf<XMLCh>* const enums, const bool isDerivedByList, const int finalSet, const bool isUserDefined) {
	return DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator(self, typeName, baseValidator, facets, enums, isDerivedByList, finalSet, isUserDefined, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const STR typeName, xercesc::DatatypeValidator* const baseValidator, xercesc::RefHashTableOf<xercesc::KVStringPair>* const facets, xercesc::RefArrayVectorOf<XMLCh>* const enums, const bool isDerivedByList, const int finalSet) {
	return DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator(self, typeName, baseValidator, facets, enums, isDerivedByList, finalSet, true);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const STR typeName, xercesc::DatatypeValidator* const baseValidator, xercesc::RefHashTableOf<xercesc::KVStringPair>* const facets, xercesc::RefArrayVectorOf<XMLCh>* const enums, const bool isDerivedByList) {
	return DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator(self, typeName, baseValidator, facets, enums, isDerivedByList, 0);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const STR typeName, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const validators, const int finalSet, const bool isUserDefined, xercesc::MemoryManager* const manager) {
	XMLString buff(typeName);
	return self.createDatatypeValidator(buff.ptr(), validators, finalSet, isUserDefined, manager);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const STR typeName, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const validators, const int finalSet, const bool isUserDefined) {
	return DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator(self, typeName, validators, finalSet, isUserDefined, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::DatatypeValidator* createDatatypeValidator(xercesc::DatatypeValidatorFactory& self, const STR typeName, xercesc::RefVectorOf<xercesc::DatatypeValidator>* const validators, const int finalSet) {
	return DatatypeValidatorFactoryDefVisitor<STR>::createDatatypeValidator(self, typeName, validators, finalSet, true);
}

};

void DatatypeValidatorFactory_init(void) {
	//! xercesc::DatatypeValidatorFactory
	boost::python::class_<xercesc::DatatypeValidatorFactory, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("DatatypeValidatorFactory", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(DatatypeValidatorFactoryDefVisitor<XMLString&>())
			.def(DatatypeValidatorFactoryDefVisitor<char*>())
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
