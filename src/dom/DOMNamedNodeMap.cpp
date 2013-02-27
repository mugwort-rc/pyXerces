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

class DOMNamedNodeMapDefVisitor
: public boost::python::def_visitor<DOMNamedNodeMapDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getNamedItem", static_cast<xercesc::DOMNode*(*)(xercesc::DOMNamedNodeMap&, const XMLString&)>(&DOMNamedNodeMapDefVisitor::getNamedItem), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getNamedItem", static_cast<xercesc::DOMNode*(*)(xercesc::DOMNamedNodeMap&, const std::string&)>(&DOMNamedNodeMapDefVisitor::getNamedItem), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("removeNamedItem", static_cast<xercesc::DOMNode*(*)(xercesc::DOMNamedNodeMap&, const XMLString&)>(&DOMNamedNodeMapDefVisitor::removeNamedItem), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("removeNamedItem", static_cast<xercesc::DOMNode*(*)(xercesc::DOMNamedNodeMap&, const std::string&)>(&DOMNamedNodeMapDefVisitor::removeNamedItem), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getNamedItemNS", static_cast<xercesc::DOMNode*(*)(xercesc::DOMNamedNodeMap&, const XMLString&, const XMLString&)>(&DOMNamedNodeMapDefVisitor::getNamedItemNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getNamedItemNS", static_cast<xercesc::DOMNode*(*)(xercesc::DOMNamedNodeMap&, const std::string&, const std::string&)>(&DOMNamedNodeMapDefVisitor::getNamedItemNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("removeNamedItemNS", static_cast<xercesc::DOMNode*(*)(xercesc::DOMNamedNodeMap&, const XMLString&, const XMLString&)>(&DOMNamedNodeMapDefVisitor::removeNamedItemNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("removeNamedItemNS", static_cast<xercesc::DOMNode*(*)(xercesc::DOMNamedNodeMap&, const std::string&, const std::string&)>(&DOMNamedNodeMapDefVisitor::removeNamedItemNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMNode* getNamedItem(xercesc::DOMNamedNodeMap& self, const XMLString& name) {
	return self.getNamedItem(name.ptr());
}

static xercesc::DOMNode* getNamedItem(xercesc::DOMNamedNodeMap& self, const std::string& name) {
	XMLString buff(name);
	return DOMNamedNodeMapDefVisitor::getNamedItem(self, buff);
}

static xercesc::DOMNode* removeNamedItem(xercesc::DOMNamedNodeMap& self, const XMLString& name) {
	return self.removeNamedItem(name.ptr());
}

static xercesc::DOMNode* removeNamedItem(xercesc::DOMNamedNodeMap& self, const std::string& name) {
	XMLString buff(name);
	return DOMNamedNodeMapDefVisitor::removeNamedItem(self, buff);
}

static xercesc::DOMNode* getNamedItemNS(xercesc::DOMNamedNodeMap& self, const XMLString& namespaceURI, const XMLString& localName) {
	return self.getNamedItemNS(namespaceURI.ptr(), localName.ptr());
}

static xercesc::DOMNode* getNamedItemNS(xercesc::DOMNamedNodeMap& self, const std::string& namespaceURI, const std::string& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return DOMNamedNodeMapDefVisitor::getNamedItemNS(self, buff1, buff2);
}

static xercesc::DOMNode* removeNamedItemNS(xercesc::DOMNamedNodeMap& self, const XMLString& namespaceURI, const XMLString& localName) {
	return self.removeNamedItemNS(namespaceURI.ptr(), localName.ptr());
}

static xercesc::DOMNode* removeNamedItemNS(xercesc::DOMNamedNodeMap& self, const std::string& namespaceURI, const std::string& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return DOMNamedNodeMapDefVisitor::removeNamedItemNS(self, buff1, buff2);
}

};

void DOMNamedNodeMap_init(void) {
	//! xercesc::DOMNamedNodeMap
	boost::python::class_<xercesc::DOMNamedNodeMap, boost::noncopyable>("DOMNamedNodeMap", boost::python::no_init)
			.def(DOMNamedNodeMapDefVisitor())
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
