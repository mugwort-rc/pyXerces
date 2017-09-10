/*
 * XSTypeDefinition.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XSTypeDefinition.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSTypeDefinition.hpp>

#include "../../util/XMLString.h"

namespace pyxerces {

class XSTypeDefinitionWrapper
: public xercesc::XSTypeDefinition, public boost::python::wrapper<xercesc::XSTypeDefinition>
{
public:
XSTypeDefinitionWrapper(xercesc::XSTypeDefinition::TYPE_CATEGORY typeCategory, xercesc::XSTypeDefinition* const xsBaseType, xercesc::XSModel* const xsModel, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::XSTypeDefinition(typeCategory, xsBaseType, xsModel, manager)
{}

const XMLCh* getName() const {
	return this->get_override("getName")();
}

const XMLCh* getNamespace() const {
	return this->get_override("getNamespace")();
}

xercesc::XSNamespaceItem *getNamespaceItem() {
	return this->get_override("getNamespaceItem")();
}

xercesc::XSTypeDefinition *getBaseType() {
	return this->get_override("getBaseType")();
}

bool getAnonymous() const {
	return this->get_override("getAnonymous")();
}

bool derivedFromType(const xercesc::XSTypeDefinition* const ancestorType) {
	return this->get_override("derivedFromType")(ancestorType);
}

};

class XSTypeDefinitionDefVisitor
: public boost::python::def_visitor<XSTypeDefinitionDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("derivedFrom", &XSTypeDefinitionDefVisitor::derivedFrom)
	;
}

static bool derivedFrom(xercesc::XSTypeDefinition& self, const XMLString& typeNamespace, const XMLString& name) {
	return self.derivedFrom(typeNamespace.ptr(), name.ptr());
}

};

void XSTypeDefinition_init(void) {
	//! xercesc::XSTypeDefinition
	auto XSTypeDefinition = boost::python::class_<XSTypeDefinitionWrapper, boost::noncopyable, boost::python::bases<xercesc::XSObject> >("XSTypeDefinition", boost::python::init<xercesc::XSTypeDefinition::TYPE_CATEGORY, xercesc::XSTypeDefinition* const, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(XSTypeDefinitionDefVisitor())
			.def("getName", &xercesc::XSTypeDefinition::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespace", &xercesc::XSTypeDefinition::getNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespaceItem", &xercesc::XSTypeDefinition::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTypeCategory", &xercesc::XSTypeDefinition::getTypeCategory)
			.def("getBaseType", &xercesc::XSTypeDefinition::getBaseType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isFinal", &xercesc::XSTypeDefinition::isFinal)
			.def("getFinal", &xercesc::XSTypeDefinition::getFinal)
			.def("getAnonymous", &xercesc::XSTypeDefinition::getAnonymous)
			.def("derivedFromType", &xercesc::XSTypeDefinition::derivedFromType)
			.def("derivedFrom", &xercesc::XSTypeDefinition::derivedFrom)
			;
	boost::python::scope XSTypeDefinitionScope = XSTypeDefinition;
	//! xercesc::XSTypeDefinition::TYPE_CATEGORY
	boost::python::enum_<xercesc::XSTypeDefinition::TYPE_CATEGORY>("TYPE_CATEGORY")
			.value("COMPLEX_TYPE", xercesc::XSTypeDefinition::COMPLEX_TYPE)
			.value("SIMPLE_TYPE", xercesc::XSTypeDefinition::SIMPLE_TYPE)
			.export_values()
			;
}

} /* namespace pyxerces */
