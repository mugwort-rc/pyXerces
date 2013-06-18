/*
 * DOMRangeException.cpp
 *
 *  Created on: 2013/02/27
 *      Author: mugwort_rc
 */

#include "DOMRangeException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/dom/DOMRangeException.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

extern PyObject* pyXercesDOMExceptionType;

void translateDOMRangeException(const xercesc::DOMRangeException& e) {
	assert(pyXercesDOMExceptionType != nullptr);
	boost::python::object instance(e);

	boost::python::object exceptionType(boost::python::handle<>(boost::python::borrowed(pyXercesDOMExceptionType)));
	exceptionType.attr("cause") = instance;

	PyErr_SetString(pyXercesDOMExceptionType, XMLString(e.getMessage()).toString().c_str());
}

void DOMRangeException_init(void) {
	//! xercesc::DOMRangeException
	auto DOMRangeException = boost::python::class_<xercesc::DOMRangeException, boost::python::bases<xercesc::DOMException> >("DOMRangeException")
			.def(boost::python::init<short, short, xercesc::MemoryManager* const>())
			.def(boost::python::init<const xercesc::DOMRangeException&>())
			;
	boost::python::scope DOMLSExceptionScope = DOMRangeException;
	//! xercesc::DOMRangeException::RangeExceptionCode
	boost::python::enum_<xercesc::DOMRangeException::RangeExceptionCode>("RangeExceptionCode")
			.value("BAD_BOUNDARYPOINTS_ERR", xercesc::DOMRangeException::BAD_BOUNDARYPOINTS_ERR)
			.value("INVALID_NODE_TYPE_ERR", xercesc::DOMRangeException::INVALID_NODE_TYPE_ERR)
			.export_values()
			;
	boost::python::register_exception_translator<xercesc::DOMRangeException>(&translateDOMRangeException);
}

} /* namespace pyxerces */
