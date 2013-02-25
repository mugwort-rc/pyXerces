/*
 * DOMElement.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMElement.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMAttr.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMNodeList.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMTypeInfo.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMElement.hpp>

namespace pyxerces {

void DOMElement_init(void) {
	//! xercesc::DOMElement
	boost::python::class_<xercesc::DOMElement, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMElement", boost::python::no_init)
			.def("getTagName", &xercesc::DOMElement::getTagName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAttribute", &xercesc::DOMElement::getAttribute, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAttributeNode", &xercesc::DOMElement::getAttributeNode, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getElementsByTagName", &xercesc::DOMElement::getElementsByTagName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setAttribute", &xercesc::DOMElement::setAttribute)
			.def("setAttributeNode", &xercesc::DOMElement::setAttributeNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeAttributeNode", &xercesc::DOMElement::removeAttributeNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeAttribute", &xercesc::DOMElement::removeAttribute)
			.def("getAttributeNS", &xercesc::DOMElement::getAttributeNS, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setAttributeNS", &xercesc::DOMElement::setAttributeNS)
			.def("removeAttributeNS", &xercesc::DOMElement::removeAttributeNS)
			.def("getAttributeNodeNS", &xercesc::DOMElement::getAttributeNodeNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setAttributeNodeNS", &xercesc::DOMElement::setAttributeNodeNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementsByTagNameNS", &xercesc::DOMElement::getElementsByTagNameNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hasAttribute", &xercesc::DOMElement::hasAttribute)
			.def("hasAttributeNS", &xercesc::DOMElement::hasAttributeNS)
			.def("setIdAttribute", &xercesc::DOMElement::setIdAttribute)
			.def("setIdAttributeNS", &xercesc::DOMElement::setIdAttributeNS)
			.def("setIdAttributeNode", &xercesc::DOMElement::setIdAttributeNode)
			.def("getSchemaTypeInfo", &xercesc::DOMElement::getSchemaTypeInfo, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFirstElementChild", &xercesc::DOMElement::getFirstElementChild, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLastElementChild", &xercesc::DOMElement::getLastElementChild, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPreviousElementSibling", &xercesc::DOMElement::getPreviousElementSibling, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNextElementSibling", &xercesc::DOMElement::getNextElementSibling, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getChildElementCount", &xercesc::DOMElement::getChildElementCount)
			;
}

} /* namespace pyxerces */
