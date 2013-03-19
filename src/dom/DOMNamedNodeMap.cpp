/*
 * DOMNamedNodeMap.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMNamedNodeMap.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMNode.hpp>

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

class DOMNamedNodeMapWrapper
: public xercesc::DOMNamedNodeMap, public boost::python::wrapper<xercesc::DOMNamedNodeMap>
{
public:
xercesc::DOMNode *setNamedItem(xercesc::DOMNode *arg) {
	return this->get_override("setNamedItem")(boost::python::ptr(arg));
}

xercesc::DOMNode *item(XMLSize_t index) const {
	return this->get_override("item")(index);
}

xercesc::DOMNode *getNamedItem(const XMLCh *name) const {
	return this->get_override("getNamedItem")(XMLString(name));
}

XMLSize_t getLength() const {
	return this->get_override("getLength")();
}

xercesc::DOMNode *removeNamedItem(const XMLCh *name) {
	return this->get_override("removeNamedItem")(XMLString(name));
}

xercesc::DOMNode *getNamedItemNS(const XMLCh *namespaceURI, const XMLCh *localName) const {
	return this->get_override("getNamedItemNS")(XMLString(namespaceURI), XMLString(localName));
}

xercesc::DOMNode *setNamedItemNS(xercesc::DOMNode *arg) {
	return this->get_override("setNamedItemNS")(boost::python::ptr(arg));
}

xercesc::DOMNode *removeNamedItemNS(const XMLCh *namespaceURI, const XMLCh *localName) {
	return this->get_override("removeNamedItemNS")(XMLString(namespaceURI), XMLString(localName));
}

};

void DOMNamedNodeMap_init(void) {
	//! xercesc::DOMNamedNodeMap
	boost::python::class_<DOMNamedNodeMapWrapper, boost::noncopyable>("DOMNamedNodeMap")
			.def(DOMNamedNodeMapDefVisitor<XMLString>())
			.def(DOMNamedNodeMapDefVisitor<std::string>())
			.def("setNamedItem", boost::python::pure_virtual(&xercesc::DOMNamedNodeMap::setNamedItem), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("item", boost::python::pure_virtual(&xercesc::DOMNamedNodeMap::item), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNamedItem", boost::python::pure_virtual(&xercesc::DOMNamedNodeMap::getNamedItem), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLength", boost::python::pure_virtual(&xercesc::DOMNamedNodeMap::getLength))
			.def("removeNamedItem", boost::python::pure_virtual(&xercesc::DOMNamedNodeMap::removeNamedItem), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNamedItemNS", boost::python::pure_virtual(&xercesc::DOMNamedNodeMap::getNamedItemNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setNamedItemNS", boost::python::pure_virtual(&xercesc::DOMNamedNodeMap::setNamedItemNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeNamedItemNS", boost::python::pure_virtual(&xercesc::DOMNamedNodeMap::removeNamedItemNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
