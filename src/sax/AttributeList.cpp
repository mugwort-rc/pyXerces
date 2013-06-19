/*
 * AttributeList.cpp
 *
 *  Created on: 2013/03/07
 *      Author: mugwort_rc
 */

#include "AttributeList.h"

#include <boost/python.hpp>
#include <xercesc/sax/AttributeList.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class AttributeListWrapper
: public xercesc::AttributeList, public boost::python::wrapper<xercesc::AttributeList>
{
public:
	XMLSize_t getLength() const {
		return this->get_override("getLength")();
	}

	const XMLCh* getName(const XMLSize_t index) const {
		return this->get_override("getName")(index);
	}

	const XMLCh* getType(const XMLSize_t index) const {
		return this->get_override("getType")(index);
	}

	const XMLCh* getValue(const XMLSize_t index) const {
		return this->get_override("getValue")(index);
	}

	const XMLCh* getType(const XMLCh* const name) const {
		return this->get_override("getType")(name);
	}

	const XMLCh* getValue(const XMLCh* const name) const {
		return this->get_override("getValue")(name);
	}

	const XMLCh* getValue(const char* const name) const {
		return this->get_override("getValue")(name);
	}
};

class AttributeListDefVisitor
: public boost::python::def_visitor<AttributeListDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getType", &AttributeListDefVisitor::getType, boost::python::return_value_policy<boost::python::return_by_value>())
	.def("getValue", &AttributeListDefVisitor::getValue, boost::python::return_value_policy<boost::python::return_by_value>())
	;
}

static const XMLCh* getType(xercesc::AttributeList& self, const XMLString& name) {
	return self.getType(name.ptr());
}

static const XMLCh* getValue(xercesc::AttributeList& self, const XMLString& name) {
	return self.getValue(name.ptr());
}

};

void AttributeList_init(void) {
	//! xercesc::AttributeList
	boost::python::class_<AttributeListWrapper, boost::noncopyable>("AttributeList")
			.def(AttributeListDefVisitor())
			.def("getLength", &xercesc::AttributeList::getLength)
			.def("getName", &xercesc::AttributeList::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getType", boost::python::pure_virtual(static_cast<const XMLCh*(xercesc::AttributeList::*)(const XMLSize_t) const>(&xercesc::AttributeList::getType)), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getValue", boost::python::pure_virtual(static_cast<const XMLCh*(xercesc::AttributeList::*)(const XMLSize_t) const>(&xercesc::AttributeList::getValue)), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getType", boost::python::pure_virtual(static_cast<const XMLCh*(xercesc::AttributeList::*)(const XMLCh* const) const>(&xercesc::AttributeList::getType)), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getValue", boost::python::pure_virtual(static_cast<const XMLCh*(xercesc::AttributeList::*)(const XMLCh* const) const>(&xercesc::AttributeList::getValue)), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getValue", boost::python::pure_virtual(static_cast<const XMLCh*(xercesc::AttributeList::*)(const char* const) const>(&xercesc::AttributeList::getValue)), boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxerces */
