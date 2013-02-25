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
#include <xercesc/dom/DOMNode.hpp>

namespace pyxerces {

void DOMNode_init(void) {
	//! xercesc::DOMNode
	auto DOMNode = boost::python::class_<xercesc::DOMNode, boost::noncopyable>("DOMNode", boost::python::no_init)
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
