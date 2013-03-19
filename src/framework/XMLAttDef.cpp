/*
 * XMLAttDef.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XMLAttDef.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/XMLAttr.hpp>

#include <xercesc/framework/XMLAttDef.hpp>

#include "../internal/XSerializable.h"
#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class XMLAttDefDefVisitor
: public boost::python::def_visitor<XMLAttDefDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setValue", &XMLAttDefDefVisitor<STR>::setValue)
	.def("setEnumeration", &XMLAttDefDefVisitor<STR>::setEnumeration)
	;
}

static void setValue(xercesc::XMLAttDef& self, const STR& value) {
	XMLString buff(value);
	self.setValue(buff.ptr());
}

static void setEnumeration(xercesc::XMLAttDef& self, const STR& newValue) {
	XMLString buff(newValue);
	self.setValue(buff.ptr());
}

};

class XMLAttDefWrapper
: public xercesc::XMLAttDef, public boost::python::wrapper<xercesc::XMLAttDef>
{
public:
const XMLCh* getFullName() const {
	return this->get_override("getFullName")();
}

void reset() {
	this->get_override("reset")();
}

PyDECL_XSERIALIZABLEWrapper

};

//! XMLAttDef
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLAttDefGetAttTypeString, xercesc::XMLAttDef::getAttTypeString, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLAttDefGetDefAttTypeString, xercesc::XMLAttDef::getDefAttTypeString, 1, 2)

void XMLAttDef_init(void) {
	//! xercesc::XMLAttDef
	auto XMLAttDef = boost::python::class_<XMLAttDefWrapper, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLAttDef")
			.def_readonly("fgInvalidAttrId", &xercesc::XMLAttDef::fgInvalidAttrId)
			.def("getAttTypeString", &xercesc::XMLAttDef::getAttTypeString, XMLAttDefGetAttTypeString()[boost::python::return_value_policy<boost::python::return_by_value>()])
			.def("getDefAttTypeString", &xercesc::XMLAttDef::getDefAttTypeString, XMLAttDefGetDefAttTypeString()[boost::python::return_value_policy<boost::python::return_by_value>()])
			.staticmethod("getAttTypeString")
			.staticmethod("getDefAttTypeString")
			.def(XMLAttDefDefVisitor<XMLString>())
			.def(XMLAttDefDefVisitor<std::string>())
			.def("getFullName", boost::python::pure_virtual(&xercesc::XMLAttDef::getFullName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("reset", boost::python::pure_virtual(&xercesc::XMLAttDef::reset))
			.def("getDefaultType", &xercesc::XMLAttDef::getDefaultType)
			.def("getEnumeration", &xercesc::XMLAttDef::getEnumeration, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getId", &xercesc::XMLAttDef::getId)
			.def("getType", &xercesc::XMLAttDef::getType)
			.def("getValue", &xercesc::XMLAttDef::getValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getCreateReason", &xercesc::XMLAttDef::getCreateReason)
			.def("isExternal", &xercesc::XMLAttDef::isExternal)
			.def("getMemoryManager", &xercesc::XMLAttDef::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setDefaultType", &xercesc::XMLAttDef::setDefaultType)
			.def("setId", &xercesc::XMLAttDef::setId)
			.def("setType", &xercesc::XMLAttDef::setType)
			.def("setValue", &xercesc::XMLAttDef::setValue)
			.def("setEnumeration", &xercesc::XMLAttDef::setEnumeration)
			.def("setCreateReason", &xercesc::XMLAttDef::setCreateReason)
			.def("setExternalAttDeclaration", &xercesc::XMLAttDef::setExternalAttDeclaration)
			PyDECL_XSERIALIZABLE(XMLAttDef)
			;
	boost::python::scope XMLAttDefScope = XMLAttDef;
	//! xercesc::XMLAttDef::AttTypes
	boost::python::enum_<xercesc::XMLAttDef::AttTypes>("AttTypes")
			.value("CData", xercesc::XMLAttDef::CData)
			.value("ID", xercesc::XMLAttDef::ID)
			.value("IDRef", xercesc::XMLAttDef::IDRef)
			.value("IDRefs", xercesc::XMLAttDef::IDRefs)
			.value("Entity", xercesc::XMLAttDef::Entity)
			.value("Entities", xercesc::XMLAttDef::Entities)
			.value("NmToken", xercesc::XMLAttDef::NmToken)
			.value("NmTokens", xercesc::XMLAttDef::NmTokens)
			.value("Notation", xercesc::XMLAttDef::Notation)
			.value("Enumeration", xercesc::XMLAttDef::Enumeration)
			.value("Simple", xercesc::XMLAttDef::Simple)
			.value("Any_Any", xercesc::XMLAttDef::Any_Any)
			.value("Any_Other", xercesc::XMLAttDef::Any_Other)
			.value("Any_List", xercesc::XMLAttDef::Any_List)
			.value("AttTypes_Count", xercesc::XMLAttDef::AttTypes_Count)
			.value("AttTypes_Min", xercesc::XMLAttDef::AttTypes_Min)
			.value("AttTypes_Max", xercesc::XMLAttDef::AttTypes_Max)
			.value("AttTypes_Unknown", xercesc::XMLAttDef::AttTypes_Unknown)
			.export_values()
			;
	//! xercesc::XMLAttDef::DefAttTypes
	boost::python::enum_<xercesc::XMLAttDef::DefAttTypes>("DefAttTypes")
			.value("Default", xercesc::XMLAttDef::Default)
			.value("Fixed", xercesc::XMLAttDef::Fixed)
			.value("Required", xercesc::XMLAttDef::Required)
			.value("Required_And_Fixed", xercesc::XMLAttDef::Required_And_Fixed)
			.value("Implied", xercesc::XMLAttDef::Implied)
			.value("ProcessContents_Skip", xercesc::XMLAttDef::ProcessContents_Skip)
			.value("ProcessContents_Lax", xercesc::XMLAttDef::ProcessContents_Lax)
			.value("ProcessContents_Strict", xercesc::XMLAttDef::ProcessContents_Strict)
			.value("Prohibited", xercesc::XMLAttDef::Prohibited)
			.value("DefAttTypes_Count", xercesc::XMLAttDef::DefAttTypes_Count)
			.value("DefAttTypes_Min", xercesc::XMLAttDef::DefAttTypes_Min)
			.value("DefAttTypes_Max", xercesc::XMLAttDef::DefAttTypes_Max)
			.value("DefAttTypes_Unknown", xercesc::XMLAttDef::DefAttTypes_Unknown)
			.export_values()
			;
	//! xercesc::XMLAttDef::CreateReasons
	boost::python::enum_<xercesc::XMLAttDef::CreateReasons>("CreateReasons")
			.value("NoReason", xercesc::XMLAttDef::NoReason)
			.value("JustFaultIn", xercesc::XMLAttDef::JustFaultIn)
			.export_values()
			;
}

} /* namespace pyxerces */
