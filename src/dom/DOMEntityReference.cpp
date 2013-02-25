/*
 * DOMEntityReference.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMEntityReference.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMEntityReference.hpp>

namespace pyxerces {

void DOMEntityReference_init(void) {
	//! xercesc::DOMEntityReference
	boost::python::class_<xercesc::DOMEntityReference, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMEntityReference", boost::python::no_init);
}

} /* namespace pyxerces */
