/*
 * DOMElement.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMElement.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMTypeInfo.hpp>
// DOMNode
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMUserDataHandler.hpp>
#include <xercesc/dom/DOMXPathNamespace.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/dom/DOMCharacterData.hpp>
#include <xercesc/dom/DOMDocumentFragment.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/dom/DOMEntity.hpp>
#include <xercesc/dom/DOMEntityReference.hpp>
#include <xercesc/dom/DOMNotation.hpp>
#include <xercesc/dom/DOMProcessingInstruction.hpp>
#include <xercesc/dom/DOMXPathNamespace.hpp>

#include <xercesc/dom/DOMElement.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
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

static const XMLCh* getAttribute(xercesc::DOMElement& self, const STR name) {
	XMLString buff(name);
	return self.getAttribute(buff.ptr());
}

static xercesc::DOMAttr* getAttributeNode(xercesc::DOMElement& self, const STR name) {
	XMLString buff(name);
	return self.getAttributeNode(buff.ptr());
}

static xercesc::DOMNodeList* getElementsByTagName(xercesc::DOMElement& self, const STR name) {
	XMLString buff(name);
	return self.getElementsByTagName(buff.ptr());
}

static void setAttribute(xercesc::DOMElement& self, const STR name, const STR value) {
	XMLString buff1(name), buff2(value);
	self.setAttribute(buff1.ptr(), buff2.ptr());
}

static void removeAttribute(xercesc::DOMElement& self, const STR name) {
	XMLString buff(name);
	self.removeAttribute(buff.ptr());
}

static const XMLCh* getAttributeNS(xercesc::DOMElement& self, const STR namespaceURI, const STR localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return self.getAttributeNS(buff1.ptr(), buff2.ptr());
}

static void setAttributeNS(xercesc::DOMElement& self, const STR namespaceURI, const STR qualifiedName, const STR value) {
	XMLString buff1(namespaceURI), buff2(qualifiedName), buff3(value);
	self.setAttributeNS(buff1.ptr(), buff2.ptr(), buff3.ptr());
}

static void removeAttributeNS(xercesc::DOMElement& self, const STR namespaceURI, const STR localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	self.removeAttributeNS(buff1.ptr(), buff2.ptr());
}

static xercesc::DOMAttr* getAttributeNodeNS(xercesc::DOMElement& self, const STR namespaceURI, const STR localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return self.getAttributeNodeNS(buff1.ptr(), buff2.ptr());
}

static xercesc::DOMNodeList* getElementsByTagNameNS(xercesc::DOMElement& self, const STR namespaceURI, const STR localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return self.getElementsByTagNameNS(buff1.ptr(), buff2.ptr());
}

static bool hasAttribute(xercesc::DOMElement& self, const STR name) {
	XMLString buff(name);
	return self.hasAttribute(buff.ptr());
}

static bool hasAttributeNS(xercesc::DOMElement& self, const STR namespaceURI, const STR localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return self.hasAttributeNS(buff1.ptr(), buff2.ptr());
}

static void setIdAttribute(xercesc::DOMElement& self, const STR name, bool isId) {
	XMLString buff(name);
	self.setIdAttribute(buff.ptr(), isId);
}

static void setIdAttributeNS(xercesc::DOMElement& self, const STR namespaceURI, const STR localName, bool isId) {
	XMLString buff1(namespaceURI), buff2(localName);
	self.setIdAttributeNS(buff1.ptr(), buff2.ptr(), isId);
}

};

class DOMElementWrapper
: public xercesc::DOMElement, public boost::python::wrapper<xercesc::DOMElement>
{
public:
const XMLCh* getTagName() const {
	return this->get_override("getTagName")();
}

const XMLCh* getAttribute(const XMLCh *name) const {
	return this->get_override("getAttribute")(XMLString(name));
}

xercesc::DOMAttr* getAttributeNode(const XMLCh *name) const {
	return this->get_override("getAttributeNode")(XMLString(name));
}

xercesc::DOMNodeList* getElementsByTagName(const XMLCh *name) const {
	return this->get_override("getElementsByTagName")(XMLString(name));
}

void setAttribute(const XMLCh *name, const XMLCh *value) {
	this->get_override("setAttribute")(XMLString(name), XMLString(value));
}

xercesc::DOMAttr* setAttributeNode(xercesc::DOMAttr *newAttr) {
	return this->get_override("setAttributeNode")(boost::python::ptr(newAttr));
}

xercesc::DOMAttr* removeAttributeNode(xercesc::DOMAttr *oldAttr) {
	return this->get_override("removeAttributeNode")(boost::python::ptr(oldAttr));
}

void removeAttribute(const XMLCh *name) {
	this->get_override("removeAttribute")(XMLString(name));
}

const XMLCh* getAttributeNS(const XMLCh *namespaceURI, const XMLCh *localName) const {
	return this->get_override("getAttributeNS")(XMLString(namespaceURI), XMLString(localName));
}

void setAttributeNS(const XMLCh *namespaceURI, const XMLCh *qualifiedName, const XMLCh *value) {
	this->get_override("setAttributeNS")(XMLString(namespaceURI), XMLString(qualifiedName), XMLString(value));
}

void removeAttributeNS(const XMLCh *namespaceURI, const XMLCh *localName) {
	this->get_override("removeAttributeNS")(XMLString(namespaceURI), XMLString(localName));
}

xercesc::DOMAttr* getAttributeNodeNS(const XMLCh *namespaceURI, const XMLCh *localName) const {
	return this->get_override("getAttributeNodeNS")(XMLString(namespaceURI), XMLString(localName));
}

xercesc::DOMAttr* setAttributeNodeNS(xercesc::DOMAttr *newAttr) {
	return this->get_override("setAttributeNodeNS")(boost::python::ptr(newAttr));
}

xercesc::DOMNodeList* getElementsByTagNameNS(const XMLCh *namespaceURI, const XMLCh *localName) const {
	return this->get_override("getElementsByTagNameNS")(XMLString(namespaceURI), XMLString(localName));
}

bool hasAttribute(const XMLCh *name) const {
	return this->get_override("hasAttribute")(XMLString(name));
}

bool hasAttributeNS(const XMLCh *namespaceURI, const XMLCh *localName) const {
	return this->get_override("hasAttributeNS")(XMLString(namespaceURI), XMLString(localName));
}

void setIdAttribute(const XMLCh* name, bool isId) {
	this->get_override("setIdAttribute")(XMLString(name), isId);
}

void setIdAttributeNS(const XMLCh* namespaceURI, const XMLCh* localName, bool isId) {
	this->get_override("setIdAttributeNS")(XMLString(namespaceURI), XMLString(localName), isId);
}

void setIdAttributeNode(const xercesc::DOMAttr *idAttr, bool isId) {
	this->get_override("setIdAttributeNode")(boost::python::ptr(idAttr), isId);
}

const xercesc::DOMTypeInfo* getSchemaTypeInfo() const {
	return this->get_override("getSchemaTypeInfo")();
}

DOMElement* getFirstElementChild() const {
	return this->get_override("getFirstElementChild")();
}

DOMElement* getLastElementChild() const {
	return this->get_override("getLastElementChild")();
}

DOMElement* getPreviousElementSibling() const {
	return this->get_override("getPreviousElementSibling")();
}

DOMElement* getNextElementSibling() const {
	return this->get_override("getNextElementSibling")();
}

XMLSize_t getChildElementCount() const {
	return this->get_override("getChildElementCount")();
}

//! ---------- DOMNode ----------
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

void DOMElement_init(void) {
	//! xercesc::DOMElement
	boost::python::class_<DOMElementWrapper, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMElement")
			.def(DOMElementDefVisitor<XMLString&>())
			.def(DOMElementDefVisitor<char*>())
			.def("getTagName", boost::python::pure_virtual(&xercesc::DOMElement::getTagName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAttribute", boost::python::pure_virtual(&xercesc::DOMElement::getAttribute), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAttributeNode", boost::python::pure_virtual(&xercesc::DOMElement::getAttributeNode), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getElementsByTagName", boost::python::pure_virtual(&xercesc::DOMElement::getElementsByTagName), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setAttribute", boost::python::pure_virtual(&xercesc::DOMElement::setAttribute))
			.def("setAttributeNode", boost::python::pure_virtual(&xercesc::DOMElement::setAttributeNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeAttributeNode", boost::python::pure_virtual(&xercesc::DOMElement::removeAttributeNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeAttribute", boost::python::pure_virtual(&xercesc::DOMElement::removeAttribute))
			.def("getAttributeNS", boost::python::pure_virtual(&xercesc::DOMElement::getAttributeNS), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setAttributeNS", boost::python::pure_virtual(&xercesc::DOMElement::setAttributeNS))
			.def("removeAttributeNS", boost::python::pure_virtual(&xercesc::DOMElement::removeAttributeNS))
			.def("getAttributeNodeNS", boost::python::pure_virtual(&xercesc::DOMElement::getAttributeNodeNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setAttributeNodeNS", boost::python::pure_virtual(&xercesc::DOMElement::setAttributeNodeNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementsByTagNameNS", boost::python::pure_virtual(&xercesc::DOMElement::getElementsByTagNameNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hasAttribute", boost::python::pure_virtual(&xercesc::DOMElement::hasAttribute))
			.def("hasAttributeNS", boost::python::pure_virtual(&xercesc::DOMElement::hasAttributeNS))
			.def("setIdAttribute", boost::python::pure_virtual(&xercesc::DOMElement::setIdAttribute))
			.def("setIdAttributeNS", boost::python::pure_virtual(&xercesc::DOMElement::setIdAttributeNS))
			.def("setIdAttributeNode", boost::python::pure_virtual(&xercesc::DOMElement::setIdAttributeNode))
			.def("getSchemaTypeInfo", boost::python::pure_virtual(&xercesc::DOMElement::getSchemaTypeInfo), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFirstElementChild", boost::python::pure_virtual(&xercesc::DOMElement::getFirstElementChild), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLastElementChild", boost::python::pure_virtual(&xercesc::DOMElement::getLastElementChild), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPreviousElementSibling", boost::python::pure_virtual(&xercesc::DOMElement::getPreviousElementSibling), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNextElementSibling", boost::python::pure_virtual(&xercesc::DOMElement::getNextElementSibling), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getChildElementCount", boost::python::pure_virtual(&xercesc::DOMElement::getChildElementCount))
			;
}

} /* namespace pyxerces */
