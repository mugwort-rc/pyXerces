/*
 * DOMException.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/dom/DOMException.hpp>

#include "../common/Exception.h"
#include "../util/XMLString.h"

namespace pyxerces {

// !DOMException
PyObject* pyXercesDOMExceptionType = nullptr;

void translateDOMException(const xercesc::DOMException& e) {
	assert(pyXercesDOMExceptionType != nullptr);
	boost::python::object instance(e);

	boost::python::object exceptionType(boost::python::handle<>(boost::python::borrowed(pyXercesDOMExceptionType)));
	exceptionType.attr("cause") = instance;

	PyErr_SetString(pyXercesDOMExceptionType, XMLString(e.getMessage()).toString().c_str());
}

void DOMException_init(void) {
	//! xercesc::DOMException
	auto DOMException = boost::python::class_<xercesc::DOMException>("DOMException")
			.def(boost::python::init<short, boost::python::optional<short, xercesc::MemoryManager*> >())
			.def(boost::python::init<const xercesc::DOMException&>())
			.def("getMessage", &xercesc::DOMException::getMessage, boost::python::return_value_policy<boost::python::return_by_value>())
			.def_readwrite("code", &xercesc::DOMException::code)
			;
	pyXercesDOMExceptionType = createException("DOMException");
	boost::python::register_exception_translator<xercesc::DOMException>(&translateDOMException);

	boost::python::scope DOMExceptionScope = DOMException;
	//! xercesc::DOMException::ExceptionCode
	boost::python::enum_<xercesc::DOMException::ExceptionCode>("ExceptionCode")
			.value("INDEX_SIZE_ERR", xercesc::DOMException::INDEX_SIZE_ERR)
			.value("DOMSTRING_SIZE_ERR", xercesc::DOMException::DOMSTRING_SIZE_ERR)
			.value("HIERARCHY_REQUEST_ERR", xercesc::DOMException::HIERARCHY_REQUEST_ERR)
			.value("WRONG_DOCUMENT_ERR", xercesc::DOMException::WRONG_DOCUMENT_ERR)
			.value("INVALID_CHARACTER_ERR", xercesc::DOMException::INVALID_CHARACTER_ERR)
			.value("NO_DATA_ALLOWED_ERR", xercesc::DOMException::NO_DATA_ALLOWED_ERR)
			.value("NO_MODIFICATION_ALLOWED_ERR", xercesc::DOMException::NO_MODIFICATION_ALLOWED_ERR)
			.value("NOT_FOUND_ERR", xercesc::DOMException::NOT_FOUND_ERR)
			.value("NOT_SUPPORTED_ERR", xercesc::DOMException::NOT_SUPPORTED_ERR)
			.value("INUSE_ATTRIBUTE_ERR", xercesc::DOMException::INUSE_ATTRIBUTE_ERR)
			.value("INVALID_STATE_ERR", xercesc::DOMException::INVALID_STATE_ERR)
			.value("SYNTAX_ERR", xercesc::DOMException::SYNTAX_ERR)
			.value("INVALID_MODIFICATION_ERR", xercesc::DOMException::INVALID_MODIFICATION_ERR)
			.value("NAMESPACE_ERR", xercesc::DOMException::NAMESPACE_ERR)
			.value("INVALID_ACCESS_ERR", xercesc::DOMException::INVALID_ACCESS_ERR)
			.value("VALIDATION_ERR", xercesc::DOMException::VALIDATION_ERR)
			.value("TYPE_MISMATCH_ERR", xercesc::DOMException::TYPE_MISMATCH_ERR)
			.export_values()
			;
}

} /* namespace pyxerces */
