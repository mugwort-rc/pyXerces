/*
 * ValidationContext.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "ValidationContext.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/XMLRefInfo.hpp>
#include <xercesc/validators/DTD/DTDEntityDecl.hpp>
#include <xercesc/validators/datatype/DatatypeValidator.hpp>
#include <xercesc/internal/ElemStack.hpp>
#include <xercesc/validators/schema/NamespaceScope.hpp>
#include <xercesc/internal/XMLScanner.hpp>

#include <xercesc/framework/ValidationContext.hpp>

namespace pyxerces {

void ValidationContext_init(void) {
	//! xercesc::ValidationContext
	boost::python::class_<xercesc::ValidationContext, boost::noncopyable>("ValidationContext", boost::python::no_init)
			.def("getIdRefList", &xercesc::ValidationContext::getIdRefList, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setIdRefList", &xercesc::ValidationContext::setIdRefList)
			.def("clearIdRefList", &xercesc::ValidationContext::clearIdRefList)
			.def("addId", &xercesc::ValidationContext::addId)
			.def("addIdRef", &xercesc::ValidationContext::addIdRef)
			.def("toCheckIdRefList", &xercesc::ValidationContext::toCheckIdRefList)
			.def("getEntityDeclPool", &xercesc::ValidationContext::getEntityDeclPool, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setEntityDeclPool", &xercesc::ValidationContext::setEntityDeclPool, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("checkEntity", &xercesc::ValidationContext::checkEntity)
			.def("getValidatingMemberType", &xercesc::ValidationContext::getValidatingMemberType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setValidatingMemberType", &xercesc::ValidationContext::setValidatingMemberType)
			.def("isPrefixUnknown", &xercesc::ValidationContext::isPrefixUnknown)
			.def("setElemStack", &xercesc::ValidationContext::setElemStack)
			.def("getURIForPrefix", &xercesc::ValidationContext::getURIForPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setScanner", &xercesc::ValidationContext::setScanner)
			.def("setNamespaceScope", &xercesc::ValidationContext::setNamespaceScope)
			;
}

} /* namespace pyxerces */
