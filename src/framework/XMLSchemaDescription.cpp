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

template <class STR>
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

static void setTargetNamespace(xercesc::XMLSchemaDescription& self, const STR& ns) {
	XMLString buff(ns);
	self.setTargetNamespace(buff.ptr());
}

static void setLocationHints(xercesc::XMLSchemaDescription& self, const STR& hints) {
	XMLString buff(hints);
	self.setLocationHints(buff.ptr());
}

};

void XMLSchemaDescription_init(void) {
	//! xercesc::XMLSchemaDescription
	auto XMLSchemaDescription = boost::python::class_<xercesc::XMLSchemaDescription, boost::noncopyable, boost::python::bases<xercesc::XMLGrammarDescription> >("XMLSchemaDescription", boost::python::no_init)
			.def(XMLSchemaDescriptionDefVisitor<XMLString>())
			.def(XMLSchemaDescriptionDefVisitor<std::string>())
			.def("getGrammarType", &xercesc::XMLSchemaDescription::getGrammarType)
			.def("getContextType", &xercesc::XMLSchemaDescription::getContextType)
			.def("getTargetNamespace", &xercesc::XMLSchemaDescription::getTargetNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLocationHints", &xercesc::XMLSchemaDescription::getLocationHints, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTriggeringComponent", &xercesc::XMLSchemaDescription::getTriggeringComponent, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEnclosingElementName", &xercesc::XMLSchemaDescription::getEnclosingElementName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributes", &xercesc::XMLSchemaDescription::getAttributes, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setContextType", &xercesc::XMLSchemaDescription::setContextType)
			.def("setTargetNamespace", &xercesc::XMLSchemaDescription::setTargetNamespace)
			.def("setLocationHints", &xercesc::XMLSchemaDescription::setLocationHints)
			.def("setTriggeringComponent", &xercesc::XMLSchemaDescription::setTriggeringComponent)
			.def("setEnclosingElementName", &xercesc::XMLSchemaDescription::setEnclosingElementName)
			.def("setAttributes", &xercesc::XMLSchemaDescription::setAttributes)
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
