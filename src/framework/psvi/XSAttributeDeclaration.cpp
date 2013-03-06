/*
 * XSAttributeDeclaration.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XSAttributeDeclaration.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSComplexTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>
#include <xercesc/validators/schema/SchemaAttDef.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSAttributeDeclaration.hpp>

namespace pyxerces {

void XSAttributeDeclaration_init(void) {
	//! xercesc::XSAttributeDeclaration
	boost::python::class_<xercesc::XSAttributeDeclaration, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSAttributeDeclaration", boost::python::init<xercesc::SchemaAttDef* const, xercesc::XSSimpleTypeDefinition* const, xercesc::XSAnnotation* const, xercesc::XSModel* const, xercesc::XSConstants::SCOPE, xercesc::XSComplexTypeDefinition*, boost::python::optional<xercesc::MemoryManager* const > >())
			.def("getName", &xercesc::XSAttributeDeclaration::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespace", &xercesc::XSAttributeDeclaration::getNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespaceItem", &xercesc::XSAttributeDeclaration::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTypeDefinition", &xercesc::XSAttributeDeclaration::getTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getScope", &xercesc::XSAttributeDeclaration::getScope)
			.def("getEnclosingCTDefinition", &xercesc::XSAttributeDeclaration::getEnclosingCTDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getConstraintType", &xercesc::XSAttributeDeclaration::getConstraintType)
			.def("getConstraintValue", &xercesc::XSAttributeDeclaration::getConstraintValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAnnotation", &xercesc::XSAttributeDeclaration::getAnnotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getRequired", &xercesc::XSAttributeDeclaration::getRequired)
			;
}

} /* namespace pyxerces */
