/*
 * PanicHandler.cpp
 *
 *  Created on: 2013/03/11
 *      Author: mugwort_rc
 */

#include "PanicHandler.h"

#include <boost/python.hpp>
#include <xercesc/util/PanicHandler.hpp>

namespace pyxerces {

void PanicHandler_init(void) {
	//! xercesc::PanicHandler
	boost::python::class_<xercesc::PanicHandler, boost::noncopyable>("PanicHandler", boost::python::no_init)
			.def("panic", &xercesc::PanicHandler::panic)
			.def("getPanicReasonString", &xercesc::PanicHandler::getPanicReasonString)
			.staticmethod("getPanicReasonString")
			;
}

} /* namespace pyxerces */
