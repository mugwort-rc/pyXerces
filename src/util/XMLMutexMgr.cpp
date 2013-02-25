/*
 * XMLMutexMgr.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "XMLMutexMgr.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>	//!< for forward declaration
#include <xercesc/util/XMLMutexMgr.hpp>

namespace pyxerces {

class XMLMutexMgrWrapper
: public xercesc::XMLMutexMgr, public boost::python::wrapper<xercesc::XMLMutexMgr>
{
public:
	xercesc::XMLMutexHandle create(xercesc::MemoryManager* const manager) {
		return this->get_override("create")(manager);
	}

	void destroy(xercesc::XMLMutexHandle mtx, xercesc::MemoryManager* const manager) {
		this->get_override("destroy")(mtx, manager);
	}

	void lock(xercesc::XMLMutexHandle mtx) {
		this->get_override("lock")(mtx);
	}

	void unlock(xercesc::XMLMutexHandle mtx) {
		this->get_override("unlock")(mtx);
	}
};

void XMLMutexMgr_init(void) {
	//! xercesc::XMLMutexMgr
	boost::python::class_<XMLMutexMgrWrapper, boost::noncopyable>("XMLMutexMgr")
			.def("create", &xercesc::XMLMutexMgr::create, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("destroy", &xercesc::XMLMutexMgr::destroy)
			.def("lock", &xercesc::XMLMutexMgr::lock)
			.def("unlock", &xercesc::XMLMutexMgr::unlock)
			;
}

} /* namespace pyxerces */
