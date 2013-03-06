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

template <class STR>
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

static unsigned int addOrFind(xercesc::XMLStringPool& self, const STR& newString) {
	XMLString buff(newString);
	return self.addOrFind(buff.ptr());
}

static bool exists(xercesc::XMLStringPool& self, const STR& newString) {
	XMLString buff(newString);
	return self.exists(buff.ptr());
}

static unsigned int getId(xercesc::XMLStringPool& self, const STR& toFind) {
	XMLString buff(toFind);
	return self.getId(buff.ptr());
}

};

void StringPool_init(void) {
	//! xercesc::XMLStringPool
	boost::python::class_<xercesc::XMLStringPool, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLStringPool", boost::python::init<boost::python::optional<const unsigned int, xercesc::MemoryManager* const> >())
			.def(boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(XMLStringPoolDefVisitor<XMLString>())
			.def(XMLStringPoolDefVisitor<std::string>())
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
