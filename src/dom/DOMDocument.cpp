/*
 * DOMDocument.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMDocument.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/DOMConfiguration.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMDocumentFragment.hpp>
#include <xercesc/dom/DOMComment.hpp>
#include <xercesc/dom/DOMCDATASection.hpp>
#include <xercesc/dom/DOMProcessingInstruction.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/dom/DOMEntity.hpp>
#include <xercesc/dom/DOMEntityReference.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMNodeFilter.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMNotation.hpp>
#include <xercesc/dom/DOMText.hpp>
#include <xercesc/dom/DOMNode.hpp>
//! DOMDocumentRange
#include <xercesc/dom/DOMRange.hpp>
//! DOMXPathEvaluator
#include <xercesc/dom/DOMXPathNSResolver.hpp>
#include <xercesc/dom/DOMXPathExpression.hpp>
//! DOMDocumentTraversal
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMTreeWalker.hpp>
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

#include <xercesc/dom/DOMDocument.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class DOMDocumentDefVisitor
: public boost::python::def_visitor<DOMDocumentDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createElement", &DOMDocumentDefVisitor::createElement, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createTextNode", &DOMDocumentDefVisitor::createTextNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createComment", &DOMDocumentDefVisitor::createComment, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createCDATASection", &DOMDocumentDefVisitor::createCDATASection, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createProcessingInstruction", &DOMDocumentDefVisitor::createProcessingInstruction, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createAttribute", &DOMDocumentDefVisitor::createAttribute, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createEntityReference", &DOMDocumentDefVisitor::createEntityReference, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagName", &DOMDocumentDefVisitor::getElementsByTagName, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createElementNS", &DOMDocumentDefVisitor::createElementNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createAttributeNS", &DOMDocumentDefVisitor::createAttributeNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagNameNS", &DOMDocumentDefVisitor::getElementsByTagNameNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementById", &DOMDocumentDefVisitor::getElementById, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setXmlVersion", &DOMDocumentDefVisitor::setXmlVersion)
	.def("setDocumentURI", &DOMDocumentDefVisitor::setDocumentURI)
	.def("renameNode", &DOMDocumentDefVisitor::renameNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createEntity", &DOMDocumentDefVisitor::createEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocumentType", static_cast<xercesc::DOMDocumentType*(*)(xercesc::DOMDocument&, const STR&)>(&DOMDocumentDefVisitor::createDocumentType), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocumentType", static_cast<xercesc::DOMDocumentType*(*)(xercesc::DOMDocument&, const STR&, const STR&, const STR&)>(&DOMDocumentDefVisitor::createDocumentType), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createNotation", &DOMDocumentDefVisitor::createNotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createElementNS", &DOMDocumentDefVisitor::nonStandardCreateElementNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMElement* createElement(xercesc::DOMDocument& self, const STR& tagName) {
	XMLString buff(tagName);
	return self.createElement(buff.ptr());
}

static xercesc::DOMText* createTextNode(xercesc::DOMDocument& self, const STR& data) {
	XMLString buff(data);
	return self.createTextNode(buff.ptr());
}

static xercesc::DOMComment* createComment(xercesc::DOMDocument& self, const STR& data) {
	XMLString buff(data);
	return self.createComment(buff.ptr());
}

static xercesc::DOMCDATASection* createCDATASection(xercesc::DOMDocument& self, const STR& data) {
	XMLString buff(data);
	return self.createCDATASection(buff.ptr());
}

static xercesc::DOMProcessingInstruction* createProcessingInstruction(xercesc::DOMDocument& self, const STR& target, const STR& data) {
	XMLString buff1(target), buff2(data);
	return self.createProcessingInstruction(buff1.ptr(), buff2.ptr());
}

static xercesc::DOMAttr* createAttribute(xercesc::DOMDocument& self, const STR& name) {
	XMLString buff(name);
	return self.createAttribute(buff.ptr());
}

static xercesc::DOMEntityReference* createEntityReference(xercesc::DOMDocument& self, const STR& name) {
	XMLString buff(name);
	return self.createEntityReference(buff.ptr());
}

static xercesc::DOMNodeList* getElementsByTagName(xercesc::DOMDocument& self, const STR& tagName) {
	XMLString buff(tagName);
	return self.getElementsByTagName(buff.ptr());
}

static xercesc::DOMElement* createElementNS(xercesc::DOMDocument& self, const STR& namespaceURI, const STR& qualifiedName) {
	XMLString buff1(namespaceURI), buff2(qualifiedName);
	return self.createElementNS(buff1.ptr(), buff2.ptr());
}

static xercesc::DOMAttr* createAttributeNS(xercesc::DOMDocument& self, const STR& namespaceURI, const STR& qualifiedName) {
	XMLString buff1(namespaceURI), buff2(qualifiedName);
	return self.createAttributeNS(buff1.ptr(), buff2.ptr());
}

static xercesc::DOMNodeList* getElementsByTagNameNS(xercesc::DOMDocument& self, const STR& namespaceURI, const STR& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return self.getElementsByTagNameNS(buff1.ptr(), buff2.ptr());
}

static xercesc::DOMElement* getElementById(xercesc::DOMDocument& self, const STR& elementId) {
	XMLString buff(elementId);
	return self.getElementById(buff.ptr());
}

static void setXmlVersion(xercesc::DOMDocument& self, const STR& version) {
	XMLString buff(version);
	self.setXmlVersion(buff.ptr());
}

static void setDocumentURI(xercesc::DOMDocument& self, const STR& documentURI) {
	XMLString buff(documentURI);
	self.setDocumentURI(buff.ptr());
}

static xercesc::DOMNode* renameNode(xercesc::DOMDocument& self, xercesc::DOMNode* n, const STR& namespaceURI, const STR& qualifiedName) {
	XMLString buff1(namespaceURI), buff2(qualifiedName);
	return self.renameNode(n, buff1.ptr(), buff2.ptr());
}

static xercesc::DOMEntity* createEntity(xercesc::DOMDocument& self, const STR& name) {
	XMLString buff(name);
	return self.createEntity(buff.ptr());
}

static xercesc::DOMDocumentType* createDocumentType(xercesc::DOMDocument& self, const STR& name) {
	XMLString buff(name);
	return self.createDocumentType(buff.ptr());
}

static xercesc::DOMDocumentType* createDocumentType(xercesc::DOMDocument& self, const STR& qName, const STR& publicId, const STR& systemId) {
	XMLString buff1(qName), buff2(publicId), buff3(systemId);
	return self.createDocumentType(buff1.ptr(), buff2.ptr(), buff3.ptr());
}

static xercesc::DOMNotation* createNotation(xercesc::DOMDocument& self, const STR& name) {
	XMLString buff(name);
	return self.createNotation(buff.ptr());
}

static xercesc::DOMElement* nonStandardCreateElementNS(xercesc::DOMDocument& self, const STR& namespaceURI, const STR& qualifiedName, const XMLFileLoc lineNum, const XMLFileLoc columnNum) {
	XMLString buff1(namespaceURI), buff2(qualifiedName);
	return self.createElementNS(buff1.ptr(), buff2.ptr(), lineNum, columnNum);
}

};

class DOMDocumentWrapper
: public xercesc::DOMDocument, public boost::python::wrapper<xercesc::DOMDocument>
{
public:
xercesc::DOMElement *createElement(const XMLCh *tagName) {
	return this->get_override("createElement")(XMLString(tagName));
}

xercesc::DOMDocumentFragment *createDocumentFragment() {
	return this->get_override("createDocumentFragment")();
}

xercesc::DOMText *createTextNode(const XMLCh *data) {
	return this->get_override("createTextNode")(XMLString(data));
}

xercesc::DOMComment *createComment(const XMLCh *data) {
	return this->get_override("createComment")(XMLString(data));
}

xercesc::DOMCDATASection *createCDATASection(const XMLCh *data) {
	return this->get_override("createCDATASection")(XMLString(data));
}

xercesc::DOMProcessingInstruction *createProcessingInstruction(const XMLCh *target, const XMLCh *data) {
	return this->get_override("createProcessingInstruction")(XMLString(target), XMLString(data));
}

xercesc::DOMAttr *createAttribute(const XMLCh *name) {
	return this->get_override("createAttribute")(XMLString(name));
}

xercesc::DOMEntityReference *createEntityReference(const XMLCh *name) {
	return this->get_override("createEntityReference")(XMLString(name));
}

xercesc::DOMDocumentType *getDoctype() const {
	return this->get_override("getDoctype")();
}

xercesc::DOMImplementation *getImplementation() const {
	return this->get_override("getImplementation")();
}

xercesc::DOMElement *getDocumentElement() const {
	return this->get_override("getDocumentElement")();
}

xercesc::DOMNodeList *getElementsByTagName(const XMLCh *tagname) const {
	return this->get_override("getElementsByTagName")(XMLString(tagname));
}

xercesc::DOMNode *importNode(const xercesc::DOMNode *importedNode, bool deep) {
	return this->get_override("importNode")(boost::python::ptr(importedNode), deep);
}

xercesc::DOMElement *createElementNS(const XMLCh *namespaceURI, const XMLCh *qualifiedName) {
	return this->get_override("createElementNS")(XMLString(namespaceURI), XMLString(qualifiedName));
}

xercesc::DOMAttr *createAttributeNS(const XMLCh *namespaceURI, const XMLCh *qualifiedName) {
	return this->get_override("createAttributeNS")(XMLString(namespaceURI), XMLString(qualifiedName));
}

xercesc::DOMNodeList *getElementsByTagNameNS(const XMLCh *namespaceURI, const XMLCh *localName) const {
	return this->get_override("getElementsByTagNameNS")(XMLString(namespaceURI), XMLString(localName));
}

xercesc::DOMElement* getElementById(const XMLCh *elementId) const {
	return this->get_override("getElementById")(XMLString(elementId));
}

const XMLCh* getInputEncoding() const {
	return this->get_override("getInputEncoding")();
}

const XMLCh* getXmlEncoding() const {
	return this->get_override("getXmlEncoding")();
}

bool getXmlStandalone() const {
	return this->get_override("getXmlStandalone")();
}

void setXmlStandalone(bool standalone) {
	this->get_override("setXmlStandalone")(standalone);
}

const XMLCh* getXmlVersion() const {
	return this->get_override("getXmlVersion")();
}

void setXmlVersion(const XMLCh* version) {
	this->get_override("setXmlVersion")(XMLString(version));
}

const XMLCh* getDocumentURI() const {
	return this->get_override("getDocumentURI")();
}

void setDocumentURI(const XMLCh* documentURI) {
	this->get_override("setDocumentURI")(XMLString(documentURI));
}

bool getStrictErrorChecking() const {
	return this->get_override("getStrictErrorChecking")();
}

void setStrictErrorChecking(bool strictErrorChecking) {
	this->get_override("setStrictErrorChecking")(strictErrorChecking);
}

xercesc::DOMNode* renameNode(xercesc::DOMNode* n, const XMLCh* namespaceURI, const XMLCh* qualifiedName) {
	return this->get_override("renameNode")(boost::python::ptr(n), XMLString(namespaceURI), XMLString(qualifiedName));
}

xercesc::DOMNode* adoptNode(xercesc::DOMNode* source) {
	return this->get_override("adoptNode")(boost::python::ptr(source));
}

void normalizeDocument() {
	this->get_override("normalizeDocument")();
}

xercesc::DOMConfiguration* getDOMConfig() const {
	return this->get_override("getDOMConfig")();
}

xercesc::DOMEntity *createEntity(const XMLCh *name) {
	return this->get_override("createEntity")(XMLString(name));
}

xercesc::DOMDocumentType *createDocumentType(const XMLCh *name) {
	return this->get_override("createDocumentType")(XMLString(name));
}

xercesc::DOMDocumentType* createDocumentType(const XMLCh *qName, const XMLCh* publicId, const XMLCh* systemId) {
	if(boost::python::override createDocumentType = this->get_override("createDocumentType")){
		return createDocumentType(XMLString(qName), XMLString(publicId), XMLString(systemId));
	}else{
		return xercesc::DOMDocument::createDocumentType(qName, publicId, systemId);
	}
}

xercesc::DOMNotation *createNotation(const XMLCh *name) {
	return this->get_override("createNotation")(XMLString(name));
}

xercesc::DOMElement *createElementNS(const XMLCh *namespaceURI, const XMLCh *qualifiedName, const XMLFileLoc lineNum, const XMLFileLoc columnNum) {
	return this->get_override("createElementNS")(XMLString(namespaceURI), XMLString(qualifiedName), lineNum, columnNum);
}

//! ---------- DOMDocumentRange ----------
xercesc::DOMRange *createRange() {
	return this->get_override("createRange")();
}

//! ---------- DOMXPathEvaluator ----------
xercesc::DOMXPathExpression* createExpression(const XMLCh *expression, const xercesc::DOMXPathNSResolver *resolver) {
	return this->get_override("createExpression")(XMLString(expression), boost::python::ptr(resolver));
}

xercesc::DOMXPathNSResolver* createNSResolver(const xercesc::DOMNode *nodeResolver) {
	return this->get_override("createNSResolver")(boost::python::ptr(nodeResolver));
}

xercesc::DOMXPathResult* evaluate(const XMLCh *expression, const xercesc::DOMNode *contextNode, const xercesc::DOMXPathNSResolver *resolver, xercesc::DOMXPathResult::ResultType type, xercesc::DOMXPathResult* result) {
	return this->get_override("evaluate")(XMLString(expression), boost::python::ptr(contextNode), boost::python::ptr(resolver), type, boost::python::ptr(result));
}

//! ---------- DOMDocumentTraversal ----------
xercesc::DOMNodeIterator *createNodeIterator(xercesc::DOMNode* root, xercesc::DOMNodeFilter::ShowType whatToShow, xercesc::DOMNodeFilter* filter, bool entityReferenceExpansion) {
	return this->get_override("createNodeIterator")(boost::python::ptr(root), whatToShow, boost::python::ptr(filter), entityReferenceExpansion);
}

xercesc::DOMTreeWalker *createTreeWalker(xercesc::DOMNode* root, xercesc::DOMNodeFilter::ShowType whatToShow, xercesc::DOMNodeFilter* filter, bool entityReferenceExpansion) {
	return this->get_override("createTreeWalker")(boost::python::ptr(root), whatToShow, boost::python::ptr(filter), entityReferenceExpansion);
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

void DOMDocument_init(void) {
	//! xercesc::DOMDocument
	auto DOMDocument = boost::python::class_<DOMDocumentWrapper, boost::noncopyable, boost::python::bases<xercesc::DOMDocumentRange, xercesc::DOMXPathEvaluator, xercesc::DOMDocumentTraversal, xercesc::DOMNode> >("DOMDocument")
			.def(DOMDocumentDefVisitor<XMLString>())
			.def(DOMDocumentDefVisitor<std::string>())
			.def("createElement", boost::python::pure_virtual(&xercesc::DOMDocument::createElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createDocumentFragment", boost::python::pure_virtual(&xercesc::DOMDocument::createDocumentFragment), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createTextNode", boost::python::pure_virtual(&xercesc::DOMDocument::createTextNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createComment", boost::python::pure_virtual(&xercesc::DOMDocument::createComment), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createCDATASection", boost::python::pure_virtual(&xercesc::DOMDocument::createCDATASection), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createProcessingInstruction", boost::python::pure_virtual(&xercesc::DOMDocument::createProcessingInstruction), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createAttribute", boost::python::pure_virtual(&xercesc::DOMDocument::createAttribute), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createEntityReference", boost::python::pure_virtual(&xercesc::DOMDocument::createEntityReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDoctype", boost::python::pure_virtual(&xercesc::DOMDocument::getDoctype), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getImplementation", boost::python::pure_virtual(&xercesc::DOMDocument::getImplementation), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDocumentElement", boost::python::pure_virtual(&xercesc::DOMDocument::getDocumentElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementsByTagName", boost::python::pure_virtual(&xercesc::DOMDocument::getElementsByTagName), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("importNode", boost::python::pure_virtual(&xercesc::DOMDocument::importNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createElementNS", boost::python::pure_virtual(static_cast<xercesc::DOMElement*(xercesc::DOMDocument::*)(const XMLCh*, const XMLCh*)>(&xercesc::DOMDocument::createElementNS)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createAttributeNS", boost::python::pure_virtual(&xercesc::DOMDocument::createAttributeNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementsByTagNameNS", boost::python::pure_virtual(&xercesc::DOMDocument::getElementsByTagNameNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementById", boost::python::pure_virtual(&xercesc::DOMDocument::getElementById), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getInputEncoding", boost::python::pure_virtual(&xercesc::DOMDocument::getInputEncoding), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getXmlEncoding", boost::python::pure_virtual(&xercesc::DOMDocument::getXmlEncoding), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getXmlStandalone", boost::python::pure_virtual(&xercesc::DOMDocument::getXmlStandalone))
			.def("setXmlStandalone", boost::python::pure_virtual(&xercesc::DOMDocument::setXmlStandalone))
			.def("getXmlVersion", boost::python::pure_virtual(&xercesc::DOMDocument::getXmlVersion), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setXmlVersion", boost::python::pure_virtual(&xercesc::DOMDocument::setXmlVersion))
			.def("getDocumentURI", boost::python::pure_virtual(&xercesc::DOMDocument::getDocumentURI), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setDocumentURI", boost::python::pure_virtual(&xercesc::DOMDocument::setDocumentURI))
			.def("getStrictErrorChecking", boost::python::pure_virtual(&xercesc::DOMDocument::getStrictErrorChecking))
			.def("setStrictErrorChecking", boost::python::pure_virtual(&xercesc::DOMDocument::setStrictErrorChecking))
			.def("renameNode", boost::python::pure_virtual(&xercesc::DOMDocument::renameNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("adoptNode", boost::python::pure_virtual(&xercesc::DOMDocument::adoptNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("normalizeDocument", boost::python::pure_virtual(&xercesc::DOMDocument::normalizeDocument))
			.def("getDOMConfig", boost::python::pure_virtual(&xercesc::DOMDocument::getDOMConfig), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createEntity", boost::python::pure_virtual(&xercesc::DOMDocument::createEntity), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createDocumentType", boost::python::pure_virtual(static_cast<xercesc::DOMDocumentType*(xercesc::DOMDocument::*)(const XMLCh*)>(&xercesc::DOMDocument::createDocumentType)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createDocumentType", static_cast<xercesc::DOMDocumentType*(xercesc::DOMDocument::*)(const XMLCh*, const XMLCh*, const XMLCh*)>(&xercesc::DOMDocument::createDocumentType), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createNotation", boost::python::pure_virtual(&xercesc::DOMDocument::createNotation), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createElementNS", boost::python::pure_virtual(static_cast<xercesc::DOMElement*(xercesc::DOMDocument::*)(const XMLCh*, const XMLCh*, XMLFileLoc, XMLFileLoc)>(&xercesc::DOMDocument::createElementNS)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
