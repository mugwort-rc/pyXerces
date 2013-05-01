/*
 * XMLSchemaDescription.cpp
 *
 *  Created on: 2013/03/05
 *      Author: mugwort_rc
 */

#include "XMLSchemaDescription.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLSchemaDescription.hpp>

#include "../internal/XSerializable.h"
#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class XMLSchemaDescriptionDefVisitor
: public boost::python::def_visitor<XMLSchemaDescriptionDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setTargetNamespace", &XMLSchemaDescriptionDefVisitor<STR>::setTargetNamespace)
	.def("setLocationHints", &XMLSchemaDescriptionDefVisitor<STR>::setLocationHints)
	;
}

static void setTargetNamespace(xercesc::XMLSchemaDescription& self, const STR ns) {
	XMLString buff(ns);
	self.setTargetNamespace(buff.ptr());
}

static void setLocationHints(xercesc::XMLSchemaDescription& self, const STR hints) {
	XMLString buff(hints);
	self.setLocationHints(buff.ptr());
}

};

class XMLSchemaDescriptionWrapper
: public xercesc::XMLSchemaDescription, public boost::python::wrapper<xercesc::XMLSchemaDescription>
{
public:
xercesc::Grammar::GrammarType getGrammarType() const {
    if(boost::python::override getGrammarType = this->get_override("getGrammarType")){
    	return getGrammarType();
    }else{
    	return xercesc::XMLSchemaDescription::getGrammarType();
    }
}

ContextType getContextType() const {
	return this->get_override("getContextType")();
}

const XMLCh* getTargetNamespace() const {
	return this->get_override("getTargetNamespace")();
}

const xercesc::RefArrayVectorOf<XMLCh>* getLocationHints() const {
	return this->get_override("getLocationHints")();
}

const xercesc::QName* getTriggeringComponent() const {
	return this->get_override("getTriggeringComponent")();
}

const xercesc::QName* getEnclosingElementName() const {
	return this->get_override("getEnclosingElementName")();
}

const xercesc::XMLAttDef* getAttributes() const {
	return this->get_override("getAttributes")();
}

void setContextType(ContextType type) {
	this->get_override("setContextType")(type);
}

void setTargetNamespace(const XMLCh* const target) {
	this->get_override("setTargetNamespace")(XMLString(target));
}

void setLocationHints(const XMLCh* const hints) {
	this->get_override("setLocationHints")(XMLString(hints));
}

void setTriggeringComponent(xercesc::QName* const component) {
	this->get_override("setTriggeringComponent")(boost::python::ptr(component));
}

void setEnclosingElementName(xercesc::QName* const name) {
	this->get_override("setEnclosingElementName")(boost::python::ptr(name));
}

void setAttributes(xercesc::XMLAttDef* const attr) {
	this->get_override("setAttributes")(boost::python::ptr(attr));
}

// ---------- XMLGrammarDescription ----------
const XMLCh* getGrammarKey() const {
	return this->get_override("getGrammarKey")();
}

PyDECL_XSERIALIZABLEWrapper;

};

void XMLSchemaDescription_init(void) {
	//! xercesc::XMLSchemaDescription
	auto XMLSchemaDescription = boost::python::class_<XMLSchemaDescriptionWrapper, boost::noncopyable, boost::python::bases<xercesc::XMLGrammarDescription> >("XMLSchemaDescription")
			.def(XMLSchemaDescriptionDefVisitor<XMLString&>())
			.def(XMLSchemaDescriptionDefVisitor<char*>())
			.def("getGrammarType", &xercesc::XMLSchemaDescription::getGrammarType)
			.def("getContextType", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::getContextType))
			.def("getTargetNamespace", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::getTargetNamespace), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLocationHints", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::getLocationHints), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTriggeringComponent", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::getTriggeringComponent), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEnclosingElementName", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::getEnclosingElementName), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributes", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::getAttributes), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setContextType", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::setContextType))
			.def("setTargetNamespace", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::setTargetNamespace))
			.def("setLocationHints", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::setLocationHints))
			.def("setTriggeringComponent", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::setTriggeringComponent))
			.def("setEnclosingElementName", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::setEnclosingElementName))
			.def("setAttributes", boost::python::pure_virtual(&xercesc::XMLSchemaDescription::setAttributes))
			PyDECL_XSERIALIZABLE(XMLSchemaDescription)
			;
	boost::python::scope XMLSchemaDescriptionScope = XMLSchemaDescription;
	//! xercesc::XMLSchemaDescription::ContextType
	boost::python::enum_<xercesc::XMLSchemaDescription::ContextType>("ContextType")
			.value("CONTEXT_INCLUDE", xercesc::XMLSchemaDescription::CONTEXT_INCLUDE)
			.value("CONTEXT_REDEFINE", xercesc::XMLSchemaDescription::CONTEXT_REDEFINE)
			.value("CONTEXT_IMPORT", xercesc::XMLSchemaDescription::CONTEXT_IMPORT)
			.value("CONTEXT_PREPARSE", xercesc::XMLSchemaDescription::CONTEXT_PREPARSE)
			.value("CONTEXT_INSTANCE", xercesc::XMLSchemaDescription::CONTEXT_INSTANCE)
			.value("CONTEXT_ELEMENT", xercesc::XMLSchemaDescription::CONTEXT_ELEMENT)
			.value("CONTEXT_ATTRIBUTE", xercesc::XMLSchemaDescription::CONTEXT_ATTRIBUTE)
			.value("CONTEXT_XSITYPE", xercesc::XMLSchemaDescription::CONTEXT_XSITYPE)
			.value("CONTEXT_UNKNOWN", xercesc::XMLSchemaDescription::CONTEXT_UNKNOWN)
			.export_values()
			;
}

} /* namespace pyxerces */
