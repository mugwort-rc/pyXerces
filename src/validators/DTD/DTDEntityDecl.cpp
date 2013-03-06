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

template <class STR>
xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR& entName, xercesc::MemoryManager* const manager) {
	XMLString buff(entName);
	return new xercesc::DTDEntityDecl(buff.ptr(), manager);
}

template <class STR>
xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR& entName) {
	return DTDEntityDecl_fromstring<STR>(entName, xercesc::XMLPlatformUtils::fgMemoryManager);
}

template <class STR>
xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR& entName, const STR& value, const bool fromIntSubset, xercesc::MemoryManager* const manager) {
	XMLString buff1(entName), buff2(value);
	return new xercesc::DTDEntityDecl(buff1.ptr(), buff2.ptr(), fromIntSubset, manager);
}

template <class STR>
xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR& entName, const STR& value, const bool fromIntSubset) {
	return DTDEntityDecl_fromstring<STR>(entName, value, fromIntSubset, xercesc::XMLPlatformUtils::fgMemoryManager);
}

template <class STR>
xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR& entName, const STR& value) {
	return DTDEntityDecl_fromstring<STR>(entName, value, false);
}

template <class STR>
xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR& entName, const XMLCh value, const bool fromIntSubset, const bool specialChar) {
	XMLString buff(entName);
	return new xercesc::DTDEntityDecl(buff.ptr(), value, fromIntSubset, specialChar);
}

template <class STR>
xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR& entName, const XMLCh value, const bool fromIntSubset) {
	return DTDEntityDecl_fromstring<STR>(entName, value, fromIntSubset, false);
}

template <class STR>
xercesc::DTDEntityDecl* DTDEntityDecl_fromstring(const STR& entName, const XMLCh value) {
	return DTDEntityDecl_fromstring<STR>(entName, value, false);
}

void DTDEntityDecl_init(void) {
	//! xercesc::DTDEntityDecl
	boost::python::class_<xercesc::DTDEntityDecl, boost::noncopyable, boost::python::bases<xercesc::XMLEntityDecl> >("DTDEntityDecl", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh, boost::python::optional<const bool, const bool> >())
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, xercesc::MemoryManager* const)>(&DTDEntityDecl_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&)>(&DTDEntityDecl_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLString&, const bool, xercesc::MemoryManager* const)>(&DTDEntityDecl_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLString&, const bool)>(&DTDEntityDecl_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLString&)>(&DTDEntityDecl_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLCh, const bool, const bool)>(&DTDEntityDecl_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLCh, const bool)>(&DTDEntityDecl_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const XMLString&, const XMLCh)>(&DTDEntityDecl_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const std::string&, xercesc::MemoryManager* const)>(&DTDEntityDecl_fromstring<std::string>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const std::string&)>(&DTDEntityDecl_fromstring<std::string>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const std::string&, const std::string&, const bool, xercesc::MemoryManager* const)>(&DTDEntityDecl_fromstring<std::string>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const std::string&, const std::string&, const bool)>(&DTDEntityDecl_fromstring<std::string>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const std::string&, const std::string&)>(&DTDEntityDecl_fromstring<std::string>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const std::string&, const XMLCh, const bool, const bool)>(&DTDEntityDecl_fromstring<std::string>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const std::string&, const XMLCh, const bool)>(&DTDEntityDecl_fromstring<std::string>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDEntityDecl*(*)(const std::string&, const XMLCh)>(&DTDEntityDecl_fromstring<std::string>)))
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
