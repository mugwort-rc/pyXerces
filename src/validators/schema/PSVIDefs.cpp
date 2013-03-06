/*
 * PSVIDefs.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "PSVIDefs.h"

#include <boost/python.hpp>
#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/validators/schema/PSVIDefs.hpp>

namespace pyxerces {

void PSVIDefs_init(void) {
	//! xercesc::PSVIDefs
	auto PSVIDefs = boost::python::class_<xercesc::PSVIDefs, boost::noncopyable>("PSVIDefs", boost::python::no_init);
	boost::python::scope PSVIDefsScope = PSVIDefs;
	//! xercesc::PSVIDefs::PSVIScope
	boost::python::enum_<xercesc::PSVIDefs::PSVIScope>("PSVIScope")
			.value("SCP_ABSENT", xercesc::PSVIDefs::SCP_ABSENT)
			.value("SCP_GLOBAL", xercesc::PSVIDefs::SCP_GLOBAL)
			.value("SCP_LOCAL", xercesc::PSVIDefs::SCP_LOCAL)
			.export_values()
			;
}

} /* namespace pyxerces */
