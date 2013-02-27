/*
 * DOMTypeInfo.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMTypeInfo.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMTypeInfo.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMTypeInfoDefVisitor
: public boost::python::def_visitor<DOMTypeInfoDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("isDerivedFrom", static_cast<bool(*)(xercesc::DOMTypeInfo&, const XMLString&, const XMLString&, xercesc::DOMTypeInfo::DerivationMethods)>(&DOMTypeInfoDefVisitor::isDerivedFrom))
	.def("isDerivedFrom", static_cast<bool(*)(xercesc::DOMTypeInfo&, const std::string&, const std::string&, xercesc::DOMTypeInfo::DerivationMethods)>(&DOMTypeInfoDefVisitor::isDerivedFrom))
	;
}

static bool isDerivedFrom(xercesc::DOMTypeInfo& self, const XMLString& typeNamespaceArg, const XMLString& typeNameArg, xercesc::DOMTypeInfo::DerivationMethods derivationMethod) {
	return self.isDerivedFrom(typeNamespaceArg.ptr(), typeNameArg.ptr(), derivationMethod);
}

static bool isDerivedFrom(xercesc::DOMTypeInfo& self, const std::string& typeNamespaceArg, const std::string& typeNameArg, xercesc::DOMTypeInfo::DerivationMethods derivationMethod) {
	XMLString buff1(typeNamespaceArg), buff2(typeNameArg);
	return DOMTypeInfoDefVisitor::isDerivedFrom(self, buff1, buff2, derivationMethod);
}
};

void DOMTypeInfo_init(void) {
	//! xercesc::DOMTypeInfo
	auto DOMTypeInfo = boost::python::class_<xercesc::DOMTypeInfo, boost::noncopyable>("DOMTypeInfo", boost::python::no_init)
			.def(DOMTypeInfoDefVisitor())
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
