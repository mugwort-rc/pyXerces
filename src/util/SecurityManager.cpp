/*
 * SecurityManager.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "SecurityManager.h"

#include <boost/python.hpp>
#include <xercesc/util/SecurityManager.hpp>

namespace pyxerces {

void SecurityManager_init(void) {
	//! xercesc::SecurityManager
	boost::python::class_<xercesc::SecurityManager, boost::noncopyable>("SecurityManager")
			.def("setEntityExpansionLimit", &xercesc::SecurityManager::setEntityExpansionLimit)
			.def("getEntityExpansionLimit", &xercesc::SecurityManager::getEntityExpansionLimit)
			;
}

} /* namespace pyxerces */
