/*
 * PSVIHandler.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "PSVIHandler.h"

#include <boost/python.hpp>
#include <xercesc/framework/psvi/PSVIElement.hpp>		//!< for forward declaration
#include <xercesc/framework/psvi/PSVIAttributeList.hpp>	//!< for forward declaration
#include <xercesc/framework/psvi/PSVIHandler.hpp>

namespace pyxerces {

void PSVIHandler_init(void) {
	//! xercesc::PSVIHandler
	boost::python::class_<xercesc::PSVIHandler, boost::noncopyable>("PSVIHandler", boost::python::no_init)
			.def("handleElementPSVI", &xercesc::PSVIHandler::handleElementPSVI)
			.def("handlePartialElementPSVI", &xercesc::PSVIHandler::handlePartialElementPSVI)
			.def("handleAttributesPSVI", &xercesc::PSVIHandler::handleAttributesPSVI)
			;
}

} /* namespace pyxerces */
