/*
 * DOMRangeException.cpp
 *
 *  Created on: 2013/02/27
 *      Author: mugwort_rc
 */

#include "DOMRangeException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMRangeException.hpp>

namespace pyxerces {

PyObject* pyXercesDOMRangeExceptionType = nullptr;

void translateDOMRangeException(const xercesc::DOMRangeException& e) {
	assert(pyXercesDOMRangeExceptionType != nullptr);
	boost::python::object instance(e);
	PyErr_SetObject(pyXercesDOMRangeExceptionType, instance.ptr());
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
	pyXercesDOMRangeExceptionType = DOMRangeException.ptr();
	boost::python::register_exception_translator<xercesc::DOMRangeException>(&translateDOMRangeException);
}

} /* namespace pyxerces */
