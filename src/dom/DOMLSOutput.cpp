/*
 * DOMLSOutput.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSOutput.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLFormatter.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMLSOutput.hpp>

namespace pyxerces {

void DOMLSOutput_init(void) {
	//! xercesc::DOMLSOutput
	boost::python::class_<xercesc::DOMLSOutput, boost::noncopyable>("DOMLSOutput", boost::python::no_init)
			.def("getByteStream", &xercesc::DOMLSOutput::getByteStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEncoding", &xercesc::DOMLSOutput::getEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::DOMLSOutput::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setByteStream", &xercesc::DOMLSOutput::setByteStream)
			.def("setEncoding", &xercesc::DOMLSOutput::setEncoding)
			.def("setSystemId", &xercesc::DOMLSOutput::setSystemId)
			.def("release", &xercesc::DOMLSOutput::release)
			;
}

} /* namespace pyxerces */
