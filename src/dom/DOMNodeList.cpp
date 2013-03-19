/*
 * DOMNodeList.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMNodeList.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMNode.hpp>

#include <xercesc/dom/DOMNodeList.hpp>

namespace pyxerces {

class DOMNodeListWrapper
: public xercesc::DOMNodeList, public boost::python::wrapper<xercesc::DOMNodeList>
{
public:
xercesc::DOMNode *item(XMLSize_t index) const {
	return this->get_override("item")(index);
}

XMLSize_t getLength() const {
	return this->get_override("getLength")();
}

};

void DOMNodeList_init(void) {
	//! xercesc::DOMNodeList
	boost::python::class_<DOMNodeListWrapper, boost::noncopyable>("DOMNodeList")
			.def("item", &xercesc::DOMNodeList::item, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLength", boost::python::pure_virtual(&xercesc::DOMNodeList::getLength))
			.def("__getitem__", boost::python::pure_virtual(&xercesc::DOMNodeList::item), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("__len__", boost::python::pure_virtual(&xercesc::DOMNodeList::getLength))
			;
}

} /* namespace pyxerces */
