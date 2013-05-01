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

template <typename STR>
class DOMStringListDefVisitor
: public boost::python::def_visitor<DOMStringListDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("contains", &DOMStringListDefVisitor::contains)
	;
}

static bool contains(xercesc::DOMStringList& self, const STR value) {
	XMLString buff(value);
	return self.contains(buff.ptr());
}

};

class DOMStringListWrapper
: public xercesc::DOMStringList, public boost::python::wrapper<xercesc::DOMStringList>
{
public:
const XMLCh *item(XMLSize_t index) const {
	return this->get_override("item")(index);
}

XMLSize_t getLength() const {
	return this->get_override("getLength")();
}

bool contains(const XMLCh* val) const {
	return this->get_override("getLength")(XMLString(val));
}

void release(){
	this->get_override("release")();
}

};

void DOMStringList_init(void) {
	//! xercesc::DOMStringList
	boost::python::class_<DOMStringListWrapper, boost::noncopyable>("DOMStringList")
			.def(DOMStringListDefVisitor<XMLString&>())
			.def(DOMStringListDefVisitor<char*>())
			.def("item", boost::python::pure_virtual(&xercesc::DOMStringList::item), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLength", boost::python::pure_virtual(&xercesc::DOMStringList::getLength))
			.def("contains", boost::python::pure_virtual(&xercesc::DOMStringList::contains))
			.def("release", boost::python::pure_virtual(&xercesc::DOMStringList::release))
			;
}

} /* namespace pyxerces */
