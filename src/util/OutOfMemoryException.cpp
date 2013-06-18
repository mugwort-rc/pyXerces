/*
 * OutOfMemoryException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "OutOfMemoryException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/util/OutOfMemoryException.hpp>

#include "../common/Exception.h"
#include "../util/XMLString.h"

namespace pyxerces {

PyObject* pyXercesOutOfMemoryExceptionType = nullptr;

void translateOutOfMemoryException(const xercesc::OutOfMemoryException& e) {
	assert(pyXercesOutOfMemoryExceptionType != nullptr);
	boost::python::object instance(e);

	boost::python::object exceptionType(boost::python::handle<>(boost::python::borrowed(pyXercesOutOfMemoryExceptionType)));
	exceptionType.attr("cause") = instance;

	PyErr_SetString(pyXercesOutOfMemoryExceptionType, XMLString(e.getMessage()).toString().c_str());
}

void OutOfMemoryException_init(void) {
	//! xercesc::OutOfMemoryException
	auto OutOfMemoryException = boost::python::class_<xercesc::OutOfMemoryException>("OutOfMemoryException")
			.def("getCode", &xercesc::OutOfMemoryException::getCode)
			.def("getMessage", &xercesc::OutOfMemoryException::getMessage, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getType", &xercesc::OutOfMemoryException::getType, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSrcFile", &xercesc::OutOfMemoryException::getSrcFile)
			.def("getSrcLine", &xercesc::OutOfMemoryException::getSrcLine)
			;
	pyXercesOutOfMemoryExceptionType = createException("OutOfMemoryException", PyExc_MemoryError);
	boost::python::register_exception_translator<xercesc::OutOfMemoryException>(&translateOutOfMemoryException);
}

} /* namespace pyxerces */
