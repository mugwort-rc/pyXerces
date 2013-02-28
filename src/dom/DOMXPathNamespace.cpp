/*
 * DOMXPathNamespace.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "DOMXPathNamespace.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMElement.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMXPathNamespace.hpp>

namespace pyxerces {

void DOMXPathNamespace_init(void) {
	//! xercesc::DOMXPathNamespace
	auto DOMXPathNamespace = boost::python::class_<xercesc::DOMXPathNamespace, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMXPathNamespace", boost::python::no_init)
			.def("getOwnerElement", &xercesc::DOMXPathNamespace::getOwnerElement, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
	boost::python::scope DOMXPathNamespaceScope = DOMXPathNamespace;
	//! xercesc::DOMXPathNamespace::XPathNodeType
	boost::python::enum_<xercesc::DOMXPathNamespace::XPathNodeType>("XPathNodeType")
			.value("XPATH_NAMESPACE_NODE", xercesc::DOMXPathNamespace::XPATH_NAMESPACE_NODE)
			.export_values()
			;
}

} /* namespace pyxerces */
