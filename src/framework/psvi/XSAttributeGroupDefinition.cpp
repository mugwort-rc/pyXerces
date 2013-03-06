/*
 * XSAttributeGroupDefinition.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XSAttributeGroupDefinition.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSAttributeUse.hpp>
#include <xercesc/framework/psvi/XSWildcard.hpp>
#include <xercesc/validators/schema/XercesAttGroupInfo.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSAttributeGroupDefinition.hpp>

namespace pyxerces {

void XSAttributeGroupDefinition_init(void) {
	//! xercesc::XSAttributeGroupDefinition
	boost::python::class_<xercesc::XSAttributeGroupDefinition, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSAttributeGroupDefinition", boost::python::init<xercesc::XercesAttGroupInfo* const, xercesc::XSAttributeUseList* const, xercesc:: XSWildcard* const, xercesc::XSAnnotation* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getName", &xercesc::XSAttributeGroupDefinition::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespace", &xercesc::XSAttributeGroupDefinition::getNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespaceItem", &xercesc::XSAttributeGroupDefinition::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributeUses", &xercesc::XSAttributeGroupDefinition::getAttributeUses, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributeWildcard", &xercesc::XSAttributeGroupDefinition::getAttributeWildcard, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAnnotation", &xercesc::XSAttributeGroupDefinition::getAnnotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
