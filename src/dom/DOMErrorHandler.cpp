/*
 * DOMErrorHandler.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "DOMErrorHandler.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMError.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace pyxerces {

void DOMErrorHandler_init(void) {
	//! xercesc::DOMErrorHandler
	boost::python::class_<xercesc::DOMErrorHandler, boost::noncopyable>("DOMErrorHandler", boost::python::no_init)
			.def("handleError", &xercesc::DOMErrorHandler::handleError)
			;
}

} /* namespace pyxerces */
