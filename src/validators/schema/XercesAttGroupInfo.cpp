/*
 * XercesAttGroupInfo.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XercesAttGroupInfo.h"

#include <boost/python.hpp>
#include <xercesc/validators/schema/XercesAttGroupInfo.hpp>

#include "../../internal/XSerializable.h"
#include "../../util/XMLString.h"

namespace pyxerces {

template <class STR>
class XercesAttGroupInfoDefVisitor
: public boost::python::def_visitor<XercesAttGroupInfoDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getAttDef", &XercesAttGroupInfoDefVisitor<STR>::getAttDef, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("containsAttribute", &XercesAttGroupInfoDefVisitor<STR>::containsAttribute)
	;
}

static xercesc::SchemaAttDef* getAttDef(xercesc::XercesAttGroupInfo& self, const STR& baseName, const int urlId) {
	XMLString buff(baseName);
	return const_cast<xercesc::SchemaAttDef*>(self.getAttDef(buff.ptr(), urlId));
}

static bool containsAttribute(xercesc::XercesAttGroupInfo& self, const STR& name, const int urlId) {
	XMLString buff(name);
	return self.containsAttribute(buff.ptr(), urlId);
}

};

void XercesAttGroupInfo_init(void) {
	//! xercesc::XercesAttGroupInfo
	boost::python::class_<xercesc::XercesAttGroupInfo, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XercesAttGroupInfo", boost::python::init<unsigned int, unsigned int, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(XercesAttGroupInfoDefVisitor<XMLString>())
			.def(XercesAttGroupInfoDefVisitor<std::string>())
			.def("containsTypeWithId", &xercesc::XercesAttGroupInfo::containsTypeWithId)
			.def("attributeCount", &xercesc::XercesAttGroupInfo::attributeCount)
			.def("anyAttributeCount", &xercesc::XercesAttGroupInfo::anyAttributeCount)
			.def("getNameId", &xercesc::XercesAttGroupInfo::getNameId)
			.def("getNamespaceId", &xercesc::XercesAttGroupInfo::getNamespaceId)
			.def("attributeAt", static_cast<xercesc::SchemaAttDef*(xercesc::XercesAttGroupInfo::*)(const XMLSize_t)>(&xercesc::XercesAttGroupInfo::attributeAt), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("anyAttributeAt", static_cast<xercesc::SchemaAttDef*(xercesc::XercesAttGroupInfo::*)(const XMLSize_t)>(&xercesc::XercesAttGroupInfo::anyAttributeAt), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getCompleteWildCard", static_cast<xercesc::SchemaAttDef*(xercesc::XercesAttGroupInfo::*)() const>(&xercesc::XercesAttGroupInfo::getCompleteWildCard), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttDef", static_cast<const xercesc::SchemaAttDef*(xercesc::XercesAttGroupInfo::*)(const XMLCh* const, const int) const>(&xercesc::XercesAttGroupInfo::getAttDef), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setTypeWithId", &xercesc::XercesAttGroupInfo::setTypeWithId)
			.def("addAttDef", &xercesc::XercesAttGroupInfo::addAttDef)
			.def("addAnyAttDef", &xercesc::XercesAttGroupInfo::addAnyAttDef)
			.def("setCompleteWildCard", &xercesc::XercesAttGroupInfo::setCompleteWildCard)
			.def("containsAttribute", &xercesc::XercesAttGroupInfo::containsAttribute)
			PyDECL_XSERIALIZABLE(XercesAttGroupInfo)
			;
}

} /* namespace pyxerces */
