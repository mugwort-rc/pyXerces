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

void DOMDocument_init(void) {
	//! xercesc::DOMDocument
	auto DOMDocument = boost::python::class_<xercesc::DOMDocument, boost::noncopyable, boost::python::bases<xercesc::DOMDocumentRange, xercesc::DOMXPathEvaluator, xercesc::DOMDocumentTraversal, xercesc::DOMNode> >("DOMDocument", boost::python::no_init)
			.def(DOMDocumentDefVisitor<XMLString>())
			.def(DOMDocumentDefVisitor<std::string>())
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
