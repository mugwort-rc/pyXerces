/*
 * DOMStringList.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMStringList.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMStringList.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMStringListDefVisitor
: public boost::python::def_visitor<DOMStringListDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("contains", static_cast<bool(*)(xercesc::DOMStringList&, const XMLString&)>(&DOMStringListDefVisitor::contains))
	.def("contains", static_cast<bool(*)(xercesc::DOMStringList&, const std::string&)>(&DOMStringListDefVisitor::contains))
	;
}

static bool contains(xercesc::DOMStringList& self, const XMLString& value) {
	return self.contains(value.ptr());
}

static bool contains(xercesc::DOMStringList& self, const std::string& value) {
	XMLString buff(value);
	return DOMStringListDefVisitor::contains(self, buff);
}
};

void DOMStringList_init(void) {
	//! xercesc::DOMStringList
	boost::python::class_<xercesc::DOMStringList, boost::noncopyable>("DOMStringList", boost::python::no_init)
			.def(DOMStringListDefVisitor())
			.def("item", &xercesc::DOMStringList::item, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLength", &xercesc::DOMStringList::getLength)
			.def("contains", &xercesc::DOMStringList::contains)
			.def("release", &xercesc::DOMStringList::release)
			;
}

} /* namespace pyxerces */
