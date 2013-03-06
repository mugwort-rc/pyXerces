/*
 * XSIDCDefinition.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XSIDCDefinition.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/validators/schema/identity/IdentityConstraint.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSIDCDefinition.hpp>

namespace pyxerces {

void XSIDCDefinition_init(void) {
	//! xercesc::XSIDCDefinition
	auto XSIDCDefinition = boost::python::class_<xercesc::XSIDCDefinition, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSIDCDefinition", boost::python::init<xercesc::IdentityConstraint* const, xercesc::XSIDCDefinition* const, xercesc::XSAnnotation* const, xercesc::StringList* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getName", &xercesc::XSIDCDefinition::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespace", &xercesc::XSIDCDefinition::getNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespaceItem", &xercesc::XSIDCDefinition::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getCategory", &xercesc::XSIDCDefinition::getCategory)
			.def("getSelectorStr", &xercesc::XSIDCDefinition::getSelectorStr, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getFieldStrs", &xercesc::XSIDCDefinition::getFieldStrs, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getRefKey", &xercesc::XSIDCDefinition::getRefKey, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAnnotations", &xercesc::XSIDCDefinition::getAnnotations, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
	boost::python::scope XSIDCDefinitionScope = XSIDCDefinition;
	//! xercesc::XSIDCDefinition::IC_CATEGORY
	boost::python::enum_<xercesc::XSIDCDefinition::IC_CATEGORY>("IC_CATEGORY")
			.value("IC_KEY", xercesc::XSIDCDefinition::IC_KEY)
			.value("IC_KEYREF", xercesc::XSIDCDefinition::IC_KEYREF)
			.value("IC_UNIQUE", xercesc::XSIDCDefinition::IC_UNIQUE)
			.export_values()
			;
}

} /* namespace pyxerces */
