/*
 * XMLEntityHandler.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "XMLEntityHandler.h"

#include <boost/python.hpp>
#include <xercesc/sax/InputSource.hpp>				//!< for forward declaration
#include <xercesc/framework/XMLBuffer.hpp>			//!< for forward declaration
#include <xercesc/util/XMLResourceIdentifier.hpp>	//!< for forward declaration
#include <xercesc/framework/XMLEntityHandler.hpp>

namespace pyxerces {

void XMLEntityHandler_init(void) {
	//! xercesc::XMLEntityHandler
	boost::python::class_<xercesc::XMLEntityHandler, boost::noncopyable>("XMLEntityHandler", boost::python::no_init)
			.def("endInputSource", &xercesc::XMLEntityHandler::endInputSource)
			.def("expandSystemId", &xercesc::XMLEntityHandler::expandSystemId)
			.def("resetEntities", &xercesc::XMLEntityHandler::resetEntities)
			.def("resolveEntity", &xercesc::XMLEntityHandler::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("startInputSource", &xercesc::XMLEntityHandler::startInputSource)
			;
}

} /* namespace pyxerces */
