/*
 * DOMCharacterData.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMCharacterData.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMCharacterData.hpp>

namespace pyxerces {

void DOMCharacterData_init(void) {
	//! xercesc::DOMCharacterData
	boost::python::class_<xercesc::DOMCharacterData, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMCharacterData", boost::python::no_init)
			.def("getData", &xercesc::DOMCharacterData::getData, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLength", &xercesc::DOMCharacterData::getLength)
			.def("substringData", &xercesc::DOMCharacterData::substringData, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("appendData", &xercesc::DOMCharacterData::appendData)
			.def("insertData", &xercesc::DOMCharacterData::insertData)
			.def("deleteData", &xercesc::DOMCharacterData::deleteData)
			.def("replaceData", &xercesc::DOMCharacterData::replaceData)
			.def("setData", &xercesc::DOMCharacterData::setData)
			;
}

} /* namespace pyxerces */
