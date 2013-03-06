/*
 * XSComplexTypeDefinition.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XSComplexTypeDefinition.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSAttributeUse.hpp>
#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSParticle.hpp>
#include <xercesc/framework/psvi/XSWildcard.hpp>
#include <xercesc/validators/schema/ComplexTypeInfo.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSComplexTypeDefinition.hpp>

namespace pyxerces {

void XSComplexTypeDefinition_init(void) {
	//! xercesc::XSComplexTypeDefinition
	auto XSComplexTypeDefinition = boost::python::class_<xercesc::XSComplexTypeDefinition, boost::noncopyable, boost::python::bases<xercesc::XSTypeDefinition> >("XSComplexTypeDefinition", boost::python::init<xercesc::ComplexTypeInfo* const, xercesc::XSWildcard* const, xercesc::XSSimpleTypeDefinition* const, xercesc::XSAttributeUseList* const, xercesc::XSTypeDefinition* const, xercesc::XSParticle* const, xercesc::XSAnnotation* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getDerivationMethod", &xercesc::XSComplexTypeDefinition::getDerivationMethod)
			.def("getAbstract", &xercesc::XSComplexTypeDefinition::getAbstract)
			.def("getAttributeUses", &xercesc::XSComplexTypeDefinition::getAttributeUses, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributeWildcard", &xercesc::XSComplexTypeDefinition::getAttributeWildcard, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getContentType", &xercesc::XSComplexTypeDefinition::getContentType)
			.def("getSimpleType", &xercesc::XSComplexTypeDefinition::getSimpleType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getParticle", &xercesc::XSComplexTypeDefinition::getParticle, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isProhibitedSubstitution", &xercesc::XSComplexTypeDefinition::isProhibitedSubstitution)
			.def("getProhibitedSubstitutions", &xercesc::XSComplexTypeDefinition::getProhibitedSubstitutions)
			.def("getAnnotations", &xercesc::XSComplexTypeDefinition::getAnnotations, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getName", &xercesc::XSComplexTypeDefinition::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespace", &xercesc::XSComplexTypeDefinition::getNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespaceItem", &xercesc::XSComplexTypeDefinition::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAnonymous", &xercesc::XSComplexTypeDefinition::getAnonymous)
			.def("getBaseType", &xercesc::XSComplexTypeDefinition::getBaseType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("derivedFromType", &xercesc::XSComplexTypeDefinition::derivedFromType)
			;
	boost::python::scope XSComplexTypeDefinitionScope = XSComplexTypeDefinition;
	//! xercesc::XSComplexTypeDefinition::
	boost::python::enum_<xercesc::XSComplexTypeDefinition::CONTENT_TYPE>("CONTENT_TYPE")
			.value("CONTENTTYPE_EMPTY", xercesc::XSComplexTypeDefinition::CONTENTTYPE_EMPTY)
			.value("CONTENTTYPE_SIMPLE", xercesc::XSComplexTypeDefinition::CONTENTTYPE_SIMPLE)
			.value("CONTENTTYPE_ELEMENT", xercesc::XSComplexTypeDefinition::CONTENTTYPE_ELEMENT)
			.value("CONTENTTYPE_MIXED", xercesc::XSComplexTypeDefinition::CONTENTTYPE_MIXED)
			.export_values();
			;
}

} /* namespace pyxerces */
