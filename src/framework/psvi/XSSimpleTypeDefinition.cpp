/*
 * XSSimpleTypeDefinition.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XSSimpleTypeDefinition.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSFacet.hpp>
#include <xercesc/framework/psvi/XSMultiValueFacet.hpp>
#include <xercesc/validators/datatype/DatatypeValidator.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>

#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>

namespace pyxerces {

void XSSimpleTypeDefinition_init(void) {
	//! xercesc::XSSimpleTypeDefinition
	auto XSSimpleTypeDefinition = boost::python::class_<xercesc::XSSimpleTypeDefinition, boost::noncopyable, boost::python::bases<xercesc::XSTypeDefinition> >("XSSimpleTypeDefinition", boost::python::init<xercesc::DatatypeValidator* const, xercesc::XSSimpleTypeDefinition::VARIETY, xercesc::XSTypeDefinition* const, xercesc::XSSimpleTypeDefinition* const, xercesc::XSSimpleTypeDefinitionList* const, xercesc::XSAnnotation*, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getVariety", &xercesc::XSSimpleTypeDefinition::getVariety)
			.def("getPrimitiveType", &xercesc::XSSimpleTypeDefinition::getPrimitiveType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getItemType", &xercesc::XSSimpleTypeDefinition::getItemType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemberTypes", &xercesc::XSSimpleTypeDefinition::getMemberTypes, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDefinedFacets", &xercesc::XSSimpleTypeDefinition::getDefinedFacets)
			.def("isDefinedFacet", &xercesc::XSSimpleTypeDefinition::isDefinedFacet)
			.def("getFixedFacets", &xercesc::XSSimpleTypeDefinition::getFixedFacets)
			.def("isFixedFacet", &xercesc::XSSimpleTypeDefinition::isFixedFacet)
			.def("getLexicalFacetValue", &xercesc::XSSimpleTypeDefinition::getLexicalFacetValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLexicalEnumeration", &xercesc::XSSimpleTypeDefinition::getLexicalEnumeration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLexicalPattern", &xercesc::XSSimpleTypeDefinition::getLexicalPattern, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getOrdered", &xercesc::XSSimpleTypeDefinition::getOrdered)
			.def("getFinite", &xercesc::XSSimpleTypeDefinition::getFinite)
			.def("getBounded", &xercesc::XSSimpleTypeDefinition::getBounded)
			.def("getNumeric", &xercesc::XSSimpleTypeDefinition::getNumeric)
			.def("getAnnotations", &xercesc::XSSimpleTypeDefinition::getAnnotations, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFacets", &xercesc::XSSimpleTypeDefinition::getFacets, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMultiValueFacets", &xercesc::XSSimpleTypeDefinition::getMultiValueFacets, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getName", &xercesc::XSSimpleTypeDefinition::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespace", &xercesc::XSSimpleTypeDefinition::getNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespaceItem", &xercesc::XSSimpleTypeDefinition::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAnonymous", &xercesc::XSSimpleTypeDefinition::getAnonymous)
			.def("getBaseType", &xercesc::XSSimpleTypeDefinition::getBaseType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("derivedFromType", &xercesc::XSSimpleTypeDefinition::derivedFromType)
			.def("getDatatypeValidator", &xercesc::XSSimpleTypeDefinition::getDatatypeValidator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
	boost::python::scope XSSimpleTypeDefinitionScope = XSSimpleTypeDefinition;
	//! xercesc::XSSimpleTypeDefinition::VARIETY
	boost::python::enum_<xercesc::XSSimpleTypeDefinition::VARIETY>("VARIETY")
			.value("VARIETY_ABSENT", xercesc::XSSimpleTypeDefinition::VARIETY_ABSENT)
			.value("VARIETY_ATOMIC", xercesc::XSSimpleTypeDefinition::VARIETY_ATOMIC)
			.value("VARIETY_LIST", xercesc::XSSimpleTypeDefinition::VARIETY_LIST)
			.value("VARIETY_UNION", xercesc::XSSimpleTypeDefinition::VARIETY_UNION)
			.export_values()
			;
	//! xercesc::XSSimpleTypeDefinition::FACET
	boost::python::enum_<xercesc::XSSimpleTypeDefinition::FACET>("FACET")
			.value("FACET_NONE", xercesc::XSSimpleTypeDefinition::FACET_NONE)
			.value("FACET_LENGTH", xercesc::XSSimpleTypeDefinition::FACET_LENGTH)
			.value("FACET_MINLENGTH", xercesc::XSSimpleTypeDefinition::FACET_MINLENGTH)
			.value("FACET_MAXLENGTH", xercesc::XSSimpleTypeDefinition::FACET_MAXLENGTH)
			.value("FACET_PATTERN", xercesc::XSSimpleTypeDefinition::FACET_PATTERN)
			.value("FACET_WHITESPACE", xercesc::XSSimpleTypeDefinition::FACET_WHITESPACE)
			.value("FACET_MAXINCLUSIVE", xercesc::XSSimpleTypeDefinition::FACET_MAXINCLUSIVE)
			.value("FACET_MAXEXCLUSIVE", xercesc::XSSimpleTypeDefinition::FACET_MAXEXCLUSIVE)
			.value("FACET_MINEXCLUSIVE", xercesc::XSSimpleTypeDefinition::FACET_MINEXCLUSIVE)
			.value("FACET_MININCLUSIVE", xercesc::XSSimpleTypeDefinition::FACET_MININCLUSIVE)
			.value("FACET_TOTALDIGITS", xercesc::XSSimpleTypeDefinition::FACET_TOTALDIGITS)
			.value("FACET_FRACTIONDIGITS", xercesc::XSSimpleTypeDefinition::FACET_FRACTIONDIGITS)
			.value("FACET_ENUMERATION", xercesc::XSSimpleTypeDefinition::FACET_ENUMERATION)
			.export_values()
			;
	//! xercesc::XSSimpleTypeDefinition::ORDERING
	boost::python::enum_<xercesc::XSSimpleTypeDefinition::ORDERING>("ORDERING")
			.value("ORDERED_FALSE", xercesc::XSSimpleTypeDefinition::ORDERED_FALSE)
			.value("ORDERED_PARTIAL", xercesc::XSSimpleTypeDefinition::ORDERED_PARTIAL)
			.value("ORDERED_TOTAL", xercesc::XSSimpleTypeDefinition::ORDERED_TOTAL)
			.export_values()
			;
}

} /* namespace pyxerces */
