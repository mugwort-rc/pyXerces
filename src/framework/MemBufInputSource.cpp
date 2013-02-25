/*
 * MemBufInputSource.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "MemBufInputSource.h"

#include <boost/python.hpp>
#include <xercesc/util/BinInputStream.hpp>		//!< for forward declaration
#include <xercesc/framework/MemoryManager.hpp>	//!< for forward declaration
#include <xercesc/framework/MemBufInputSource.hpp>

namespace pyxerces {

void MemBufInputSource_init(void) {
	//! xercesc::MemBufInputSource
	boost::python::class_<xercesc::MemBufInputSource, boost::noncopyable, boost::python::bases<xercesc::InputSource> >("MemBufInputSource", boost::python::init<const XMLByte* const, const XMLSize_t, const char* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLByte* const, const XMLSize_t, const XMLCh* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def("makeStream", &xercesc::MemBufInputSource::makeStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setCopyBufToStream", &xercesc::MemBufInputSource::setCopyBufToStream)
			.def("resetMemBufInputSource", &xercesc::MemBufInputSource::resetMemBufInputSource)
			;
}

} /* namespace pyxerces */
