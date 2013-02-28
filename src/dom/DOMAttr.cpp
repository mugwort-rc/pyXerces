/*
 * DOMAttr.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMAttr.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMElement.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMTypeInfo.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMAttr.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class DOMAttrDefVisitor
: public boost::python::def_visitor<DOMAttrDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setValue", &DOMAttrDefVisitor::setValue)
	;
}

static void setValue(xercesc::DOMAttr& self, const STR& value) {
	XMLString buff(value);
	self.setValue(buff.ptr());
}

};

void DOMAttr_init(void) {
	//! xercesc::DOMAttr
	boost::python::class_<xercesc::DOMAttr, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMAttr", boost::python::no_init)
			.def(DOMAttrDefVisitor<XMLString>())
			.def(DOMAttrDefVisitor<std::string>())
			.def("getName", &xercesc::DOMAttr::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSpecified", &xercesc::DOMAttr::getSpecified)
			.def("getValue", &xercesc::DOMAttr::getValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setValue", &xercesc::DOMAttr::setValue)
			.def("getOwnerElement", &xercesc::DOMAttr::getOwnerElement, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isId", &xercesc::DOMAttr::isId)
			.def("getSchemaTypeInfo", &xercesc::DOMAttr::getSchemaTypeInfo, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
