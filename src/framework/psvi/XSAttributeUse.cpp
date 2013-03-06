/*
 * XSAttributeUse.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XSAttributeUse.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAttributeDeclaration.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSAttributeUse.hpp>

namespace pyxerces {

void XSAttributeUse_init(void) {
	//! xercesc::XSAttributeUse
	boost::python::class_<xercesc::XSAttributeUse, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSAttributeUse", boost::python::init<xercesc::XSAttributeDeclaration* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getRequired", &xercesc::XSAttributeUse::getRequired)
			.def("getAttrDeclaration", &xercesc::XSAttributeUse::getAttrDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getConstraintType", &xercesc::XSAttributeUse::getConstraintType)
			.def("getConstraintValue", &xercesc::XSAttributeUse::getConstraintValue, boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxerces */
