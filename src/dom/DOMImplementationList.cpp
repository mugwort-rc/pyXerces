/*
 * DOMImplementationList.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMImplementationList.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMImplementation.hpp>

#include <xercesc/dom/DOMImplementationList.hpp>

namespace pyxerces {

class DOMImplementationListWrapper
: public xercesc::DOMImplementationList, public boost::python::wrapper<xercesc::DOMImplementationList>
{
public:
xercesc::DOMImplementation *item(XMLSize_t index) const {
	return this->get_override("item")(index);
}

XMLSize_t getLength() const {
	return this->get_override("getLength")();
}

void release() {
	this->get_override("release")();
}

};

void DOMImplementationList_init(void) {
	//! xercesc::DOMImplementationList
	boost::python::class_<DOMImplementationListWrapper, boost::noncopyable>("DOMImplementationList")
			.def("item", boost::python::pure_virtual(&xercesc::DOMImplementationList::item), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLength", boost::python::pure_virtual(&xercesc::DOMImplementationList::getLength))
			.def("release", boost::python::pure_virtual(&xercesc::DOMImplementationList::release))
			;
}

} /* namespace pyxerces */
