/*
 * DOMCharacterData.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMCharacterData.h"

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

#include <xercesc/dom/DOMCharacterData.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class DOMCharacterDataDefVisitor
: public boost::python::def_visitor<DOMCharacterDataDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("appendData", &DOMCharacterDataDefVisitor::appendData)
	.def("insertData", &DOMCharacterDataDefVisitor::insertData)
	.def("replaceData", &DOMCharacterDataDefVisitor::replaceData)
	.def("setData", &DOMCharacterDataDefVisitor::setData)
	;
}

static void appendData(xercesc::DOMCharacterData& self, const STR& arg) {
	XMLString buff(arg);
	self.appendData(buff.ptr());
}

static void insertData(xercesc::DOMCharacterData& self, XMLSize_t offset, const STR& arg) {
	XMLString buff(arg);
	self.insertData(offset, buff);
}

static void replaceData(xercesc::DOMCharacterData& self, XMLSize_t offset, XMLSize_t count, const STR& arg) {
	XMLString buff(arg);
	self.replaceData(offset, count, buff.ptr());
}

static void setData(xercesc::DOMCharacterData& self, const STR& data) {
	XMLString buff(data);
	self.setData(buff.ptr());
}

};

class DOMCharacterDataWrapper
: public xercesc::DOMCharacterData, public boost::python::wrapper<xercesc::DOMCharacterData>
{
public:
const XMLCh* getData() const {
	return this->get_override("getData")();
}

XMLSize_t getLength() const {
	return this->get_override("getLength")();
}

const XMLCh* substringData(XMLSize_t offset, XMLSize_t count) const {
	return this->get_override("substringData")(offset, count);
}

void appendData(const XMLCh *arg) {
	this->get_override("appendData")(XMLString(arg));
}

void insertData(XMLSize_t offset, const XMLCh *arg) {
	this->get_override("insertData")(offset, XMLString(arg));
}

void deleteData(XMLSize_t offset, XMLSize_t count) {
	this->get_override("deleteData")(offset, count);
}

void replaceData(XMLSize_t offset, XMLSize_t count, const XMLCh *arg) {
	this->get_override("replaceData")(offset, count, XMLString(arg));
}

void setData(const XMLCh *data) {
	this->get_override("setData")(XMLString(data));
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

void DOMCharacterData_init(void) {
	//! xercesc::DOMCharacterData
	boost::python::class_<DOMCharacterDataWrapper, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMCharacterData")
			.def(DOMCharacterDataDefVisitor<XMLString>())
			.def(DOMCharacterDataDefVisitor<std::string>())
			.def("getData", boost::python::pure_virtual(&xercesc::DOMCharacterData::getData), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLength", boost::python::pure_virtual(&xercesc::DOMCharacterData::getLength))
			.def("substringData", boost::python::pure_virtual(&xercesc::DOMCharacterData::substringData), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("appendData", boost::python::pure_virtual(&xercesc::DOMCharacterData::appendData))
			.def("insertData", boost::python::pure_virtual(&xercesc::DOMCharacterData::insertData))
			.def("deleteData", boost::python::pure_virtual(&xercesc::DOMCharacterData::deleteData))
			.def("replaceData", boost::python::pure_virtual(&xercesc::DOMCharacterData::replaceData))
			.def("setData", boost::python::pure_virtual(&xercesc::DOMCharacterData::setData))
			;
}

} /* namespace pyxerces */
