/*
 * DOMErrorHandler.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "DOMErrorHandler.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMError.hpp>

#include <xercesc/dom/DOMErrorHandler.hpp>

namespace pyxerces {

class DOMErrorHandlerWrapper
: public xercesc::DOMErrorHandler, public boost::python::wrapper<xercesc::DOMErrorHandler>
{
public:
bool handleError(const xercesc::DOMError& domError) {
	return this->get_override("handleError")(boost::ref(domError));
}

};

void DOMErrorHandler_init(void) {
	//! xercesc::DOMErrorHandler
	boost::python::class_<DOMErrorHandlerWrapper, boost::noncopyable>("DOMErrorHandler")
			.def("handleError", boost::python::pure_virtual(&xercesc::DOMErrorHandler::handleError))
			;
}

} /* namespace pyxerces */
