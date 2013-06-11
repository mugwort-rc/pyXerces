/*
 * XMLURL.cpp
 *
 *  Created on: 2013/05/04
 *      Author: mugwort_rc
 */

#include "XMLURL.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/util/BinInputStream.hpp>
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/util/XMLURL.hpp>

namespace pyxerces {

void XMLURL_init(void) {
	//! XMLURL
	auto XMLURL = boost::python::class_<xercesc::XMLURL>("XMLURL", boost::python::init<boost::python::optional<xercesc::MemoryManager*> >())
			.def(boost::python::init<const XMLCh*, const XMLCh*, boost::python::optional<xercesc::MemoryManager*> >())
			.def(boost::python::init<const XMLCh*, const char*, boost::python::optional<xercesc::MemoryManager*> >())
			.def(boost::python::init<const xercesc::XMLURL&, const XMLCh*>())
			.def(boost::python::init<const xercesc::XMLURL&, const char*>())
			.def(boost::python::init<const XMLCh*, boost::python::optional<xercesc::MemoryManager*> >())
			.def(boost::python::init<const char*, boost::python::optional<xercesc::MemoryManager*> >())
			.def("__eq__", &xercesc::XMLURL::operator==)
			.def("__ne__", &xercesc::XMLURL::operator!=)
			.def("getFragment", &xercesc::XMLURL::getFragment, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getHost", &xercesc::XMLURL::getHost, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPassword", &xercesc::XMLURL::getPassword, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPath", &xercesc::XMLURL::getPath, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPortNum", &xercesc::XMLURL::getPortNum)
			.def("getProtocol", &xercesc::XMLURL::getProtocol)
			.def("getProtocolName", &xercesc::XMLURL::getProtocolName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getQuery", &xercesc::XMLURL::getQuery, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getURLText", &xercesc::XMLURL::getURLText, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getUser", &xercesc::XMLURL::getUser, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getMemoryManager", &xercesc::XMLURL::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setURL", static_cast<void(xercesc::XMLURL::*)(const XMLCh*)>(&xercesc::XMLURL::setURL))
			.def("setURL", static_cast<void(xercesc::XMLURL::*)(const XMLCh*, const XMLCh*)>(&xercesc::XMLURL::setURL))
			.def("setURL", static_cast<void(xercesc::XMLURL::*)(const xercesc::XMLURL&, const XMLCh*)>(&xercesc::XMLURL::setURL))
			.def("setURL", static_cast<bool(xercesc::XMLURL::*)(const XMLCh*, const XMLCh*, xercesc::XMLURL&)>(&xercesc::XMLURL::setURL))
			.def("isRelative", &xercesc::XMLURL::isRelative)
			.def("hasInvalidChar", &xercesc::XMLURL::hasInvalidChar)
			.def("makeNewStream", &xercesc::XMLURL::makeNewStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("makeRelativeTo", static_cast<void(xercesc::XMLURL::*)(const XMLCh*)>(&xercesc::XMLURL::makeRelativeTo))
			.def("makeRelativeTo", static_cast<void(xercesc::XMLURL::*)(const xercesc::XMLURL&)>(&xercesc::XMLURL::makeRelativeTo))
			;
	boost::python::scope XMLURLScope = XMLURL;
	//! XMLURL::Protocols
	boost::python::enum_<xercesc::XMLURL::Protocols>("Protocols")
			.value("File", xercesc::XMLURL::File)
			.value("HTTP", xercesc::XMLURL::HTTP)
			.value("FTP", xercesc::XMLURL::FTP)
			.value("HTTPS", xercesc::XMLURL::HTTPS)
			.value("Protocols_Count", xercesc::XMLURL::Protocols_Count)
			.value("Unknown", xercesc::XMLURL::Unknown)
			.export_values()
			;
}

} /* namespace pyxerces */
