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

class PanicHandlerWrapper
: public xercesc::PanicHandler, public boost::python::wrapper<xercesc::PanicHandler>
{
public:
void panic(const PanicHandler::PanicReasons reason) {
	this->get_override("panic")(reason);
}

};

void PanicHandler_init(void) {
	//! xercesc::PanicHandler
	boost::python::class_<PanicHandlerWrapper, boost::noncopyable>("PanicHandler")
			.def("panic", boost::python::pure_virtual(&xercesc::PanicHandler::panic))
			.def("getPanicReasonString", &xercesc::PanicHandler::getPanicReasonString)
			.staticmethod("getPanicReasonString")
			;
}

} /* namespace pyxerces */
