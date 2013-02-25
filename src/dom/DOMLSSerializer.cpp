/*
 * DOMLSSerializer.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSSerializer.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMLSOutput.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMLSSerializer.hpp>

namespace pyxerces {

//! DOMLSSerializer
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMLSSerializerWriteToStringOverloads, writeToString, 1, 2)

void DOMLSSerializer_init(void) {
	//! xercesc::DOMLSSerializer
	boost::python::class_<xercesc::DOMLSSerializer, boost::noncopyable>("DOMLSSerializer", boost::python::no_init)
			.def("getDomConfig", &xercesc::DOMLSSerializer::getDomConfig, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setNewLine", &xercesc::DOMLSSerializer::setNewLine)
			.def("setFilter", &xercesc::DOMLSSerializer::setFilter)
			.def("getNewLine", &xercesc::DOMLSSerializer::getNewLine, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getFilter", &xercesc::DOMLSSerializer::getFilter, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("write", &xercesc::DOMLSSerializer::write)
			.def("writeToURI", &xercesc::DOMLSSerializer::writeToURI)
			.def("writeToString", &xercesc::DOMLSSerializer::writeToString, DOMLSSerializerWriteToStringOverloads()[boost::python::return_value_policy<boost::python::return_by_value>()])
			.def("release", &xercesc::DOMLSSerializer::release)
			;
}

} /* namespace pyxerces */
