/*
 * IC_Field.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "IC_Field.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/schema/identity/ValueStore.hpp>
#include <xercesc/validators/schema/identity/FieldActivator.hpp>
#include <xercesc/validators/datatype/DatatypeValidator.hpp>
#include <xercesc/validators/schema/identity/IdentityConstraint.hpp>
#include <xercesc/validators/schema/identity/XercesXPath.hpp>

#include <xercesc/validators/schema/identity/IC_Field.hpp>

#include "../../../internal/XSerializable.h"

namespace pyxerces {

//! IC_Field
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(IC_FieldCreateMatcherOverloads, createMatcher, 2, 3)

void IC_Field_init(void) {
	//! xercesc::IC_Field
	boost::python::class_<xercesc::IC_Field, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("IC_Field", boost::python::init<xercesc::XercesXPath* const, xercesc::IdentityConstraint* const>())
			.def(boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def("__eq__", &xercesc::IC_Field::operator ==)
			.def("__ne__", &xercesc::IC_Field::operator !=)
			.def("getXPath", &xercesc::IC_Field::getXPath, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getIdentityConstraint", &xercesc::IC_Field::getIdentityConstraint, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createMatcher", &xercesc::IC_Field::createMatcher, IC_FieldCreateMatcherOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			PyDECL_XSERIALIZABLE(IC_Field)
			;
	//! xercesc::FieldMatcher
	boost::python::class_<xercesc::FieldMatcher, boost::noncopyable, boost::python::bases<xercesc::XPathMatcher> >("FieldMatcher", boost::python::no_init)
			.def("getValueStore", &xercesc::FieldMatcher::getValueStore, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getField", &xercesc::FieldMatcher::getField, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("matched", &xercesc::FieldMatcher::matched)
			;
}

} /* namespace pyxerces */
