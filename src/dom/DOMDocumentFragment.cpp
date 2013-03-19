/*
 * DOMDocumentFragment.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMDocumentFragment.h"

#include <boost/python.hpp>

//! for forward declaration
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

#include <xercesc/dom/DOMDocumentFragment.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMDocumentFragmentWrapper
: public xercesc::DOMDocumentFragment, public boost::python::wrapper<xercesc::DOMDocumentFragment>
{
public:
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

void DOMDocumentFragment_init(void) {
	//! xercesc::DOMDocumentFragment
	boost::python::class_<DOMDocumentFragmentWrapper, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMDocumentFragment");
}

} /* namespace pyxerces */
