/*
 * URLInputSource.cpp
 *
 *  Created on: 2013/05/04
 *      Author: mugwort_rc
 */

#include "URLInputSource.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/util/BinInputStream.hpp>
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/framework/URLInputSource.hpp>

namespace pyxerces {

void URLInputSource_init(void) {
	//! URLInputSource
	boost::python::class_<xercesc::URLInputSource, boost::noncopyable, boost::python::bases<xercesc::InputSource> >("URLInputSource", boost::python::init<const xercesc::XMLURL&, boost::python::optional<xercesc::MemoryManager*> >())
			.def(boost::python::init<const XMLCh*, const XMLCh*, boost::python::optional<xercesc::MemoryManager*> >())
			.def(boost::python::init<const XMLCh*, const XMLCh*, const XMLCh*, boost::python::optional<xercesc::MemoryManager*> >())
			.def(boost::python::init<const XMLCh*, const char*, boost::python::optional<xercesc::MemoryManager*> >())
			.def(boost::python::init<const XMLCh*, const char*, const char*, boost::python::optional<xercesc::MemoryManager*> >())
			.def("makeStream", &xercesc::URLInputSource::makeStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("urlSrc", &xercesc::URLInputSource::urlSrc, boost::python::return_internal_reference<>())
			;
}

} /* namespace pyxerces */
