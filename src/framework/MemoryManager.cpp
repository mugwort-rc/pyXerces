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

class MemoryManagerWrapper
: public xercesc::MemoryManager, public boost::python::wrapper<xercesc::MemoryManager>
{
public:
xercesc::MemoryManager* getExceptionMemoryManager() {
	return this->get_override("getExceptionMemoryManager")();
}

void* allocate(XMLSize_t size) {
	return this->get_override("allocate")(size);
}

void deallocate(void* p) {
	// XXX: p
	this->get_override("deallocate")(p);
}

};

void MemoryManager_init(void) {
	//! xercesc::MemoryManager
	boost::python::class_<MemoryManagerWrapper, boost::noncopyable>("MemoryManager")
			.def("getExceptionMemoryManager", boost::python::pure_virtual(&xercesc::MemoryManager::getExceptionMemoryManager), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("allocate", boost::python::pure_virtual(&xercesc::MemoryManager::allocate), boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("deallocate", boost::python::pure_virtual(&xercesc::MemoryManager::deallocate))
			;
}

} /* namespace pyxerces */
