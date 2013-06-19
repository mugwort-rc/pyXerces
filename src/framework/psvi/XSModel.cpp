/*
 * XSModel.cpp
 *
 *  Created on: 2013/03/05
 *      Author: mugwort_rc
 */

#include "XSModel.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/common/Grammar.hpp>
#include <xercesc/framework/XMLGrammarPool.hpp>
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSAttributeDeclaration.hpp>
#include <xercesc/framework/psvi/XSAttributeGroupDefinition.hpp>
#include <xercesc/framework/psvi/XSElementDeclaration.hpp>
#include <xercesc/framework/psvi/XSModelGroupDefinition.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSNotationDeclaration.hpp>
#include <xercesc/framework/psvi/XSTypeDefinition.hpp>
#include <xercesc/internal/XSObjectFactory.hpp>
#include <xercesc/validators/common/GrammarResolver.hpp>

#include <xercesc/framework/psvi/XSModel.hpp>

#include "../../util/XMLString.h"

namespace pyxerces {

class XSModelDefVisitor
: public boost::python::def_visitor<XSModelDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getComponentsByNamespace", &XSModelDefVisitor::getComponentsByNamespace, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElementDeclaration", &XSModelDefVisitor::getElementDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getAttributeDeclaration", &XSModelDefVisitor::getAttributeDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getTypeDefinition", &XSModelDefVisitor::getTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getAttributeGroup", &XSModelDefVisitor::getAttributeGroup, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getModelGroupDefinition", &XSModelDefVisitor::getModelGroupDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getNotationDeclaration", &XSModelDefVisitor::getNotationDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getNamespaceItem", &XSModelDefVisitor::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::XSNamedMap<xercesc::XSObject> *getComponentsByNamespace(xercesc::XSModel& self, xercesc::XSConstants::COMPONENT_TYPE objectType, const XMLString& compNamespace) {
	return self.getComponentsByNamespace(objectType, compNamespace.ptr());
}

static xercesc::XSElementDeclaration *getElementDeclaration(xercesc::XSModel& self, const XMLString& name, const XMLString& compNamespace) {
	return self.getElementDeclaration(name.ptr(), compNamespace.ptr());
}

static xercesc::XSAttributeDeclaration *getAttributeDeclaration(xercesc::XSModel& self, const XMLString& name, const XMLString& compNamespace) {
	return self.getAttributeDeclaration(name.ptr(), compNamespace.ptr());
}

static xercesc::XSTypeDefinition *getTypeDefinition(xercesc::XSModel& self, const XMLString& name, const XMLString& compNamespace) {
	return self.getTypeDefinition(name.ptr(), compNamespace.ptr());
}

static xercesc::XSAttributeGroupDefinition *getAttributeGroup(xercesc::XSModel& self, const XMLString& name, const XMLString& compNamespace) {
	return self.getAttributeGroup(name.ptr(), compNamespace.ptr());
}

static xercesc::XSModelGroupDefinition *getModelGroupDefinition(xercesc::XSModel& self, const XMLString& name, const XMLString& compNamespace) {
	return self.getModelGroupDefinition(name.ptr(), compNamespace.ptr());
}

static xercesc::XSNotationDeclaration *getNotationDeclaration(xercesc::XSModel& self, const XMLString& name, const XMLString& compNamespace) {
	return self.getNotationDeclaration(name.ptr(), compNamespace.ptr());
}

static xercesc::XSNamespaceItem* getNamespaceItem(xercesc::XSModel& self, const XMLString& key) {
	return self.getNamespaceItem(key.ptr());
}

};

void XSModel_init(void) {
	//! xercesc::XSModel
	boost::python::class_<xercesc::XSModel, boost::noncopyable>("XSModel", boost::python::init<xercesc::XMLGrammarPool*, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<xercesc::XMLGrammarPool*, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<xercesc::XSModel*, xercesc::GrammarResolver*, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(XSModelDefVisitor())
			.def("getNamespaces", &xercesc::XSModel::getNamespaces, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNamespaceItems", &xercesc::XSModel::getNamespaceItems, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getComponents", &xercesc::XSModel::getComponents, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getComponentsByNamespace", &xercesc::XSModel::getComponentsByNamespace, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAnnotations", &xercesc::XSModel::getAnnotations, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementDeclaration", &xercesc::XSModel::getElementDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributeDeclaration", &xercesc::XSModel::getAttributeDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTypeDefinition", &xercesc::XSModel::getTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributeGroup", &xercesc::XSModel::getAttributeGroup, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getModelGroupDefinition", &xercesc::XSModel::getModelGroupDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNotationDeclaration", &xercesc::XSModel::getNotationDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getXSObjectById", &xercesc::XSModel::getXSObjectById, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURIStringPool", &xercesc::XSModel::getURIStringPool, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNamespaceItem", &xercesc::XSModel::getNamespaceItem, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getXSObject", &xercesc::XSModel::getXSObject, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
