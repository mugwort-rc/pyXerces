/*
 * XSObject.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XSObject.h"

#include <boost/python.hpp>

//! for forward declarations
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSAttributeDeclaration.hpp>
#include <xercesc/framework/psvi/XSAttributeGroupDefinition.hpp>
#include <xercesc/framework/psvi/XSAttributeUse.hpp>
#include <xercesc/framework/psvi/XSComplexTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSElementDeclaration.hpp>
#include <xercesc/framework/psvi/XSFacet.hpp>
#include <xercesc/framework/psvi/XSModelGroup.hpp>
#include <xercesc/framework/psvi/XSModelGroupDefinition.hpp>
#include <xercesc/framework/psvi/XSMultiValueFacet.hpp>
#include <xercesc/framework/psvi/XSNamedMap.hpp>
#include <xercesc/framework/psvi/XSNotationDeclaration.hpp>
#include <xercesc/framework/psvi/XSParticle.hpp>
#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSWildcard.hpp>

#include <xercesc/framework/psvi/XSObject.hpp>

namespace pyxerces {

class XSObjectDefVisitor
: public boost::python::def_visitor<XSObjectDefVisitor>
{
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("toXSAnnotation", &XSObjectDefVisitor::toXSAnnotation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSAttributeDeclaration", &XSObjectDefVisitor::toXSAttributeDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSAttributeGroupDefinition", &XSObjectDefVisitor::toXSAttributeGroupDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSAttributeUse", &XSObjectDefVisitor::toXSAttributeUse, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSComplexTypeDefinition", &XSObjectDefVisitor::toXSComplexTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSElementDeclaration", &XSObjectDefVisitor::toXSElementDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSFacet", &XSObjectDefVisitor::toXSFacet, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSModelGroup", &XSObjectDefVisitor::toXSModelGroup, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSModelGroupDefinition", &XSObjectDefVisitor::toXSModelGroupDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSMultiValueFacet", &XSObjectDefVisitor::toXSMultiValueFacet, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSNotationDeclaration", &XSObjectDefVisitor::toXSNotationDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSObject", &XSObjectDefVisitor::toXSObject, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSParticle", &XSObjectDefVisitor::toXSParticle, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSSimpleTypeDefinition", &XSObjectDefVisitor::toXSSimpleTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSTypeDefinition", &XSObjectDefVisitor::toXSTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toXSWildcard", &XSObjectDefVisitor::toXSWildcard, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

xercesc::XSAnnotation* toXSAnnotation(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::ANNOTATION){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSAnnotation*>(&self);
}

xercesc::XSAttributeDeclaration* toXSAttributeDeclaration(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::ATTRIBUTE_DECLARATION){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSAttributeDeclaration*>(&self);
}

xercesc::XSAttributeGroupDefinition* toXSAttributeGroupDefinition(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::ATTRIBUTE_GROUP_DEFINITION){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSAttributeGroupDefinition*>(&self);
}

xercesc::XSAttributeUse* toXSAttributeUse(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::ATTRIBUTE_USE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSAttributeUse*>(&self);
}

xercesc::XSComplexTypeDefinition* toXSComplexTypeDefinition(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::TYPE_DEFINITION || reinterpret_cast<xercesc::XSTypeDefinition*>(&self)->getTypeCategory() != xercesc::XSTypeDefinition::COMPLEX_TYPE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSComplexTypeDefinition*>(&self);
}

xercesc::XSElementDeclaration* toXSElementDeclaration(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::ELEMENT_DECLARATION){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSElementDeclaration*>(&self);
}

xercesc::XSFacet* toXSFacet(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::FACET){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSFacet*>(&self);
}

xercesc::XSModelGroup* toXSModelGroup(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::MODEL_GROUP){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSModelGroup*>(&self);
}

xercesc::XSModelGroupDefinition* toXSModelGroupDefinition(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::MODEL_GROUP_DEFINITION){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSModelGroupDefinition*>(&self);
}

xercesc::XSMultiValueFacet* toXSMultiValueFacet(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::MULTIVALUE_FACET){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSMultiValueFacet*>(&self);
}

xercesc::XSNotationDeclaration* toXSNotationDeclaration(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::NOTATION_DECLARATION){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSNotationDeclaration*>(&self);
}

xercesc::XSObject* toXSObject(xercesc::XSObject& self) {
	return &self;
}

xercesc::XSParticle* toXSParticle(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::PARTICLE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSParticle*>(&self);
}

xercesc::XSSimpleTypeDefinition* toXSSimpleTypeDefinition(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::TYPE_DEFINITION || reinterpret_cast<xercesc::XSTypeDefinition*>(&self)->getTypeCategory() != xercesc::XSTypeDefinition::SIMPLE_TYPE){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSSimpleTypeDefinition*>(&self);
}

xercesc::XSTypeDefinition* toXSTypeDefinition(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::TYPE_DEFINITION){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSTypeDefinition*>(&self);
}

xercesc::XSWildcard* toXSWildcard(xercesc::XSObject& self) {
	if(self.getType() != xercesc::XSConstants::WILDCARD){
		return nullptr;
	}
	return reinterpret_cast<xercesc::XSWildcard*>(&self);
}

};

class XSObjectWrapper
: public xercesc::XSObject, public boost::python::wrapper<xercesc::XSObject>
{
public:
XSObjectWrapper(xercesc::XSConstants::COMPONENT_TYPE compType, xercesc::XSModel* const xsModel, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::XSObject(compType, xsModel, manager)
{}

const XMLCh* getName() const {
	if(boost::python::override getName = this->get_override("getName")){
		return getName();
	}else{
		return xercesc::XSObject::getName();
	}
}

const XMLCh* getNamespace() {
	if(boost::python::override getNamespace = this->get_override("getNamespace")){
		return getNamespace();
	}else{
		return xercesc::XSObject::getNamespace();
	}
}

xercesc::XSNamespaceItem *getNamespaceItem() {
	if(boost::python::override getNamespaceItem = this->get_override("getNamespaceItem")){
		return getNamespaceItem();
	}else{
		return xercesc::XSObject::getNamespaceItem();
	}
}

XMLSize_t getId() const {
	if(boost::python::override getId = this->get_override("getId")){
		return getId();
	}else{
		return xercesc::XSObject::getId();
	}
}

};

void XSObject_init(void) {
	//! xercesc::XSObject
	boost::python::class_<XSObjectWrapper, boost::noncopyable>("XSObject", boost::python::init<xercesc::XSConstants::COMPONENT_TYPE, xercesc::XSModel* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(XSObjectDefVisitor())
			.def("getType", &xercesc::XSObject::getType)
			.def("getName", &xercesc::XSObject::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespace", &xercesc::XSObject::getNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNamespaceItem", &xercesc::XSObject::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getId", &xercesc::XSObject::getId)
			.def("setId", &xercesc::XSObject::setId)
			;
}

} /* namespace pyxerces */
