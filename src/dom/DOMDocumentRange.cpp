/*
 * DOMDocumentRange.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "DOMDocumentRange.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMRange.hpp>

#include <xercesc/dom/DOMDocumentRange.hpp>

namespace pyxerces {

class DOMDocumentRangeWrapper
: public xercesc::DOMDocumentRange, public boost::python::wrapper<xercesc::DOMDocumentRange>
{
public:
xercesc::DOMRange *createRange() {
	return this->get_override("createRange")();
}

};

void DOMDocumentRange_init(void) {
	//! xercesc::DOMDocumentRange
	boost::python::class_<DOMDocumentRangeWrapper, boost::noncopyable>("DOMDocumentRange")
			.def("createRange", boost::python::pure_virtual(&xercesc::DOMDocumentRange::createRange), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
