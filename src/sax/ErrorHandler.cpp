/*
 * ErrorHandler.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "ErrorHandler.h"

#include <boost/python.hpp>

//!< for forward declaration
#include <xercesc/sax/SAXParseException.hpp>

#include <xercesc/sax/ErrorHandler.hpp>

namespace pyxerces {

class ErrorHandlerWrapper
: public xercesc::ErrorHandler, public boost::python::wrapper<xercesc::ErrorHandler>
{
public:
	ErrorHandlerWrapper()
		: xercesc::ErrorHandler()
	{}

	void warning(const xercesc::SAXParseException& exc) {
		this->get_override("warning")(exc);
	}

	void error(const xercesc::SAXParseException& exc) {
		this->get_override("error")(exc);
	}

	void fatalError(const xercesc::SAXParseException& exc) {
		this->get_override("fatalError")(exc);
	}

	void resetErrors() {
		this->get_override("resetErrors")();
	}
};

void ErrorHandler_init(void) {
	//! xercesc::ErrorHandler
	boost::python::class_<ErrorHandlerWrapper, boost::noncopyable>("ErrorHandler")
			.def("warning", boost::python::pure_virtual(&xercesc::ErrorHandler::warning))
			.def("error", boost::python::pure_virtual(&xercesc::ErrorHandler::error))
			.def("fatalError", boost::python::pure_virtual(&xercesc::ErrorHandler::fatalError))
			.def("resetErrors", boost::python::pure_virtual(&xercesc::ErrorHandler::resetErrors))
			;
}

} /* namespace pyxerces */
