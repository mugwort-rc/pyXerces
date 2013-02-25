/*
 * DOMProcessingInstruction.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMProcessingInstruction.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMProcessingInstruction.hpp>

namespace pyxerces {

void DOMProcessingInstruction_init(void) {
	//! xercesc::DOMProcessingInstruction
	boost::python::class_<xercesc::DOMProcessingInstruction, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMProcessingInstruction", boost::python::no_init)
			.def("getTarget", &xercesc::DOMProcessingInstruction::getTarget, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getData", &xercesc::DOMProcessingInstruction::getData, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setData", &xercesc::DOMProcessingInstruction::setData)
			;
}

} /* namespace pyxerces */
