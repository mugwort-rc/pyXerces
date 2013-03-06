/*
 * IdentityConstraint.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "IdentityConstraint.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/schema/identity/IC_Selector.hpp>

#include <xercesc/validators/schema/identity/IdentityConstraint.hpp>

#include "../../../internal/XSerializable.h"

namespace pyxerces {

void IdentityConstraint_init(void) {
	//! xercesc::IdentityConstraint
	auto IdentityConstraint = boost::python::class_<xercesc::IdentityConstraint, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("IdentityConstraint", boost::python::no_init)
			.def("__eq__", &xercesc::IdentityConstraint::operator ==)
			.def("__ne__", &xercesc::IdentityConstraint::operator !=)
			.def("getType", &xercesc::IdentityConstraint::getType)
			.def("getFieldCount", &xercesc::IdentityConstraint::getFieldCount)
			.def("getIdentityConstraintName", &xercesc::IdentityConstraint::getIdentityConstraintName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getElementName", &xercesc::IdentityConstraint::getElementName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSelector", &xercesc::IdentityConstraint::getSelector, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNamespaceURI", &xercesc::IdentityConstraint::getNamespaceURI)
			.def("setSelector", &xercesc::IdentityConstraint::setSelector)
			.def("setNamespaceURI", &xercesc::IdentityConstraint::setNamespaceURI)
			.def("addField", &xercesc::IdentityConstraint::addField)
			.def("getFieldAt", static_cast<xercesc::IC_Field*(xercesc::IdentityConstraint::*)(const XMLSize_t)>(&xercesc::IdentityConstraint::getFieldAt), boost::python::return_value_policy<boost::python::reference_existing_object>())
			PyDECL_XSERIALIZABLE(IdentityConstraint)
			.def("storeIC", &xercesc::IdentityConstraint::storeIC)
			.def("loadIC", &xercesc::IdentityConstraint::loadIC, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
	boost::python::scope IdentityConstraintScope = IdentityConstraint;
	//! xercesc::IdentityConstraint::ICType
	boost::python::enum_<xercesc::IdentityConstraint::ICType>("ICType")
			.value("ICType_UNIQUE", xercesc::IdentityConstraint::ICType_UNIQUE)
			.value("ICType_KEY", xercesc::IdentityConstraint::ICType_KEY)
			.value("ICType_KEYREF", xercesc::IdentityConstraint::ICType_KEYREF)
			.value("ICType_UNKNOWN", xercesc::IdentityConstraint::ICType_UNKNOWN)
			.export_values()
			;
}

} /* namespace pyxerces */
