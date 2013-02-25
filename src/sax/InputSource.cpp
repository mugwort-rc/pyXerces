/*
 * InputSource.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "InputSource.h"

#include <boost/python.hpp>
#include <xercesc/util/BinInputStream.hpp>		//!< for forward declaration
#include <xercesc/framework/MemoryManager.hpp>	//!< for forward declaration
#include <xercesc/sax/InputSource.hpp>

namespace pyxerces {

void InputSource_init(void) {
	//! xercesc::InputSource
	boost::python::class_<xercesc::InputSource, boost::noncopyable>("InputSouce", boost::python::no_init)
			.def("makeStream", &xercesc::InputSource::makeStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEncoding", &xercesc::InputSource::getEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPublicId", &xercesc::InputSource::getPublicId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::InputSource::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getIssueFatalErrorIfNotFound", &xercesc::InputSource::getIssueFatalErrorIfNotFound)
			.def("getMemoryManager", &xercesc::InputSource::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setEncoding", &xercesc::InputSource::setEncoding)
			.def("setPublicId", &xercesc::InputSource::setPublicId)
			.def("setSystemId", &xercesc::InputSource::setSystemId)
			.def("setIssueFatalErrorIfNotFound", &xercesc::InputSource::setIssueFatalErrorIfNotFound)
			;
}

} /* namespace pyxerces */
