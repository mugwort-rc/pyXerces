/*
 * DOMNamedNodeMap.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMNamedNodeMap.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNode.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMNamedNodeMap.hpp>

namespace pyxerces {

void DOMNamedNodeMap_init(void) {
	//! xercesc::DOMNamedNodeMap
	boost::python::class_<xercesc::DOMNamedNodeMap, boost::noncopyable>("DOMNamedNodeMap", boost::python::no_init)
			.def("setNamedItem", &xercesc::DOMNamedNodeMap::setNamedItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("item", &xercesc::DOMNamedNodeMap::item, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNamedItem", &xercesc::DOMNamedNodeMap::getNamedItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLength", &xercesc::DOMNamedNodeMap::getLength)
			.def("removeNamedItem", &xercesc::DOMNamedNodeMap::removeNamedItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNamedItemNS", &xercesc::DOMNamedNodeMap::getNamedItemNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setNamedItemNS", &xercesc::DOMNamedNodeMap::setNamedItemNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeNamedItemNS", &xercesc::DOMNamedNodeMap::removeNamedItemNS, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
