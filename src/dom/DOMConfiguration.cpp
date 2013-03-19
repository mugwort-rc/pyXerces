/*
 * DOMConfiguration.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMConfiguration.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMErrorHandler.hpp>

#include <xercesc/dom/DOMConfiguration.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class DOMConfigurationDefVisitor
: public boost::python::def_visitor<DOMConfigurationDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setParameter", &DOMConfigurationDefVisitor::setParameter<const void*>)
	.def("setParameter", &DOMConfigurationDefVisitor::setParameter<bool>)
	.def("setParameter", &DOMConfigurationDefVisitor::getParameter, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("canSetParameter", &DOMConfigurationDefVisitor::canSetParameter<const void*>)
	.def("canSetParameter", &DOMConfigurationDefVisitor::canSetParameter<bool>)
	.def("setParameter", &DOMConfigurationDefVisitor::setParameterCastValue<xercesc::DOMErrorHandler>)
	;
}

template <typename T>
static void setParameter(xercesc::DOMConfiguration& self, const STR& name, T value) {
	XMLString buff(name);
	self.setParameter(buff.ptr(), value);
}

static const void* getParameter(xercesc::DOMConfiguration& self, const STR& name) {
	XMLString buff(name);
	return self.getParameter(buff.ptr());
}

template <typename T>
static bool canSetParameter(xercesc::DOMConfiguration& self, const STR& name, T value) {
	XMLString buff(name);
	return self.canSetParameter(buff.ptr(), value);
}

template <typename T>
static void setParameterCastValue(xercesc::DOMConfiguration& self, const STR& name, const T& value) {
	DOMConfigurationDefVisitor::setParameter<const void*>(self, name, reinterpret_cast<const void*>(&value));
}

};

class DOMConfigurationWrapper
: public xercesc::DOMConfiguration, public boost::python::wrapper<xercesc::DOMConfiguration>
{
public:
void setParameter(const XMLCh* name, const void* value) {
	// XXX: value
	this->get_override("setParameter")(XMLString(name), value);
}

void setParameter(const XMLCh* name, bool value) {
	this->get_override("setParameter")(XMLString(name), value);
}

const void* getParameter(const XMLCh* name) const {
	return this->get_override("getParameter")(XMLString(name));
}

bool canSetParameter(const XMLCh* name, const void* value) const {
	// XXX: value
	return this->get_override("canSetParameter")(XMLString(name), value);
}

bool canSetParameter(const XMLCh* name, bool value) const {
	return this->get_override("canSetParameter")(XMLString(name), value);
}

const xercesc::DOMStringList* getParameterNames() const {
	return this->get_override("getParameterNames")();
}

};

void DOMConfiguration_init(void) {
	//! xercesc::DOMConfiguration
	boost::python::class_<DOMConfigurationWrapper, boost::noncopyable>("DOMConfiguration")
			.def(DOMConfigurationDefVisitor<XMLString>())
			.def(DOMConfigurationDefVisitor<std::string>())
			.def("setParameter", boost::python::pure_virtual(static_cast<void(xercesc::DOMConfiguration::*)(const XMLCh*, const void*)>(&xercesc::DOMConfiguration::setParameter)))
			.def("setParameter", boost::python::pure_virtual(static_cast<void(xercesc::DOMConfiguration::*)(const XMLCh*, bool)>(&xercesc::DOMConfiguration::setParameter)))
			.def("getParameter", boost::python::pure_virtual(&xercesc::DOMConfiguration::getParameter), boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("canSetParameter", boost::python::pure_virtual(static_cast<bool(xercesc::DOMConfiguration::*)(const XMLCh*, const void*) const>(&xercesc::DOMConfiguration::canSetParameter)))
			.def("canSetParameter", boost::python::pure_virtual(static_cast<bool(xercesc::DOMConfiguration::*)(const XMLCh*, bool) const>(&xercesc::DOMConfiguration::canSetParameter)))
			.def("getParameterNames", boost::python::pure_virtual(&xercesc::DOMConfiguration::getParameterNames), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
