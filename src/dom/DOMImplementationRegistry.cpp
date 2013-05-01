/*
 * DOMImplementationRegistry.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMImplementationRegistry.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationSource.hpp>
#include <xercesc/dom/DOMImplementationList.hpp>

#include <xercesc/dom/DOMImplementationRegistry.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class DOMImplementationRegistryDefVisitor
: public boost::python::def_visitor<DOMImplementationRegistryDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getDOMImplementation", &DOMImplementationRegistryDefVisitor::getDOMImplementation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getDOMImplementationList", &DOMImplementationRegistryDefVisitor::getDOMImplementationList, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMImplementation* getDOMImplementation(const STR features) {
	XMLString buff(features);
	return xercesc::DOMImplementationRegistry::getDOMImplementation(buff.ptr());
}

static xercesc::DOMImplementationList* getDOMImplementationList(const STR features) {
	XMLString buff(features);
	return xercesc::DOMImplementationRegistry::getDOMImplementationList(buff.ptr());
}

};

void DOMImplementationRegistry_init(void) {
	//! xercesc::DOMImplementationRegistry
	boost::python::class_<xercesc::DOMImplementationRegistry, boost::noncopyable>("DOMImplementationRegistry", boost::python::no_init)
			.def(DOMImplementationRegistryDefVisitor<XMLString&>())
			.def(DOMImplementationRegistryDefVisitor<char*>())
			.def("getDOMImplementation", &xercesc::DOMImplementationRegistry::getDOMImplementation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDOMImplementationList", &xercesc::DOMImplementationRegistry::getDOMImplementationList, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("addSource", &xercesc::DOMImplementationRegistry::addSource)
			.staticmethod("getDOMImplementation")
			.staticmethod("getDOMImplementationList")
			.staticmethod("addSource")
			;
}

} /* namespace pyxerces */
