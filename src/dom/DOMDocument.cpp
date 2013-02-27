/*
 * DOMDocument.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMDocument.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNode.hpp>					//!< for forward declaration
#include <xercesc/dom/DOMConfiguration.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMDocumentType.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMElement.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMDocumentFragment.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMComment.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMCDATASection.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMProcessingInstruction.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMAttr.hpp>					//!< for forward declaration
#include <xercesc/dom/DOMEntity.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMEntityReference.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMImplementation.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMNodeFilter.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMNodeList.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMNotation.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMText.hpp>					//!< for forward declaration
#include <xercesc/dom/DOMNode.hpp>					//!< for forward declaration
#include <xercesc/dom/DOMDocument.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMDocumentDefVisitor
: public boost::python::def_visitor<DOMDocumentDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createElement", static_cast<xercesc::DOMElement*(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::createElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createElement", static_cast<xercesc::DOMElement*(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::createElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createTextNode", static_cast<xercesc::DOMText*(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::createTextNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createTextNode", static_cast<xercesc::DOMText*(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::createTextNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createComment", static_cast<xercesc::DOMComment*(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::createComment), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createComment", static_cast<xercesc::DOMComment*(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::createComment), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createCDATASection", static_cast<xercesc::DOMCDATASection*(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::createCDATASection), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createCDATASection", static_cast<xercesc::DOMCDATASection*(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::createCDATASection), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createProcessingInstruction", static_cast<xercesc::DOMProcessingInstruction*(*)(xercesc::DOMDocument&, const XMLString&, const XMLString&)>(&DOMDocumentDefVisitor::createProcessingInstruction), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createProcessingInstruction", static_cast<xercesc::DOMProcessingInstruction*(*)(xercesc::DOMDocument&, const std::string&, const std::string&)>(&DOMDocumentDefVisitor::createProcessingInstruction), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createAttribute", static_cast<xercesc::DOMAttr*(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::createAttribute), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createAttribute", static_cast<xercesc::DOMAttr*(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::createAttribute), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createEntityReference", static_cast<xercesc::DOMEntityReference*(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::createEntityReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createEntityReference", static_cast<xercesc::DOMEntityReference*(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::createEntityReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagName", static_cast<xercesc::DOMNodeList*(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::getElementsByTagName), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagName", static_cast<xercesc::DOMNodeList*(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::getElementsByTagName), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createElementNS", static_cast<xercesc::DOMElement*(*)(xercesc::DOMDocument&, const XMLString&, const XMLString&)>(&DOMDocumentDefVisitor::createElementNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createElementNS", static_cast<xercesc::DOMElement*(*)(xercesc::DOMDocument&, const std::string&, const std::string&)>(&DOMDocumentDefVisitor::createElementNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createAttributeNS", static_cast<xercesc::DOMAttr*(*)(xercesc::DOMDocument&, const XMLString&, const XMLString&)>(&DOMDocumentDefVisitor::createAttributeNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createAttributeNS", static_cast<xercesc::DOMAttr*(*)(xercesc::DOMDocument&, const std::string&, const std::string&)>(&DOMDocumentDefVisitor::createAttributeNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagNameNS", static_cast<xercesc::DOMNodeList*(*)(xercesc::DOMDocument&, const XMLString&, const XMLString&)>(&DOMDocumentDefVisitor::getElementsByTagNameNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementsByTagNameNS", static_cast<xercesc::DOMNodeList*(*)(xercesc::DOMDocument&, const std::string&, const std::string&)>(&DOMDocumentDefVisitor::getElementsByTagNameNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementById", static_cast<xercesc::DOMElement*(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::getElementById), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementById", static_cast<xercesc::DOMElement*(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::getElementById), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setXmlVersion", static_cast<void(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::setXmlVersion))
	.def("setXmlVersion", static_cast<void(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::setXmlVersion))
	.def("setDocumentURI", static_cast<void(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::setDocumentURI))
	.def("setDocumentURI", static_cast<void(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::setDocumentURI))
	.def("renameNode", static_cast<xercesc::DOMNode*(*)(xercesc::DOMDocument&, xercesc::DOMNode*, const XMLString&, const XMLString&)>(&DOMDocumentDefVisitor::renameNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("renameNode", static_cast<xercesc::DOMNode*(*)(xercesc::DOMDocument&, xercesc::DOMNode*, const std::string&, const std::string&)>(&DOMDocumentDefVisitor::renameNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createEntity", static_cast<xercesc::DOMEntity*(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::createEntity), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createEntity", static_cast<xercesc::DOMEntity*(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::createEntity), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocumentType", static_cast<xercesc::DOMDocumentType*(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::createDocumentType), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocumentType", static_cast<xercesc::DOMDocumentType*(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::createDocumentType), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocumentType", static_cast<xercesc::DOMDocumentType*(*)(xercesc::DOMDocument&, const XMLString&, const XMLString&, const XMLString&)>(&DOMDocumentDefVisitor::createDocumentType), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocumentType", static_cast<xercesc::DOMDocumentType*(*)(xercesc::DOMDocument&, const std::string&, const std::string&, const std::string&)>(&DOMDocumentDefVisitor::createDocumentType), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createNotation", static_cast<xercesc::DOMNotation*(*)(xercesc::DOMDocument&, const XMLString&)>(&DOMDocumentDefVisitor::createNotation), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createNotation", static_cast<xercesc::DOMNotation*(*)(xercesc::DOMDocument&, const std::string&)>(&DOMDocumentDefVisitor::createNotation), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createElementNS", static_cast<xercesc::DOMElement*(*)(xercesc::DOMDocument&, const XMLString&, const XMLString&, const XMLFileLoc, const XMLFileLoc)>(&DOMDocumentDefVisitor::createElementNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createElementNS", static_cast<xercesc::DOMElement*(*)(xercesc::DOMDocument&, const std::string&, const std::string&, const XMLFileLoc, const XMLFileLoc)>(&DOMDocumentDefVisitor::createElementNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMElement* createElement(xercesc::DOMDocument& self, const XMLString& tagName) {
	return self.createElement(tagName.ptr());
}

static xercesc::DOMElement* createElement(xercesc::DOMDocument& self, const std::string& tagName) {
	XMLString buff(tagName);
	return DOMDocumentDefVisitor::createElement(self, buff);
}

static xercesc::DOMText* createTextNode(xercesc::DOMDocument& self, const XMLString& data) {
	return self.createTextNode(data.ptr());
}

static xercesc::DOMText* createTextNode(xercesc::DOMDocument& self, const std::string& data) {
	XMLString buff(data);
	return DOMDocumentDefVisitor::createTextNode(self, buff);
}

static xercesc::DOMComment* createComment(xercesc::DOMDocument& self, const XMLString& data) {
	return self.createComment(data.ptr());
}

static xercesc::DOMComment* createComment(xercesc::DOMDocument& self, const std::string& data) {
	XMLString buff(data);
	return DOMDocumentDefVisitor::createComment(self, buff);
}

static xercesc::DOMCDATASection* createCDATASection(xercesc::DOMDocument& self, const XMLString& data) {
	return self.createCDATASection(data.ptr());
}

static xercesc::DOMCDATASection* createCDATASection(xercesc::DOMDocument& self, const std::string& data) {
	XMLString buff(data);
	return DOMDocumentDefVisitor::createCDATASection(self, buff);
}

static xercesc::DOMProcessingInstruction* createProcessingInstruction(xercesc::DOMDocument& self, const XMLString& target, const XMLString& data) {
	return self.createProcessingInstruction(target.ptr(), data.ptr());
}

static xercesc::DOMProcessingInstruction* createProcessingInstruction(xercesc::DOMDocument& self, const std::string& target, const std::string& data) {
	XMLString buff1(target), buff2(data);
	return DOMDocumentDefVisitor::createProcessingInstruction(self, buff1, buff2);
}

static xercesc::DOMAttr* createAttribute(xercesc::DOMDocument& self, const XMLString& name) {
	return self.createAttribute(name.ptr());
}

static xercesc::DOMAttr* createAttribute(xercesc::DOMDocument& self, const std::string& name) {
	XMLString buff(name);
	return DOMDocumentDefVisitor::createAttribute(self, buff);
}

static xercesc::DOMEntityReference* createEntityReference(xercesc::DOMDocument& self, const XMLString& name) {
	return self.createEntityReference(name.ptr());
}

static xercesc::DOMEntityReference* createEntityReference(xercesc::DOMDocument& self, const std::string& name) {
	XMLString buff(name);
	return DOMDocumentDefVisitor::createEntityReference(self, buff);
}

static xercesc::DOMNodeList* getElementsByTagName(xercesc::DOMDocument& self, const XMLString& tagName) {
	return self.getElementsByTagName(tagName.ptr());
}

static xercesc::DOMNodeList* getElementsByTagName(xercesc::DOMDocument& self, const std::string& tagName) {
	XMLString buff(tagName);
	return DOMDocumentDefVisitor::getElementsByTagName(self, buff);
}

static xercesc::DOMElement* createElementNS(xercesc::DOMDocument& self, const XMLString& namespaceURI, const XMLString& qualifiedName) {
	return self.createElementNS(namespaceURI.ptr(), qualifiedName.ptr());
}

static xercesc::DOMElement* createElementNS(xercesc::DOMDocument& self, const std::string& namespaceURI, const std::string& qualifiedName) {
	XMLString buff1(namespaceURI), buff2(qualifiedName);
	return DOMDocumentDefVisitor::createElementNS(self, buff1, buff2);
}

static xercesc::DOMAttr* createAttributeNS(xercesc::DOMDocument& self, const XMLString& namespaceURI, const XMLString& qualifiedName) {
	return self.createAttributeNS(namespaceURI.ptr(), qualifiedName.ptr());
}

static xercesc::DOMAttr* createAttributeNS(xercesc::DOMDocument& self, const std::string& namespaceURI, const std::string& qualifiedName) {
	XMLString buff1(namespaceURI), buff2(qualifiedName);
	return DOMDocumentDefVisitor::createAttributeNS(self, buff1, buff2);
}

static xercesc::DOMNodeList* getElementsByTagNameNS(xercesc::DOMDocument& self, const XMLString& namespaceURI, const XMLString& localName) {
	return self.getElementsByTagNameNS(namespaceURI.ptr(), localName.ptr());
}

static xercesc::DOMNodeList* getElementsByTagNameNS(xercesc::DOMDocument& self, const std::string& namespaceURI, const std::string& localName) {
	XMLString buff1(namespaceURI), buff2(localName);
	return DOMDocumentDefVisitor::getElementsByTagNameNS(self, buff1, buff2);
}

static xercesc::DOMElement* getElementById(xercesc::DOMDocument& self, const XMLString& elementId) {
	return self.getElementById(elementId.ptr());
}

static xercesc::DOMElement* getElementById(xercesc::DOMDocument& self, const std::string& elementId) {
	XMLString buff(elementId);
	return DOMDocumentDefVisitor::getElementById(self, buff);
}

static void setXmlVersion(xercesc::DOMDocument& self, const XMLString& version) {
	self.setXmlVersion(version.ptr());
}

static void setXmlVersion(xercesc::DOMDocument& self, const std::string& version) {
	XMLString buff(version);
	DOMDocumentDefVisitor::setXmlVersion(self, buff);
}

static void setDocumentURI(xercesc::DOMDocument& self, const XMLString& documentURI) {
	self.setDocumentURI(documentURI.ptr());
}

static void setDocumentURI(xercesc::DOMDocument& self, const std::string& documentURI) {
	XMLString buff(documentURI);
	DOMDocumentDefVisitor::setDocumentURI(self, buff);
}

static xercesc::DOMNode* renameNode(xercesc::DOMDocument& self, xercesc::DOMNode* n, const XMLString& namespaceURI, const XMLString& qualifiedName) {
	return self.renameNode(n, namespaceURI.ptr(), qualifiedName.ptr());
}

static xercesc::DOMNode* renameNode(xercesc::DOMDocument& self, xercesc::DOMNode* n, const std::string& namespaceURI, const std::string& qualifiedName) {
	XMLString buff1(namespaceURI), buff2(qualifiedName);
	return DOMDocumentDefVisitor::renameNode(self, n, buff1, buff2);
}

static xercesc::DOMEntity* createEntity(xercesc::DOMDocument& self, const XMLString& name) {
	return self.createEntity(name.ptr());
}

static xercesc::DOMEntity* createEntity(xercesc::DOMDocument& self, const std::string& name) {
	XMLString buff(name);
	return DOMDocumentDefVisitor::createEntity(self, buff);
}

static xercesc::DOMDocumentType* createDocumentType(xercesc::DOMDocument& self, const XMLString& name) {
	return self.createDocumentType(name.ptr());
}

static xercesc::DOMDocumentType* createDocumentType(xercesc::DOMDocument& self, const std::string& name) {
	XMLString buff(name);
	return DOMDocumentDefVisitor::createDocumentType(self, buff);
}

static xercesc::DOMDocumentType* createDocumentType(xercesc::DOMDocument& self, const XMLString& qName, const XMLString& publicId, const XMLString& systemId) {
	return self.createDocumentType(qName.ptr(), publicId.ptr(), systemId.ptr());
}

static xercesc::DOMDocumentType* createDocumentType(xercesc::DOMDocument& self, const std::string& qName, const std::string& publicId, const std::string& systemId) {
	XMLString buff1(qName), buff2(publicId), buff3(systemId);
	return DOMDocumentDefVisitor::createDocumentType(self, buff1, buff2, buff3);
}

static xercesc::DOMNotation* createNotation(xercesc::DOMDocument& self, const XMLString& name) {
	return self.createNotation(name.ptr());
}

static xercesc::DOMNotation* createNotation(xercesc::DOMDocument& self, const std::string& name) {
	XMLString buff(name);
	return DOMDocumentDefVisitor::createNotation(self, buff);
}

static xercesc::DOMElement* createElementNS(xercesc::DOMDocument& self, const XMLString& namespaceURI, const XMLString& qualifiedName, const XMLFileLoc lineNum, const XMLFileLoc columnNum) {
	return self.createElementNS(namespaceURI.ptr(), qualifiedName.ptr(), lineNum, columnNum);
}

static xercesc::DOMElement* createElementNS(xercesc::DOMDocument& self, const std::string& namespaceURI, const std::string& qualifiedName, const XMLFileLoc lineNum, const XMLFileLoc columnNum) {
	XMLString buff1(namespaceURI), buff2(qualifiedName);
	return DOMDocumentDefVisitor::createElementNS(self, buff1, buff2, lineNum, columnNum);
}
};

void DOMDocument_init(void) {
	//! xercesc::DOMDocument
	auto DOMDocument = boost::python::class_<xercesc::DOMDocument, boost::noncopyable, boost::python::bases<xercesc::DOMDocumentRange, xercesc::DOMXPathEvaluator, xercesc::DOMDocumentTraversal, xercesc::DOMNode> >("DOMDocument", boost::python::no_init)
			.def(DOMDocumentDefVisitor())
			.def("createElement", &xercesc::DOMDocument::createElement, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createDocumentFragment", &xercesc::DOMDocument::createDocumentFragment, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createTextNode", &xercesc::DOMDocument::createTextNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createComment", &xercesc::DOMDocument::createComment, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createCDATASection", &xercesc::DOMDocument::createCDATASection, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createProcessingInstruction", &xercesc::DOMDocument::createProcessingInstruction, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createAttribute", &xercesc::DOMDocument::createAttribute, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createEntityReference", &xercesc::DOMDocument::createEntityReference, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDoctype", &xercesc::DOMDocument::getDoctype, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getImplementation", &xercesc::DOMDocument::getImplementation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDocumentElement", &xercesc::DOMDocument::getDocumentElement, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementsByTagName", &xercesc::DOMDocument::getElementsByTagName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("importNode", &xercesc::DOMDocument::importNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createElementNS", static_cast<xercesc::DOMElement*(xercesc::DOMDocument::*)(const XMLCh*, const XMLCh*)>(&xercesc::DOMDocument::createElementNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createAttributeNS", &xercesc::DOMDocument::createAttributeNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementsByTagNameNS", &xercesc::DOMDocument::getElementsByTagNameNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementById", &xercesc::DOMDocument::getElementById, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getInputEncoding", &xercesc::DOMDocument::getInputEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getXmlEncoding", &xercesc::DOMDocument::getXmlEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getXmlStandalone", &xercesc::DOMDocument::getXmlStandalone)
			.def("setXmlStandalone", &xercesc::DOMDocument::setXmlStandalone)
			.def("getXmlVersion", &xercesc::DOMDocument::getXmlVersion, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setXmlVersion", &xercesc::DOMDocument::setXmlVersion)
			.def("getDocumentURI", &xercesc::DOMDocument::getDocumentURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setDocumentURI", &xercesc::DOMDocument::setDocumentURI)
			.def("getStrictErrorChecking", &xercesc::DOMDocument::getStrictErrorChecking)
			.def("setStrictErrorChecking", &xercesc::DOMDocument::setStrictErrorChecking)
			.def("renameNode", &xercesc::DOMDocument::renameNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("adoptNode", &xercesc::DOMDocument::adoptNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("normalizeDocument", &xercesc::DOMDocument::normalizeDocument)
			.def("getDOMConfig", &xercesc::DOMDocument::getDOMConfig, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createEntity", &xercesc::DOMDocument::createEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createDocumentType", static_cast<xercesc::DOMDocumentType*(xercesc::DOMDocument::*)(const XMLCh*)>(&xercesc::DOMDocument::createDocumentType), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createNotation", &xercesc::DOMDocument::createNotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createElementNS", static_cast<xercesc::DOMElement*(xercesc::DOMDocument::*)(const XMLCh*, const XMLCh*, XMLFileLoc, XMLFileLoc)>(&xercesc::DOMDocument::createElementNS), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
