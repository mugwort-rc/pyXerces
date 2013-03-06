/*
 * XSMultiValueFacet.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XSMultiValueFacet.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSMultiValueFacet.hpp>

namespace pyxerces {

void XSMultiValueFacet_init(void) {
	//! xercesc::XSMultiValueFacet
	boost::python::class_<xercesc::XSMultiValueFacet, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSMultiValueFacet", boost::python::init<xercesc::XSSimpleTypeDefinition::FACET, xercesc::StringList*, bool, xercesc::XSAnnotation* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getFacetKind", &xercesc::XSMultiValueFacet::getFacetKind)
			.def("getLexicalFacetValues", &xercesc::XSMultiValueFacet::getLexicalFacetValues, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isFixed", &xercesc::XSMultiValueFacet::isFixed)
			.def("getAnnotations", &xercesc::XSMultiValueFacet::getAnnotations, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
