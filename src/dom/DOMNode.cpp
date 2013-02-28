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
#include <xercesc/dom/DOMXPathNamespace.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMAttr.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMCharacterData.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMDocumentFragment.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMDocumentType.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMElement.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMEntity.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMEntityReference.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMNotation.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMProcessingInstruction.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMXPathNamespace.hpp>	//!< for forward declaration
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
	.def("toDOMNode", &DOMNodeDefVisitor::toDOMNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toDOMAttr", &DOMNodeDefVisitor::toDOMAttr, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toDOMCharacterData", &DOMNodeDefVisitor::toDOMCharacterData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toDOMDocument", &DOMNodeDefVisitor::toDOMDocument, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toDOMDocumentFragment", &DOMNodeDefVisitor::toDOMDocumentFragment, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toDOMDocumentType", &DOMNodeDefVisitor::toDOMDocumentType, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toDOMElement", &DOMNodeDefVisitor::toDOMElement, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toDOMEntity", &DOMNodeDefVisitor::toDOMEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toDOMEntityReference", &DOMNodeDefVisitor::toDOMEntityReference, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toDOMNotation", &DOMNodeDefVisitor::toDOMNotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toDOMProcessingInstruction", &DOMNodeDefVisitor::toDOMProcessingInstruction, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toDOMXPathNamespace", &DOMNodeDefVisitor::toDOMXPathNamespace, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMNode* toDOMNode(xercesc::DOMNode& self) {
	return &self;
}

static xercesc::DOMAttr* toDOMAttr(xercesc::DOMNode& self) {
	if(self.getNodeType() != xercesc::DOMNode::ATTRIBUTE_NODE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::DOMAttr*>(&self);
}

static xercesc::DOMCharacterData* toDOMCharacterData(xercesc::DOMNode& self) {
	if(self.getNodeType() != xercesc::DOMNode::TEXT_NODE && self.getNodeType() != xercesc::DOMNode::CDATA_SECTION_NODE && self.getNodeType() != xercesc::DOMNode::COMMENT_NODE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::DOMCharacterData*>(&self);
}

static xercesc::DOMDocument* toDOMDocument(xercesc::DOMNode& self) {
	if(self.getNodeType() != xercesc::DOMNode::DOCUMENT_NODE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::DOMDocument*>(&self);
}

static xercesc::DOMDocumentFragment* toDOMDocumentFragment(xercesc::DOMNode& self) {
	if(self.getNodeType() != xercesc::DOMNode::DOCUMENT_FRAGMENT_NODE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::DOMDocumentFragment*>(&self);
}

static xercesc::DOMDocumentType* toDOMDocumentType(xercesc::DOMNode& self) {
	if(self.getNodeType() != xercesc::DOMNode::DOCUMENT_TYPE_NODE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::DOMDocumentType*>(&self);
}

static xercesc::DOMElement* toDOMElement(xercesc::DOMNode& self) {
	if(self.getNodeType() != xercesc::DOMNode::ELEMENT_NODE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::DOMElement*>(&self);
}

static xercesc::DOMEntity* toDOMEntity(xercesc::DOMNode& self) {
	if(self.getNodeType() != xercesc::DOMNode::ENTITY_NODE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::DOMEntity*>(&self);
}

static xercesc::DOMEntityReference* toDOMEntityReference(xercesc::DOMNode& self) {
	if(self.getNodeType() != xercesc::DOMNode::ENTITY_REFERENCE_NODE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::DOMEntityReference*>(&self);
}

static xercesc::DOMNotation* toDOMNotation(xercesc::DOMNode& self) {
	if(self.getNodeType() != xercesc::DOMNode::NOTATION_NODE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::DOMNotation*>(&self);
}

static xercesc::DOMProcessingInstruction* toDOMProcessingInstruction(xercesc::DOMNode& self) {
	if(self.getNodeType() != xercesc::DOMNode::PROCESSING_INSTRUCTION_NODE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::DOMProcessingInstruction*>(&self);
}

static xercesc::DOMXPathNamespace* toDOMXPathNamespace(xercesc::DOMNode& self) {
	if(self.getNodeType() != xercesc::DOMXPathNamespace::XPATH_NAMESPACE_NODE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::DOMXPathNamespace*>(&self);
}

};

template <class STR>
class DOMNodeStringDefVisitor
: public boost::python::def_visitor<DOMNodeStringDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setNodeValue", &DOMNodeStringDefVisitor::setNodeValue)
	.def("isSupported", &DOMNodeStringDefVisitor::isSupported)
	.def("setPrefix", &DOMNodeStringDefVisitor::setPrefix)
	.def("setUserData", &DOMNodeStringDefVisitor::setUserData, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("getUserData", &DOMNodeStringDefVisitor::getUserData, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("setTextContent", &DOMNodeStringDefVisitor::setTextContent)
	.def("lookupPrefix", &DOMNodeStringDefVisitor::lookupPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
	.def("isDefaultNamespace", &DOMNodeStringDefVisitor::isDefaultNamespace)
	.def("lookupNamespaceURI", &DOMNodeStringDefVisitor::lookupNamespaceURI, boost::python::return_value_policy<boost::python::return_by_value>())
	.def("getFeature", &DOMNodeStringDefVisitor::getFeature, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	;
}

static void setNodeValue(xercesc::DOMNode& self, const STR& nodeValue) {
	XMLString buff(nodeValue);
	self.setNodeValue(buff.ptr());
}

static bool isSupported(xercesc::DOMNode& self, const STR& feature, const STR& version) {
	XMLString buff1(feature), buff2(version);
	return self.isSupported(buff1.ptr(), buff2.ptr());
}

static void setPrefix(xercesc::DOMNode& self, const STR& prefix) {
	XMLString buff(prefix);
	self.setPrefix(buff.ptr());
}

static void* setUserData(xercesc::DOMNode& self, const STR& key, void* data, xercesc::DOMUserDataHandler* handler) {
	XMLString buff(key);
	return self.setUserData(buff.ptr(), data, handler);
}

static void* getUserData(xercesc::DOMNode& self, const STR& key) {
	XMLString buff(key);
	return self.getUserData(buff.ptr());
}

static void setTextContent(xercesc::DOMNode& self, const STR& textContent) {
	XMLString buff(textContent);
	self.setTextContent(buff.ptr());
}

static const XMLCh* lookupPrefix(xercesc::DOMNode& self, const STR& namespaceURI) {
	XMLString buff(namespaceURI);
	return self.lookupPrefix(buff.ptr());
}

static bool isDefaultNamespace(xercesc::DOMNode& self, const STR& namespaceURI) {
	XMLString buff(namespaceURI);
	return self.isDefaultNamespace(buff.ptr());
}

static const XMLCh* lookupNamespaceURI(xercesc::DOMNode& self, const STR& prefix) {
	XMLString buff(prefix);
	return self.lookupNamespaceURI(buff.ptr());
}

static void* getFeature(xercesc::DOMNode& self, const STR& feature, const STR& version) {
	XMLString buff1(feature), buff2(version);
	return self.getFeature(buff1.ptr(), buff2.ptr());
}

};

void DOMNode_init(void) {
	//! xercesc::DOMNode
	auto DOMNode = boost::python::class_<xercesc::DOMNode, boost::noncopyable>("DOMNode", boost::python::no_init)
			.def(DOMNodeDefVisitor())
			.def(DOMNodeStringDefVisitor<XMLString>())
			.def(DOMNodeStringDefVisitor<std::string>())
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
