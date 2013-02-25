/*
 * QName.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "QName.h"

#include <boost/python.hpp>
#include <xercesc/util/QName.hpp>

namespace pyxerces {

void QName_init(void) {
	//! xercesc::QName
	boost::python::class_<xercesc::QName, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("QName", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, const unsigned int, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const unsigned int, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const xercesc::QName&>())
			.def("getPrefix", static_cast<const XMLCh*(xercesc::QName::*)(void) const>(&xercesc::QName::getPrefix), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLocalPart", static_cast<const XMLCh*(xercesc::QName::*)(void) const>(&xercesc::QName::getLocalPart), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getURI", &xercesc::QName::getURI)
			.def("getRawName", static_cast<const XMLCh*(xercesc::QName::*)(void) const>(&xercesc::QName::getRawName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getMemoryManager", &xercesc::QName::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setName", static_cast<void(xercesc::QName::*)(const XMLCh* const, const XMLCh* const, const unsigned int)>(&xercesc::QName::setName))
			.def("setName", static_cast<void(xercesc::QName::*)(const XMLCh* const, const unsigned int)>(&xercesc::QName::setName))
			.def("setPrefix", &xercesc::QName::setPrefix)
			.def("setLocalPart", &xercesc::QName::setLocalPart)
			.def("setNPrefix", &xercesc::QName::setNPrefix)
			.def("setNLocalPart", &xercesc::QName::setNLocalPart)
			.def("setURI", &xercesc::QName::setURI)
			.def("setValues", &xercesc::QName::setValues)
			.def("__eq__", &xercesc::QName::operator==)
			.def("cleanUp", &xercesc::QName::cleanUp)
			.def("isSerializable", &xercesc::QName::isSerializable)
			.def("getProtoType", &xercesc::QName::getProtoType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("serialize", &xercesc::QName::serialize)
			;
}

} /* namespace pyxerces */
