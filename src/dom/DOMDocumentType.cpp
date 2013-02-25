/*
 * DOMDocumentType.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMDocumentType.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMDocumentType.hpp>

namespace pyxerces {

void DOMDocumentType_init(void) {
	//! xercesc::DOMDocumentType
	boost::python::class_<xercesc::DOMDocumentType, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMDocumentType", boost::python::no_init)
			.def("getName", &xercesc::DOMDocumentType::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getEntities", &xercesc::DOMDocumentType::getEntities, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNotations", &xercesc::DOMDocumentType::getNotations, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPublicId", &xercesc::DOMDocumentType::getPublicId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::DOMDocumentType::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getInternalSubset", &xercesc::DOMDocumentType::getInternalSubset, boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxerces */
