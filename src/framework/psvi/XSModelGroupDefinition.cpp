/*
 * XSModelGroupDefinition.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XSModelGroupDefinition.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSModelGroup.hpp>
#include <xercesc/framework/psvi/XSParticle.hpp>
#include <xercesc/validators/schema/XercesGroupInfo.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSModelGroupDefinition.hpp>

namespace pyxerces {

void XSModelGroupDefinition_init(void) {
	//! xercesc::XSModelGroupDefinition
	boost::python::class_<xercesc::XSModelGroupDefinition, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSModelGroupDefinition", boost::python::init<xercesc::XercesGroupInfo* const, xercesc::XSParticle* const, xercesc::XSAnnotation* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getName", &xercesc::XSModelGroupDefinition::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespace", &xercesc::XSModelGroupDefinition::getNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespaceItem", &xercesc::XSModelGroupDefinition::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getModelGroup", &xercesc::XSModelGroupDefinition::getModelGroup, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAnnotation", &xercesc::XSModelGroupDefinition::getAnnotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
