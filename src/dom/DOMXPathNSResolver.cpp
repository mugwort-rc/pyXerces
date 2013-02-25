/*
 * DOMXPathNSResolver.cpp
 *
 *  Created on: 2013/02/26
 *      Author: mugwort_rc
 */

#include "DOMXPathNSResolver.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMXPathNSResolver.hpp>

namespace pyxerces {

void DOMXPathNSResolver_init(void) {
	//! xercesc::DOMXPathNSResolver
	boost::python::class_<xercesc::DOMXPathNSResolver, boost::noncopyable>("DOMXPathNSResolver", boost::python::no_init)
			.def("lookupNamespaceURI", &xercesc::DOMXPathNSResolver::lookupNamespaceURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("lookupPrefix", &xercesc::DOMXPathNSResolver::lookupPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("addNamespaceBinding", &xercesc::DOMXPathNSResolver::addNamespaceBinding)
			.def("release", &xercesc::DOMXPathNSResolver::release)
			;
}

} /* namespace pyxerces */
