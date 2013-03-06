/*
 * XSConstants.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XSConstants.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSAttributeUse.hpp>
#include <xercesc/framework/psvi/XSFacet.hpp>
#include <xercesc/framework/psvi/XSMultiValueFacet.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSParticle.hpp>
#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>

#include <xercesc/framework/psvi/XSConstants.hpp>

namespace pyxerces {

void XSConstants_init(void) {
	//! xercesc::XSConstants
	auto XSConstants = boost::python::class_<xercesc::XSConstants, boost::noncopyable>("XSConstants", boost::python::no_init);
	boost::python::scope XSConstantsScope = XSConstants;
	//! xercesc::XSConstants::COMPONENT_TYPE
	boost::python::enum_<xercesc::XSConstants::COMPONENT_TYPE>("COMPONENT_TYPE")
			.value("ATTRIBUTE_DECLARATION", xercesc::XSConstants::ATTRIBUTE_DECLARATION)
			.value("ELEMENT_DECLARATION", xercesc::XSConstants::ELEMENT_DECLARATION)
			.value("TYPE_DEFINITION", xercesc::XSConstants::TYPE_DEFINITION)
			.value("ATTRIBUTE_USE", xercesc::XSConstants::ATTRIBUTE_USE)
			.value("ATTRIBUTE_GROUP_DEFINITION", xercesc::XSConstants::ATTRIBUTE_GROUP_DEFINITION)
			.value("MODEL_GROUP_DEFINITION", xercesc::XSConstants::MODEL_GROUP_DEFINITION)
			.value("MODEL_GROUP", xercesc::XSConstants::MODEL_GROUP)
			.value("PARTICLE", xercesc::XSConstants::PARTICLE)
			.value("WILDCARD", xercesc::XSConstants::WILDCARD)
			.value("IDENTITY_CONSTRAINT", xercesc::XSConstants::IDENTITY_CONSTRAINT)
			.value("NOTATION_DECLARATION", xercesc::XSConstants::NOTATION_DECLARATION)
			.value("ANNOTATION", xercesc::XSConstants::ANNOTATION)
			.value("FACET", xercesc::XSConstants::FACET)
			.value("MULTIVALUE_FACET", xercesc::XSConstants::MULTIVALUE_FACET)
			.export_values()
			;
	//! xercesc::XSConstants::DERIVATION_TYPE
	boost::python::enum_<xercesc::XSConstants::DERIVATION_TYPE>("DERIVATION_TYPE")
			.value("DERIVATION_NONE", xercesc::XSConstants::DERIVATION_NONE)
			.value("DERIVATION_EXTENSION", xercesc::XSConstants::DERIVATION_EXTENSION)
			.value("DERIVATION_RESTRICTION", xercesc::XSConstants::DERIVATION_RESTRICTION)
			.value("DERIVATION_SUBSTITUTION", xercesc::XSConstants::DERIVATION_SUBSTITUTION)
			.value("DERIVATION_UNION", xercesc::XSConstants::DERIVATION_UNION)
			.value("DERIVATION_LIST", xercesc::XSConstants::DERIVATION_LIST)
			.export_values()
			;
	//! xercesc::XSConstants::SCOPE
	boost::python::enum_<xercesc::XSConstants::SCOPE>("SCOPE")
			.value("SCOPE_ABSENT", xercesc::XSConstants::SCOPE_ABSENT)
			.value("SCOPE_GLOBAL", xercesc::XSConstants::SCOPE_GLOBAL)
			.value("SCOPE_LOCAL", xercesc::XSConstants::SCOPE_LOCAL)
			.export_values()
			;
	//! xercesc::XSConstants::VALUE_CONSTRAINT
	boost::python::enum_<xercesc::XSConstants::VALUE_CONSTRAINT>("VALUE_CONSTRAINT")
			.value("VALUE_CONSTRAINT_NONE", xercesc::XSConstants::VALUE_CONSTRAINT_NONE)
			.value("VALUE_CONSTRAINT_DEFAULT", xercesc::XSConstants::VALUE_CONSTRAINT_DEFAULT)
			.value("VALUE_CONSTRAINT_FIXED", xercesc::XSConstants::VALUE_CONSTRAINT_FIXED)
			.export_values()
			;
}

} /* namespace pyxerces */
