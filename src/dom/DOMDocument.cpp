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

namespace pyxerces {

void DOMDocument_init(void) {
	//! xercesc::DOMDocument
	auto DOMDocument = boost::python::class_<xercesc::DOMDocument, boost::noncopyable, boost::python::bases<xercesc::DOMDocumentRange, xercesc::DOMXPathEvaluator, xercesc::DOMDocumentTraversal, xercesc::DOMNode> >("DOMDocument", boost::python::no_init)
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
