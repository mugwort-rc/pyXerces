/*
 * XMLCanRepGroup.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XMLCanRepGroup.h"

#include <boost/python.hpp>
#include <xercesc/validators/datatype/XMLCanRepGroup.hpp>

namespace pyxerces {

void XMLCanRepGroup_init(void) {
	//! xercesc::XMLCanRepGroup
	auto XMLCanRepGroup = boost::python::class_<xercesc::XMLCanRepGroup, boost::noncopyable>("XMLCanRepGroup", boost::python::init<xercesc::XMLCanRepGroup::CanRepGroup>())
			.def("getGroup", &xercesc::XMLCanRepGroup::getGroup)
			;
	boost::python::scope XMLCanRepGroupScope = XMLCanRepGroup;
	//! xercesc::XMLCanRepGroup::CanRepGroup
	boost::python::enum_<xercesc::XMLCanRepGroup::CanRepGroup>("CanRepGroup")
			.value("Boolean", xercesc::XMLCanRepGroup::Boolean)
			.value("DoubleFloat", xercesc::XMLCanRepGroup::DoubleFloat)
			.value("DateTime", xercesc::XMLCanRepGroup::DateTime)
			.value("Time", xercesc::XMLCanRepGroup::Time)
			.value("Decimal", xercesc::XMLCanRepGroup::Decimal)
			.value("Decimal_Derived_signed", xercesc::XMLCanRepGroup::Decimal_Derived_signed)
			.value("Decimal_Derived_unsigned", xercesc::XMLCanRepGroup::Decimal_Derived_unsigned)
			.value("Decimal_Derived_npi", xercesc::XMLCanRepGroup::Decimal_Derived_npi)
			.value("String", xercesc::XMLCanRepGroup::String)
			.export_values()
			;
}

} /* namespace pyxerces */
