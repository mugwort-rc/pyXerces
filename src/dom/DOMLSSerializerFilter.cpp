/*
 * DOMLSSerializerFilter.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSSerializerFilter.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMLSSerializerFilter.hpp>

namespace pyxerces {

void DOMLSSerializerFilter_init(void) {
	//! xercesc::DOMLSSerializerFilter
	boost::python::class_<xercesc::DOMLSSerializerFilter, boost::noncopyable, boost::python::bases<xercesc::DOMNodeFilter> >("DOMLSSerializerFilter", boost::python::no_init)
			.def("acceptNode", &xercesc::DOMLSSerializerFilter::acceptNode)
			.def("getWhatToShow", &xercesc::DOMLSSerializerFilter::getWhatToShow)
			;
}

} /* namespace pyxerces */
