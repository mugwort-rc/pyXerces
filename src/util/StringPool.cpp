/*
 * StringPool.cpp
 *
 *  Created on: 2013/03/05
 *      Author: mugwort_rc
 */

#include "StringPool.h"

#include <boost/python.hpp>
#include <xercesc/util/StringPool.hpp>

#include "../internal/XSerializable.h"
#include "XMLString.h"

namespace pyxerces {

template <typename STR>
class XMLStringPoolDefVisitor
: public boost::python::def_visitor<XMLStringPoolDefVisitor<STR> >
{
friend class def_veisitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("addOrFind", &XMLStringPoolDefVisitor<STR>::addOrFind)
	.def("exists", &XMLStringPoolDefVisitor<STR>::exists)
	.def("getId", &XMLStringPoolDefVisitor<STR>::getId)
	;
}

static unsigned int addOrFind(xercesc::XMLStringPool& self, const STR newString) {
	XMLString buff(newString);
	return self.addOrFind(buff.ptr());
}

static bool exists(xercesc::XMLStringPool& self, const STR newString) {
	XMLString buff(newString);
	return self.exists(buff.ptr());
}

static unsigned int getId(xercesc::XMLStringPool& self, const STR toFind) {
	XMLString buff(toFind);
	return self.getId(buff.ptr());
}

};

class XMLStringPoolWrapper
: public xercesc::XMLStringPool, public boost::python::wrapper<xercesc::XMLStringPool>
{
public:
XMLStringPoolWrapper(const unsigned int modulus = 109, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::XMLStringPool(modulus, manager)
{}

XMLStringPoolWrapper(xercesc::MemoryManager* const manager)
: xercesc::XMLStringPool(manager)
{}

unsigned int addOrFind(const XMLCh* const newString) {
	if(boost::python::override addOrFind = this->get_override("addOrFind")){
		return addOrFind(XMLString(newString));
	}else{
		return xercesc::XMLStringPool::addOrFind(newString);
	}
}

bool exists(const XMLCh* const newString) const {
	if(boost::python::override exists = this->get_override("exists")){
		return exists(XMLString(newString));
	}else{
		return xercesc::XMLStringPool::exists(newString);
	}
}

bool exists(const unsigned int id) const {
	if(boost::python::override exists = this->get_override("exists")){
		return exists(id);
	}else{
		return xercesc::XMLStringPool::exists(id);
	}
}

void flushAll() {
	if(boost::python::override flushAll = this->get_override("flushAll")){
		flushAll();
	}else{
		xercesc::XMLStringPool::flushAll();
	}
}

unsigned int getId(const XMLCh* const toFind) const {
	if(boost::python::override getId = this->get_override("getId")){
		return getId(XMLString(toFind));
	}else{
		return xercesc::XMLStringPool::getId(toFind);
	}
}

const XMLCh* getValueForId(const unsigned int id) const {
	if(boost::python::override getValueForId = this->get_override("getValueForId")){
		return getValueForId(id);
	}else{
		return xercesc::XMLStringPool::getValueForId(id);
	}
}

unsigned int getStringCount() const {
	if(boost::python::override getStringCount = this->get_override("getStringCount")){
		return getStringCount();
	}else{
		return xercesc::XMLStringPool::getStringCount();
	}
}

PyDECL_XSERIALIZABLEWrapper

};

void StringPool_init(void) {
	//! xercesc::XMLStringPool
	boost::python::class_<XMLStringPoolWrapper, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLStringPool", boost::python::init<boost::python::optional<const unsigned int, xercesc::MemoryManager* const> >())
			.def(boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(XMLStringPoolDefVisitor<XMLString&>())
			.def(XMLStringPoolDefVisitor<char*>())
			.def("addOrFind", &xercesc::XMLStringPool::addOrFind)
			.def("exists", static_cast<bool(xercesc::XMLStringPool::*)(const XMLCh* const) const>(&xercesc::XMLStringPool::exists))
			.def("exists", static_cast<bool(xercesc::XMLStringPool::*)(const unsigned int) const>(&xercesc::XMLStringPool::exists))
			.def("flushAll", &xercesc::XMLStringPool::flushAll)
			.def("getId", &xercesc::XMLStringPool::getId)
			.def("getValueForId", &xercesc::XMLStringPool::getValueForId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getStringCount", &xercesc::XMLStringPool::getStringCount)
			;
}

} /* namespace pyxerces */
