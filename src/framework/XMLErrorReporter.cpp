/*
 * XMLErrorReporter.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "XMLErrorReporter.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLErrorReporter.hpp>

namespace pyxerces {

void XMLErrorReporter_init(void) {
	//! xercesc::XMLErrorReporter
	auto XMLErrorReporter = boost::python::class_<xercesc::XMLErrorReporter, boost::noncopyable>("XMLErrorReporter", boost::python::no_init)
			.def("error", &xercesc::XMLErrorReporter::error)
			.def("resetErrors", &xercesc::XMLErrorReporter::resetErrors)
			;
	boost::python::scope XMLErrorReporterScope = XMLErrorReporter;
	//! xercesc::XMLErrorReporter::ErrTypes
	boost::python::enum_<xercesc::XMLErrorReporter::ErrTypes>("ErrTypes")
			.value("ErrType_Warning", xercesc::XMLErrorReporter::ErrType_Warning)
			.value("ErrType_Error", xercesc::XMLErrorReporter::ErrType_Error)
			.value("ErrType_Fatal", xercesc::XMLErrorReporter::ErrType_Fatal)
			.value("ErrTypes_Unknown", xercesc::XMLErrorReporter::ErrTypes_Unknown)
			.export_values()
			;

}

} /* namespace pyxerces */
