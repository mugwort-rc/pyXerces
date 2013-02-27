/*
 * QName.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "QName.h"

#include <boost/python.hpp>
#include <xercesc/util/QName.hpp>

#include "XMLString.h"

namespace pyxerces {

class QNameDefVisitor
: public boost::python::def_visitor<QNameDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setName", static_cast<void(*)(xercesc::QName&, const XMLString&, const XMLString&, const unsigned int)>(&QNameDefVisitor::setName))
	.def("setName", static_cast<void(*)(xercesc::QName&, const std::string&, const std::string&, const unsigned int)>(&QNameDefVisitor::setName))
	.def("setName", static_cast<void(*)(xercesc::QName&, const XMLString&, const unsigned int)>(&QNameDefVisitor::setName))
	.def("setName", static_cast<void(*)(xercesc::QName&, const std::string&, const unsigned int)>(&QNameDefVisitor::setName))
	.def("setPrefix", static_cast<void(*)(xercesc::QName&, const XMLString&)>(&QNameDefVisitor::setPrefix))
	.def("setPrefix", static_cast<void(*)(xercesc::QName&, const std::string&)>(&QNameDefVisitor::setPrefix))
	.def("setLocalPart", static_cast<void(*)(xercesc::QName&, const XMLString&)>(&QNameDefVisitor::setLocalPart))
	.def("setLocalPart", static_cast<void(*)(xercesc::QName&, const std::string&)>(&QNameDefVisitor::setLocalPart))
	;
}

static void setName(xercesc::QName& self, const XMLString& prefix, const XMLString& localPart, const unsigned int uriId) {
	self.setName(prefix.ptr(), localPart.ptr(), uriId);
}

static void setName(xercesc::QName& self, const std::string& prefix, const std::string& localPart, const unsigned int uriId) {
	XMLString buff1(prefix), buff2(localPart);
	QNameDefVisitor::setName(self, buff1, buff2, uriId);
}

static void setName(xercesc::QName& self, const XMLString& rawName, const unsigned int uriId) {
	self.setName(rawName.ptr(), uriId);
}

static void setName(xercesc::QName& self, const std::string& rawName, const unsigned int uriId) {
	XMLString buff(rawName);
	QNameDefVisitor::setName(self, buff, uriId);
}

static void setPrefix(xercesc::QName& self, const XMLString& prefix) {
	self.setPrefix(prefix.ptr());
}

static void setPrefix(xercesc::QName& self, const std::string& prefix) {
	XMLString buff(prefix);
	QNameDefVisitor::setPrefix(self, buff);
}

static void setLocalPart(xercesc::QName& self, const XMLString& localPart) {
	self.setLocalPart(localPart.ptr());
}

static void setLocalPart(xercesc::QName& self, const std::string& localPart) {
	XMLString buff(localPart);
	QNameDefVisitor::setLocalPart(self, buff);
}

};

xercesc::QName* QName_fromstring(const std::string& prefix, const std::string& localPart, const unsigned int uriId, xercesc::MemoryManager* const manager) {
	XMLString buff1(prefix), buff2(localPart);
	return new xercesc::QName(buff1.ptr(), buff2.ptr(), uriId, manager);
}

xercesc::QName* QName_fromstring(const std::string& prefix, const std::string& localPart, const unsigned int uriId) {
	return QName_fromstring(prefix, localPart, uriId, xercesc::XMLPlatformUtils::fgMemoryManager);
}

xercesc::QName* QName_fromstring(const std::string& rawName, const unsigned int uriId, xercesc::MemoryManager* const manager) {
	XMLString buff(rawName);
	return new xercesc::QName(buff.ptr(), uriId, manager);
}

xercesc::QName* QName_fromstring(const std::string& rawName, const unsigned int uriId) {
	return QName_fromstring(rawName, uriId, xercesc::XMLPlatformUtils::fgMemoryManager);
}

void QName_init(void) {
	//! xercesc::QName
	boost::python::class_<xercesc::QName, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("QName", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(QNameDefVisitor())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, const unsigned int, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const unsigned int, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const xercesc::QName&>())
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::QName*(*)(const std::string&, const std::string&, const unsigned int, xercesc::MemoryManager* const)>(&QName_fromstring)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::QName*(*)(const std::string&, const std::string&, const unsigned int)>(&QName_fromstring)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::QName*(*)(const std::string&, const unsigned int, xercesc::MemoryManager* const)>(&QName_fromstring)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::QName*(*)(const std::string&, const unsigned int)>(&QName_fromstring)))
			.def("getPrefix", static_cast<const XMLCh*(xercesc::QName::*)(void) const>(&xercesc::QName::getPrefix), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLocalPart", static_cast<const XMLCh*(xercesc::QName::*)(void) const>(&xercesc::QName::getLocalPart), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getURI", &xercesc::QName::getURI)
			.def("getRawName", static_cast<const XMLCh*(xercesc::QName::*)(void) const>(&xercesc::QName::getRawName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getMemoryManager", &xercesc::QName::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setName", static_cast<void(xercesc::QName::*)(const XMLCh* const, const XMLCh* const, const unsigned int)>(&xercesc::QName::setName))
			.def("setName", static_cast<void(xercesc::QName::*)(const XMLCh* const, const unsigned int)>(&xercesc::QName::setName))
			.def("setPrefix", &xercesc::QName::setPrefix)
			.def("setLocalPart", &xercesc::QName::setLocalPart)
			.def("setNPrefix", &xercesc::QName::setNPrefix)
			.def("setNLocalPart", &xercesc::QName::setNLocalPart)
			.def("setURI", &xercesc::QName::setURI)
			.def("setValues", &xercesc::QName::setValues)
			.def("__eq__", &xercesc::QName::operator==)
			.def("cleanUp", &xercesc::QName::cleanUp)
			.def("isSerializable", &xercesc::QName::isSerializable)
			.def("getProtoType", &xercesc::QName::getProtoType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("serialize", &xercesc::QName::serialize)
			;
}

} /* namespace pyxerces */
