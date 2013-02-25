/*
 * MemoryManager.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "MemoryManager.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>

namespace pyxerces {

void MemoryManager_init(void) {
	//! xercesc::MemoryManager
	boost::python::class_<xercesc::MemoryManager, boost::noncopyable>("MemoryManager", boost::python::no_init)
			.def("getExceptionMemoryManager", &xercesc::MemoryManager::getExceptionMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("allocate", &xercesc::MemoryManager::allocate, boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("deallocate", &xercesc::MemoryManager::deallocate)
			;
}

} /* namespace pyxerces */
