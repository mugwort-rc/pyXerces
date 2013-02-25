/*
 * DOMStringList.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMStringList.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMStringList.hpp>

namespace pyxerces {

void DOMStringList_init(void) {
	//! xercesc::DOMStringList
	boost::python::class_<xercesc::DOMStringList, boost::noncopyable>("DOMStringList", boost::python::no_init)
			.def("item", &xercesc::DOMStringList::item, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLength", &xercesc::DOMStringList::getLength)
			.def("contains", &xercesc::DOMStringList::contains)
			.def("release", &xercesc::DOMStringList::release)
			;
}

} /* namespace pyxerces */
