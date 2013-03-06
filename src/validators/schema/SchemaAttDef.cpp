/*
 * SchemaAttDef.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "SchemaAttDef.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/datatype/DatatypeValidator.hpp>
#include <xercesc/util/QName.hpp>
#include <xercesc/validators/schema/ComplexTypeInfo.hpp>

#include <xercesc/validators/schema/SchemaAttDef.hpp>

#include "../../internal/XSerializable.h"

namespace pyxerces {

void SchemaAttDef_init(void) {
	//! xercesc::SchemaAttDef
	boost::python::class_<xercesc::SchemaAttDef, boost::noncopyable>("SchemaAttDef", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, const int, boost::python::optional<const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, const int, const XMLCh* const, const xercesc::XMLAttDef::AttTypes, const xercesc::XMLAttDef::DefAttTypes, boost::python::optional<const XMLCh* const, xercesc::MemoryManager* const> >())
			.def(boost::python::init<boost::python::optional<const xercesc::SchemaAttDef*> >())
			.def("getFullName", &xercesc::SchemaAttDef::getFullName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("reset", &xercesc::SchemaAttDef::reset)
			.def("getElemId", &xercesc::SchemaAttDef::getElemId)
			.def("getAttName", &xercesc::SchemaAttDef::getAttName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDatatypeValidator", &xercesc::SchemaAttDef::getDatatypeValidator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNamespaceList", &xercesc::SchemaAttDef::getNamespaceList, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getBaseAttDecl", static_cast<xercesc::SchemaAttDef*(xercesc::SchemaAttDef::*)(void)>(&xercesc::SchemaAttDef::getBaseAttDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPSVIScope", &xercesc::SchemaAttDef::getPSVIScope)
			.def("setElemId", &xercesc::SchemaAttDef::setElemId)
			.def("setAttName", &xercesc::SchemaAttDef::setAttName)
			.def("setDatatypeValidator", &xercesc::SchemaAttDef::setDatatypeValidator)
			.def("setBaseAttDecl", &xercesc::SchemaAttDef::setBaseAttDecl)
			.def("setPSVIScope", &xercesc::SchemaAttDef::setPSVIScope)
			.def("setNamespaceList", &xercesc::SchemaAttDef::setNamespaceList)
			.def("resetNamespaceList", &xercesc::SchemaAttDef::resetNamespaceList)
			.def("setEnclosingCT", &xercesc::SchemaAttDef::setEnclosingCT)
			PyDECL_XSERIALIZABLE(SchemaAttDef)
			;
}

} /* namespace pyxerces */
