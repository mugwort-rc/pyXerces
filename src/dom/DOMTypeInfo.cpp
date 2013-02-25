/*
 * DOMTypeInfo.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMTypeInfo.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMTypeInfo.hpp>

namespace pyxerces {

void DOMTypeInfo_init(void) {
	//! xercesc::DOMTypeInfo
	auto DOMTypeInfo = boost::python::class_<xercesc::DOMTypeInfo, boost::noncopyable>("DOMTypeInfo", boost::python::no_init)
			.def("getTypeName", &xercesc::DOMTypeInfo::getTypeName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getTypeNamespace", &xercesc::DOMTypeInfo::getTypeNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("isDerivedFrom", &xercesc::DOMTypeInfo::isDerivedFrom)
			;
	boost::python::scope DOMTypeInfoScope = DOMTypeInfo;
	//! xercesc::DOMTypeInfo::DerivationMethods
	boost::python::enum_<xercesc::DOMTypeInfo::DerivationMethods>("DerivationMethods")
			.value("DERIVATION_RESTRICTION", xercesc::DOMTypeInfo::DERIVATION_RESTRICTION)
			.value("DERIVATION_EXTENSION", xercesc::DOMTypeInfo::DERIVATION_EXTENSION)
			.value("DERIVATION_UNION", xercesc::DOMTypeInfo::DERIVATION_UNION)
			.value("DERIVATION_LIST", xercesc::DOMTypeInfo::DERIVATION_LIST)
			;
}

} /* namespace pyxerces */
