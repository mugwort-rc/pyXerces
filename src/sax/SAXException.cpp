/*
 * SAXException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "SAXException.h"

#include <boost/python.hpp>
#include <xercesc/sax/SAXException.hpp>

namespace pyxerces {

//! SAXException
PyObject* pyXercesSAXExceptionType = nullptr;

void translateSAXException(const xercesc::SAXException& e) {
	assert(pyXercesSAXExceptionType != nullptr);
	boost::python::object instance(e);
	PyErr_SetObject(pyXercesSAXExceptionType, instance.ptr());
}

//! SAXNotSupportedException
PyObject* pyXercesSAXNotSupportedExceptionType = nullptr;

void translateSAXNotSupportedException(const xercesc::SAXNotSupportedException& e) {
	assert(pyXercesSAXNotSupportedExceptionType != nullptr);
	boost::python::object instance(e);
	PyErr_SetObject(pyXercesSAXNotSupportedExceptionType, instance.ptr());
}

//! SAXNotRecognizedException
PyObject* pyXercesSAXNotRecognizedExceptionType = nullptr;

void translateSAXNotRecognizedException(const xercesc::SAXNotRecognizedException& e) {
	assert(pyXercesSAXNotRecognizedExceptionType != nullptr);
	boost::python::object instance(e);
	PyErr_SetObject(pyXercesSAXNotRecognizedExceptionType, instance.ptr());
}

void SAXException_init(void) {
	//! xercesc::SAXException
	auto SAXException = boost::python::class_<xercesc::SAXException>("SAXException", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const char* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getMessage", &xercesc::SAXException::getMessage, boost::python::return_value_policy<boost::python::return_by_value>())
			;
	pyXercesSAXExceptionType = SAXException.ptr();
	boost::python::register_exception_translator<xercesc::SAXException>(&translateSAXException);
	//! xercesc::SAXNotSupportedException
	auto SAXNotSupportedException = boost::python::class_<xercesc::SAXNotSupportedException, boost::python::bases<xercesc::SAXException> >("SAXNotSupportedException", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const char* const, boost::python::optional<xercesc::MemoryManager* const> >())
			;
	pyXercesSAXNotSupportedExceptionType = SAXNotSupportedException.ptr();
	boost::python::register_exception_translator<xercesc::SAXNotSupportedException>(&translateSAXNotSupportedException);
	//! xercesc::SAXNotRecognizedException
	auto SAXNotRecognizedException = boost::python::class_<xercesc::SAXNotRecognizedException, boost::python::bases<xercesc::SAXException> >("SAXNotRecognizedException", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const char* const, boost::python::optional<xercesc::MemoryManager* const> >())
			;
	pyXercesSAXNotRecognizedExceptionType = SAXNotRecognizedException.ptr();
	boost::python::register_exception_translator<xercesc::SAXNotRecognizedException>(&translateSAXNotRecognizedException);
}

} /* namespace pyxerces */