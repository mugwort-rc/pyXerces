/*
 * DOMCDATASection.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMCDATASection.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMCDATASection.hpp>

namespace pyxerces {

void DOMCDATASection_init(void) {
	//! xercesc::DOMCDATASection
	boost::python::class_<xercesc::DOMCDATASection, boost::noncopyable, boost::python::bases<xercesc::DOMText> >("DOMCDATASection", boost::python::no_init);
}

} /* namespace pyxerces */
