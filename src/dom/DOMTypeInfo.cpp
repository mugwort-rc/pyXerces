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

template <class STR>
class DOMTypeInfoDefVisitor
: public boost::python::def_visitor<DOMTypeInfoDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("isDerivedFrom", &DOMTypeInfoDefVisitor::isDerivedFrom)
	;
}

static bool isDerivedFrom(xercesc::DOMTypeInfo& self, const STR& typeNamespaceArg, const STR& typeNameArg, xercesc::DOMTypeInfo::DerivationMethods derivationMethod) {
	XMLString buff1(typeNamespaceArg), buff2(typeNameArg);
	return self.isDerivedFrom(buff1.ptr(), buff2.ptr(), derivationMethod);
}

};

void DOMTypeInfo_init(void) {
	//! xercesc::DOMTypeInfo
	auto DOMTypeInfo = boost::python::class_<xercesc::DOMTypeInfo, boost::noncopyable>("DOMTypeInfo", boost::python::no_init)
			.def(DOMTypeInfoDefVisitor<XMLString>())
			.def(DOMTypeInfoDefVisitor<std::string>())
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
