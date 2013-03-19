/*
 * DOMNodeIterator.cpp
 *
 *  Created on: 2013/02/26
 *      Author: mugwort_rc
 */

#include "DOMNodeIterator.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>

namespace pyxerces {

class DOMNodeIteratorWrapper
: public xercesc::DOMNodeIterator, public boost::python::wrapper<xercesc::DOMNodeIterator>
{
public:
xercesc::DOMNode* getRoot() {
	return this->get_override("getRoot")();
}

xercesc::DOMNodeFilter::ShowType getWhatToShow() {
	return this->get_override("getWhatToShow")();
}

xercesc::DOMNodeFilter* getFilter() {
	return this->get_override("getFilter")();
}

bool getExpandEntityReferences() {
	return this->get_override("getExpandEntityReferences")();
}

xercesc::DOMNode* nextNode() {
	return this->get_override("nextNode")();
}

xercesc::DOMNode* previousNode() {
	return this->get_override("previousNode")();
}

void detach() {
	this->get_override("detach")();
}

void release() {
	this->get_override("release")();
}

};

void DOMNodeIterator_init(void) {
	//! xercesc::DOMNodeIterator
	boost::python::class_<DOMNodeIteratorWrapper, boost::noncopyable>("DOMNodeIterator")
			.def("getRoot", boost::python::pure_virtual(&xercesc::DOMNodeIterator::getRoot), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getWhatToShow", boost::python::pure_virtual(&xercesc::DOMNodeIterator::getWhatToShow))
			.def("getFilter", boost::python::pure_virtual(&xercesc::DOMNodeIterator::getFilter), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getExpandEntityReferences", boost::python::pure_virtual(&xercesc::DOMNodeIterator::getExpandEntityReferences))
			.def("nextNode", boost::python::pure_virtual(&xercesc::DOMNodeIterator::nextNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("previousNode", boost::python::pure_virtual(&xercesc::DOMNodeIterator::previousNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("detach", boost::python::pure_virtual(&xercesc::DOMNodeIterator::detach))
			.def("release", boost::python::pure_virtual(&xercesc::DOMNodeIterator::release))
			;
}

} /* namespace pyxerces */
