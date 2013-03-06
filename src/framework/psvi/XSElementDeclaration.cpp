/*
 * XSElementDeclaration.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XSElementDeclaration.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSComplexTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSIDCDefinition.hpp>
#include <xercesc/framework/psvi/XSTypeDefinition.hpp>
#include <xercesc/validators/schema/SchemaElementDecl.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSElementDeclaration.hpp>

namespace pyxerces {

void XSElementDeclaration_init(void) {
	//! xercesc::XSElementDeclaration
	boost::python::class_<xercesc::XSElementDeclaration, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSElementDeclaration", boost::python::init<xercesc::SchemaElementDecl* const, xercesc::XSTypeDefinition* const, xercesc::XSElementDeclaration* const, xercesc::XSAnnotation* const, xercesc::XSNamedMap<xercesc::XSIDCDefinition>* const, xercesc::XSModel* const, boost::python::optional<xercesc::XSConstants::SCOPE, xercesc::XSComplexTypeDefinition* const, xercesc::MemoryManager* const> >())
			.def("getName", &xercesc::XSElementDeclaration::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespace", &xercesc::XSElementDeclaration::getNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespaceItem", &xercesc::XSElementDeclaration::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTypeDefinition", &xercesc::XSElementDeclaration::getTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getScope", &xercesc::XSElementDeclaration::getScope)
			.def("getEnclosingCTDefinition", &xercesc::XSElementDeclaration::getEnclosingCTDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getConstraintType", &xercesc::XSElementDeclaration::getConstraintType)
			.def("getConstraintValue", &xercesc::XSElementDeclaration::getConstraintValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNillable", &xercesc::XSElementDeclaration::getNillable)
			.def("getIdentityConstraints", &xercesc::XSElementDeclaration::getIdentityConstraints, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getSubstitutionGroupAffiliation", &xercesc::XSElementDeclaration::getSubstitutionGroupAffiliation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isSubstitutionGroupExclusion", &xercesc::XSElementDeclaration::isSubstitutionGroupExclusion)
			.def("getSubstitutionGroupExclusions", &xercesc::XSElementDeclaration::getSubstitutionGroupExclusions)
			.def("isDisallowedSubstitution", &xercesc::XSElementDeclaration::isDisallowedSubstitution)
			.def("getDisallowedSubstitutions", &xercesc::XSElementDeclaration::getDisallowedSubstitutions)
			.def("getAbstract", &xercesc::XSElementDeclaration::getAbstract)
			.def("getAnnotation", &xercesc::XSElementDeclaration::getAnnotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setTypeDefinition", &xercesc::XSElementDeclaration::setTypeDefinition)
			;
}

} /* namespace pyxerces */
