/*
 * DOMImplementationRegistry.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMImplementationRegistry.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMImplementation.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMImplementationSource.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMImplementationList.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMImplementationRegistry.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMImplementationRegistryDefVisitor
: public boost::python::def_visitor<DOMImplementationRegistryDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getDOMImplementation", static_cast<xercesc::DOMImplementation*(*)(const XMLString&)>(&DOMImplementationRegistryDefVisitor::getDOMImplementation), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getDOMImplementation", static_cast<xercesc::DOMImplementation*(*)(const std::string&)>(&DOMImplementationRegistryDefVisitor::getDOMImplementation), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getDOMImplementationList", static_cast<xercesc::DOMImplementationList*(*)(const XMLString&)>(&DOMImplementationRegistryDefVisitor::getDOMImplementationList), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getDOMImplementationList", static_cast<xercesc::DOMImplementationList*(*)(const std::string&)>(&DOMImplementationRegistryDefVisitor::getDOMImplementationList), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMImplementation* getDOMImplementation(const XMLString& features) {
	return xercesc::DOMImplementationRegistry::getDOMImplementation(features.ptr());
}

static xercesc::DOMImplementation* getDOMImplementation(const std::string& features) {
	XMLString buff(features);
	return DOMImplementationRegistryDefVisitor::getDOMImplementation(buff);
}

static xercesc::DOMImplementationList* getDOMImplementationList(const XMLString& features) {
	return xercesc::DOMImplementationRegistry::getDOMImplementationList(features.ptr());
}

static xercesc::DOMImplementationList* getDOMImplementationList(const std::string& features) {
	XMLString buff(features);
	return DOMImplementationRegistryDefVisitor::getDOMImplementationList(buff);
}
};

void DOMImplementationRegistry_init(void) {
	//! xercesc::DOMImplementationRegistry
	boost::python::class_<xercesc::DOMImplementationRegistry, boost::noncopyable>("DOMImplementationRegistry", boost::python::no_init)
			.def(DOMImplementationRegistryDefVisitor())
			.def("getDOMImplementation", &xercesc::DOMImplementationRegistry::getDOMImplementation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDOMImplementationList", &xercesc::DOMImplementationRegistry::getDOMImplementationList, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("addSource", &xercesc::DOMImplementationRegistry::addSource)
			.staticmethod("getDOMImplementation")
			.staticmethod("getDOMImplementationList")
			.staticmethod("addSource")
			;
}

} /* namespace pyxerces */
