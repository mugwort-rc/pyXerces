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

template <typename STR>
class KVStringPairDefVisitor
: public boost::python::def_visitor<KVStringPairDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::KVStringPair*(*)(const STR, const STR, xercesc::MemoryManager* const)>(&KVStringPair_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::KVStringPair*(*)(const STR, const STR)>(&KVStringPair_fromstring)))
	.def("setKey", &KVStringPairDefVisitor::setKey)
	.def("setValue", &KVStringPairDefVisitor::setValue)
	.def("set", &KVStringPairDefVisitor::set)
	;
}

static xercesc::KVStringPair* KVStringPair_fromstring(const STR key, const STR value, xercesc::MemoryManager* const manager) {
	XMLString buff1(key), buff2(value);
	return new xercesc::KVStringPair(buff1.ptr(), buff2.ptr(), manager);
}

static xercesc::KVStringPair* KVStringPair_fromstring(const STR key, const STR value) {
	return KVStringPair_fromstring(key, value, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static void setKey(xercesc::KVStringPair& self, const STR newKey) {
	XMLString buff(newKey);
	self.setKey(buff.ptr());
}

static void setValue(xercesc::KVStringPair& self, const STR newValue) {
	XMLString buff(newValue);
	self.setValue(buff.ptr());
}

static void set(xercesc::KVStringPair& self, const STR newKey, const STR newValue) {
	XMLString buff1(newKey), buff2(newValue);
	self.set(buff1.ptr(), buff2.ptr());
}

};

void KVStringPair_init(void) {
	//! xercesc::KVStringPair
	boost::python::class_<xercesc::KVStringPair, boost::python::bases<xercesc::XSerializable> >("KVStringPair", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLSize_t, const XMLCh* const, const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(KVStringPairDefVisitor<XMLString&>())
			.def(KVStringPairDefVisitor<char*>())
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
