/*
 * DOMDocumentFragment.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMDocumentFragment.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMDocumentFragment.hpp>

namespace pyxerces {

void DOMDocumentFragment_init(void) {
	//! xercesc::DOMDocumentFragment
	boost::python::class_<xercesc::DOMDocumentFragment, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMDocumentFragment", boost::python::no_init);
}

} /* namespace pyxerces */
