/*
 * XSNotationDeclaration.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XSNotationDeclaration.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/XMLNotationDecl.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSNotationDeclaration.hpp>

namespace pyxerces {

void XSNotationDeclaration_init(void) {
	//! xercesc::XSNotationDeclaration
	boost::python::class_<xercesc::XSNotationDeclaration, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSNotationDeclaration", boost::python::init<xercesc::XMLNotationDecl* const, xercesc::XSAnnotation* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getName", &xercesc::XSNotationDeclaration::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespace", &xercesc::XSNotationDeclaration::getNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespaceItem", &xercesc::XSNotationDeclaration::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getSystemId", &xercesc::XSNotationDeclaration::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPublicId", &xercesc::XSNotationDeclaration::getPublicId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAnnotation", &xercesc::XSNotationDeclaration::getAnnotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
