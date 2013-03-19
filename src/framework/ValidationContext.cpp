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

#include "../util/XMLString.h"

namespace pyxerces {

class ValidationContextWrapper
: public xercesc::ValidationContext, public boost::python::wrapper<xercesc::ValidationContext>
{
public:
xercesc::RefHashTableOf<xercesc::XMLRefInfo>* getIdRefList() const {
	return this->get_override("getIdRefList")();
}

void setIdRefList(xercesc::RefHashTableOf<xercesc::XMLRefInfo>* const table) {
	this->get_override("setIdRefList")(boost::python::ptr(table));
}

void clearIdRefList() {
	this->get_override("clearIdRefList")();
}

void addId(const XMLCh* const id) {
	this->get_override("addId")(XMLString(id));
}

void addIdRef(const XMLCh* const ref) {
	this->get_override("addIdRef")(XMLString(ref));
}

void toCheckIdRefList(bool check) {
	this->get_override("toCheckIdRefList")(check);
}

const xercesc::NameIdPool<xercesc::DTDEntityDecl>* getEntityDeclPool() const {
	return this->get_override("getEntityDeclPool")();
}

const xercesc::NameIdPool<xercesc::DTDEntityDecl>* setEntityDeclPool(const xercesc::NameIdPool<xercesc::DTDEntityDecl>* const pool) {
	return this->get_override("setEntityDeclPool")(boost::python::ptr(pool));
}

void checkEntity(const XMLCh* const entity) const {
	this->get_override("checkEntity")(XMLString(entity));
}

xercesc::DatatypeValidator* getValidatingMemberType() const {
	return this->get_override("getValidatingMemberType")();
}

void setValidatingMemberType(xercesc::DatatypeValidator* validatingMemberType) {
	this->get_override("setValidatingMemberType")(boost::python::ptr(validatingMemberType));
}

bool isPrefixUnknown(XMLCh* prefix) {
	if(boost::python::override isPrefixUnknown = this->get_override("isPrefixUnknown")){
		return isPrefixUnknown(XMLString(prefix));
	}else{
		return xercesc::ValidationContext::isPrefixUnknown(prefix);
	}
}

void setElemStack(xercesc::ElemStack* elemStack) {
	if(boost::python::override setElemStack = this->get_override("setElemStack")){
		setElemStack(boost::python::ptr(elemStack));
	}else{
		xercesc::ValidationContext::setElemStack(elemStack);
	}
}

const XMLCh* getURIForPrefix(XMLCh* prefix) {
	if(boost::python::override getURIForPrefix = this->get_override("getURIForPrefix")){
		return getURIForPrefix(XMLString(prefix));
	}else{
		return xercesc::ValidationContext::getURIForPrefix(prefix);
	}
}

void setScanner(xercesc::XMLScanner* scanner) {
	if(boost::python::override setScanner = this->get_override("setScanner")){
		setScanner(boost::python::ptr(scanner));
	}else{
		xercesc::ValidationContext::setScanner(scanner);
	}
}

void setNamespaceScope(xercesc::NamespaceScope* nsStack) {
	if(boost::python::override setNamespaceScope = this->get_override("setNamespaceScope")){
		setNamespaceScope(boost::python::ptr(nsStack));
	}else{
		xercesc::ValidationContext::setNamespaceScope(nsStack);
	}
}

};

void ValidationContext_init(void) {
	//! xercesc::ValidationContext
	boost::python::class_<ValidationContextWrapper, boost::noncopyable>("ValidationContext")
			.def("getIdRefList", boost::python::pure_virtual(&xercesc::ValidationContext::getIdRefList), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setIdRefList", boost::python::pure_virtual(&xercesc::ValidationContext::setIdRefList))
			.def("clearIdRefList", boost::python::pure_virtual(&xercesc::ValidationContext::clearIdRefList))
			.def("addId", boost::python::pure_virtual(&xercesc::ValidationContext::addId))
			.def("addIdRef", boost::python::pure_virtual(&xercesc::ValidationContext::addIdRef))
			.def("toCheckIdRefList", boost::python::pure_virtual(&xercesc::ValidationContext::toCheckIdRefList))
			.def("getEntityDeclPool", boost::python::pure_virtual(&xercesc::ValidationContext::getEntityDeclPool), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setEntityDeclPool", boost::python::pure_virtual(&xercesc::ValidationContext::setEntityDeclPool), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("checkEntity", boost::python::pure_virtual(&xercesc::ValidationContext::checkEntity))
			.def("getValidatingMemberType", boost::python::pure_virtual(&xercesc::ValidationContext::getValidatingMemberType), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setValidatingMemberType", boost::python::pure_virtual(&xercesc::ValidationContext::setValidatingMemberType))
			.def("isPrefixUnknown", boost::python::pure_virtual(&xercesc::ValidationContext::isPrefixUnknown))
			.def("setElemStack", boost::python::pure_virtual(&xercesc::ValidationContext::setElemStack))
			.def("getURIForPrefix", boost::python::pure_virtual(&xercesc::ValidationContext::getURIForPrefix), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setScanner", boost::python::pure_virtual(&xercesc::ValidationContext::setScanner))
			.def("setNamespaceScope", boost::python::pure_virtual(&xercesc::ValidationContext::setNamespaceScope))
			;
}

} /* namespace pyxerces */
