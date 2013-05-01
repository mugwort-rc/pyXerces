/*
 * DOMNode.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMNode.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMUserDataHandler.hpp>
#include <xercesc/dom/DOMXPathNamespace.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/dom/DOMCharacterData.hpp>
#include <xercesc/dom/DOMDocumentFragment.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMEntity.hpp>
#include <xercesc/dom/DOMEntityReference.hpp>
#include <xercesc/dom/DOMNotation.hpp>
#include <xercesc/dom/DOMProcessingInstruction.hpp>
#include <xercesc/dom/DOMXPathNamespace.hpp>

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

template <typename STR>
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

static void setNodeValue(xercesc::DOMNode& self, const STR nodeValue) {
	XMLString buff(nodeValue);
	self.setNodeValue(buff.ptr());
}

static bool isSupported(xercesc::DOMNode& self, const STR feature, const STR version) {
	XMLString buff1(feature), buff2(version);
	return self.isSupported(buff1.ptr(), buff2.ptr());
}

static void setPrefix(xercesc::DOMNode& self, const STR prefix) {
	XMLString buff(prefix);
	self.setPrefix(buff.ptr());
}

static void* setUserData(xercesc::DOMNode& self, const STR key, void* data, xercesc::DOMUserDataHandler* handler) {
	XMLString buff(key);
	return self.setUserData(buff.ptr(), data, handler);
}

static void* getUserData(xercesc::DOMNode& self, const STR key) {
	XMLString buff(key);
	return self.getUserData(buff.ptr());
}

static void setTextContent(xercesc::DOMNode& self, const STR textContent) {
	XMLString buff(textContent);
	self.setTextContent(buff.ptr());
}

static const XMLCh* lookupPrefix(xercesc::DOMNode& self, const STR namespaceURI) {
	XMLString buff(namespaceURI);
	return self.lookupPrefix(buff.ptr());
}

static bool isDefaultNamespace(xercesc::DOMNode& self, const STR namespaceURI) {
	XMLString buff(namespaceURI);
	return self.isDefaultNamespace(buff.ptr());
}

static const XMLCh* lookupNamespaceURI(xercesc::DOMNode& self, const STR prefix) {
	XMLString buff(prefix);
	return self.lookupNamespaceURI(buff.ptr());
}

static void* getFeature(xercesc::DOMNode& self, const STR feature, const STR version) {
	XMLString buff1(feature), buff2(version);
	return self.getFeature(buff1.ptr(), buff2.ptr());
}

};

class DOMNodeWrapper
: public xercesc::DOMNode, public boost::python::wrapper<xercesc::DOMNode>
{
public:
const XMLCh* getNodeName() const {
	return this->get_override("getNodeName")();
}

const XMLCh* getNodeValue() const {
	return this->get_override("getNodeValue")();
}

NodeType getNodeType() const {
	return this->get_override("getNodeType")();
}

xercesc::DOMNode *getParentNode() const {
	return this->get_override("getParentNode")();
}

xercesc::DOMNodeList *getChildNodes() const {
	return this->get_override("getChildNodes")();
}

xercesc::DOMNode *getFirstChild() const {
	return this->get_override("getFirstChild")();
}

xercesc::DOMNode *getLastChild() const {
	return this->get_override("getLastChild")();
}

xercesc::DOMNode *getPreviousSibling() const {
	return this->get_override("getPreviousSibling")();
}

xercesc::DOMNode *getNextSibling() const {
	return this->get_override("getNextSibling")();
}

xercesc::DOMNamedNodeMap *getAttributes() const {
	return this->get_override("getAttributes")();
}

xercesc::DOMDocument *getOwnerDocument() const {
	return this->get_override("getOwnerDocument")();
}

xercesc::DOMNode * cloneNode(bool deep) const {
	return this->get_override("cloneNode")(deep);
}

xercesc::DOMNode *insertBefore(xercesc::DOMNode *newChild, xercesc::DOMNode *refChild) {
	return this->get_override("insertBefore")(boost::python::ptr(newChild), boost::python::ptr(refChild));
}

xercesc::DOMNode *replaceChild(xercesc::DOMNode *newChild, xercesc::DOMNode *oldChild) {
	return this->get_override("replaceChild")(boost::python::ptr(newChild), boost::python::ptr(oldChild));
}

xercesc::DOMNode *removeChild(xercesc::DOMNode *oldChild) {
	return this->get_override("removeChild")(boost::python::ptr(oldChild));
}

xercesc::DOMNode *appendChild(xercesc::DOMNode *newChild) {
	return this->get_override("appendChild")(boost::python::ptr(newChild));
}

bool hasChildNodes() const {
	return this->get_override("hasChildNodes")();
}

void setNodeValue(const XMLCh *nodeValue) {
	this->get_override("setNodeValue")(XMLString(nodeValue));
}

void normalize() {
	this->get_override("normalize")();
}

bool isSupported(const XMLCh *feature, const XMLCh *version) const {
	return this->get_override("isSupported")(XMLString(feature), XMLString(version));
}

const XMLCh* getNamespaceURI() const {
	return this->get_override("getNamespaceURI")();
}

const XMLCh* getPrefix() const {
	return this->get_override("getPrefix")();
}

const XMLCh* getLocalName() const {
	return this->get_override("getLocalName")();
}

void setPrefix(const XMLCh * prefix) {
	this->get_override("setPrefix")(XMLString(prefix));
}

bool hasAttributes() const {
	return this->get_override("hasAttributes")();
}

bool isSameNode(const xercesc::DOMNode* other) const {
	return this->get_override("isSameNode")(boost::python::ptr(other));
}

bool isEqualNode(const xercesc::DOMNode* arg) const {
	return this->get_override("isEqualNode")(boost::python::ptr(arg));
}

void* setUserData(const XMLCh* key, void* data, xercesc::DOMUserDataHandler* handler) {
	// XXX: data
	return this->get_override("setUserData")(XMLString(key), data, boost::python::ptr(handler));
}

void* getUserData(const XMLCh* key) const {
	return this->get_override("getUserData")(XMLString(key));
}

const XMLCh* getBaseURI() const {
	return this->get_override("getBaseURI")();
}

short compareDocumentPosition(const xercesc::DOMNode* other) const {
	return this->get_override("compareDocumentPosition")(boost::python::ptr(other));
}

const XMLCh* getTextContent() const {
	return this->get_override("getTextContent")();
}

void setTextContent(const XMLCh* textContent) {
	this->get_override("setTextContent")(XMLString(textContent));
}

const XMLCh* lookupPrefix(const XMLCh* namespaceURI) const {
	return this->get_override("lookupPrefix")(XMLString(namespaceURI));
}

bool isDefaultNamespace(const XMLCh* namespaceURI) const {
	return this->get_override("isDefaultNamespace")(XMLString(namespaceURI));
}

const XMLCh* lookupNamespaceURI(const XMLCh* prefix) const  {
	return this->get_override("lookupNamespaceURI")(XMLString(prefix));
}

void* getFeature(const XMLCh* feature, const XMLCh* version) const {
	return this->get_override("getFeature")(XMLString(feature), XMLString(version));
}

void release() {
	this->get_override("release")();
}

};

void DOMNode_init(void) {
	//! xercesc::DOMNode
	auto DOMNode = boost::python::class_<DOMNodeWrapper, boost::noncopyable>("DOMNode")
			.def(DOMNodeDefVisitor())
			.def(DOMNodeStringDefVisitor<XMLString&>())
			.def(DOMNodeStringDefVisitor<char*>())
			.def("getNodeName", boost::python::pure_virtual(&xercesc::DOMNode::getNodeName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNodeValue", boost::python::pure_virtual(&xercesc::DOMNode::getNodeValue), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNodeType", boost::python::pure_virtual(&xercesc::DOMNode::getNodeType))
			.def("getParentNode", boost::python::pure_virtual(&xercesc::DOMNode::getParentNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getChildNodes", boost::python::pure_virtual(&xercesc::DOMNode::getChildNodes), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFirstChild", boost::python::pure_virtual(&xercesc::DOMNode::getFirstChild), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLastChild", boost::python::pure_virtual(&xercesc::DOMNode::getLastChild), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPreviousSibling", boost::python::pure_virtual(&xercesc::DOMNode::getPreviousSibling), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNextSibling", boost::python::pure_virtual(&xercesc::DOMNode::getNextSibling), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributes", boost::python::pure_virtual(&xercesc::DOMNode::getAttributes), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getOwnerDocument", boost::python::pure_virtual(&xercesc::DOMNode::getOwnerDocument), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("cloneNode", boost::python::pure_virtual(&xercesc::DOMNode::cloneNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("insertBefore", boost::python::pure_virtual(&xercesc::DOMNode::insertBefore), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("replaceChild", boost::python::pure_virtual(&xercesc::DOMNode::replaceChild), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeChild", boost::python::pure_virtual(&xercesc::DOMNode::removeChild), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendChild", boost::python::pure_virtual(&xercesc::DOMNode::appendChild), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hasChildNodes", boost::python::pure_virtual(&xercesc::DOMNode::hasChildNodes))
			.def("setNodeValue", boost::python::pure_virtual(&xercesc::DOMNode::setNodeValue))
			.def("normalize", boost::python::pure_virtual(&xercesc::DOMNode::normalize))
			.def("isSupported", boost::python::pure_virtual(&xercesc::DOMNode::isSupported))
			.def("getNamespaceURI", boost::python::pure_virtual(&xercesc::DOMNode::getNamespaceURI), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPrefix", boost::python::pure_virtual(&xercesc::DOMNode::getPrefix), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLocalName", boost::python::pure_virtual(&xercesc::DOMNode::getLocalName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setPrefix", boost::python::pure_virtual(&xercesc::DOMNode::setPrefix))
			.def("hasAttributes", boost::python::pure_virtual(&xercesc::DOMNode::hasAttributes))
			.def("isSameNode", boost::python::pure_virtual(&xercesc::DOMNode::isSameNode))
			.def("isEqualNode", boost::python::pure_virtual(&xercesc::DOMNode::isEqualNode))
			.def("setUserData", boost::python::pure_virtual(&xercesc::DOMNode::setUserData), boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("getUserData", boost::python::pure_virtual(&xercesc::DOMNode::getUserData), boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("getBaseURI", boost::python::pure_virtual(&xercesc::DOMNode::getBaseURI), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("compareDocumentPosition", boost::python::pure_virtual(&xercesc::DOMNode::compareDocumentPosition))
			.def("getTextContent", boost::python::pure_virtual(&xercesc::DOMNode::getTextContent), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setTextContent", boost::python::pure_virtual(&xercesc::DOMNode::setTextContent))
			.def("lookupPrefix", boost::python::pure_virtual(&xercesc::DOMNode::lookupPrefix), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("isDefaultNamespace", boost::python::pure_virtual(&xercesc::DOMNode::isDefaultNamespace))
			.def("lookupNamespaceURI", boost::python::pure_virtual(&xercesc::DOMNode::lookupNamespaceURI), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getFeature", boost::python::pure_virtual(&xercesc::DOMNode::getFeature), boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("release", boost::python::pure_virtual(&xercesc::DOMNode::release))
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
