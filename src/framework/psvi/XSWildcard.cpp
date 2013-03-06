/*
 * XSWildcard.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "XSWildcard.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/validators/schema/SchemaAttDef.hpp>
#include <xercesc/validators/common/ContentSpecNode.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSWildcard.hpp>

namespace pyxerces {

void XSWildcard_init(void) {
	//! xercesc::XSWildcard
	auto XSWildcard = boost::python::class_<xercesc::XSWildcard, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSWildcard", boost::python::init<xercesc::SchemaAttDef* const, xercesc::XSAnnotation* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const xercesc::ContentSpecNode* const, xercesc::XSAnnotation* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getConstraintType", &xercesc::XSWildcard::getConstraintType)
			.def("getNsConstraintList", &xercesc::XSWildcard::getNsConstraintList, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getProcessContents", &xercesc::XSWildcard::getProcessContents)
			.def("getAnnotation", &xercesc::XSWildcard::getAnnotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
	boost::python::scope XSWildcardScope = XSWildcard;
	//! xercesc::XSWildcard::NAMESPACE_CONSTRAINT
	boost::python::enum_<xercesc::XSWildcard::NAMESPACE_CONSTRAINT>("NAMESPACE_CONSTRAINT")
			.value("NSCONSTRAINT_ANY", xercesc::XSWildcard::NSCONSTRAINT_ANY)
			.value("NSCONSTRAINT_NOT", xercesc::XSWildcard::NSCONSTRAINT_NOT)
			.value("NSCONSTRAINT_DERIVATION_LIST", xercesc::XSWildcard::NSCONSTRAINT_DERIVATION_LIST)
			.export_values()
			;
	//! xercesc::XSWildcard::PROCESS_CONTENTS
	boost::python::enum_<xercesc::XSWildcard::PROCESS_CONTENTS>("PROCESS_CONTENTS")
			.value("PC_STRICT", xercesc::XSWildcard::PC_STRICT)
			.value("PC_SKIP", xercesc::XSWildcard::PC_SKIP)
			.value("PC_LAX", xercesc::XSWildcard::PC_LAX)
			.export_values()
			;
}

} /* namespace pyxerces */
