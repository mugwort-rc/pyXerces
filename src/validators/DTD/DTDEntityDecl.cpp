/*
 * DTDEntityDecl.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "DTDEntityDecl.h"

#include <boost/python.hpp>
#include <xercesc/validators/DTD/DTDEntityDecl.hpp>

#include "../../internal/XSerializable.h"
#include "../../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class DTDEntityDeclDefVisitor
: public boost::python::def_visitor<DTDEntityDeclDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const STR, xercesc::MemoryManager* const)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const STR)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const STR, const STR, const bool, xercesc::MemoryManager* const)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const STR, const STR, const bool)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const STR, const STR)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const STR, const XMLCh, const bool, const bool)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const STR, const XMLCh, const bool)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const STR, const XMLCh)>(&DTDEntityDecl_fromstring)))
	;
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR entName, xercesc::MemoryManager* const manager) {
	XMLString buff(entName);
	return new xercesc::DTDEntityDecl(buff.ptr(), manager);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR entName) {
	return DTDEntityDecl_fromstring(entName, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR entName, const STR value, const bool fromIntSubset, xercesc::MemoryManager* const manager) {
	XMLString buff1(entName), buff2(value);
	return new xercesc::DTDEntityDecl(buff1.ptr(), buff2.ptr(), fromIntSubset, manager);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR entName, const STR value, const bool fromIntSubset) {
	return DTDEntityDecl_fromstring(entName, value, fromIntSubset, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR entName, const STR value) {
	return DTDEntityDecl_fromstring(entName, value, false);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR entName, const XMLCh value, const bool fromIntSubset, const bool specialChar) {
	XMLString buff(entName);
	return new xercesc::DTDEntityDecl(buff.ptr(), value, fromIntSubset, specialChar);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR entName, const XMLCh value, const bool fromIntSubset) {
	return DTDEntityDecl_fromstring(entName, value, fromIntSubset, false);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR entName, const XMLCh value) {
	return DTDEntityDecl_fromstring(entName, value, false);
}

};

void DTDEntityDecl_init(void) {
	//! xercesc::DTDEntityDecl
	boost::python::class_<xercesc::DTDEntityDecl, boost::noncopyable, boost::python::bases<xercesc::XMLEntityDecl> >("DTDEntityDecl", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh, boost::python::optional<const bool, const bool> >())
			.def(DTDEntityDeclDefVisitor<XMLString&>())
			.def(DTDEntityDeclDefVisitor<char*>())
			.def("getDeclaredInIntSubset", &xercesc::DTDEntityDecl::getDeclaredInIntSubset)
			.def("getIsParameter", &xercesc::DTDEntityDecl::getIsParameter)
			.def("getIsSpecialChar", &xercesc::DTDEntityDecl::getIsSpecialChar)
			.def("setDeclaredInIntSubset", &xercesc::DTDEntityDecl::setDeclaredInIntSubset)
			.def("setIsParameter", &xercesc::DTDEntityDecl::setIsParameter)
			.def("setIsSpecialChar", &xercesc::DTDEntityDecl::setIsSpecialChar)
			PyDECL_XSERIALIZABLE(DTDEntityDecl)
			;
}

} /* namespace pyxerces */
