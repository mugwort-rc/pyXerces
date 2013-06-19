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
	.def("isDerivedFrom", &DOMTypeInfoDefVisitor::isDerivedFrom)
	;
}

static bool isDerivedFrom(xercesc::DOMTypeInfo& self, const XMLString& typeNamespaceArg, const XMLString& typeNameArg, xercesc::DOMTypeInfo::DerivationMethods derivationMethod) {
	return self.isDerivedFrom(typeNamespaceArg.ptr(), typeNameArg.ptr(), derivationMethod);
}

};

class DOMTypeInfoWrapper
: public xercesc::DOMTypeInfo, public boost::python::wrapper<xercesc::DOMTypeInfo>
{
public:
const XMLCh* getTypeName() const {
	return this->get_override("getTypeName")();
}

const XMLCh* getTypeNamespace() const {
	return this->get_override("getTypeNamespace")();
}

bool isDerivedFrom(const XMLCh* typeNamespaceArg, const XMLCh* typeNameArg, DerivationMethods derivationMethod) const {
	return this->get_override("isDerivedFrom")(XMLString(typeNamespaceArg), XMLString(typeNameArg), derivationMethod);
}

};

void DOMTypeInfo_init(void) {
	//! xercesc::DOMTypeInfo
	auto DOMTypeInfo = boost::python::class_<DOMTypeInfoWrapper, boost::noncopyable>("DOMTypeInfo")
			.def(DOMTypeInfoDefVisitor())
			.def("getTypeName", boost::python::pure_virtual(&xercesc::DOMTypeInfo::getTypeName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getTypeNamespace", boost::python::pure_virtual(&xercesc::DOMTypeInfo::getTypeNamespace), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("isDerivedFrom", boost::python::pure_virtual(&xercesc::DOMTypeInfo::isDerivedFrom))
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
