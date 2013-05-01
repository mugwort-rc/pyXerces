/*
 * XMLElementDecl.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "XMLElementDecl.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/common/ContentSpecNode.hpp>
#include <xercesc/framework/XMLContentModel.hpp>

#include <xercesc/framework/XMLElementDecl.hpp>

#include "../internal/XSerializable.h"
#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class XMLElementDeclDefVisitor
: public boost::python::def_visitor<XMLElementDeclDefVisitor<STR> > {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setElementName", static_cast<void(*)(xercesc::XMLElementDecl&, const STR, const STR, const int)>(&XMLElementDeclDefVisitor::setElementName))
	.def("setElementName", static_cast<void(*)(xercesc::XMLElementDecl&, const STR, const int)>(&XMLElementDeclDefVisitor::setElementName))
	;
}

static void setElementName(xercesc::XMLElementDecl& self, const STR prefix, const STR localPart, const int uriId) {
	XMLString buff1(prefix), buff2(localPart);
	self.setElementName(buff1.ptr(), buff2.ptr(), uriId);
}

static void setElementName(xercesc::XMLElementDecl& self, const STR rawName, const int uriId) {
	XMLString buff(rawName);
	self.setElementName(buff.ptr(), uriId);
}

};

class XMLElementDeclWrapper
: public xercesc::XMLElementDecl, public boost::python::wrapper<xercesc::XMLElementDecl>
{
public:
xercesc::XMLAttDefList& getAttDefList() const {
	// XXX: reference return
	return this->get_override("getAttDefList")();
}

CharDataOpts getCharDataOpts() const {
	return this->get_override("getCharDataOpts")();
}

bool hasAttDefs() const {
	return this->get_override("hasAttDefs")();
}

const xercesc::ContentSpecNode* getContentSpec() const {
	return this->get_override("getContentSpec")();
}

xercesc::ContentSpecNode* getContentSpec() {
	return this->get_override("getContentSpec")();
}

void setContentSpec(xercesc::ContentSpecNode* toAdopt) {
	this->get_override("setContentSpec")(boost::python::ptr(toAdopt));
}

xercesc::XMLContentModel* getContentModel() {
	return this->get_override("getContentModel")();
}

void setContentModel(xercesc::XMLContentModel* const newModelToAdopt) {
	this->get_override("setContentModel")(boost::python::ptr(newModelToAdopt));
}

const XMLCh* getFormattedContentModel ()   const {
	return this->get_override("getFormattedContentModel")();
}

PyDECL_XSERIALIZABLEWrapper

XMLElementDecl::objectType  getObjectType() const {
	return this->get_override("getObjectType")();
}

};

void XMLElementDecl_init(void) {
	//! xercesc::XMLElementDecl
	auto XMLElementDecl = boost::python::class_<XMLElementDeclWrapper, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLElementDecl")
			.def(XMLElementDeclDefVisitor<XMLString&>())
			.def(XMLElementDeclDefVisitor<char*>())
			.def("getAttDefList", boost::python::pure_virtual(&xercesc::XMLElementDecl::getAttDefList), boost::python::return_internal_reference<>())
			.def("getCharDataOpts", boost::python::pure_virtual(&xercesc::XMLElementDecl::getCharDataOpts))
			.def("hasAttDefs", boost::python::pure_virtual(&xercesc::XMLElementDecl::hasAttDefs))
			.def("getContentSpec", boost::python::pure_virtual(static_cast<xercesc::ContentSpecNode*(xercesc::XMLElementDecl::*)(void)>(&xercesc::XMLElementDecl::getContentSpec)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setContentSpec", boost::python::pure_virtual(&xercesc::XMLElementDecl::setContentSpec))
			.def("getContentModel", boost::python::pure_virtual(&xercesc::XMLElementDecl::getContentModel), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setContentModel", boost::python::pure_virtual(&xercesc::XMLElementDecl::setContentModel))
			.def("getFormattedContentModel", boost::python::pure_virtual(&xercesc::XMLElementDecl::getFormattedContentModel), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getBaseName", static_cast<const XMLCh*(xercesc::XMLElementDecl::*)(void) const>(&xercesc::XMLElementDecl::getBaseName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getURI", &xercesc::XMLElementDecl::getURI)
			.def("getElementName", static_cast<xercesc::QName*(xercesc::XMLElementDecl::*)(void)>(&xercesc::XMLElementDecl::getElementName), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFullName", &xercesc::XMLElementDecl::getFullName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getId", &xercesc::XMLElementDecl::getId)
			.def("isDeclared", &xercesc::XMLElementDecl::isDeclared)
			.def("isExternal", &xercesc::XMLElementDecl::isExternal)
			.def("getMemoryManager", &xercesc::XMLElementDecl::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setElementName", static_cast<void(xercesc::XMLElementDecl::*)(const XMLCh* const, const XMLCh* const, const int)>(&xercesc::XMLElementDecl::setElementName))
			.def("setElementName", static_cast<void(xercesc::XMLElementDecl::*)(const XMLCh* const, const int)>(&xercesc::XMLElementDecl::setElementName))
			.def("setElementName", static_cast<void(xercesc::XMLElementDecl::*)(const xercesc::QName* const)>(&xercesc::XMLElementDecl::setElementName))
			.def("setCreateReason", &xercesc::XMLElementDecl::setCreateReason)
			.def("setId", &xercesc::XMLElementDecl::setId)
			.def("setExternalElemDeclaration", &xercesc::XMLElementDecl::setExternalElemDeclaration)
			PyDECL_XSERIALIZABLE(XMLElementDecl)
			.def("getObjectType", boost::python::pure_virtual(&xercesc::XMLElementDecl::getObjectType))
			.def("storeElementDecl", &xercesc::XMLElementDecl::storeElementDecl)
			.def("loadElementDecl", &xercesc::XMLElementDecl::loadElementDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.staticmethod("storeElementDecl")
			.staticmethod("loadElementDecl")
			.def_readonly("fgInvalidElemId", &xercesc::XMLElementDecl::fgInvalidElemId)
			.def_readonly("fgPCDataElemId", &xercesc::XMLElementDecl::fgPCDataElemId)
			.def_readonly("fgPCDataElemName", &xercesc::XMLElementDecl::fgPCDataElemName)
			;
	boost::python::scope XMLElementDeclScope = XMLElementDecl;
	//! xercesc::XMLElementDecl::CreateReasons
	boost::python::enum_<xercesc::XMLElementDecl::CreateReasons>("CreateReasons")
			.value("NoReason", xercesc::XMLElementDecl::NoReason)
			.value("Declared", xercesc::XMLElementDecl::Declared)
			.value("AttList", xercesc::XMLElementDecl::AttList)
			.value("InContentModel", xercesc::XMLElementDecl::InContentModel)
			.value("AsRootElem", xercesc::XMLElementDecl::AsRootElem)
			.value("JustFaultIn", xercesc::XMLElementDecl::JustFaultIn)
			.export_values()
			;
	//! xercesc::XMLElementDecl::CharDataOpts
	boost::python::enum_<xercesc::XMLElementDecl::CharDataOpts>("CharDataOpts")
			.value("NoCharData", xercesc::XMLElementDecl::NoCharData)
			.value("SpacesOk", xercesc::XMLElementDecl::SpacesOk)
			.value("AllCharData", xercesc::XMLElementDecl::AllCharData)
			.export_values()
			;
	//! xercesc::XMLElementDecl::objectType
	boost::python::enum_<xercesc::XMLElementDecl::objectType>("objectType")
			.value("Schema", xercesc::XMLElementDecl::Schema)
			.value("DTD", xercesc::XMLElementDecl::DTD)
			.value("UnKnown", xercesc::XMLElementDecl::UnKnown)
			;
}

} /* namespace pyxerces */
