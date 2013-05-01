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

template <typename STR>
class SchemaAttDefDefVisitor
: public boost::python::def_visitor<SchemaAttDefDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const STR, const STR, const int, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes, xercesc::MemoryManager* const)>(&SchemaAttDefDefVisitor<STR>::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const STR, const STR, const int, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes)>(&SchemaAttDefDefVisitor<STR>::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const STR, const STR, const int, const xercesc::XMLAttDef::AttTypes)>(&SchemaAttDefDefVisitor<STR>::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const STR, const STR, const int)>(&SchemaAttDefDefVisitor<STR>::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const STR, const STR, const int, const STR, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes, const STR&, xercesc::MemoryManager* const)>(&SchemaAttDefDefVisitor<STR>::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const STR, const STR, const int, const STR, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes, const STR&)>(&SchemaAttDefDefVisitor<STR>::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::SchemaAttDef*(*)(const STR, const STR, const int, const STR, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes)>(&SchemaAttDefDefVisitor<STR>::fromstring)))
	;
}

static xercesc::SchemaAttDef* fromstring(const STR prefix, const STR localPart, const int uriId, const xercesc::XMLAttDef::AttTypes type, const xercesc::XMLAttDef::DefAttTypes defType, xercesc::MemoryManager* const manager) {
	XMLString buff1(prefix), buff2(localPart);
	return new xercesc::SchemaAttDef(buff1.ptr(), buff2.ptr(), uriId, type, defType, manager);
}

static xercesc::SchemaAttDef* fromstring(const STR prefix, const STR localPart, const int uriId, const xercesc::XMLAttDef::AttTypes type, const xercesc::XMLAttDef::DefAttTypes defType) {
	return SchemaAttDefDefVisitor<STR>::fromstring(prefix, localPart, uriId, type, defType, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::SchemaAttDef* fromstring(const STR prefix, const STR localPart, const int uriId, const xercesc::XMLAttDef::AttTypes type) {
	return SchemaAttDefDefVisitor<STR>::fromstring(prefix, localPart, uriId, type, xercesc::SchemaAttDef::Implied);
}

static xercesc::SchemaAttDef* fromstring(const STR prefix, const STR localPart, const int uriId) {
	return SchemaAttDefDefVisitor<STR>::fromstring(prefix, localPart, uriId, xercesc::SchemaAttDef::CData);
}

static xercesc::SchemaAttDef* fromstring(const STR prefix, const STR localPart, const int uriId, const STR attValue, const xercesc::XMLAttDef::AttTypes type, const xercesc::XMLAttDef::DefAttTypes defType, const STR& enumValues, xercesc::MemoryManager* const manager) {
	XMLString buff1(prefix), buff2(localPart), buff3(attValue), buff4(enumValues);
	return new xercesc::SchemaAttDef(buff1.ptr(), buff2.ptr(), uriId, buff3.ptr(), type, defType, buff4.ptr(), manager);
}

static xercesc::SchemaAttDef* fromstring(const STR prefix, const STR localPart, const int uriId, const STR attValue, const xercesc::XMLAttDef::AttTypes type, const xercesc::XMLAttDef::DefAttTypes defType, const STR& enumValues) {
	return SchemaAttDefDefVisitor<STR>::fromstring(prefix, localPart, uriId, attValue, type, defType, enumValues, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::SchemaAttDef* fromstring(const STR prefix, const STR localPart, const int uriId, const STR attValue, const xercesc::XMLAttDef::AttTypes type, const xercesc::XMLAttDef::DefAttTypes defType) {
	XMLString buff1(prefix), buff2(localPart), buff3(attValue);
	return new xercesc::SchemaAttDef(buff1.ptr(), buff2.ptr(), uriId, buff3.ptr(), type, defType, nullptr, xercesc::XMLPlatformUtils::fgMemoryManager);
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
			.def(SchemaAttDefDefVisitor<XMLString&>())
			.def(SchemaAttDefDefVisitor<char*>())
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
