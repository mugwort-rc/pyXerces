/*
 * DOMLSException.cpp
 *
 *  Created on: 2013/02/27
 *      Author: mugwort_rc
 */

#include "DOMLSException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/dom/DOMLSException.hpp>

namespace pyxerces {

extern PyObject* pyXercesDOMExceptionType;

void translateDOMLSException(const xercesc::DOMLSException& e) {
	assert(pyXercesDOMExceptionType != nullptr);
	boost::python::object instance(e);
	PyErr_SetObject(pyXercesDOMExceptionType, instance.ptr());
}

void DOMLSException_init(void) {
	//! xercesc::DOMLSException
	auto DOMLSException = boost::python::class_<xercesc::DOMLSException, boost::python::bases<xercesc::DOMException> >("DOMLSException")
			.def(boost::python::init<short, short, xercesc::MemoryManager* const>())
			.def(boost::python::init<const xercesc::DOMLSException&>())
			;
	boost::python::scope DOMLSExceptionScope = DOMLSException;
	//! xercesc::DOMLSException::LSExceptionCode
	boost::python::enum_<xercesc::DOMLSException::LSExceptionCode>("LSExceptionCode")
			.value("PARSE_ERR", xercesc::DOMLSException::PARSE_ERR)
			.value("SERIALIZE_ERR", xercesc::DOMLSException::SERIALIZE_ERR)
			.export_values()
			;
	boost::python::register_exception_translator<xercesc::DOMLSException>(&translateDOMLSException);
}

} /* namespace pyxerces */
