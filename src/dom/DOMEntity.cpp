/*
 * DOMEntity.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMEntity.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMEntity.hpp>

namespace pyxerces {

void DOMEntity_init(void) {
	//! xercesc::DOMEntity
	boost::python::class_<xercesc::DOMEntity, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMEntity", boost::python::no_init)
			.def("getPublicId", &xercesc::DOMEntity::getPublicId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::DOMEntity::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNotationName", &xercesc::DOMEntity::getNotationName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getInputEncoding", &xercesc::DOMEntity::getInputEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getXmlEncoding", &xercesc::DOMEntity::getXmlEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getXmlVersion", &xercesc::DOMEntity::getXmlVersion, boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxerces */
