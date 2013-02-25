/*
 * DOMLSInput.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSInput.h"

#include <boost/python.hpp>
#include <xercesc/sax/InputSource.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMLSInput.hpp>

namespace pyxerces {

void DOMLSInput_init(void) {
	//! xercesc::DOMLSInput
	boost::python::class_<xercesc::DOMLSInput, boost::noncopyable>("DOMLSInput", boost::python::no_init)
			.def("getStringData", &xercesc::DOMLSInput::getStringData, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getByteStream", &xercesc::DOMLSInput::getByteStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEncoding", &xercesc::DOMLSInput::getEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPublicId", &xercesc::DOMLSInput::getPublicId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::DOMLSInput::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getBaseURI", &xercesc::DOMLSInput::getBaseURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setStringData", &xercesc::DOMLSInput::setStringData)
			.def("setByteStream", &xercesc::DOMLSInput::setByteStream)
			.def("setEncoding", &xercesc::DOMLSInput::setEncoding)
			.def("setPublicId", &xercesc::DOMLSInput::setPublicId)
			.def("setSystemId", &xercesc::DOMLSInput::setSystemId)
			.def("setBaseURI", &xercesc::DOMLSInput::setBaseURI)
			.def("setIssueFatalErrorIfNotFound", &xercesc::DOMLSInput::setIssueFatalErrorIfNotFound)
			.def("getIssueFatalErrorIfNotFound", &xercesc::DOMLSInput::getIssueFatalErrorIfNotFound)
			.def("release", &xercesc::DOMLSInput::release)
			;
}

} /* namespace pyxerces */
