/*
 * DOMNodeList.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMNodeList.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNode.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMNodeList.hpp>

namespace pyxerces {

void DOMNodeList_init(void) {
	//! xercesc::DOMNodeList
	boost::python::class_<xercesc::DOMNodeList, boost::noncopyable>("DOMNodeList", boost::python::no_init)
			.def("item", &xercesc::DOMNodeList::item, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLength", &xercesc::DOMNodeList::getLength)
			.def("__getitem__", &xercesc::DOMNodeList::item, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("__len__", &xercesc::DOMNodeList::getLength)
			;
}

} /* namespace pyxerces */
