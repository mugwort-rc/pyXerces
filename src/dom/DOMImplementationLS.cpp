/*
 * DOMImplementationLS.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMImplementationLS.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMLSInput.hpp>					//!< for forward declaration
#include <xercesc/dom/DOMLSOutput.hpp>					//!< for forward declaration
#include <xercesc/dom/DOMLSSerializer.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMLSParser.hpp>					//!< for forward declaration
#include <xercesc/framework/XMLGrammarPool.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMImplementationLS.hpp>

namespace pyxerces {

//! DOMImplementationLS
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSParserOverloads, createLSParser, 2, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSSerializerOverloads, createLSSerializer, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSInputOverloads, createLSInput, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSOutputOverloads, createLSOutput, 0, 1)

void DOMImplementationLS_init(void) {
	//! xercesc::DOMImplementationLS
	auto DOMImplementationLS = boost::python::class_<xercesc::DOMImplementationLS, boost::noncopyable>("DOMImplementationLS", boost::python::no_init)
			.def("createLSParser", &xercesc::DOMImplementationLS::createLSParser, DOMImplementationLSCreateLSParserOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("createLSSerializer", &xercesc::DOMImplementationLS::createLSSerializer, DOMImplementationLSCreateLSSerializerOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("createLSInput", &xercesc::DOMImplementationLS::createLSInput, DOMImplementationLSCreateLSInputOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("createLSOutput", &xercesc::DOMImplementationLS::createLSOutput, DOMImplementationLSCreateLSOutputOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			;
	boost::python::scope DOMImplementationLSScope = DOMImplementationLS;
	//! xercesc::DOMImplementationLS::DOMImplementationLSMode
	boost::python::enum_<xercesc::DOMImplementationLS::DOMImplementationLSMode>("DOMImplementationLSMode")
			.value("MODE_SYNCHRONOUS", xercesc::DOMImplementationLS::MODE_SYNCHRONOUS)
			.value("MODE_ASYNCHRONOUS", xercesc::DOMImplementationLS::MODE_ASYNCHRONOUS)
			.export_values()
			;
}

} /* namespace pyxerces */
