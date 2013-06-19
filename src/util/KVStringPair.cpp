/*
 * KVStringPair.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "KVStringPair.h"

#include <boost/python.hpp>
#include <xercesc/util/KVStringPair.hpp>

#include "../internal/XSerializable.h"
#include "XMLString.h"

namespace pyxerces {

class KVStringPairDefVisitor
: public boost::python::def_visitor<KVStringPairDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::KVStringPair*(*)(const XMLString&, const XMLString&, xercesc::MemoryManager* const)>(&KVStringPair_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::KVStringPair*(*)(const XMLString&, const XMLString&)>(&KVStringPair_fromstring)))
	.def("setKey", &KVStringPairDefVisitor::setKey)
	.def("setValue", &KVStringPairDefVisitor::setValue)
	.def("set", &KVStringPairDefVisitor::set)
	;
}

static xercesc::KVStringPair* KVStringPair_fromstring(const XMLString& key, const XMLString& value, xercesc::MemoryManager* const manager) {
	return new xercesc::KVStringPair(key.ptr(), value.ptr(), manager);
}

static xercesc::KVStringPair* KVStringPair_fromstring(const XMLString& key, const XMLString& value) {
	return KVStringPair_fromstring(key, value, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static void setKey(xercesc::KVStringPair& self, const XMLString& newKey) {
	self.setKey(newKey.ptr());
}

static void setValue(xercesc::KVStringPair& self, const XMLString& newValue) {
	self.setValue(newValue.ptr());
}

static void set(xercesc::KVStringPair& self, const XMLString& newKey, const XMLString& newValue) {
	self.set(newKey.ptr(), newValue.ptr());
}

};

void KVStringPair_init(void) {
	//! xercesc::KVStringPair
	boost::python::class_<xercesc::KVStringPair, boost::python::bases<xercesc::XSerializable> >("KVStringPair", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLSize_t, const XMLCh* const, const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(KVStringPairDefVisitor())
			.def("getKey", static_cast<const XMLCh*(xercesc::KVStringPair::*)(void) const>(&xercesc::KVStringPair::getKey), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getValue", static_cast<const XMLCh*(xercesc::KVStringPair::*)(void) const>(&xercesc::KVStringPair::getValue), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setKey", static_cast<void(xercesc::KVStringPair::*)(const XMLCh* const)>(&xercesc::KVStringPair::setKey))
			.def("setValue", static_cast<void(xercesc::KVStringPair::*)(const XMLCh* const)>(&xercesc::KVStringPair::setValue))
			.def("setKey", static_cast<void(xercesc::KVStringPair::*)(const XMLCh* const, const XMLSize_t)>(&xercesc::KVStringPair::setKey))
			.def("setValue", static_cast<void(xercesc::KVStringPair::*)(const XMLCh* const, const XMLSize_t)>(&xercesc::KVStringPair::setValue))
			.def("set", static_cast<void(xercesc::KVStringPair::*)(const XMLCh* const, const XMLCh* const)>(&xercesc::KVStringPair::set))
			.def("set", static_cast<void(xercesc::KVStringPair::*)(const XMLCh* const, const XMLSize_t, const XMLCh* const, const XMLSize_t)>(&xercesc::KVStringPair::set))
			PyDECL_XSERIALIZABLE(KVStringPair)
			;
}

} /* namespace pyxerces */
