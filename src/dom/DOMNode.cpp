/*
 * DOMNode.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMNode.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMDocument.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMNamedNodeMap.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMNodeList.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMUserDataHandler.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMNode.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMNodeDefVisitor
: public boost::python::def_visitor<DOMNodeDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setNodeValue", static_cast<void(*)(xercesc::DOMNode&, const XMLString&)>(&DOMNodeDefVisitor::setNodeValue))
	.def("setNodeValue", static_cast<void(*)(xercesc::DOMNode&, const std::string&)>(&DOMNodeDefVisitor::setNodeValue))
	.def("isSupported", static_cast<bool(*)(xercesc::DOMNode&, const XMLString&, const XMLString&)>(&DOMNodeDefVisitor::isSupported))
	.def("isSupported", static_cast<bool(*)(xercesc::DOMNode&, const std::string&, const std::string&)>(&DOMNodeDefVisitor::isSupported))
	.def("setPrefix", static_cast<void(*)(xercesc::DOMNode&, const XMLString&)>(&DOMNodeDefVisitor::setPrefix))
	.def("setPrefix", static_cast<void(*)(xercesc::DOMNode&, const std::string&)>(&DOMNodeDefVisitor::setPrefix))
	.def("setUserData", static_cast<void*(*)(xercesc::DOMNode&, const XMLString&, void*, xercesc::DOMUserDataHandler*)>(&DOMNodeDefVisitor::setUserData), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("setUserData", static_cast<void*(*)(xercesc::DOMNode&, const std::string&, void*, xercesc::DOMUserDataHandler*)>(&DOMNodeDefVisitor::setUserData), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("getUserData", static_cast<void*(*)(xercesc::DOMNode&, const XMLString&)>(&DOMNodeDefVisitor::getUserData), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("getUserData", static_cast<void*(*)(xercesc::DOMNode&, const std::string&)>(&DOMNodeDefVisitor::getUserData), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("setTextContent", static_cast<void(*)(xercesc::DOMNode&, const XMLString&)>(&DOMNodeDefVisitor::setTextContent))
	.def("setTextContent", static_cast<void(*)(xercesc::DOMNode&, const std::string&)>(&DOMNodeDefVisitor::setTextContent))
	.def("lookupPrefix", static_cast<const XMLCh*(*)(xercesc::DOMNode&, const XMLString&)>(&DOMNodeDefVisitor::lookupPrefix), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("lookupPrefix", static_cast<const XMLCh*(*)(xercesc::DOMNode&, const std::string&)>(&DOMNodeDefVisitor::lookupPrefix), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("isDefaultNamespace", static_cast<bool(*)(xercesc::DOMNode&, const XMLString&)>(&DOMNodeDefVisitor::isDefaultNamespace))
	.def("isDefaultNamespace", static_cast<bool(*)(xercesc::DOMNode&, const std::string&)>(&DOMNodeDefVisitor::isDefaultNamespace))
	.def("lookupNamespaceURI", static_cast<const XMLCh*(*)(xercesc::DOMNode&, const XMLString&)>(&DOMNodeDefVisitor::lookupNamespaceURI), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("lookupNamespaceURI", static_cast<const XMLCh*(*)(xercesc::DOMNode&, const std::string&)>(&DOMNodeDefVisitor::lookupNamespaceURI), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("getFeature", static_cast<void*(*)(xercesc::DOMNode&, const XMLString&, const XMLString&)>(&DOMNodeDefVisitor::getFeature), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("getFeature", static_cast<void*(*)(xercesc::DOMNode&, const std::string&, const std::string&)>(&DOMNodeDefVisitor::getFeature), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	;
}

static void setNodeValue(xercesc::DOMNode& self, const XMLString& nodeValue) {
	self.setNodeValue(nodeValue.ptr());
}

static void setNodeValue(xercesc::DOMNode& self, const std::string& nodeValue) {
	XMLString buff(nodeValue);
	DOMNodeDefVisitor::setNodeValue(self, buff);
}

static bool isSupported(xercesc::DOMNode& self, const XMLString& feature, const XMLString& version) {
	return self.isSupported(feature.ptr(), version.ptr());
}

static bool isSupported(xercesc::DOMNode& self, const std::string& feature, const std::string& version) {
	XMLString buff1(feature), buff2(version);
	return DOMNodeDefVisitor::isSupported(self, buff1, buff2);
}

static void setPrefix(xercesc::DOMNode& self, const XMLString& prefix) {
	self.setPrefix(prefix.ptr());
}

static void setPrefix(xercesc::DOMNode& self, const std::string& prefix) {
	XMLString buff(prefix);
	DOMNodeDefVisitor::setPrefix(self, buff);
}

static void* setUserData(xercesc::DOMNode& self, const XMLString& key, void* data, xercesc::DOMUserDataHandler* handler) {
	return self.setUserData(key.ptr(), data, handler);
}

static void* setUserData(xercesc::DOMNode& self, const std::string& key, void* data, xercesc::DOMUserDataHandler* handler) {
	XMLString buff(key);
	return DOMNodeDefVisitor::setUserData(self, buff, data, handler);
}

static void* getUserData(xercesc::DOMNode& self, const XMLString& key) {
	return self.getUserData(key.ptr());
}

static void* getUserData(xercesc::DOMNode& self, const std::string& key) {
	XMLString buff(key);
	return DOMNodeDefVisitor::getUserData(self, buff);
}

static void setTextContent(xercesc::DOMNode& self, const XMLString& textContent) {
	self.setTextContent(textContent.ptr());
}

static void setTextContent(xercesc::DOMNode& self, const std::string& textContent) {
	XMLString buff(textContent);
	DOMNodeDefVisitor::setTextContent(self, buff);
}

static const XMLCh* lookupPrefix(xercesc::DOMNode& self, const XMLString& namespaceURI) {
	return self.lookupPrefix(namespaceURI.ptr());
}

static const XMLCh* lookupPrefix(xercesc::DOMNode& self, const std::string& namespaceURI) {
	XMLString buff(namespaceURI);
	return DOMNodeDefVisitor::lookupPrefix(self, buff);
}

static bool isDefaultNamespace(xercesc::DOMNode& self, const XMLString& namespaceURI) {
	return self.isDefaultNamespace(namespaceURI.ptr());
}

static bool isDefaultNamespace(xercesc::DOMNode& self, const std::string& namespaceURI) {
	XMLString buff(namespaceURI);
	return DOMNodeDefVisitor::isDefaultNamespace(self, buff);
}

static const XMLCh* lookupNamespaceURI(xercesc::DOMNode& self, const XMLString& prefix) {
	return self.lookupNamespaceURI(prefix.ptr());
}

static const XMLCh* lookupNamespaceURI(xercesc::DOMNode& self, const std::string& prefix) {
	XMLString buff(prefix);
	return DOMNodeDefVisitor::lookupNamespaceURI(self, buff);
}

static void* getFeature(xercesc::DOMNode& self, const XMLString& feature, const XMLString& version) {
	return self.getFeature(feature.ptr(), version.ptr());
}

static void* getFeature(xercesc::DOMNode& self, const std::string& feature, const std::string& version) {
	XMLString buff1(feature), buff2(version);
	return DOMNodeDefVisitor::getFeature(self, buff1, buff2);
}

};

void DOMNode_init(void) {
	//! xercesc::DOMNode
	auto DOMNode = boost::python::class_<xercesc::DOMNode, boost::noncopyable>("DOMNode", boost::python::no_init)
			.def(DOMNodeDefVisitor())
			.def("getNodeName", &xercesc::DOMNode::getNodeName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNodeValue", &xercesc::DOMNode::getNodeValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNodeType", &xercesc::DOMNode::getNodeType)
			.def("getParentNode", &xercesc::DOMNode::getParentNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getChildNodes", &xercesc::DOMNode::getChildNodes, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFirstChild", &xercesc::DOMNode::getFirstChild, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLastChild", &xercesc::DOMNode::getLastChild, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPreviousSibling", &xercesc::DOMNode::getPreviousSibling, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNextSibling", &xercesc::DOMNode::getNextSibling, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributes", &xercesc::DOMNode::getAttributes, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getOwnerDocument", &xercesc::DOMNode::getOwnerDocument, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("cloneNode", &xercesc::DOMNode::cloneNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("insertBefore", &xercesc::DOMNode::insertBefore, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("replaceChild", &xercesc::DOMNode::replaceChild, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeChild", &xercesc::DOMNode::removeChild, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendChild", &xercesc::DOMNode::appendChild, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hasChildNodes", &xercesc::DOMNode::hasChildNodes)
			.def("setNodeValue", &xercesc::DOMNode::setNodeValue)
			.def("normalize", &xercesc::DOMNode::normalize)
			.def("isSupported", &xercesc::DOMNode::isSupported)
			.def("getNamespaceURI", &xercesc::DOMNode::getNamespaceURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPrefix", &xercesc::DOMNode::getPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLocalName", &xercesc::DOMNode::getLocalName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setPrefix", &xercesc::DOMNode::setPrefix)
			.def("hasAttributes", &xercesc::DOMNode::hasAttributes)
			.def("isSameNode", &xercesc::DOMNode::isSameNode)
			.def("isEqualNode", &xercesc::DOMNode::isEqualNode)
			.def("setUserData", &xercesc::DOMNode::setUserData, boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("getUserData", &xercesc::DOMNode::getUserData, boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("getBaseURI", &xercesc::DOMNode::getBaseURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("compareDocumentPosition", &xercesc::DOMNode::compareDocumentPosition)
			.def("getTextContent", &xercesc::DOMNode::getTextContent, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setTextContent", &xercesc::DOMNode::setTextContent)
			.def("lookupPrefix", &xercesc::DOMNode::lookupPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("isDefaultNamespace", &xercesc::DOMNode::isDefaultNamespace)
			.def("lookupNamespaceURI", &xercesc::DOMNode::lookupNamespaceURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getFeature", &xercesc::DOMNode::getFeature, boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("release", &xercesc::DOMNode::release)
			;
	boost::python::scope DOMNodeScope = DOMNode;
	//! xercesc::DOMNode::NodeType
	boost::python::enum_<xercesc::DOMNode::NodeType>("NodeType")
			.value("ELEMENT_NODE", xercesc::DOMNode::ELEMENT_NODE)
			.value("ATTRIBUTE_NODE", xercesc::DOMNode::ATTRIBUTE_NODE)
			.value("TEXT_NODE", xercesc::DOMNode::TEXT_NODE)
			.value("CDATA_SECTION_NODE", xercesc::DOMNode::CDATA_SECTION_NODE)
			.value("ENTITY_REFERENCE_NODE", xercesc::DOMNode::ENTITY_REFERENCE_NODE)
			.value("ENTITY_NODE", xercesc::DOMNode::ENTITY_NODE)
			.value("PROCESSING_INSTRUCTION_NODE", xercesc::DOMNode::PROCESSING_INSTRUCTION_NODE)
			.value("COMMENT_NODE", xercesc::DOMNode::COMMENT_NODE)
			.value("DOCUMENT_NODE", xercesc::DOMNode::DOCUMENT_NODE)
			.value("DOCUMENT_TYPE_NODE", xercesc::DOMNode::DOCUMENT_TYPE_NODE)
			.value("DOCUMENT_FRAGMENT_NODE", xercesc::DOMNode::DOCUMENT_FRAGMENT_NODE)
			.value("NOTATION_NODE", xercesc::DOMNode::NOTATION_NODE)
			.export_values()
			;
	//! xercesc::DOMNode::DocumentPosition
	boost::python::enum_<xercesc::DOMNode::DocumentPosition>("DocumentPosition")
			.value("DOCUMENT_POSITION_DISCONNECTED", xercesc::DOMNode::DOCUMENT_POSITION_DISCONNECTED)
			.value("DOCUMENT_POSITION_PRECEDING", xercesc::DOMNode::DOCUMENT_POSITION_PRECEDING)
			.value("DOCUMENT_POSITION_FOLLOWING", xercesc::DOMNode::DOCUMENT_POSITION_FOLLOWING)
			.value("DOCUMENT_POSITION_CONTAINS", xercesc::DOMNode::DOCUMENT_POSITION_CONTAINS)
			.value("DOCUMENT_POSITION_CONTAINED_BY", xercesc::DOMNode::DOCUMENT_POSITION_CONTAINED_BY)
			.value("DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC", xercesc::DOMNode::DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC)
			.export_values()
			;
}

} /* namespace pyxerces */
