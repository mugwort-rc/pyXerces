/*
 * XMLRefInfo.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XMLRefInfo.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLRefInfo.hpp>

#include "../internal/XSerializable.h"

namespace pyxerces {

void XMLRefInfo_init(void) {
	//! xercesc::XMLRefInfo
	boost::python::class_<xercesc::XMLRefInfo, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLRefInfo", boost::python::init<const XMLCh* const, boost::python::optional<const bool, const bool, xercesc::MemoryManager* const> >())
			.def(boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getDeclared", &xercesc::XMLRefInfo::getDeclared)
			.def("getRefName", &xercesc::XMLRefInfo::getRefName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getUsed", &xercesc::XMLRefInfo::getUsed)
			.def("setDeclared", &xercesc::XMLRefInfo::setDeclared)
			.def("setUsed", &xercesc::XMLRefInfo::setUsed)
			PyDECL_XSERIALIZABLE(XMLRefInfo)
			;
}

} /* namespace pyxerces */
