/*
 * XSModelGroup.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XSModelGroup.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSParticle.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSModelGroup.hpp>

namespace pyxerces {

void XSModelGroup_init(void) {
	//! xercesc::XSModelGroup
	auto XSModelGroup = boost::python::class_<xercesc::XSModelGroup, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSModelGroup", boost::python::init<xercesc::XSModelGroup::COMPOSITOR_TYPE, xercesc::XSParticleList* const, xercesc::XSAnnotation* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getCompositor", &xercesc::XSModelGroup::getCompositor)
			.def("getParticles", &xercesc::XSModelGroup::getParticles, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAnnotation", &xercesc::XSModelGroup::getAnnotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
	boost::python::scope XSModelGroupScope = XSModelGroup;
	//! xercesc::XSModelGroup::COMPOSITOR_TYPE
	boost::python::enum_<xercesc::XSModelGroup::COMPOSITOR_TYPE>("COMPOSITOR_TYPE")
			.value("COMPOSITOR_SEQUENCE", xercesc::XSModelGroup::COMPOSITOR_SEQUENCE)
			.value("COMPOSITOR_CHOICE", xercesc::XSModelGroup::COMPOSITOR_CHOICE)
			.value("COMPOSITOR_ALL", xercesc::XSModelGroup::COMPOSITOR_ALL)
			.export_values()
			;
}

} /* namespace pyxerces */
