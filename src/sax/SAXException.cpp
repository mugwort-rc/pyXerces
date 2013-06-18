/*
 * SAXException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "SAXException.h"

#include <boost/python.hpp>
#include <xercesc/sax/SAXException.hpp>

#include "../common/Exception.h"
#include "../util/XMLString.h"

namespace pyxerces {

//! SAXException
PyObject* pyXercesSAXExceptionType = nullptr;

void translateSAXException(const xercesc::SAXException& e) {
	assert(pyXercesSAXExceptionType != nullptr);
	boost::python::object instance(e);

	boost::python::object exceptionType(boost::python::handle<>(boost::python::borrowed(pyXercesSAXExceptionType)));
	exceptionType.attr("cause") = instance;

	PyErr_SetString(pyXercesSAXExceptionType, XMLString(e.getMessage()).toString().c_str());
}

//! SAXNotSupportedException
void translateSAXNotSupportedException(const xercesc::SAXNotSupportedException& e) {
	assert(pyXercesSAXExceptionType != nullptr);
	boost::python::object instance(e);

	boost::python::object exceptionType(boost::python::handle<>(boost::python::borrowed(pyXercesSAXExceptionType)));
	exceptionType.attr("cause") = instance;

	PyErr_SetString(pyXercesSAXExceptionType, XMLString(e.getMessage()).toString().c_str());
}

//! SAXNotRecognizedException
void translateSAXNotRecognizedException(const xercesc::SAXNotRecognizedException& e) {
	assert(pyXercesSAXExceptionType != nullptr);
	boost::python::object instance(e);

	boost::python::object exceptionType(boost::python::handle<>(boost::python::borrowed(pyXercesSAXExceptionType)));
	exceptionType.attr("cause") = instance;

	PyErr_SetString(pyXercesSAXExceptionType, XMLString(e.getMessage()).toString().c_str());
}

void SAXException_init(void) {
	//! xercesc::SAXException
	auto SAXException = boost::python::class_<xercesc::SAXException>("SAXException", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const char* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getMessage", &xercesc::SAXException::getMessage, boost::python::return_value_policy<boost::python::return_by_value>())
			;
	pyXercesSAXExceptionType = createException("SAXException");
	boost::python::register_exception_translator<xercesc::SAXException>(&translateSAXException);
	//! xercesc::SAXNotSupportedException
	boost::python::class_<xercesc::SAXNotSupportedException, boost::python::bases<xercesc::SAXException> >("SAXNotSupportedException", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const char* const, boost::python::optional<xercesc::MemoryManager* const> >())
			;
	boost::python::register_exception_translator<xercesc::SAXNotSupportedException>(&translateSAXNotSupportedException);
	//! xercesc::SAXNotRecognizedException
	boost::python::class_<xercesc::SAXNotRecognizedException, boost::python::bases<xercesc::SAXException> >("SAXNotRecognizedException", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const char* const, boost::python::optional<xercesc::MemoryManager* const> >())
			;
	boost::python::register_exception_translator<xercesc::SAXNotRecognizedException>(&translateSAXNotRecognizedException);
}

} /* namespace pyxerces */
