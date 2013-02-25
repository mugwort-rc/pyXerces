/*
 * ErrorHandler.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "ErrorHandler.h"

#include <boost/python.hpp>
#include <xercesc/sax/SAXParseException.hpp>	//!< for forward declaration
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
			.def("warning", &xercesc::ErrorHandler::warning)
			.def("error", &xercesc::ErrorHandler::error)
			.def("fatalError", &xercesc::ErrorHandler::fatalError)
			.def("resetErrors", &xercesc::ErrorHandler::resetErrors)
			;
}

} /* namespace pyxerces */
