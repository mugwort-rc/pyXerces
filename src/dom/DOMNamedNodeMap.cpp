/*
 * DOMNamedNodeMap.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMNamedNodeMap.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNode.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMNamedNodeMap.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class DOMNamedNodeMapDefVisitor
: public boost::python::def_visitor<DOMNamedNodeMapDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getNamedItem", &DOMNamedNodeMapDefVisitor::getNamedItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("removeNamedItem", &DOMNamedNodeMapDefVisitor::removeNamedItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getNamedItemNS", &DOMNamedNodeMapDefVisitor::getNamedItemNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("removeNamedItemNS", &DOMNamedNodeMapDefVisitor::removeNamedItemNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMNode* getNamedItem(xercesc::DOMNamedNodeMap& self, const STR& name) {
	XMLString buff(name);
	return self.getNamedItem(buff.ptr());
}

static xercesc::DOMNode* removeNamedItem(xercesc::DOMNamedNodeMap& self, const STR& name) {
	XMLString buff(name);
	return self.removeNamedItem(buff.ptr());
}

static xercesc::DOMNode* getNamedItemNS(xercesc::DOMNamedNodeMap& self, const STR& namespaceURI, const STR& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return self.getNamedItemNS(buff1.ptr(), buff2.ptr());
}

static xercesc::DOMNode* removeNamedItemNS(xercesc::DOMNamedNodeMap& self, const STR& namespaceURI, const STR& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return self.removeNamedItemNS(buff1.ptr(), buff2.ptr());
}

};

void DOMNamedNodeMap_init(void) {
	//! xercesc::DOMNamedNodeMap
	boost::python::class_<xercesc::DOMNamedNodeMap, boost::noncopyable>("DOMNamedNodeMap", boost::python::no_init)
			.def(DOMNamedNodeMapDefVisitor<XMLString>())
			.def(DOMNamedNodeMapDefVisitor<std::string>())
			.def("setNamedItem", &xercesc::DOMNamedNodeMap::setNamedItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("item", &xercesc::DOMNamedNodeMap::item, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNamedItem", &xercesc::DOMNamedNodeMap::getNamedItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLength", &xercesc::DOMNamedNodeMap::getLength)
			.def("removeNamedItem", &xercesc::DOMNamedNodeMap::removeNamedItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNamedItemNS", &xercesc::DOMNamedNodeMap::getNamedItemNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setNamedItemNS", &xercesc::DOMNamedNodeMap::setNamedItemNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeNamedItemNS", &xercesc::DOMNamedNodeMap::removeNamedItemNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
