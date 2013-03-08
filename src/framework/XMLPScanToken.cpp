/*
 * XMLPScanToken.cpp
 *
 *  Created on: 2013/03/08
 *      Author: mugwort_rc
 */

#include "XMLPScanToken.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLPScanToken.hpp>

namespace pyxerces {

void XMLPScanToken_init(void) {
	//! xercesc::XMLPScanToken
	boost::python::class_<xercesc::XMLPScanToken>("XMLPScanToken");
}

} /* namespace pyxerces */
