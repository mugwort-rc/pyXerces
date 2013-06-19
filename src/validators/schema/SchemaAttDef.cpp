/*
 * SchemaAttDef.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "SchemaAttDef.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/datatype/DatatypeValidator.hpp>
#include <xercesc/util/QName.hpp>
#include <xercesc/validators/schema/ComplexTypeInfo.hpp>

#include <xercesc/validators/schema/SchemaAttDef.hpp>

#include "../../internal/XSerializable.h"
#include "../../util/XMLString.h"

namespace pyxerces {

class SchemaAttDefDefVisitor
: public boost::python::def_visitor<SchemaAttDefDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const XMLString&, const XMLString&, const int, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes, xercesc::MemoryManager* const)>(&SchemaAttDefDefVisitor::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const XMLString&, const XMLString&, const int, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes)>(&SchemaAttDefDefVisitor::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const XMLString&, const XMLString&, const int, const xercesc::XMLAttDef::AttTypes)>(&SchemaAttDefDefVisitor::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const XMLString&, const XMLString&, const int)>(&SchemaAttDefDefVisitor::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const XMLString&, const XMLString&, const int, const XMLString&, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes, const XMLString&, xercesc::MemoryManager* const)>(&SchemaAttDefDefVisitor::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const XMLString&, const XMLString&, const int, const XMLString&, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes, const XMLString&)>(&SchemaAttDefDefVisitor::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const XMLString&, const XMLString&, const int, const XMLString&, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes)>(&SchemaAttDefDefVisitor::fromstring)))
	;
}

static xercesc::SchemaAttDef* fromstring(const XMLString& prefix, const XMLString& localPart, const int uriId, const xercesc::XMLAttDef::AttTypes type, const xercesc::XMLAttDef::DefAttTypes defType, xercesc::MemoryManager* const manager) {
	return new xercesc::SchemaAttDef(prefix.ptr(), localPart.ptr(), uriId, type, defType, manager);
}

static xercesc::SchemaAttDef* fromstring(const XMLString& prefix, const XMLString& localPart, const int uriId, const xercesc::XMLAttDef::AttTypes type, const xercesc::XMLAttDef::DefAttTypes defType) {
	return SchemaAttDefDefVisitor::fromstring(prefix, localPart, uriId, type, defType, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::SchemaAttDef* fromstring(const XMLString& prefix, const XMLString& localPart, const int uriId, const xercesc::XMLAttDef::AttTypes type) {
	return SchemaAttDefDefVisitor::fromstring(prefix, localPart, uriId, type, xercesc::SchemaAttDef::Implied);
}

static xercesc::SchemaAttDef* fromstring(const XMLString& prefix, const XMLString& localPart, const int uriId) {
	return SchemaAttDefDefVisitor::fromstring(prefix, localPart, uriId, xercesc::SchemaAttDef::CData);
}

static xercesc::SchemaAttDef* fromstring(const XMLString& prefix, const XMLString& localPart, const int uriId, const XMLString& attValue, const xercesc::XMLAttDef::AttTypes type, const xercesc::XMLAttDef::DefAttTypes defType, const XMLString& enumValues, xercesc::MemoryManager* const manager) {
	return new xercesc::SchemaAttDef(prefix.ptr(), localPart.ptr(), uriId, attValue.ptr(), type, defType, enumValues.ptr(), manager);
}

static xercesc::SchemaAttDef* fromstring(const XMLString& prefix, const XMLString& localPart, const int uriId, const XMLString& attValue, const xercesc::XMLAttDef::AttTypes type, const xercesc::XMLAttDef::DefAttTypes defType, const XMLString& enumValues) {
	return SchemaAttDefDefVisitor::fromstring(prefix, localPart, uriId, attValue, type, defType, enumValues, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::SchemaAttDef* fromstring(const XMLString& prefix, const XMLString& localPart, const int uriId, const XMLString& attValue, const xercesc::XMLAttDef::AttTypes type, const xercesc::XMLAttDef::DefAttTypes defType) {
	return new xercesc::SchemaAttDef(prefix.ptr(), localPart.ptr(), uriId, attValue.ptr(), type, defType, nullptr, xercesc::XMLPlatformUtils::fgMemoryManager);
}

};

class SchemaAttDefWrapper
: public xercesc::SchemaAttDef, public boost::python::wrapper<xercesc::SchemaAttDef>
{
public:
SchemaAttDefWrapper(xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::SchemaAttDef(manager)
{}

SchemaAttDefWrapper(const XMLCh* const prefix, const XMLCh* const localPart, const int uriId, const XMLAttDef::AttTypes type = CData, const XMLAttDef::DefAttTypes defType = Implied, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::SchemaAttDef(prefix, localPart, uriId, type, defType, manager)
{}

SchemaAttDefWrapper(const XMLCh* const prefix, const XMLCh* const localPart, const int uriId, const XMLCh* const attValue, const XMLAttDef::AttTypes type, const XMLAttDef::DefAttTypes defType, const XMLCh* const enumValues = 0, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::SchemaAttDef(prefix, localPart, uriId, attValue, type, defType, enumValues, manager)
{}

SchemaAttDefWrapper(const SchemaAttDef* other)
: xercesc::SchemaAttDef(other)
{}

const XMLCh* getFullName() const {
	if(boost::python::override getFullName = this->get_override("getFullName")){
		return getFullName();
	}else{
		return xercesc::SchemaAttDef::getFullName();
	}
}

void reset() {
	if(boost::python::override reset = this->get_override("reset")){
		reset();
	}else{
		xercesc::SchemaAttDef::reset();
	}
}

PyDECL_XSERIALIZABLEWrapper

};

void SchemaAttDef_init(void) {
	//! xercesc::SchemaAttDef
	boost::python::class_<SchemaAttDefWrapper, boost::noncopyable>("SchemaAttDef", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, const int, boost::python::optional<const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, const int, const XMLCh* const, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes, boost::python::optional<const XMLCh* const, xercesc::MemoryManager* const> >())
			.def(boost::python::init<boost::python::optional<const xercesc::SchemaAttDef*> >())
			.def(SchemaAttDefDefVisitor())
			.def("getFullName", &xercesc::SchemaAttDef::getFullName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("reset", &xercesc::SchemaAttDef::reset)
			.def("getElemId", &xercesc::SchemaAttDef::getElemId)
			.def("getAttName", &xercesc::SchemaAttDef::getAttName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDatatypeValidator", &xercesc::SchemaAttDef::getDatatypeValidator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNamespaceList", &xercesc::SchemaAttDef::getNamespaceList, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getBaseAttDecl", static_cast<xercesc::SchemaAttDef*(xercesc::SchemaAttDef::*)(void)>(&xercesc::SchemaAttDef::getBaseAttDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPSVIScope", &xercesc::SchemaAttDef::getPSVIScope)
			.def("setElemId", &xercesc::SchemaAttDef::setElemId)
			.def("setAttName", &xercesc::SchemaAttDef::setAttName)
			.def("setDatatypeValidator", &xercesc::SchemaAttDef::setDatatypeValidator)
			.def("setBaseAttDecl", &xercesc::SchemaAttDef::setBaseAttDecl)
			.def("setPSVIScope", &xercesc::SchemaAttDef::setPSVIScope)
			.def("setNamespaceList", &xercesc::SchemaAttDef::setNamespaceList)
			.def("resetNamespaceList", &xercesc::SchemaAttDef::resetNamespaceList)
			.def("setEnclosingCT", &xercesc::SchemaAttDef::setEnclosingCT)
			PyDECL_XSERIALIZABLE(SchemaAttDef)
			;
}

} /* namespace pyxerces */
