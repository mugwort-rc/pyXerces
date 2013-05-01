/*
 * XSNamespaceItem.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XSNamespaceItem.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/psvi/XSAnnotation.hpp>
#include <xercesc/framework/psvi/XSAttributeDeclaration.hpp>
#include <xercesc/framework/psvi/XSAttributeGroupDefinition.hpp>
#include <xercesc/framework/psvi/XSElementDeclaration.hpp>
#include <xercesc/framework/psvi/XSModelGroupDefinition.hpp>
#include <xercesc/framework/psvi/XSNotationDeclaration.hpp>
#include <xercesc/framework/psvi/XSTypeDefinition.hpp>
#include <xercesc/validators/schema/SchemaGrammar.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>

#include <xercesc/framework/psvi/XSNamespaceItem.hpp>

#include "../../util/XMLString.h"

namespace pyxerces {

class XSNamespaceItemDefVisitor
: public boost::python::def_visitor<XSNamespaceItemDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getDocumentLocations", &XSNamespaceItemDefVisitor::getDocumentLocations, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::StringList* getDocumentLocations(xercesc::XSNamespaceItem& self) {
	return const_cast<xercesc::StringList*>(self.getDocumentLocations());
}

};

template <typename STR>
class XSNamespaceItemStringDefVisitor
: public boost::python::def_visitor<XSNamespaceItemStringDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XSNamespaceItem*(*)(xercesc::XSModel* const, const STR, xercesc::MemoryManager* const)>(&XSNamespaceItem_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XSNamespaceItem*(*)(xercesc::XSModel* const, const STR)>(&XSNamespaceItem_fromstring)))
	.def("getElementDeclaration", &XSNamespaceItemStringDefVisitor<STR>::getElementDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getAttributeDeclaration", &XSNamespaceItemStringDefVisitor<STR>::getAttributeDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getTypeDefinition", &XSNamespaceItemStringDefVisitor<STR>::getTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getAttributeGroup", &XSNamespaceItemStringDefVisitor<STR>::getAttributeGroup, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getModelGroupDefinition", &XSNamespaceItemStringDefVisitor<STR>::getModelGroupDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getNotationDeclaration", &XSNamespaceItemStringDefVisitor<STR>::getNotationDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::XSNamespaceItem* XSNamespaceItem_fromstring(xercesc::XSModel* const xsModel, const STR schemaNamespace, xercesc::MemoryManager* const manager) {
	XMLString buff(schemaNamespace);
	return new xercesc::XSNamespaceItem(xsModel, buff.ptr(), manager);
}

static xercesc::XSNamespaceItem* XSNamespaceItem_fromstring(xercesc::XSModel* const xsModel, const STR schemaNamespace) {
	return XSNamespaceItem_fromstring(xsModel, schemaNamespace, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::XSElementDeclaration* getElementDeclaration(xercesc::XSNamespaceItem& self, const STR name) {
	XMLString buff(name);
	return self.getElementDeclaration(buff.ptr());
}

static xercesc::XSAttributeDeclaration* getAttributeDeclaration(xercesc::XSNamespaceItem& self, const STR name) {
	XMLString buff(name);
	return self.getAttributeDeclaration(buff.ptr());
}

static xercesc::XSTypeDefinition* getTypeDefinition(xercesc::XSNamespaceItem& self, const STR name) {
	XMLString buff(name);
	return self.getTypeDefinition(buff.ptr());
}

static xercesc::XSAttributeGroupDefinition* getAttributeGroup(xercesc::XSNamespaceItem& self, const STR name) {
	XMLString buff(name);
	return self.getAttributeGroup(buff.ptr());
}

static xercesc::XSModelGroupDefinition* getModelGroupDefinition(xercesc::XSNamespaceItem& self, const STR name) {
	XMLString buff(name);
	return self.getModelGroupDefinition(buff.ptr());
}

static xercesc::XSNotationDeclaration* getNotationDeclaration(xercesc::XSNamespaceItem& self, const STR name) {
	XMLString buff(name);
	return self.getNotationDeclaration(buff.ptr());
}

};

void XSNamespaceItem_init(void) {
	//! xercesc::XSNamespaceItem
	boost::python::class_<xercesc::XSNamespaceItem, boost::noncopyable>("XSNamespaceItem", boost::python::init<xercesc::XSModel* const, xercesc::SchemaGrammar* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<xercesc::XSModel* const, const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(XSNamespaceItemDefVisitor())
			.def(XSNamespaceItemStringDefVisitor<XMLString&>())
			.def(XSNamespaceItemStringDefVisitor<char*>())
			.def("getSchemaNamespace", &xercesc::XSNamespaceItem::getSchemaNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getComponents", &xercesc::XSNamespaceItem::getComponents, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAnnotations", static_cast<xercesc::XSAnnotationList*(xercesc::XSNamespaceItem::*)(void)>(&xercesc::XSNamespaceItem::getAnnotations), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementDeclaration", &xercesc::XSNamespaceItem::getElementDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributeDeclaration", &xercesc::XSNamespaceItem::getAttributeDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTypeDefinition", &xercesc::XSNamespaceItem::getTypeDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributeGroup", &xercesc::XSNamespaceItem::getAttributeGroup, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getModelGroupDefinition", &xercesc::XSNamespaceItem::getModelGroupDefinition, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNotationDeclaration", &xercesc::XSNamespaceItem::getNotationDeclaration, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
