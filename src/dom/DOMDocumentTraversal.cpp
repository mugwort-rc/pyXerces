/*
 * DOMDocumentTraversal.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "DOMDocumentTraversal.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNode.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMNodeIterator.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMTreeWalker.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMDocumentTraversal.hpp>

namespace pyxerces {

void DOMDocumentTraversal_init(void) {
	//! xercesc::DOMDocumentTraversal
	boost::python::class_<xercesc::DOMDocumentTraversal, boost::noncopyable>("DOMDocumentTraversal", boost::python::no_init)
			.def("createNodeIterator", &xercesc::DOMDocumentTraversal::createNodeIterator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createTreeWalker", &xercesc::DOMDocumentTraversal::createTreeWalker, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
