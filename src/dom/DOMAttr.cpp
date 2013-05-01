/*
 * DOMAttr.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMAttr.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMElement.hpp>
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

#include <xercesc/dom/DOMAttr.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class DOMAttrDefVisitor
: public boost::python::def_visitor<DOMAttrDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setValue", &DOMAttrDefVisitor::setValue)
	;
}

static void setValue(xercesc::DOMAttr& self, const STR value) {
	XMLString buff(value);
	self.setValue(buff.ptr());
}

};

class DOMAttrWrapper
: public xercesc::DOMAttr, public boost::python::wrapper<xercesc::DOMAttr>
{
public:
const XMLCh* getName() const {
	return this->get_override("getName")();
}

bool getSpecified() const {
	return this->get_override("getSpecified")();
}

const XMLCh* getValue() const {
	return this->get_override("getValue")();
}

void setValue(const XMLCh *value) {
	this->get_override("setValue")(XMLString(value));
}

xercesc::DOMElement *getOwnerElement() const {
	return this->get_override("getOwnerElement")();
}

bool isId() const {
	return this->get_override("isId")();
}

const xercesc::DOMTypeInfo* getSchemaTypeInfo() const {
	return this->get_override("getSchemaTypeInfo")();
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

void DOMAttr_init(void) {
	//! xercesc::DOMAttr
	boost::python::class_<DOMAttrWrapper, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMAttr")
			.def(DOMAttrDefVisitor<XMLString&>())
			.def(DOMAttrDefVisitor<char*>())
			.def("getName", boost::python::pure_virtual(&xercesc::DOMAttr::getName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSpecified", boost::python::pure_virtual(&xercesc::DOMAttr::getSpecified))
			.def("getValue", boost::python::pure_virtual(&xercesc::DOMAttr::getValue), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setValue", boost::python::pure_virtual(&xercesc::DOMAttr::setValue))
			.def("getOwnerElement", boost::python::pure_virtual(&xercesc::DOMAttr::getOwnerElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isId", boost::python::pure_virtual(&xercesc::DOMAttr::isId))
			.def("getSchemaTypeInfo", boost::python::pure_virtual(&xercesc::DOMAttr::getSchemaTypeInfo), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
