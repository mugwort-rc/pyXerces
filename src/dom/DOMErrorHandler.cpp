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

class DOMErrorHandlerWrapper
: public xercesc::DOMErrorHandler, public boost::python::wrapper<xercesc::DOMErrorHandler>
{
public:
DOMErrorHandlerWrapper(void)
{}
~DOMErrorHandlerWrapper(void)
{}

bool handleError(const xercesc::DOMError& domError) {
	return this->get_override("handleError")(domError);
}

};

void DOMErrorHandler_init(void) {
	//! xercesc::DOMErrorHandler
	boost::python::class_<DOMErrorHandlerWrapper, boost::noncopyable>("DOMErrorHandler")
			.def("handleError", &xercesc::DOMErrorHandler::handleError)
			;
}

} /* namespace pyxerces */
