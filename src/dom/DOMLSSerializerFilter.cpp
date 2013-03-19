/*
 * DOMLSSerializerFilter.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSSerializerFilter.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMLSSerializerFilter.hpp>

namespace pyxerces {

class DOMLSSerializerFilterWrapper
: public xercesc::DOMLSSerializerFilter, public boost::python::wrapper<xercesc::DOMLSSerializerFilter>
{
public:
FilterAction acceptNode(const xercesc::DOMNode* node) const {
	return this->get_override("acceptNode")(boost::python::ptr(node));
}

ShowType getWhatToShow() const {
	return this->get_override("getWhatToShow")();
}

};

void DOMLSSerializerFilter_init(void) {
	//! xercesc::DOMLSSerializerFilter
	boost::python::class_<DOMLSSerializerFilterWrapper, boost::noncopyable, boost::python::bases<xercesc::DOMNodeFilter> >("DOMLSSerializerFilter")
			.def("acceptNode", boost::python::pure_virtual(&xercesc::DOMLSSerializerFilter::acceptNode))
			.def("getWhatToShow", boost::python::pure_virtual(&xercesc::DOMLSSerializerFilter::getWhatToShow))
			;
}

} /* namespace pyxerces */
