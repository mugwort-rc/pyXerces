/*
 * XMLAttr.cpp
 *
 *  Created on: 2013/03/15
 *      Author: mugwort_rc
 */

#include "XMLAttr.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLAttr.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class XMLAttrDefVisitor
: public boost::python::def_visitor<XMLAttrDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR, const STR, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*, const bool)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR, const STR, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR, const STR, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR, const STR, const xercesc::XMLAttDef::AttTypes, const bool)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR, const STR, const xercesc::XMLAttDef::AttTypes)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR, const STR)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*, const bool)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR, const xercesc::XMLAttDef::AttTypes, const bool)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR, const xercesc::XMLAttDef::AttTypes)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const STR, const STR)>(&XMLAttrDefVisitor<STR>::XMLAttr_fromstring)))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const STR, const STR, const STR, const xercesc::XMLAttDef::AttTypes, xercesc::DatatypeValidator*, const bool)>(&XMLAttrDefVisitor<STR>::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const STR, const STR, const STR, const xercesc::XMLAttDef::AttTypes, xercesc::DatatypeValidator*)>(&XMLAttrDefVisitor<STR>::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const STR, const STR, const STR, const xercesc::XMLAttDef::AttTypes)>(&XMLAttrDefVisitor<STR>::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const STR, const STR, const STR)>(&XMLAttrDefVisitor<STR>::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const STR, const STR, const xercesc::XMLAttDef::AttTypes, xercesc::DatatypeValidator*, const bool)>(&XMLAttrDefVisitor<STR>::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const STR, const STR, const xercesc::XMLAttDef::AttTypes, xercesc::DatatypeValidator*)>(&XMLAttrDefVisitor<STR>::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const STR, const STR, const xercesc::XMLAttDef::AttTypes)>(&XMLAttrDefVisitor<STR>::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const STR, const STR)>(&XMLAttrDefVisitor<STR>::set))
	.def("setName", &XMLAttrDefVisitor<STR>::setName)
	.def("setValue", &XMLAttrDefVisitor<STR>::setValue)
	;
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR attrName, const STR attrPrefix, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager, xercesc::DatatypeValidator* datatypeValidator, const bool isSchema) {
	XMLString buff1(attrName), buff2(attrPrefix), buff3(attrValue);
	return new xercesc::XMLAttr(uriId, buff1.ptr(), buff2.ptr(), buff3.ptr(), type, specified, manager, datatypeValidator, isSchema);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR attrName, const STR attrPrefix, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager, xercesc::DatatypeValidator* datatypeValidator) {
	return XMLAttrDefVisitor<STR>::XMLAttr_fromstring(uriId, attrName, attrPrefix, attrValue, type, specified, manager, datatypeValidator, false);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR attrName, const STR attrPrefix, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager) {
	return XMLAttrDefVisitor<STR>::XMLAttr_fromstring(uriId, attrName, attrPrefix, attrValue, type, specified, manager, nullptr);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR attrName, const STR attrPrefix, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified) {
	return XMLAttrDefVisitor<STR>::XMLAttr_fromstring(uriId, attrName, attrPrefix, attrValue, type, specified, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR attrName, const STR attrPrefix, const STR attrValue, const xercesc::XMLAttDef::AttTypes type) {
	return XMLAttrDefVisitor<STR>::XMLAttr_fromstring(uriId, attrName, attrPrefix, attrValue, type, true);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR attrName, const STR attrPrefix, const STR attrValue) {
	return XMLAttrDefVisitor<STR>::XMLAttr_fromstring(uriId, attrName, attrPrefix, attrValue, xercesc::XMLAttDef::CData);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR rawName, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager, xercesc::DatatypeValidator* datatypeValidator, const bool isSchema) {
	XMLString buff1(rawName), buff2(attrValue);
	return new xercesc::XMLAttr(uriId, buff1.ptr(), buff2.ptr(), type, specified, manager, datatypeValidator, isSchema);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR rawName, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager, xercesc::DatatypeValidator* datatypeValidator) {
	return XMLAttrDefVisitor<STR>::XMLAttr_fromstring(uriId, rawName, attrValue, type, specified, manager, datatypeValidator, false);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR rawName, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager) {
	return XMLAttrDefVisitor<STR>::XMLAttr_fromstring(uriId, rawName, attrValue, type, specified, manager, nullptr);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR rawName, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified) {
	return XMLAttrDefVisitor<STR>::XMLAttr_fromstring(uriId, rawName, attrValue, type, specified, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR rawName, const STR attrValue, const xercesc::XMLAttDef::AttTypes type) {
	return XMLAttrDefVisitor<STR>::XMLAttr_fromstring(uriId, rawName, attrValue, type, true);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const STR rawName, const STR attrValue) {
	return XMLAttrDefVisitor<STR>::XMLAttr_fromstring(uriId, rawName, attrValue, xercesc::XMLAttDef::CData);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const STR attrName, const STR attrPrefix, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, xercesc::DatatypeValidator* datatypeValidator, const bool isSchema) {
	XMLString buff1(attrName), buff2(attrPrefix), buff3(attrValue);
	self.set(uriId, buff1.ptr(), buff2.ptr(), buff3.ptr(), type, datatypeValidator, isSchema);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const STR attrName, const STR attrPrefix, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, xercesc::DatatypeValidator* datatypeValidator) {
	XMLAttrDefVisitor<STR>::set(self, uriId, attrName, attrPrefix, attrValue, type, datatypeValidator, false);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const STR attrName, const STR attrPrefix, const STR attrValue, const xercesc::XMLAttDef::AttTypes type) {
	XMLAttrDefVisitor<STR>::set(self, uriId, attrName, attrPrefix, attrValue, type, nullptr);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const STR attrName, const STR attrPrefix, const STR attrValue) {
	XMLAttrDefVisitor<STR>::set(self, uriId, attrName, attrPrefix, attrValue, xercesc::XMLAttDef::CData);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const STR attrRawName, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, xercesc::DatatypeValidator* datatypeValidator, const bool isSchema) {
	XMLString buff1(attrRawName), buff2(attrValue);
	self.set(uriId, buff1.ptr(), buff2.ptr(), type, datatypeValidator, isSchema);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const STR attrRawName, const STR attrValue, const xercesc::XMLAttDef::AttTypes type, xercesc::DatatypeValidator* datatypeValidator) {
	XMLAttrDefVisitor<STR>::set(self, uriId, attrRawName, attrValue, type, datatypeValidator, false);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const STR attrRawName, const STR attrValue, const xercesc::XMLAttDef::AttTypes type) {
	XMLAttrDefVisitor<STR>::set(self, uriId, attrRawName, attrValue, type, nullptr);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const STR attrRawName, const STR attrValue) {
	XMLAttrDefVisitor<STR>::set(self, uriId, attrRawName, attrValue, xercesc::XMLAttDef::CData);
}

static void setName(xercesc::XMLAttr& self, const unsigned int uriId, const STR attrName, const STR attrPrefix) {
	XMLString buff1(attrName), buff2(attrPrefix);
	self.setName(uriId, buff1.ptr(), buff2.ptr());
}

static void setValue(xercesc::XMLAttr& self, const STR newValue) {
	XMLString buff(newValue);
	self.setValue(buff.ptr());
}

};

void XMLAttr_init(void) {
	//! xercesc::XMLAttr
	boost::python::class_<xercesc::XMLAttr, boost::noncopyable>("XMLAttr", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const unsigned int, const XMLCh* const, const XMLCh* const, const XMLCh* const, boost::python::optional<const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*, const bool> >())
			.def(boost::python::init<const unsigned int, const XMLCh* const, const XMLCh* const, boost::python::optional<const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*, const bool> >())
			.def(XMLAttrDefVisitor<XMLString&>())
			.def(XMLAttrDefVisitor<char*>())
			.def("getAttName", &xercesc::XMLAttr::getAttName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getName", &xercesc::XMLAttr::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPrefix", &xercesc::XMLAttr::getPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getQName", &xercesc::XMLAttr::getQName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSpecified", &xercesc::XMLAttr::getSpecified)
			.def("getType", &xercesc::XMLAttr::getType)
			.def("getValue", &xercesc::XMLAttr::getValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getURIId", &xercesc::XMLAttr::getURIId)
			.def("set", static_cast<void(xercesc::XMLAttr::*)(const unsigned int, const XMLCh* const, const XMLCh* const, const XMLCh* const, const xercesc::XMLAttDef::AttTypes, xercesc::DatatypeValidator*, const bool)>(&xercesc::XMLAttr::set))
			.def("set", static_cast<void(xercesc::XMLAttr::*)(const unsigned int, const XMLCh* const, const XMLCh* const, const xercesc::XMLAttDef::AttTypes, xercesc::DatatypeValidator*, const bool)>(&xercesc::XMLAttr::set))
			.def("setName", &xercesc::XMLAttr::setName)
			.def("setSpecified", &xercesc::XMLAttr::setSpecified)
			.def("setType", &xercesc::XMLAttr::setType)
			.def("setValue", &xercesc::XMLAttr::setValue)
			.def("setURIId", &xercesc::XMLAttr::setURIId)
			;
}

} /* namespace pyxerces */
