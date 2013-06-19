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

class DTDEntityDeclDefVisitor
: public boost::python::def_visitor<DTDEntityDeclDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, xercesc::MemoryManager* const)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLString&, const bool, xercesc::MemoryManager* const)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLString&, const bool)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLString&)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLCh, const bool, const bool)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLCh, const bool)>(&DTDEntityDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLCh)>(&DTDEntityDecl_fromstring)))
	;
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const XMLString& entName, xercesc::MemoryManager* const manager) {
	return new xercesc::DTDEntityDecl(entName.ptr(), manager);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const XMLString& entName) {
	return DTDEntityDecl_fromstring(entName, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const XMLString& entName, const XMLString& value, const bool fromIntSubset, xercesc::MemoryManager* const manager) {
	return new xercesc::DTDEntityDecl(entName.ptr(), value.ptr(), fromIntSubset, manager);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const XMLString& entName, const XMLString& value, const bool fromIntSubset) {
	return DTDEntityDecl_fromstring(entName, value, fromIntSubset, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const XMLString& entName, const XMLString& value) {
	return DTDEntityDecl_fromstring(entName, value, false);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const XMLString& entName, const XMLCh value, const bool fromIntSubset, const bool specialChar) {
	return new xercesc::DTDEntityDecl(entName.ptr(), value, fromIntSubset, specialChar);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const XMLString& entName, const XMLCh value, const bool fromIntSubset) {
	return DTDEntityDecl_fromstring(entName, value, fromIntSubset, false);
}

static xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const XMLString& entName, const XMLCh value) {
	return DTDEntityDecl_fromstring(entName, value, false);
}

};

void DTDEntityDecl_init(void) {
	//! xercesc::DTDEntityDecl
	boost::python::class_<xercesc::DTDEntityDecl, boost::noncopyable, boost::python::bases<xercesc::XMLEntityDecl> >("DTDEntityDecl", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh, boost::python::optional<const bool, const bool> >())
			.def(DTDEntityDeclDefVisitor())
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
