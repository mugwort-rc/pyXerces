/*
 * DOMElement.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMElement.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMAttr.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMNodeList.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMTypeInfo.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMElement.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class DOMElementDefVisitor
: public boost::python::def_visitor<DOMElementDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getAttribute", &DOMElementDefVisitor::getAttribute, boost::python::return_value_policy<boost::python::return_by_value>())
	.def("getAttributeNode", &DOMElementDefVisitor::getAttributeNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagName", &DOMElementDefVisitor::getElementsByTagName, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setAttribute", &DOMElementDefVisitor::setAttribute)
	.def("removeAttribute", &DOMElementDefVisitor::removeAttribute)
	.def("getAttributeNS", &DOMElementDefVisitor::getAttributeNS, boost::python::return_value_policy<boost::python::return_by_value>())
	.def("setAttributeNS", &DOMElementDefVisitor::setAttributeNS)
	.def("removeAttributeNS", &DOMElementDefVisitor::removeAttributeNS)
	.def("getAttributeNodeNS", &DOMElementDefVisitor::getAttributeNodeNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagNameNS", &DOMElementDefVisitor::getElementsByTagNameNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("hasAttribute", &DOMElementDefVisitor::hasAttribute)
	.def("hasAttributeNS", &DOMElementDefVisitor::hasAttributeNS)
	.def("setIdAttribute", &DOMElementDefVisitor::setIdAttribute)
	.def("setIdAttributeNS", &DOMElementDefVisitor::setIdAttributeNS)
	;
}

static const XMLCh* getAttribute(xercesc::DOMElement& self, const STR& name) {
	XMLString buff(name);
	return self.getAttribute(buff.ptr());
}

static xercesc::DOMAttr* getAttributeNode(xercesc::DOMElement& self, const STR& name) {
	XMLString buff(name);
	return self.getAttributeNode(buff.ptr());
}

static xercesc::DOMNodeList* getElementsByTagName(xercesc::DOMElement& self, const STR& name) {
	XMLString buff(name);
	return self.getElementsByTagName(buff.ptr());
}

static void setAttribute(xercesc::DOMElement& self, const STR& name, const STR& value) {
	XMLString buff1(name), buff2(value);
	self.setAttribute(buff1.ptr(), buff2.ptr());
}

static void removeAttribute(xercesc::DOMElement& self, const STR& name) {
	XMLString buff(name);
	self.removeAttribute(buff.ptr());
}

static const XMLCh* getAttributeNS(xercesc::DOMElement& self, const STR& namespaceURI, const STR& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return self.getAttributeNS(buff1.ptr(), buff2.ptr());
}

static void setAttributeNS(xercesc::DOMElement& self, const STR& namespaceURI, const STR& qualifiedName, const STR& value) {
	XMLString buff1(namespaceURI), buff2(qualifiedName), buff3(value);
	self.setAttributeNS(buff1.ptr(), buff2.ptr(), buff3.ptr());
}

static void removeAttributeNS(xercesc::DOMElement& self, const STR& namespaceURI, const STR& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	self.removeAttributeNS(buff1.ptr(), buff2.ptr());
}

static xercesc::DOMAttr* getAttributeNodeNS(xercesc::DOMElement& self, const STR& namespaceURI, const STR& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return self.getAttributeNodeNS(buff1.ptr(), buff2.ptr());
}

static xercesc::DOMNodeList* getElementsByTagNameNS(xercesc::DOMElement& self, const STR& namespaceURI, const STR& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return self.getElementsByTagNameNS(buff1.ptr(), buff2.ptr());
}

static bool hasAttribute(xercesc::DOMElement& self, const STR& name) {
	XMLString buff(name);
	return self.hasAttribute(buff.ptr());
}

static bool hasAttributeNS(xercesc::DOMElement& self, const STR& namespaceURI, const STR& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return self.hasAttributeNS(buff1.ptr(), buff2.ptr());
}

static void setIdAttribute(xercesc::DOMElement& self, const STR& name, bool isId) {
	XMLString buff(name);
	self.setIdAttribute(buff.ptr(), isId);
}

static void setIdAttributeNS(xercesc::DOMElement& self, const STR& namespaceURI, const STR& localName, bool isId) {
	XMLString buff1(namespaceURI), buff2(localName);
	self.setIdAttributeNS(buff1.ptr(), buff2.ptr(), isId);
}

};

void DOMElement_init(void) {
	//! xercesc::DOMElement
	boost::python::class_<xercesc::DOMElement, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMElement", boost::python::no_init)
			.def(DOMElementDefVisitor<XMLString>())
			.def(DOMElementDefVisitor<std::string>())
			.def("getTagName", &xercesc::DOMElement::getTagName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAttribute", &xercesc::DOMElement::getAttribute, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAttributeNode", &xercesc::DOMElement::getAttributeNode, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getElementsByTagName", &xercesc::DOMElement::getElementsByTagName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setAttribute", &xercesc::DOMElement::setAttribute)
			.def("setAttributeNode", &xercesc::DOMElement::setAttributeNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeAttributeNode", &xercesc::DOMElement::removeAttributeNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeAttribute", &xercesc::DOMElement::removeAttribute)
			.def("getAttributeNS", &xercesc::DOMElement::getAttributeNS, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setAttributeNS", &xercesc::DOMElement::setAttributeNS)
			.def("removeAttributeNS", &xercesc::DOMElement::removeAttributeNS)
			.def("getAttributeNodeNS", &xercesc::DOMElement::getAttributeNodeNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setAttributeNodeNS", &xercesc::DOMElement::setAttributeNodeNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementsByTagNameNS", &xercesc::DOMElement::getElementsByTagNameNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hasAttribute", &xercesc::DOMElement::hasAttribute)
			.def("hasAttributeNS", &xercesc::DOMElement::hasAttributeNS)
			.def("setIdAttribute", &xercesc::DOMElement::setIdAttribute)
			.def("setIdAttributeNS", &xercesc::DOMElement::setIdAttributeNS)
			.def("setIdAttributeNode", &xercesc::DOMElement::setIdAttributeNode)
			.def("getSchemaTypeInfo", &xercesc::DOMElement::getSchemaTypeInfo, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFirstElementChild", &xercesc::DOMElement::getFirstElementChild, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLastElementChild", &xercesc::DOMElement::getLastElementChild, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPreviousElementSibling", &xercesc::DOMElement::getPreviousElementSibling, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNextElementSibling", &xercesc::DOMElement::getNextElementSibling, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getChildElementCount", &xercesc::DOMElement::getChildElementCount)
			;
}

} /* namespace pyxerces */
