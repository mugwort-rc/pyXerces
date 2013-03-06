/*
 * XSFacet.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XSFacet.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSFacet.hpp>

#include "../../util/XMLString.h"

namespace pyxerces {

template<class STR>
xercesc::XSFacet* XSFacet_fromstring(xercesc::XSSimpleTypeDefinition::FACET facetKind, const STR& lexicalValue, bool isFixed, xercesc::XSAnnotation* const annot, xercesc::XSModel* const xsModel, xercesc::MemoryManager* const manager) {
	XMLString buff(lexicalValue);
	return new xercesc::XSFacet(facetKind, buff.ptr(), isFixed, annot, xsModel, manager);
}

template<class STR>
xercesc::XSFacet* XSFacet_fromstring(xercesc::XSSimpleTypeDefinition::FACET facetKind, const STR& lexicalValue, bool isFixed, xercesc::XSAnnotation* const annot, xercesc::XSModel* const xsModel) {
	return XSFacet_fromstring<STR>(facetKind, lexicalValue, isFixed, annot, xsModel, xercesc::XMLPlatformUtils::fgMemoryManager);
}

void XSFacet_init(void) {
	//! xercesc::XSFacet
	boost::python::class_<xercesc::XSFacet, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSFacet", boost::python::init<xercesc::XSSimpleTypeDefinition::FACET, const XMLCh* const, bool, xercesc::XSAnnotation* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::XSFacet*(*)(xercesc::XSSimpleTypeDefinition::FACET, const XMLString&, bool, xercesc::XSAnnotation* const, xercesc::XSModel* const, xercesc::MemoryManager* const)>(&XSFacet_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::XSFacet*(*)(xercesc::XSSimpleTypeDefinition::FACET, const XMLString&, bool, xercesc::XSAnnotation* const, xercesc::XSModel* const)>(&XSFacet_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::XSFacet*(*)(xercesc::XSSimpleTypeDefinition::FACET, const std::string&, bool, xercesc::XSAnnotation* const, xercesc::XSModel* const, xercesc::MemoryManager* const)>(&XSFacet_fromstring<std::string>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::XSFacet*(*)(xercesc::XSSimpleTypeDefinition::FACET, const std::string&, bool, xercesc::XSAnnotation* const, xercesc::XSModel* const)>(&XSFacet_fromstring<std::string>)))
			.def("getFacetKind", &xercesc::XSFacet::getFacetKind)
			.def("getLexicalFacetValue", &xercesc::XSFacet::getLexicalFacetValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("isFixed", &xercesc::XSFacet::isFixed)
			.def("getAnnotation", &xercesc::XSFacet::getAnnotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
