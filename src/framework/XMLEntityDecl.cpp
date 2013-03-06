/*
 * XMLEntityDecl.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XMLEntityDecl.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLEntityDecl.hpp>

#include "../internal/XSerializable.h"

namespace pyxerces {

class XMLEntityDeclWrapper
: public xercesc::XMLEntityDecl, public boost::python::wrapper<xercesc::XMLEntityDecl>
{
public:
XMLEntityDeclWrapper(xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::XMLEntityDecl(manager)
{}

XMLEntityDeclWrapper(const XMLCh* const entName, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::XMLEntityDecl(entName, manager)
{}

XMLEntityDeclWrapper(const XMLCh* const entName, const XMLCh* const value, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::XMLEntityDecl(entName, value, manager)
{}

XMLEntityDeclWrapper(const XMLCh* const entName, const XMLCh value, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::XMLEntityDecl(entName, value, manager)
{}

bool getDeclaredInIntSubset() const {
	return this->get_override("getDeclaredInIntSubset")();
}

bool getIsParameter() const {
	return this->get_override("getIsParameter")();
}

bool getIsSpecialChar() const {
	return this->get_override("getIsSpecialChar")();
}

};

void XMLEntityDecl_init(void) {
	//! xercesc::XMLEntityDecl
	boost::python::class_<XMLEntityDeclWrapper, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLEntityDecl", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getDeclaredInIntSubset", &xercesc::XMLEntityDecl::getDeclaredInIntSubset)
			.def("getIsParameter", &xercesc::XMLEntityDecl::getIsParameter)
			.def("getIsSpecialChar", &xercesc::XMLEntityDecl::getIsSpecialChar)
			.def("getId", &xercesc::XMLEntityDecl::getId)
			.def("getName", &xercesc::XMLEntityDecl::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNotationName", &xercesc::XMLEntityDecl::getNotationName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPublicId", &xercesc::XMLEntityDecl::getPublicId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::XMLEntityDecl::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getBaseURI", &xercesc::XMLEntityDecl::getBaseURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getValue", &xercesc::XMLEntityDecl::getValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getValueLen", &xercesc::XMLEntityDecl::getValueLen)
			.def("isExternal", &xercesc::XMLEntityDecl::isExternal)
			.def("isUnparsed", &xercesc::XMLEntityDecl::isUnparsed)
			.def("getMemoryManager", &xercesc::XMLEntityDecl::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setName", &xercesc::XMLEntityDecl::setName)
			.def("setIsExternal", &xercesc::XMLEntityDecl::setIsExternal)
			.def("setNotationName", &xercesc::XMLEntityDecl::setNotationName)
			.def("setPublicId", &xercesc::XMLEntityDecl::setPublicId)
			.def("setSystemId", &xercesc::XMLEntityDecl::setSystemId)
			.def("setBaseURI", &xercesc::XMLEntityDecl::setBaseURI)
			.def("setValue", &xercesc::XMLEntityDecl::setValue)
			.def("setId", &xercesc::XMLEntityDecl::setId)
			.def("getKey", &xercesc::XMLEntityDecl::getKey, boost::python::return_value_policy<boost::python::return_by_value>())
			PyDECL_XSERIALIZABLE(XMLEntityDecl)
			;
}

} /* namespace pyxerces */
