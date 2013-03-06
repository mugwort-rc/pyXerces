/*
 * XSObject.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XSObject.h"

#include <boost/python.hpp>

//! for forward declarations
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSObject.hpp>

namespace pyxerces {

void XSObject_init(void) {
	//! xercesc::XSObject
	boost::python::class_<xercesc::XSObject, boost::noncopyable>("XSObject", boost::python::init<xercesc::XSConstants::COMPONENT_TYPE, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getType", &xercesc::XSObject::getType)
			.def("getName", &xercesc::XSObject::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespace", &xercesc::XSObject::getNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespaceItem", &xercesc::XSObject::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getId", &xercesc::XSObject::getId)
			.def("setId", &xercesc::XSObject::setId)
			;
}

} /* namespace pyxerces */
