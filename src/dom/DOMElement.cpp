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

class DOMElementDefVisitor
: public boost::python::def_visitor<DOMElementDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getAttribute", static_cast<const XMLCh*(*)(xercesc::DOMElement&, const XMLString&)>(&DOMElementDefVisitor::getAttribute), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("getAttribute", static_cast<const XMLCh*(*)(xercesc::DOMElement&, const std::string&)>(&DOMElementDefVisitor::getAttribute), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("getAttributeNode", static_cast<xercesc::DOMAttr*(*)(xercesc::DOMElement&, const XMLString&)>(&DOMElementDefVisitor::getAttributeNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getAttributeNode", static_cast<xercesc::DOMAttr*(*)(xercesc::DOMElement&, const std::string&)>(&DOMElementDefVisitor::getAttributeNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagName", static_cast<xercesc::DOMNodeList*(*)(xercesc::DOMElement&, const XMLString&)>(&DOMElementDefVisitor::getElementsByTagName), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagName", static_cast<xercesc::DOMNodeList*(*)(xercesc::DOMElement&, const std::string&)>(&DOMElementDefVisitor::getElementsByTagName), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setAttribute", static_cast<void(*)(xercesc::DOMElement&, const XMLString&, const XMLString&)>(&DOMElementDefVisitor::setAttribute))
	.def("setAttribute", static_cast<void(*)(xercesc::DOMElement&, const std::string&, const std::string&)>(&DOMElementDefVisitor::setAttribute))
	.def("removeAttribute", static_cast<void(*)(xercesc::DOMElement&, const XMLString&)>(&DOMElementDefVisitor::removeAttribute))
	.def("removeAttribute", static_cast<void(*)(xercesc::DOMElement&, const std::string&)>(&DOMElementDefVisitor::removeAttribute))
	.def("getAttributeNS", static_cast<const XMLCh*(*)(xercesc::DOMElement&, const XMLString&, const XMLString&)>(&DOMElementDefVisitor::getAttributeNS), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("getAttributeNS", static_cast<const XMLCh*(*)(xercesc::DOMElement&, const std::string&, const std::string&)>(&DOMElementDefVisitor::getAttributeNS), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("setAttributeNS", static_cast<void(*)(xercesc::DOMElement&, const XMLString&, const XMLString&, const XMLString&)>(&DOMElementDefVisitor::setAttributeNS))
	.def("setAttributeNS", static_cast<void(*)(xercesc::DOMElement&, const std::string&, const std::string&, const std::string&)>(&DOMElementDefVisitor::setAttributeNS))
	.def("removeAttributeNS", static_cast<void(*)(xercesc::DOMElement&, const XMLString&, const XMLString&)>(&DOMElementDefVisitor::removeAttributeNS))
	.def("removeAttributeNS", static_cast<void(*)(xercesc::DOMElement&, const std::string&, const std::string&)>(&DOMElementDefVisitor::removeAttributeNS))
	.def("getAttributeNodeNS", static_cast<xercesc::DOMAttr*(*)(xercesc::DOMElement&, const XMLString&, const XMLString&)>(&DOMElementDefVisitor::getAttributeNodeNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getAttributeNodeNS", static_cast<xercesc::DOMAttr*(*)(xercesc::DOMElement&, const std::string&, const std::string&)>(&DOMElementDefVisitor::getAttributeNodeNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagNameNS", static_cast<xercesc::DOMNodeList*(*)(xercesc::DOMElement&, const XMLString&, const XMLString&)>(&DOMElementDefVisitor::getElementsByTagNameNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagNameNS", static_cast<xercesc::DOMNodeList*(*)(xercesc::DOMElement&, const std::string&, const std::string&)>(&DOMElementDefVisitor::getElementsByTagNameNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("hasAttribute", static_cast<bool(*)(xercesc::DOMElement&, const XMLString&)>(&DOMElementDefVisitor::hasAttribute))
	.def("hasAttribute", static_cast<bool(*)(xercesc::DOMElement&, const std::string&)>(&DOMElementDefVisitor::hasAttribute))
	.def("hasAttributeNS", static_cast<bool(*)(xercesc::DOMElement&, const XMLString&, const XMLString&)>(&DOMElementDefVisitor::hasAttributeNS))
	.def("hasAttributeNS", static_cast<bool(*)(xercesc::DOMElement&, const std::string&, const std::string&)>(&DOMElementDefVisitor::hasAttributeNS))
	.def("setIdAttribute", static_cast<void(*)(xercesc::DOMElement&, const XMLString&, bool)>(&DOMElementDefVisitor::setIdAttribute))
	.def("setIdAttribute", static_cast<void(*)(xercesc::DOMElement&, const std::string&, bool)>(&DOMElementDefVisitor::setIdAttribute))
	.def("setIdAttributeNS", static_cast<void(*)(xercesc::DOMElement&, const XMLString&, const XMLString&, bool)>(&DOMElementDefVisitor::setIdAttributeNS))
	.def("setIdAttributeNS", static_cast<void(*)(xercesc::DOMElement&, const std::string&, const std::string&, bool)>(&DOMElementDefVisitor::setIdAttributeNS))
	;
}

static const XMLCh* getAttribute(xercesc::DOMElement& self, const XMLString& name) {
	return self.getAttribute(name.ptr());
}

static const XMLCh* getAttribute(xercesc::DOMElement& self, const std::string& name) {
	XMLString buff(name);
	return DOMElementDefVisitor::getAttribute(self, buff);
}

static xercesc::DOMAttr* getAttributeNode(xercesc::DOMElement& self, const XMLString& name) {
	return self.getAttributeNode(name.ptr());
}

static xercesc::DOMAttr* getAttributeNode(xercesc::DOMElement& self, const std::string& name) {
	XMLString buff(name);
	return DOMElementDefVisitor::getAttributeNode(self, buff);
}

static xercesc::DOMNodeList* getElementsByTagName(xercesc::DOMElement& self, const XMLString& name) {
	return self.getElementsByTagName(name.ptr());
}

static xercesc::DOMNodeList* getElementsByTagName(xercesc::DOMElement& self, const std::string& name) {
	XMLString buff(name);
	return DOMElementDefVisitor::getElementsByTagName(self, buff);
}

static void setAttribute(xercesc::DOMElement& self, const XMLString& name, const XMLString& value) {
	self.setAttribute(name.ptr(), value.ptr());
}

static void setAttribute(xercesc::DOMElement& self, const std::string& name, const std::string& value) {
	XMLString buff1(name), buff2(value);
	DOMElementDefVisitor::setAttribute(self, buff1, buff2);
}

static void removeAttribute(xercesc::DOMElement& self, const XMLString& name) {
	self.removeAttribute(name.ptr());
}

static void removeAttribute(xercesc::DOMElement& self, const std::string& name) {
	XMLString buff(name);
	DOMElementDefVisitor::removeAttribute(self, buff);
}

static const XMLCh* getAttributeNS(xercesc::DOMElement& self, const XMLString& namespaceURI, const XMLString& localName) {
	return self.getAttributeNS(namespaceURI.ptr(), localName.ptr());
}

static const XMLCh* getAttributeNS(xercesc::DOMElement& self, const std::string& namespaceURI, const std::string& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return DOMElementDefVisitor::getAttributeNS(self, buff1, buff2);
}

static void setAttributeNS(xercesc::DOMElement& self, const XMLString& namespaceURI, const XMLString& qualifiedName, const XMLString& value) {
	self.setAttributeNS(namespaceURI.ptr(), qualifiedName.ptr(), value.ptr());
}

static void setAttributeNS(xercesc::DOMElement& self, const std::string& namespaceURI, const std::string& qualifiedName, const std::string& value) {
	XMLString buff1(namespaceURI), buff2(qualifiedName), buff3(value);
	DOMElementDefVisitor::setAttributeNS(self, buff1, buff2, buff3);
}

static void removeAttributeNS(xercesc::DOMElement& self, const XMLString& namespaceURI, const XMLString& localName) {
	self.removeAttributeNS(namespaceURI.ptr(), localName.ptr());
}

static void removeAttributeNS(xercesc::DOMElement& self, const std::string& namespaceURI, const std::string& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	DOMElementDefVisitor::removeAttributeNS(self, buff1, buff2);
}

static xercesc::DOMAttr* getAttributeNodeNS(xercesc::DOMElement& self, const XMLString& namespaceURI, const XMLString& localName) {
	return self.getAttributeNodeNS(namespaceURI.ptr(), localName.ptr());
}

static xercesc::DOMAttr* getAttributeNodeNS(xercesc::DOMElement& self, const std::string& namespaceURI, const std::string& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return DOMElementDefVisitor::getAttributeNodeNS(self, buff1, buff2);
}

static xercesc::DOMNodeList* getElementsByTagNameNS(xercesc::DOMElement& self, const XMLString& namespaceURI, const XMLString& localName) {
	return self.getElementsByTagNameNS(namespaceURI.ptr(), localName.ptr());
}

static xercesc::DOMNodeList* getElementsByTagNameNS(xercesc::DOMElement& self, const std::string& namespaceURI, const std::string& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return DOMElementDefVisitor::getElementsByTagNameNS(self, buff1, buff2);
}

static bool hasAttribute(xercesc::DOMElement& self, const XMLString& name) {
	return self.hasAttribute(name.ptr());
}

static bool hasAttribute(xercesc::DOMElement& self, const std::string& name) {
	XMLString buff(name);
	return DOMElementDefVisitor::hasAttribute(self, buff);
}

static bool hasAttributeNS(xercesc::DOMElement& self, const XMLString& namespaceURI, const XMLString& localName) {
	return self.hasAttributeNS(namespaceURI.ptr(), localName.ptr());
}

static bool hasAttributeNS(xercesc::DOMElement& self, const std::string& namespaceURI, const std::string& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return DOMElementDefVisitor::hasAttributeNS(self, buff1, buff2);
}

static void setIdAttribute(xercesc::DOMElement& self, const XMLString& name, bool isId) {
	self.setIdAttribute(name.ptr(), isId);
}

static void setIdAttribute(xercesc::DOMElement& self, const std::string& name, bool isId) {
	XMLString buff(name);
	DOMElementDefVisitor::setIdAttribute(self, buff, isId);
}

static void setIdAttributeNS(xercesc::DOMElement& self, const XMLString& namespaceURI, const XMLString& localName, bool isId) {
	self.setIdAttributeNS(namespaceURI.ptr(), localName.ptr(), isId);
}

static void setIdAttributeNS(xercesc::DOMElement& self, const std::string& namespaceURI, const std::string& localName, bool isId) {
	XMLString buff1(namespaceURI), buff2(localName);
	DOMElementDefVisitor::setIdAttributeNS(self, buff1, buff2, isId);
}
};

void DOMElement_init(void) {
	//! xercesc::DOMElement
	boost::python::class_<xercesc::DOMElement, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMElement", boost::python::no_init)
			.def(DOMElementDefVisitor())
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
