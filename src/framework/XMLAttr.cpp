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

class XMLAttrDefVisitor
: public boost::python::def_visitor<XMLAttrDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*, const bool)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, const bool)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&, const XMLString&)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*, const bool)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, const bool)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLAttr*(*)(const unsigned int, const XMLString&, const XMLString&)>(&XMLAttrDefVisitor::XMLAttr_fromstring)))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const XMLString&, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, xercesc::DatatypeValidator*, const bool)>(&XMLAttrDefVisitor::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const XMLString&, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, xercesc::DatatypeValidator*)>(&XMLAttrDefVisitor::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const XMLString&, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes)>(&XMLAttrDefVisitor::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const XMLString&, const XMLString&, const XMLString&)>(&XMLAttrDefVisitor::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, xercesc::DatatypeValidator*, const bool)>(&XMLAttrDefVisitor::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes, xercesc::DatatypeValidator*)>(&XMLAttrDefVisitor::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const XMLString&, const XMLString&, const xercesc::XMLAttDef::AttTypes)>(&XMLAttrDefVisitor::set))
	.def("set", static_cast<void(*)(xercesc::XMLAttr&, const unsigned int, const XMLString&, const XMLString&)>(&XMLAttrDefVisitor::set))
	.def("setName", &XMLAttrDefVisitor::setName)
	.def("setValue", &XMLAttrDefVisitor::setValue)
	;
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& attrName, const XMLString& attrPrefix, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager, xercesc::DatatypeValidator* datatypeValidator, const bool isSchema) {
	return new xercesc::XMLAttr(uriId, attrName.ptr(), attrPrefix.ptr(), attrValue.ptr(), type, specified, manager, datatypeValidator, isSchema);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& attrName, const XMLString& attrPrefix, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager, xercesc::DatatypeValidator* datatypeValidator) {
	return XMLAttrDefVisitor::XMLAttr_fromstring(uriId, attrName, attrPrefix, attrValue, type, specified, manager, datatypeValidator, false);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& attrName, const XMLString& attrPrefix, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager) {
	return XMLAttrDefVisitor::XMLAttr_fromstring(uriId, attrName, attrPrefix, attrValue, type, specified, manager, nullptr);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& attrName, const XMLString& attrPrefix, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified) {
	return XMLAttrDefVisitor::XMLAttr_fromstring(uriId, attrName, attrPrefix, attrValue, type, specified, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& attrName, const XMLString& attrPrefix, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type) {
	return XMLAttrDefVisitor::XMLAttr_fromstring(uriId, attrName, attrPrefix, attrValue, type, true);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& attrName, const XMLString& attrPrefix, const XMLString& attrValue) {
	return XMLAttrDefVisitor::XMLAttr_fromstring(uriId, attrName, attrPrefix, attrValue, xercesc::XMLAttDef::CData);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& rawName, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager, xercesc::DatatypeValidator* datatypeValidator, const bool isSchema) {
	return new xercesc::XMLAttr(uriId, rawName.ptr(), attrValue.ptr(), type, specified, manager, datatypeValidator, isSchema);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& rawName, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager, xercesc::DatatypeValidator* datatypeValidator) {
	return XMLAttrDefVisitor::XMLAttr_fromstring(uriId, rawName, attrValue, type, specified, manager, datatypeValidator, false);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& rawName, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified, xercesc::MemoryManager* const manager) {
	return XMLAttrDefVisitor::XMLAttr_fromstring(uriId, rawName, attrValue, type, specified, manager, nullptr);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& rawName, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, const bool specified) {
	return XMLAttrDefVisitor::XMLAttr_fromstring(uriId, rawName, attrValue, type, specified, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& rawName, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type) {
	return XMLAttrDefVisitor::XMLAttr_fromstring(uriId, rawName, attrValue, type, true);
}

static xercesc::XMLAttr* XMLAttr_fromstring(const unsigned int uriId, const XMLString& rawName, const XMLString& attrValue) {
	return XMLAttrDefVisitor::XMLAttr_fromstring(uriId, rawName, attrValue, xercesc::XMLAttDef::CData);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const XMLString& attrName, const XMLString& attrPrefix, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, xercesc::DatatypeValidator* datatypeValidator, const bool isSchema) {
	self.set(uriId, attrName.ptr(), attrPrefix.ptr(), attrValue.ptr(), type, datatypeValidator, isSchema);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const XMLString& attrName, const XMLString& attrPrefix, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, xercesc::DatatypeValidator* datatypeValidator) {
	XMLAttrDefVisitor::set(self, uriId, attrName, attrPrefix, attrValue, type, datatypeValidator, false);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const XMLString& attrName, const XMLString& attrPrefix, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type) {
	XMLAttrDefVisitor::set(self, uriId, attrName, attrPrefix, attrValue, type, nullptr);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const XMLString& attrName, const XMLString& attrPrefix, const XMLString& attrValue) {
	XMLAttrDefVisitor::set(self, uriId, attrName, attrPrefix, attrValue, xercesc::XMLAttDef::CData);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const XMLString& attrRawName, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, xercesc::DatatypeValidator* datatypeValidator, const bool isSchema) {
	self.set(uriId, attrRawName.ptr(), attrValue.ptr(), type, datatypeValidator, isSchema);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const XMLString& attrRawName, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type, xercesc::DatatypeValidator* datatypeValidator) {
	XMLAttrDefVisitor::set(self, uriId, attrRawName, attrValue, type, datatypeValidator, false);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const XMLString& attrRawName, const XMLString& attrValue, const xercesc::XMLAttDef::AttTypes type) {
	XMLAttrDefVisitor::set(self, uriId, attrRawName, attrValue, type, nullptr);
}

static void set(xercesc::XMLAttr& self, const unsigned int uriId, const XMLString& attrRawName, const XMLString& attrValue) {
	XMLAttrDefVisitor::set(self, uriId, attrRawName, attrValue, xercesc::XMLAttDef::CData);
}

static void setName(xercesc::XMLAttr& self, const unsigned int uriId, const XMLString& attrName, const XMLString& attrPrefix) {
	self.setName(uriId, attrName.ptr(), attrPrefix.ptr());
}

static void setValue(xercesc::XMLAttr& self, const XMLString& newValue) {
	self.setValue(newValue.ptr());
}

};

void XMLAttr_init(void) {
	//! xercesc::XMLAttr
	boost::python::class_<xercesc::XMLAttr, boost::noncopyable>("XMLAttr", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const unsigned int, const XMLCh* const, const XMLCh* const, const XMLCh* const, boost::python::optional<const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*, const bool> >())
			.def(boost::python::init<const unsigned int, const XMLCh* const, const XMLCh* const, boost::python::optional<const xercesc::XMLAttDef::AttTypes, const bool, xercesc::MemoryManager* const, xercesc::DatatypeValidator*, const bool> >())
			.def(XMLAttrDefVisitor())
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
