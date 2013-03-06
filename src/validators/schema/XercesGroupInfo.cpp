/*
 * XercesGroupInfo.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XercesGroupInfo.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/common/ContentSpecNode.hpp>
#include <xercesc/validators/schema/XSDLocator.hpp>

#include <xercesc/validators/schema/XercesGroupInfo.hpp>

#include "../../internal/XSerializable.h"

namespace pyxerces {

void XercesGroupInfo_init(void) {
	//! xercesc::XercesGroupInfo
	boost::python::class_<xercesc::XercesGroupInfo, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XercesGroupInfo", boost::python::init<unsigned int, unsigned int, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getCheckElementConsistency", &xercesc::XercesGroupInfo::getCheckElementConsistency)
			.def("getScope", &xercesc::XercesGroupInfo::getScope)
			.def("elementCount", &xercesc::XercesGroupInfo::elementCount)
			.def("getContentSpec", &xercesc::XercesGroupInfo::getContentSpec, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("elementAt", static_cast<xercesc::SchemaElementDecl*(xercesc::XercesGroupInfo::*)(const XMLSize_t)>(&xercesc::XercesGroupInfo::elementAt), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLocator", &xercesc::XercesGroupInfo::getLocator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getBaseGroup", &xercesc::XercesGroupInfo::getBaseGroup, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNameId", &xercesc::XercesGroupInfo::getNameId)
			.def("getNamespaceId", &xercesc::XercesGroupInfo::getNamespaceId)
			.def("setScope", &xercesc::XercesGroupInfo::setScope)
			.def("setContentSpec", &xercesc::XercesGroupInfo::setContentSpec)
			.def("addElement", &xercesc::XercesGroupInfo::addElement)
			.def("setLocator", &xercesc::XercesGroupInfo::setLocator)
			.def("setBaseGroup", &xercesc::XercesGroupInfo::setBaseGroup)
			.def("setCheckElementConsistency", &xercesc::XercesGroupInfo::setCheckElementConsistency)
			PyDECL_XSERIALIZABLE(XercesGroupInfo)
			;
}

} /* namespace pyxerces */
