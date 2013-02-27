/*
 * DOMConfiguration.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMConfiguration.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMConfiguration.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMConfigurationDefVisitor
: public boost::python::def_visitor<DOMConfigurationDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setParameter", static_cast<void(*)(xercesc::DOMConfiguration&, const XMLString&, const void*)>(&DOMConfigurationDefVisitor::setParameter))
	.def("setParameter", static_cast<void(*)(xercesc::DOMConfiguration&, const std::string&, const void*)>(&DOMConfigurationDefVisitor::setParameter))
	.def("setParameter", static_cast<void(*)(xercesc::DOMConfiguration&, const XMLString&, bool)>(&DOMConfigurationDefVisitor::setParameter))
	.def("setParameter", static_cast<void(*)(xercesc::DOMConfiguration&, const std::string&, bool)>(&DOMConfigurationDefVisitor::setParameter))
	.def("setParameter", static_cast<const void*(*)(xercesc::DOMConfiguration&, const XMLString&)>(&DOMConfigurationDefVisitor::getParameter), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("setParameter", static_cast<const void*(*)(xercesc::DOMConfiguration&, const std::string&)>(&DOMConfigurationDefVisitor::getParameter), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("canSetParameter", static_cast<bool(*)(xercesc::DOMConfiguration&, const XMLString&, const void*)>(&DOMConfigurationDefVisitor::canSetParameter))
	.def("canSetParameter", static_cast<bool(*)(xercesc::DOMConfiguration&, const std::string&, const void*)>(&DOMConfigurationDefVisitor::canSetParameter))
	.def("canSetParameter", static_cast<bool(*)(xercesc::DOMConfiguration&, const XMLString&, bool)>(&DOMConfigurationDefVisitor::canSetParameter))
	.def("canSetParameter", static_cast<bool(*)(xercesc::DOMConfiguration&, const std::string&, bool)>(&DOMConfigurationDefVisitor::canSetParameter))
	;
}

static void setParameter(xercesc::DOMConfiguration& self, const XMLString& name, const void* value) {
	self.setParameter(name.ptr(), value);
}

static void setParameter(xercesc::DOMConfiguration& self, const std::string& name, const void* value) {
	XMLString buff(name);
	DOMConfigurationDefVisitor::setParameter(self, buff, value);
}

static void setParameter(xercesc::DOMConfiguration& self, const XMLString& name, bool value) {
	self.setParameter(name.ptr(), value);
}

static void setParameter(xercesc::DOMConfiguration& self, const std::string& name, bool value) {
	XMLString buff(name);
	DOMConfigurationDefVisitor::setParameter(self, buff, value);
}

static const void* getParameter(xercesc::DOMConfiguration& self, const XMLString& name) {
	return self.getParameter(name.ptr());
}

static const void* getParameter(xercesc::DOMConfiguration& self, const std::string& name) {
	XMLString buff(name);
	return DOMConfigurationDefVisitor::getParameter(self, buff);
}

static bool canSetParameter(xercesc::DOMConfiguration& self, const XMLString& name, const void* value) {
	return self.canSetParameter(name.ptr(), value);
}

static bool canSetParameter(xercesc::DOMConfiguration& self, const std::string& name, const void* value) {
	XMLString buff(name);
	return DOMConfigurationDefVisitor::canSetParameter(self, buff, value);
}

static bool canSetParameter(xercesc::DOMConfiguration& self, const XMLString& name, bool value) {
	return self.canSetParameter(name.ptr(), value);
}

static bool canSetParameter(xercesc::DOMConfiguration& self, const std::string& name, bool value) {
	XMLString buff(name);
	return DOMConfigurationDefVisitor::canSetParameter(self, buff, value);
}
};

void DOMConfiguration_init(void) {
	//! xercesc::DOMConfiguration
	boost::python::class_<xercesc::DOMConfiguration, boost::noncopyable>("DOMConfiguration", boost::python::no_init)
			.def(DOMConfigurationDefVisitor())
			.def("setParameter", static_cast<void(xercesc::DOMConfiguration::*)(const XMLCh*, const void*)>(&xercesc::DOMConfiguration::setParameter))
			.def("setParameter", static_cast<void(xercesc::DOMConfiguration::*)(const XMLCh*, bool)>(&xercesc::DOMConfiguration::setParameter))
			.def("getParameter", &xercesc::DOMConfiguration::getParameter, boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("canSetParameter", static_cast<bool(xercesc::DOMConfiguration::*)(const XMLCh*, const void*) const>(&xercesc::DOMConfiguration::canSetParameter))
			.def("canSetParameter", static_cast<bool(xercesc::DOMConfiguration::*)(const XMLCh*, bool) const>(&xercesc::DOMConfiguration::canSetParameter))
			.def("getParameterNames", &xercesc::DOMConfiguration::getParameterNames, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
