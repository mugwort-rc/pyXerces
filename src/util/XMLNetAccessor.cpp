/*
 * XMLNetAccessor.cpp
 *
 *  Created on: 2013/03/11
 *      Author: mugwort_rc
 */

#include "XMLNetAccessor.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/util/BinInputStream.hpp>

#include <xercesc/util/XMLNetAccessor.hpp>

namespace pyxerces {

void XMLNetAccessor_init(void) {
	//! xercesc::XMLNetAccessor
	boost::python::class_<xercesc::XMLNetAccessor, boost::noncopyable>("XMLNetAccessor", boost::python::no_init)
			.def("getId", &xercesc::XMLNetAccessor::getId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("makeNew", &xercesc::XMLNetAccessor::makeNew, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
